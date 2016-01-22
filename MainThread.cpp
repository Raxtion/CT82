//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainThread.h"
#pragma package(smart_init)


#include "C_GetTime.h"
#include "PCIM114GL.h"
#include "IniFile.h"
#include "math.h"
#include "DominoVision.h"
#include "CEVision.h"
#include "KenenceLaser.h"
#include "SMSXML.h"
#include "frmMain.h"

#include <algorithm>

extern PCIM114GL g_MNet;
extern CIniFile g_IniFile;
extern CEVision theVision;
extern DominoVision g_Grabber;
extern CKeyenceLaser g_Laser;
bool g_bStopMainThread=false;
extern CSMSXML g_SMSXML;
extern TfmShowNow *fmShowNow;

CMainThread *g_pMainThread;
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall CMainThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall CMainThread::CMainThread(bool CreateSuspended)
        : TThread(CreateSuspended)
{

        m_bRefresh=false;
        m_bIsHomeDone=false;
        m_bStopLoad=false;
        m_bReLoad=false;
        m_bNeedHome=false;
        m_bStopBlower=false;
        bFrontTable=false;
        m_strLastUpReadID="";
        m_nSubstrateInMachine=0;
}
//---------------------------------------------------------------------------
void __fastcall CMainThread::Execute()
{
    //---- Place thread code here ----
    C_GetTime tmReset,tmAlarm,tmResetLamp,tmBlower;

	g_bStopMainThread=false;

	bool bHomeDone=false;
	bool bAutoMode=false;
    bool bPreAuto=false;

	bool bLastStart=false;
	bool bLastReset=false;

	bool bAlarmLamp=false;
	bool bResetLamp=false;

    bool bStartMachineInit=false;

	//int nThreadIndex[MAX_PROCESS]={0};		//0:Inti 1:Start Measure

	while(1)
	{
		if(g_bStopMainThread) break;

        //Status
        m_bIsHomeDone=bHomeDone;
        m_bIsAutoMode=bAutoMode;
        //

        if(m_bNeedHome)
        {
            m_bNeedHome=false;
            bHomeDone=false;
        }

        g_Motion.m_bAutoMode=m_bIsAutoMode;


        //---Start Homing
		if(g_DIO.ReadDIBit(DI::ResetBtn) && !bLastReset) tmReset.timeStart(3000);
		if(bLastReset && tmReset.timeUp())
		{
			bStartMachineInit=true;
			bHomeDone=false;
		}
		bLastReset=g_DIO.ReadDIBit(DI::ResetBtn);

        //CheckAlarm();
        if(g_MNet.IsCommError(0)) g_IniFile.m_nErrorCode=50;

        //----Alarm Occured
        //--Stop Auto
		if(g_DIO.ReadDIBit(DI::StopBtn) || (g_IniFile.m_nErrorCode>0 && g_IniFile.m_nErrorCode<1000))
        {
            bStartMachineInit=false;
            bAutoMode=false;
            bPreAuto=false;
            SetManualSpeed();

            g_Motion.StopMove(Axis_Const::SSY);
            g_Motion.StopMove(Axis_Const::SCY);
            g_Motion.StopMove(Axis_Const::FTX);
            g_Motion.StopMove(Axis_Const::RTX);
            g_Motion.StopMove(Axis_Const::CCD);

            g_DIO.SetDO(DO::SR_Start,false);
            g_DIO.SetDO(DO::SR2_Start,false);

            g_DIO.SetDO(DO::SL_Start,false);
            g_DIO.SetDO(DO::SS_SSucker,false);
            g_DIO.SetDO(DO::SS_SpaSucker,false);
            g_DIO.SetDO(DO::SC_SSucker,false);

            g_DIO.SetDO(DO::SR_Ready,false);
            g_DIO.SetDO(DO::SR2_PusherPush,false);
            g_DIO.SetDO(DO::SR2_PusherDown,false);
            g_DIO.SetDO(DO::UnloaderEnough,false);
            tmBlower.timeStart(10000);
            m_bStopBlower = true;
        }

        //---Off Blower
        if(m_bStopBlower && tmBlower.timeUp())
        {
            g_DIO.SetDO(DO::Blower, false);
            m_bStopBlower = false;
        }

                //---Reset Alarm
		if(g_DIO.ReadDIBit(DI::ResetBtn) )
		{
			g_IniFile.m_nErrorCode=0;

			g_DIO.SetDO(DO::RedLamp,false);
			g_DIO.SetDO(DO::Buzzer,false);
		}

                //---Buzzer
		if(tmAlarm.timeUp() && g_IniFile.m_nErrorCode>0)
		{
			g_DIO.SetDO(DO::RedLamp,bAlarmLamp);
			g_DIO.SetDO(DO::Buzzer,bAlarmLamp);
			bAlarmLamp=!bAlarmLamp;
			tmAlarm.timeStart(500);
		}
                //---Homing Announce
                else if(tmAlarm.timeUp() && !bHomeDone)
		{
			g_DIO.SetDO(DO::StopBtnLamp,bAlarmLamp);
            g_DIO.SetDO(DO::StartBtnLamp,bAlarmLamp);
            g_DIO.SetDO(DO::ResetBtnLamp,bAlarmLamp);

			bAlarmLamp=!bAlarmLamp;
			tmAlarm.timeStart(500);
		}



	        //---Homing Process
		if(!bHomeDone && !bAutoMode  && bStartMachineInit)
		{
			bHomeDone=InitialMachine(nThreadIndex[0]);
			if(bHomeDone)
            {

                for(int nIndex=0;nIndex<MAX_PROCESS;nIndex++)
                    nThreadIndex[nIndex]=0;


                bStartMachineInit=false;
            }

            CheckAlarm();
		}
		else if(bAutoMode && bHomeDone)	                //AutoMode
		{
			g_DIO.SetDO(DO::StopBtnLamp,false);
			g_DIO.SetDO(DO::StartBtnLamp,true);
			g_DIO.SetDO(DO::GreenLamp,true);
			g_DIO.SetDO(DO::YellowLamp,false);
			g_DIO.SetDO(DO::RedLamp,false);

            CheckAlarm();

            //do Auto process

            if(g_IniFile.m_bIsRailLoad )
            {
                doLoadRail(nThreadIndex[1]);
                doSSPickerFromRail(nThreadIndex[2]);
            }
            else
            {
                if(!m_bStopLoad) doLoadLifter(nThreadIndex[3]);
                doSSPickerFromLifter(nThreadIndex[4]);
            }

            if(g_IniFile.m_nUseTable==0 || g_IniFile.m_nUseTable==2) doTable(nThreadIndex[5],true);
            if(g_IniFile.m_nUseTable==1 || g_IniFile.m_nUseTable==2) doTable(nThreadIndex[6],false);

            doSCPicker(nThreadIndex[7]);
            doUnLoadRail(nThreadIndex[8]);


		}
		else if(bHomeDone)			        //Manual Mode
		{
			g_DIO.SetDO(DO::StopBtnLamp,true);
			g_DIO.SetDO(DO::StartBtnLamp,false);
                        g_DIO.SetDO(DO::ResetBtnLamp,false);

			g_DIO.SetDO(DO::GreenLamp,false);
			g_DIO.SetDO(DO::YellowLamp,true);
			//g_DIO.SetDO(DO::RedLamp,false);

			if(g_DIO.ReadDIBit(DI::StartBtn))
			{
                if(g_IniFile.m_strProductPgm==g_IniFile.m_strSMSPartNo)
                {
                    bPreAuto=true;
                    nThreadIndex[19]=0;      //pre auto
                    SetManualSpeed();
                }
                else g_IniFile.m_nErrorCode=51;
			}

            if(bPreAuto)
            {
                g_DIO.SetDO(DO::StopBtnLamp,true);
                g_DIO.SetDO(DO::StartBtnLamp,true);
                g_DIO.SetDO(DO::GreenLamp,true);
                g_DIO.SetDO(DO::YellowLamp,false);
                g_DIO.SetDO(DO::RedLamp,false);
                CheckAlarm();
                                
                bAutoMode=doPreAuto(nThreadIndex[19]);
                bPreAuto=!bAutoMode;
                if (bAutoMode) SetWorkSpeed();
            }
		}
		else
		{
            if(!bHomeDone && g_DIO.ReadDIBit(DI::StartBtn)) g_IniFile.m_nErrorCode=999;
            //Announce to Homing
			if(tmResetLamp.timeUp())
			{
				g_DIO.SetDO(DO::ResetBtnLamp,bResetLamp);
				g_DIO.SetDO(DO::YellowLamp,bResetLamp);
				bResetLamp=!bResetLamp;
				tmResetLamp.timeStart(500);
			}
		}
	
		::Sleep(10);
	}
}
//---------------------------------------------------------------------------
bool __fastcall CMainThread::InitialMachine(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);


        switch(nThreadIndex)
        {
                case 0:
                        if(!g_DIO.ReadDIBit(DI::MainAir)) g_IniFile.m_nErrorCode=6;     //debug
                        else if(!g_DIO.ReadDIBit(DI::FT_Positive)) g_IniFile.m_nErrorCode=7;
                        else if(!g_DIO.ReadDIBit(DI::RT_Positive)) g_IniFile.m_nErrorCode=8;
                        else if(g_DIO.ReadDIBit(DI::FT_VacGauge)) g_IniFile.m_nErrorCode=9;
                        else if(g_DIO.ReadDIBit(DI::RT_VacGauge)) g_IniFile.m_nErrorCode=10;
                        else if(!g_DIO.ReadDIBit(DI::SC_SSuckerUp)) g_IniFile.m_nErrorCode=19;
                        else if(g_DIO.ReadDIBit(DI::SC_SSuckerVacGauge)) g_IniFile.m_nErrorCode=21;
                        else if(g_DIO.ReadDIBit(DI::SC_CSuckerVacGauge)) g_IniFile.m_nErrorCode=22;

                        else if(g_DIO.ReadDIBit(DI::SR_Exist)) g_IniFile.m_nErrorCode=24;
                        else if(g_DIO.ReadDIBit(DI::SR_Inp)) g_IniFile.m_nErrorCode=25;
                        else if(g_DIO.ReadDIBit(DI::SR_Entry)) g_IniFile.m_nErrorCode=26;
                        else if(g_DIO.ReadDIBit(DI::SR2_Exist)) g_IniFile.m_nErrorCode=40;
                        else if(g_DIO.ReadDIBit(DI::SR2_Inp)) g_IniFile.m_nErrorCode=41;
                        else if(g_DIO.ReadDIBit(DI::SR2_Exit)) g_IniFile.m_nErrorCode=42;
                        else if(!g_DIO.ReadDIBit(DI::SR2_PusherBwd)) g_IniFile.m_nErrorCode=43;
                        else if(!g_DIO.ReadDIBit(DI::SR2_PusherUp)) g_IniFile.m_nErrorCode=44;
                        else if(!g_DIO.ReadDIBit(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=28;
                        else if(!g_DIO.ReadDIBit(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=29;
                        else if(g_DIO.ReadDIBit(DI::SS_SSuckerVacGauge)) g_IniFile.m_nErrorCode=30;
                        else if(g_DIO.ReadDIBit(DI::SS_SpaSuckerVacGauge)) g_IniFile.m_nErrorCode=31;
                        else
                        {
                                for(int nIndex=0;nIndex<80;nIndex++) g_DIO.SetDO(nIndex,false);

                                for(int nIndex=0;nIndex<AXIS_SIZE;nIndex++) g_Motion.ServoOn(nIndex,true);


                                nThreadIndex++;
                        }
                        break;
                case 1:

                        //g_IniFile.m_nErrorCode=1000;    //Start Homing
                        m_listLog.push_back("機台初始中,請稍后");

                        g_Motion.SetMoveSpeed(Axis_Const::FTX,20,0.01,0.01);
                        g_Motion.SetMoveSpeed(Axis_Const::RTX,20,0.01,0.01);
                        g_Motion.SetMoveSpeed(Axis_Const::SSY,10,0.01,0.01);
                        g_Motion.SetMoveSpeed(Axis_Const::CCD,10,0.01,0.01);

                        g_Motion.SetMoveSpeed(Axis_Const::SCY,10,0.01,0.01);

                        tm1MS.timeStart(1500);
                        nThreadIndex++;
                        break;
                case 2:

                        {

                                nThreadIndex++;
                        }
                        break;
                case 3:

                        {

                                nThreadIndex++;
                        }
                        break;
                case 4:

                        {
                                for(int nAxis=4;nAxis<AXIS_SIZE;nAxis++)
                                {
                                    if(g_Motion.GetAxisStatus(nAxis,Axis_Const::MEL) || g_Motion.GetAxisStatus(nAxis,Axis_Const::ORG)) g_Motion.RelMove(nAxis,10.0);
                                }

                                tm1MS.timeStart(1500);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if(g_Motion.IsMotionDone(Axis_Const::FTX) && g_Motion.IsMotionDone(Axis_Const::RTX) &&
                                g_Motion.IsMotionDone(Axis_Const::SSY) && g_Motion.IsMotionDone(Axis_Const::CCD) &&
                                g_Motion.IsMotionDone(Axis_Const::SCY) && tm1MS.timeUp())
                        {
                                tm1MS.timeStart(1500);
                                nThreadIndex++;
                        }
                        break;
                case 6:
                        if(tm1MS.timeUp())
                        {
                                for(int nAxis=4;nAxis<AXIS_SIZE;nAxis++)
                                {
                                    g_Motion.AxisHome(nAxis,false);
                                    tm1MS.timeStart(1500);
                                }
                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if(g_Motion.IsMotionDone(Axis_Const::FTX) && g_Motion.IsMotionDone(Axis_Const::RTX) &&
                                g_Motion.IsMotionDone(Axis_Const::SSY) && g_Motion.IsMotionDone(Axis_Const::CCD) &&
                                g_Motion.IsMotionDone(Axis_Const::SCY) && tm1MS.timeUp())
                        {
                                tm1MS.timeStart(1500);
                                nThreadIndex++;
                        }
                        break;
                 case 8:
                        if(tm1MS.timeUp())
                        {
                                g_Motion.StopMove(Axis_Const::SSY);
                                g_Motion.StopMove(Axis_Const::SCY);
                                g_Motion.StopMove(Axis_Const::FTX);
                                g_Motion.StopMove(Axis_Const::RTX);
                                g_Motion.StopMove(Axis_Const::CCD);

                                for(int nAxis=4;nAxis<10;nAxis++)
                                {
                                        g_Motion.SetCommandPos(nAxis,0.0);
                                        g_Motion.SetFeedbackPos(nAxis,0.0);
                                }
                                nThreadIndex++;
                        }
                        break;
                 case 9:
                        //do initial pos or flag
                        for(int nIndex=4;nIndex<AXIS_SIZE;nIndex++) g_Motion.m_dLastTargetPos[nIndex]=0.0;

                        m_nLaserCount=0;
                        m_nOKSummary=0;
                        m_nNGSummary=0;
                        m_nSubstrateRemains=0;
                        m_nSubstrateInMachine=0;
                        m_nStripCount=0;

                        m_bLoadRailReady=false;
                        m_bLoadLifterReady=false;
                        m_bSSPickerReady=false;
                        m_bTableReady[0]=false;
                        m_bTableReady[1]=false;


                        m_bSCPickerSSReady=false;
                        
                        m_bIsSSPickeLocked=false;
                        m_bIsMapCCDLocked=false;

                        m_listPutTable.clear();
                        m_listPickTable.clear();
                        m_listProductInfo.clear();


                        m_bLaserLocked=false;
                        m_bLaserReaderLocked=false;

                        m_bSSPickerDown=false;
                        m_bSpaPickerDown=false;
                        m_bSSPicker2Down=false;
                        m_bCoverPickerDown=false;
                        m_bLEDDown=false;

                        g_DIO.SetDO(DO::SS_SpaVacOff,true);
                        g_DIO.SetDO(DO::SS_SVacOff,true);
                        
                        for (int nX=0;nX<24;nX++)
                        {
                            fmShowNow->m_arraybShape[nX] = false;
                        }

                        g_IniFile.m_nErrorCode=1001;
                        nThreadIndex++;
                        break;

                default:
                        nThreadIndex=0;
                        return true;

        }

        if(g_IniFile.m_nErrorCode>0 && g_IniFile.m_nErrorCode<1000)  nThreadIndex=0;

        return false;

}
//---------------------------------------------------------------------------
void __fastcall CMainThread::CheckAlarm()
{
        if(g_Motion.GetAxisStatus(Axis_Const::FTX ,Axis_Const::ALM)) g_IniFile.m_nErrorCode=201;
        else if(g_Motion.GetAxisStatus(Axis_Const::RTX ,Axis_Const::ALM)) g_IniFile.m_nErrorCode=202;
        else if(g_Motion.GetAxisStatus(Axis_Const::SSY ,Axis_Const::ALM)) g_IniFile.m_nErrorCode=203;
        else if(g_Motion.GetAxisStatus(Axis_Const::CCD ,Axis_Const::ALM)) g_IniFile.m_nErrorCode=204;
        else if(g_Motion.GetAxisStatus(Axis_Const::SCY ,Axis_Const::ALM)) g_IniFile.m_nErrorCode=209;


        //if(!g_DIO.ReadDIBit(DI::EmgBtn)) g_IniFile.m_nErrorCode=5;     //debug
        if(!g_DIO.ReadDIBit(DI::MainAir)) g_IniFile.m_nErrorCode=6;  //debug
        if(!g_DIO.ReadDIBit(DI::SafetyDoor) && !g_DIO.ReadDOBit(DO::SafetyDoorByPass) ) g_IniFile.m_nErrorCode=35; //debug
        if(m_bIsAutoMode && g_SMSXML.m_nOnLineMode!=2 && g_IniFile.m_bUseLaserMark ) g_IniFile.m_nErrorCode=36;

        if(m_bIsAutoMode  && g_DIO.ReadDIBit(DI::FT_IN_FAN_ALM)) g_IniFile.m_nErrorCode=110;
        if(m_bIsAutoMode  && g_DIO.ReadDIBit(DI::FT_OUT_FAN_ALM)) g_IniFile.m_nErrorCode=111;
        if(m_bIsAutoMode  && g_DIO.ReadDIBit(DI::RT_IN_FAN_ALM)) g_IniFile.m_nErrorCode=112;
        if(m_bIsAutoMode  && g_DIO.ReadDIBit(DI::RT_OUT_FAN_ALM)) g_IniFile.m_nErrorCode=113;

}
//---------------------------------------------------------------------------
void __fastcall CMainThread::SetWorkSpeed()
{
        for(int nIndex=0;nIndex<10;nIndex++)
                g_Motion.SetMoveSpeed(nIndex,g_IniFile.m_dWorkSpeed[nIndex],g_IniFile.m_dACCSpeed[nIndex],g_IniFile.m_dDECSpeed[nIndex]);

}
//---------------------------------------------------------------------------
void __fastcall CMainThread::SetManualSpeed()
{
         for(int nIndex=0;nIndex<10;nIndex++)
                g_Motion.SetMoveSpeed(nIndex,g_IniFile.m_dJogSpeed[nIndex],g_IniFile.m_dACCSpeed[nIndex],g_IniFile.m_dDECSpeed[nIndex]);
}
//---------------------------------------------------------------------------
void __fastcall CMainThread::doLoadRail(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        //const int nTagA=1000;


        switch(nThreadIndex)
        {
                case 0:
                        if(!m_bStopLoad)
                        {
                                if(!g_DIO.GetDI(DI::SR_Entry) && !g_DIO.GetDI(DI::SR_Exist) && !g_DIO.GetDI(DI::SR_Inp))
                                {
                                        g_DIO.SetDO(DO::SR_Ready,true);
                                }
                                if (g_IniFile.m_nLoadingAlarmTime != 0) tm1MS.timeStart(g_IniFile.m_nLoadingAlarmTime);
                                g_DIO.SetDO(DO::UnloaderEnough,false);
                                nThreadIndex++;
                        }
                        break;
                case 1:
                        if(g_DIO.GetDI(DI::SR_Entry) && !g_DIO.GetDI(DI::SR_Exist) && !g_DIO.GetDI(DI::SR_Inp))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[0] = true;
                                m_nSubstrateRemains++;
                                m_nSubstrateInMachine++;
                                m_nStripCount++;

                                if(m_nStripCount>=g_IniFile.m_nIssueQty && g_IniFile.m_nIssueQty>0 && !m_bStopLoad)
                                {
                                        m_bStopLoad=true;
                                        m_bLoadLifterReady=false;
                                        g_DIO.SetDO(DO::SL_Start,false);
                                        m_listLog.push_back("到達設定量,自動停止入料");
                                }
                                else if(m_nStripCount==2 && g_IniFile.m_nIssueQty>0 && !m_bStopLoad && g_IniFile.m_bUsePQC)
                                {
                                        m_bStopLoad=true;
                                        m_bLoadLifterReady=false;
                                        g_DIO.SetDO(DO::SL_Start,false);
                                        m_listLog.push_back("PQC ,自動停止入料");
                                }

                                g_DIO.SetDO(DO::SR_Ready,false);
                                g_DIO.SetDO(DO::SR_Start,true);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        else if (tm1MS.timeUp())
                        {
                            g_IniFile.m_nErrorCode=321;
                            g_DIO.SetDO(DO::UnloaderEnough,true);
                            nThreadIndex--;
                        }
                        else g_DIO.SetDO(DO::SR_Ready,true);
                        break;
                case 2:
                        if(g_DIO.GetDI(DI::SR_Inp) && !g_DIO.GetDI(DI::SR_Entry))
                        {
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SR_Start))
                        {
                                g_DIO.SetDO(DO::SR_Start,true);
                                tm1MS.timeStart(5000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=300;
                        break;
                case 3:
                        if(tm1MS.timeUp())
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[0] = false;
                                fmShowNow->m_arraybShape[1] = true;
                                g_DIO.SetDO(DO::SR_Start,false);
                                g_DIO.SetDO(DO::SR_Align,true);
                                tm1MS.timeStart(500);
                                nThreadIndex++;
                        }
                        break;
                case 4:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SR_Align,false);
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if(tm1MS.timeUp())
                        {
                                m_bLoadRailReady=true;
                                nThreadIndex++;
                        }
                        break;
                case 6:
                        if(!m_bLoadRailReady)
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;
        }


}
//---------------------------------------------------------------------------
void __fastcall CMainThread::doUnLoadRail(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);


        switch(nThreadIndex)
        {
                case 0:
                        if(m_bSCPickerSSReady)
                        {
                                if(!g_DIO.GetDI(DI::SR2_Exist) && !g_DIO.GetDI(DI::SR2_Exit) && !g_DIO.GetDI(DI::SR2_Inp) && g_DIO.GetDI(DI::SR2_PusherUp))
                                {
                                        g_DIO.SetDO(DO::SC_SSucker,true);
                                        tm1MS.timeStart(3000);
                                        nThreadIndex++;
                                }
                                else g_IniFile.m_nErrorCode=45;
                        }
                        break;
                case 1:
                        if(g_DIO.GetDI(DI::SC_SSuckerDown))
                        {
                                g_DIO.SetDO(DO::SC_SSuckerVacOn,false);
                                g_DIO.SetDO(DO::SC_SSuckerVacOff,true);
                                g_DIO.SetDO(DO::SC_SSuckerDeVac,true);
                                tm1MS.timeStart(500);
                                nThreadIndex++;
                        }
                        if(!g_DIO.GetDO(DO::SC_SSucker))
                        {
                                g_DIO.SetDO(DO::SC_SSucker,true);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=507;
                        break;
                case 2:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SC_SSucker,false);
                                g_DIO.SetDO(DO::SC_SSuckerVacOff,false);
                                g_DIO.SetDO(DO::SC_SSuckerDeVac,false);
                                m_bSCPickerSSReady=false;
                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if(g_DIO.GetDI(DI::SC_SSuckerUp))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[10] = false;
                                fmShowNow->m_arraybShape[11] = true;
                                nThreadIndex++;
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=511;
                        break;
                case 4:
                        if (g_DIO.GetDI(DI::OutReady) || g_IniFile.m_bForceEject)
                        {
                                g_DIO.SetDO(DO::SR2_Start,true);
                                tm1MS.timeStart(10000);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if(g_DIO.GetDI(DI::SR2_Exit)) g_DIO.SetDO(DO::SR2_PressWheel,true);

                        if(!g_DIO.GetDI(DI::SR2_Inp) && g_DIO.GetDI(DI::SR2_Exit))
                        {
                                tm1MS.timeStart(500);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SR2_Start))
                        {
                                g_DIO.SetDO(DO::SR2_Start,true);
                                tm1MS.timeStart(10000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=46;
                        break;
                case 6:
                        if(tm1MS.timeUp())
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[11] = false;
                                fmShowNow->m_arraybShape[12] = true;

                                g_DIO.SetDO(DO::SR2_PusherDown,true);
                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if(g_DIO.GetDI(DI::SR2_PusherDown))
                        {
                                g_DIO.SetDO(DO::SR2_PusherPush,true);
                                g_DIO.SetDO(DO::SR2_OutGoing,true);
                                g_DIO.SetDO(DO::SR2_PressWheel,false);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDI(DI::SR2_PusherUp))
                        {
                                g_DIO.SetDO(DO::SR2_PusherDown,true);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=47;
                        break;
                case 8:
                        if(g_DIO.GetDI(DI::SR2_PusherFwd))                
                        {
                                g_DIO.SetDO(DO::SR2_PusherPush,false);
                                g_DIO.SetDO(DO::SR2_PusherDown,false);
                                g_DIO.SetDO(DO::SR2_OutGoing,false);
                                g_DIO.SetDO(DO::SR2_Start,false);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        else if (g_DIO.GetDI(DI::SR2_PusherUp))
                        {
                                nThreadIndex--;
                        }
                        else if(!g_DIO.GetDO(DO::SR2_PusherPush))
                        {
                                g_DIO.SetDO(DO::SR2_PusherPush,true);
                                g_DIO.SetDO(DO::SR2_PusherDown,true);
                                tm1MS.timeStart(5000);
                        }
                        else if(!g_DIO.GetDI(DI::SR2_PusherAlarm))
                        {
                                g_DIO.SetDO(DO::SR2_PusherPush,false);
                                g_DIO.SetDO(DO::SR2_PusherDown,false);
                                g_IniFile.m_nErrorCode=48;
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=49;
                        break;
                case 9:
                        if(g_DIO.GetDI(DI::SR2_PusherBwd) && g_DIO.GetDI(DI::SR2_PusherUp))
                        {
                                if(m_nSubstrateRemains>0) m_nSubstrateRemains--;

                                if (m_nSubstrateInMachine>0) m_nSubstrateInMachine--;
                                else if (m_nSubstrateInMachine == 0) g_DIO.SetDO(DO::UnloaderEnough,true);

                                //ShowNow
                                fmShowNow->m_arraybShape[12] = false;

                                tm1MS.timeStart(500);
                                nThreadIndex++;

                        }
                        else if(tm1MS.timeUp() && !g_DIO.GetDI(DI::SR2_PusherBwd)) g_IniFile.m_nErrorCode=43;
                        else if(tm1MS.timeUp() && !g_DIO.GetDI(DI::SR2_PusherUp)) g_IniFile.m_nErrorCode=44;
                        break;
                case 10:
                        if(tm1MS.timeUp())
                        {
                                if (g_DIO.GetDO(DO::UnloaderEnough))
                                {
                                    g_DIO.SetDO(DO::UnloaderEnough,false);
                                    g_pMainThread->m_bStopLoad = false;
                                    g_pMainThread->m_bLoadLifterReady = true;
                                    g_pMainThread->m_bReLoad = true;
                                }

                                if(m_bStopLoad && m_nSubstrateRemains<=0 && g_IniFile.m_bUsePQC) g_IniFile.m_nErrorCode=914;
                                else if(m_bStopLoad && m_nSubstrateRemains<=0 && g_IniFile.m_nIssueQty != 0)
                                {
                                        g_IniFile.m_strSMSPartNo="";
                                        g_IniFile.m_strSMSLotNo="";
                                        g_IniFile.m_strSBTLotNo="";
                                        g_IniFile.m_strProductID="";
                                        g_IniFile.m_nErrorCode=913;
                                }
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;
        }


}
//---------------------------------------------------------------------------

void __fastcall CMainThread::doLoadLifter(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        const bool bLifterDown=true;
        const bool bLifterUp=false;

        switch(nThreadIndex)
        {
                case 0:
                        if(g_DIO.GetDI(DI::SL_Down) && g_DIO.GetDI(DI::SL_Inp)) g_IniFile.m_nErrorCode=301;
                        else if(!g_DIO.GetDI(DI::SL_Exist)) g_IniFile.m_nErrorCode=302;
                        else
                        {
                                g_DIO.SetDO(DO::SL_Dir,bLifterDown);
                                g_DIO.SetDO(DO::SL_Start,!g_DIO.GetDI(DI::SL_Down));
                                tm1MS.timeStart(10000);
                                nThreadIndex++;
                        }
                        break;
                case 1:
                        if(!g_DIO.GetDI(DI::SL_Inp))
                        {
                                //g_DIO.SetDO(DO::SL_Start,false);
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDI(DI::SL_Down))
                        {
                                g_DIO.SetDO(DO::SL_Start,false);
                                g_IniFile.m_nErrorCode=303;
                        }
                        else if(!g_DIO.GetDO(DO::SL_Start))
                        {
                                g_DIO.SetDO(DO::SL_Start,true);
                                g_DIO.SetDO(DO::SL_Dir,bLifterDown);
                                tm1MS.timeStart(10000);
                        }
                        else if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SL_Start,false);
                                g_IniFile.m_nErrorCode=304;
                        }
                        break;
                case 2:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SL_Dir,bLifterUp);
                                g_DIO.SetDO(DO::SL_Start,true);
                                tm1MS.timeStart(10000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if(g_DIO.GetDI(DI::SL_Inp))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[20] = true;

                                g_DIO.SetDO(DO::SL_Start,false);
                                m_bLoadLifterReady=true;
                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDI(DI::SL_Up))
                        {
                                g_DIO.SetDO(DO::SL_Start,false);
                                g_IniFile.m_nErrorCode=306;
                        }
                        else if(!g_DIO.GetDI(DI::SL_Exist))
                        {
                                g_DIO.SetDO(DO::SL_Start,false);
                                g_IniFile.m_nErrorCode=302;
                        }
                        else if(!g_DIO.GetDO(DO::SL_Start))
                        {
                                g_DIO.SetDO(DO::SL_Start,true);
                                g_DIO.SetDO(DO::SL_Dir,bLifterUp);
                                tm1MS.timeStart(10000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=305;
                        break;
                case 4:
                        if(!m_bLoadLifterReady)
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;
        }

}
//---------------------------------------------------------------------------
void __fastcall CMainThread::doSSPickerFromLifter(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        static bool bIsSubstrate=false;
        
        static bool bFrontTable=false;
        const int nTagPickOK=1000;
        const int nTagReSuck=2000;

        const bool bLifterDown=true;
        const bool bLifterUp=false;

        switch(nThreadIndex)
        {
                case 0:
                case nTagReSuck:nThreadIndex=0;
                        if(!g_DIO.GetDI(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=307;
                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=308;
                        //else if(g_DIO.GetDI(DI::SS_SSuckerVacGauge)) g_IniFile.m_nErrorCode=309;
                        //else if(g_DIO.GetDI(DI::SS_SpaSuckerVacGauge)) g_IniFile.m_nErrorCode=310;
                        else if(m_bLoadLifterReady )
                        {
                                {
                                        bIsSubstrate=!g_DIO.GetDI(DI::IsSubstrate);
                                        bIsSubstrate? g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPickPos) : g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSpaPickerPickPos);
                                        tm1MS.timeStart(5000);
                                        nThreadIndex++;
                                }

                        }
                        break;
                case 1:
                        if(g_Motion.IsLastPosDone(Axis_Const::SSY))
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        } 
                        break;
                case 2:
                        if(tm1MS.timeUp())
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,true) : g_DIO.SetDO(DO::SS_SpaSucker,true);

                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if(bIsSubstrate & g_DIO.GetDI(DI::SS_SSuckerDown))
                        {
                                if (!g_DIO.GetDI(DI::SS_SSuckerColorSensor))
                                {
                                        tm1MS.timeStart(300);
                                        nThreadIndex++;
                                }
                                else
                                {
                                        g_DIO.SetDO(DO::SS_SSucker,false);
                                        g_IniFile.m_nErrorCode=320;
                                }
                        }
                        else if (!bIsSubstrate & g_DIO.GetDI(DI::SS_SpaSuckerDown))
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SS_SSucker) || !g_DIO.GetDO(DO::SS_SpaSucker) )
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,true) : g_DIO.SetDO(DO::SS_SpaSucker,true);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp())
                        {
                                bIsSubstrate? g_IniFile.m_nErrorCode=311 : g_IniFile.m_nErrorCode=312;
                                nThreadIndex=nTagReSuck;
                        }

                        break;
                case 4:
                        if(tm1MS.timeUp())
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SVacOn,true) : g_DIO.SetDO(DO::SS_SpaVacOn,true);
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SVacOff,false) : g_DIO.SetDO(DO::SS_SpaVacOff,false);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if( (bIsSubstrate & g_DIO.GetDI(DI::SS_SSuckerVacGauge)) ||
                                (!bIsSubstrate & g_DIO.GetDI(DI::SS_SpaSuckerVacGauge)))
                        {
                                if (bIsSubstrate)
                                {
                                    fmShowNow->m_arraybShape[20] = false;
                                    fmShowNow->m_arraybShape[21] = true;
                                }
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        /*
                        else if( (bIsSubstrate & !g_DIO.GetDO(DI::SS_SSuckerVacGauge)) ||
                                (!bIsSubstrate & !g_DIO.GetDO(DI::SS_SpaSuckerVacGauge)))
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SVacOn,true) : g_DIO.SetDO(DO::SS_SpaVacOn,true);
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SVacOff,false) : g_DIO.SetDO(DO::SS_SpaVacOff,false);
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,true) : g_DIO.SetDO(DO::SS_SpaSucker,true);

                                tm1MS.timeStart(5000);
                        }
                        */
                        else if(tm1MS.timeUp())
                        {
                                nThreadIndex=nTagReSuck;
                                bIsSubstrate? g_IniFile.m_nErrorCode=313 : g_IniFile.m_nErrorCode=314;
                        }
                        break;
                case 6:
                        if(tm1MS.timeUp())
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,false) : g_DIO.SetDO(DO::SS_SpaSucker,false);
                                tm1MS.timeStart(3000);

                                g_DIO.SetDO(DO::SL_Start,true);
                                g_DIO.SetDO(DO::SL_Dir,bLifterDown);

                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if(g_IniFile.m_bShakeSubstarte)
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker, !g_DIO.GetDO(DO::SS_SSucker)) : g_DIO.SetDO(DO::SS_SpaSucker,!g_DIO.GetDO(DO::SS_SpaSucker));       //Shaking
                                
                        if(tm1MS.timeUp())
                        {
                                bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,false) : g_DIO.SetDO(DO::SS_SpaSucker,false);
                                tm1MS.timeStart(3000);

                                g_DIO.SetDO(DO::SL_Start,false);
                                
                                nThreadIndex++;
                        }
                        break;
                case 8:
                        if( (bIsSubstrate & g_DIO.GetDI(DI::SS_SSuckerUp)) || (!bIsSubstrate & g_DIO.GetDI(DI::SS_SpaSuckerUp)))
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDO(DO::SS_SSucker) || g_DIO.GetDO(DO::SS_SpaSucker))
                        {
                                 bIsSubstrate? g_DIO.SetDO(DO::SS_SSucker,false) : g_DIO.SetDO(DO::SS_SpaSucker,false);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) bIsSubstrate? g_IniFile.m_nErrorCode=315 : g_IniFile.m_nErrorCode=316;
                        break;
                case 9:
                        if( (bIsSubstrate & g_DIO.GetDI(DI::SS_SSuckerVacGauge)) ||
                                (!bIsSubstrate & g_DIO.GetDI(DI::SS_SpaSuckerVacGauge)))
                        {
                                nThreadIndex++;
                        }
                        else if(tm1MS.timeUp())
                        {
                                m_bLoadLifterReady=false;      //Announce Lifter to reload again
                                nThreadIndex=nTagReSuck;
                                bIsSubstrate? g_IniFile.m_nErrorCode=313 : g_IniFile.m_nErrorCode=314;
                        }
                        break;
                case 10:
                        if(tm1MS.timeUp())
                        {
                                if(bIsSubstrate)
                                {
                                        m_nSubstrateRemains++;
                                        m_nSubstrateInMachine++;
                                        m_nStripCount++;

                                        if(m_nStripCount>=g_IniFile.m_nIssueQty && g_IniFile.m_nIssueQty>0 && !m_bStopLoad)
                                        {
                                                m_bStopLoad=true;
                                                m_bLoadLifterReady=false;
                                                g_DIO.SetDO(DO::SL_Start,false);
                                                m_listLog.push_back("到達設定量,自動停止入料");
                                        }
                                        else if(m_nStripCount==2 && g_IniFile.m_nIssueQty>0 && !m_bStopLoad && g_IniFile.m_bUsePQC)
                                        {
                                                m_bStopLoad=true;
                                                m_bLoadLifterReady=false;
                                                g_DIO.SetDO(DO::SL_Start,false);
                                                m_listLog.push_back("PQC ,自動停止入料");
                                        }

                                         m_bSSPickerReady=true;
                                         nThreadIndex=nTagPickOK;

                                         switch (g_IniFile.m_nUseTable)
                                         {
                                         case 0:
                                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[true]);
                                                break;
                                         case 1:
                                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[false]);
                                                break;
                                         case 2:
                                                if(m_listPutTable.size()>0)
                                                {
                                                        if((m_listPutTable.front()=="REAR")) bFrontTable=true;
                                                        else if( (m_listPutTable.front()=="FRONT")) bFrontTable=false;
                                                        else bFrontTable=true;
                                                        g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                                        m_listPutTable.pop_front();
                                                }
                                                else
                                                {
                                                        bFrontTable=true;
                                                        g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                                }
                                                break;
                                         }
                                }
                                else
                                {
                                        if(!g_DIO.GetDI(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=307;
                                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=308;
                                        {
                                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSpaPickerThrowPos);
                                                nThreadIndex++;
                                        }
                                }

                                m_bLoadLifterReady=false;      //Announce Lifter to reload again

                        }
                        break;
                case 11:
                        if(g_Motion.IsLastPosDone(Axis_Const::SSY))
                        {
                                //ShowNow
                                if (bFrontTable == true)
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[21] = false;
                                    fmShowNow->m_arraybShape[13] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[21] = false;
                                    fmShowNow->m_arraybShape[3] = true;
                                }
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 12:
                        if(!g_DIO.GetDI(DI::SpacerBoxExist)) g_IniFile.m_nErrorCode=318;
                        else  if(g_DIO.GetDI(DI::SpacerBoxFull)) g_IniFile.m_nErrorCode=319;
                        else if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SpaVacOn,false);
                                g_DIO.SetDO(DO::SS_SpaVacOff,true);
                                g_DIO.SetDO(DO::SS_SpaDeVac,true);
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerVacGauge)) g_IniFile.m_nErrorCode=317; 
                        break;
                case 13:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SpaDeVac,false);
                                nThreadIndex++;
                        }
                        break;
                case 14:
                case nTagPickOK: nThreadIndex=14;
                        if(!m_bSSPickerReady)
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;
        }
}
//---------------------------------------------------------------------------
void __fastcall CMainThread::doSSPickerFromRail(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        const int nTagReSuck=1000;
        
        static bool bFrontTable=false;
        switch(nThreadIndex)
        {
                case 0:
                        if(!g_DIO.GetDI(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=307;
                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=308;
                        else if(g_DIO.GetDI(DI::SS_SSuckerVacGauge)) g_IniFile.m_nErrorCode=309;
                        else if(g_DIO.GetDI(DI::SS_SpaSuckerVacGauge)) g_IniFile.m_nErrorCode=310;
                        else
                        {
                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPickRailPos) ;
                                nThreadIndex++;
                        }
                        break;
                case 1:
                        if(g_Motion.IsLastPosDone(Axis_Const::SSY) && m_bLoadRailReady)
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 2:
                case nTagReSuck:nThreadIndex=2;
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SSucker,true);

                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if( g_DIO.GetDI(DI::SS_SSuckerDown))
                        {
                                if (!g_DIO.GetDI(DI::SS_SSuckerColorSensor))
                                {
                                        tm1MS.timeStart(300);
                                        nThreadIndex++;
                                }
                                else
                                {
                                        g_DIO.SetDO(DO::SS_SSucker,false);
                                        g_IniFile.m_nErrorCode=320;
                                }
                        }
                        else if( !g_DIO.GetDO(DO::SS_SSucker))
                        {
                                g_DIO.SetDO(DO::SS_SSucker,true);

                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=311;
                        break;
                case 4:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SVacOn,true);
                                g_DIO.SetDO(DO::SS_SVacOff,false);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if( g_DIO.GetDI(DI::SS_SSuckerVacGauge))
                        {
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(tm1MS.timeUp())
                        {
                                nThreadIndex=nTagReSuck;
                                g_IniFile.m_nErrorCode=313;
                        }
                        break;
                case 6:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SSucker,false);
                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if( g_DIO.GetDI(DI::SS_SSuckerUp))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[1] = false;
                                fmShowNow->m_arraybShape[2] = true;
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDO(DO::SS_SSucker))
                        {
                                 g_DIO.SetDO(DO::SS_SSucker,false);
                                tm1MS.timeStart(2000);
                        }
                        else if(tm1MS.timeUp())g_IniFile.m_nErrorCode=315;
                        break;
                case 8:
                        if( g_DIO.GetDI(DI::SS_SSuckerVacGauge))
                        {
                                nThreadIndex++;
                        }
                        else if(tm1MS.timeUp())
                        {
                                nThreadIndex=nTagReSuck;
                                g_IniFile.m_nErrorCode=313;
                        }
                        break;
                case 9:
                        switch (g_IniFile.m_nUseTable)
                        {
                        case 0:
                                bFrontTable=true;
                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                break;
                        case 1:
                                bFrontTable=false;
                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                break;
                        case 2:
                                if(m_listPutTable.size()>0)
                                {
                                        if((m_listPutTable.front()=="REAR")) bFrontTable=true;
                                        else if( (m_listPutTable.front()=="FRONT")) bFrontTable=false;
                                        else bFrontTable=true;
                                        g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                        m_listPutTable.pop_front();
                                }
                                else
                                {
                                        bFrontTable=true;
                                        g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFrontTable]);
                                }
                                break;
                        }
                        nThreadIndex++;
                        break;
                case 10:
                        if(g_Motion.IsLastPosDone(Axis_Const::SSY))
                        {
                                //m_nSubstrateRemains++;     //move to doLoadRail
                                //ShowNow
                                if (bFrontTable == true)
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[13] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[3] = true;
                                }
                                m_bSSPickerReady=true;
                                m_bLoadRailReady=false;      //Announce Lifter to reload again
                                nThreadIndex++;

                        }
                        break;
                case 11:
                        if(!m_bSSPickerReady)
                        {
                                nThreadIndex++;
                        }
                        break;



                default:
                        nThreadIndex=0;
                        break;
        }
}

//---------------------------------------------------------------------------
void __fastcall CMainThread::doTable(int &nThreadIndex,bool bFront)
{

        static C_GetTime tm1MSFront(EX_SCALE::TIME_1MS,false);
        static C_GetTime tm1MSRear(EX_SCALE::TIME_1MS,false);
        static int nCCDIndex=0;
        const bool bTableClampOn=false;
        const bool btableClampOff=true;
        C_GetTime *p_tm1MS;

        int iTablePositive,iTableNegative,iTableLockOff,iTableLockOn,iTableAlignOff,iTableVacGauge,iTableClampOff;
        int oTable,nAxisTable,oTableAlign,oTableVac,oTableLock,oTableFlip,oTableClamp;
        
        const int nTagVenderCode=1000;
        const int nTagFMCCD=2000;
        const int nTagFMCCD2=2500;
        const int nTagMapCCD=3000;
        const int nTagUnLockMapCCD=4000;
        const int nTagLaserMark=5000;
        const int nTagLaserCodeReader=6000;
        const int nTagTableFinish=7000;

        int nFounds=0;

        int nAxis;

        if(bFront)
        {
                p_tm1MS=&tm1MSFront;
                iTablePositive=DI::FT_Positive;
                iTableNegative=DI::FT_Negative;
                iTableLockOff=DI::FT_LockerOff;
                iTableLockOn=DI::FT_LockerOn;
                iTableAlignOff=DI::FT_AlignOff;
                iTableVacGauge=DI::FT_VacGauge;
                iTableClampOff=DI::FT_Align2Off;

                oTableLock=DO::FT_Locker;
                oTableAlign=DO::FT_Align;
                oTableVac=DO::FT_Vac;
                oTableFlip=DO::FT_Flip;
                oTableClamp=DO::FT_Align2;

                nAxisTable=Axis_Const::FTX;
        }
        else
        {
                p_tm1MS=&tm1MSRear;
                iTablePositive=DI::RT_Positive;
                iTableNegative=DI::RT_Negative;
                iTableLockOff=DI::RT_LockerOff;
                iTableLockOn=DI::RT_LockerOn;
                iTableAlignOff=DI::RT_AlignOff;
                iTableVacGauge=DI::RT_VacGauge;
                iTableClampOff=DI::RT_Align2Off;

                oTableLock=DO::RT_Locker;
                oTableAlign=DO::RT_Align;
                oTableVac=DO::RT_Vac;
                oTableFlip=DO::RT_Flip;
                oTableClamp=DO::RT_Align2;

                nAxisTable=Axis_Const::RTX;
        }

        switch(nThreadIndex)
        {
                case 0:
                        if(!g_DIO.GetDI(iTablePositive)) bFront? g_IniFile.m_nErrorCode=400 : g_IniFile.m_nErrorCode=401;
                        else
                        {
                                g_DIO.SetDO(oTableLock,true);
                                p_tm1MS->timeStart(2000);
                                nThreadIndex++;
                        }
                        break;
                case 1:
                        if(g_DIO.GetDI(iTableLockOn))
                        {
                                p_tm1MS->timeStart(100);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp() ) bFront? g_IniFile.m_nErrorCode=402 : g_IniFile.m_nErrorCode=403;
                        break;
                case 2:
                        if(p_tm1MS->timeUp() )
                        {
                                g_DIO.SetDO(oTableClamp,btableClampOff);
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTablePutDownPos[bFront]);
                                p_tm1MS->timeStart(10000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if(g_Motion.IsLastPosDone(nAxisTable))
                        {
                                p_tm1MS->timeStart(3000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp() )
                        {
                                g_Motion.StopMove(nAxisTable);
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTablePutDownPos[bFront]);
                                p_tm1MS->timeStart(10000);
                        }
                        break;
                case 4:
                        if(!g_DIO.GetDI(iTableAlignOff) && p_tm1MS->timeUp()) bFront? g_IniFile.m_nErrorCode=404 : g_IniFile.m_nErrorCode=405;
                        else if(!g_DIO.GetDI(iTableClampOff) && p_tm1MS->timeUp()) bFront? g_IniFile.m_nErrorCode=432 : g_IniFile.m_nErrorCode=433;
                        else if(m_bSSPickerReady  && !m_bIsSSPickeLocked )
                        {
                                m_bIsSSPickeLocked=true;
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if(!g_DIO.GetDI(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=406;
                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=407;
                        else
                        {
                                g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[bFront]);
                                nThreadIndex++;
                        }
                        break;
                case 6:
                        if(!g_DIO.GetDI(DI::SS_SSuckerVacGauge))
                        {
                                g_IniFile.m_nErrorCode=408;
                                //Vacuum fail
                                m_bSSPickerReady=false;
                                m_bIsSSPickeLocked=false;
                                nThreadIndex=0;
                        }
                        else if(g_Motion.IsLastPosDone(Axis_Const::SSY))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[13] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[2] = false;
                                    fmShowNow->m_arraybShape[3] = true;
                                }
                                g_DIO.SetDO(DO::SS_SSucker,true);
                                p_tm1MS->timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if(g_DIO.GetDI(DI::SS_SSuckerDown))
                        {
                                p_tm1MS->timeStart(300);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SS_SSucker))
                        {
                                g_DIO.SetDO(DO::SS_SSucker,true);
                                p_tm1MS->timeStart(5000);
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=409;
                        break;
                case 8:
                        if(p_tm1MS->timeUp() && g_DIO.GetDI(DI::SS_SSuckerDown))
                        {
                                g_DIO.SetDO(DO::SS_SVacOn,false);
                                g_DIO.SetDO(DO::SS_SVacOff,true);
                                g_DIO.SetDO(DO::SS_SDeVac,true);


                                p_tm1MS->timeStart(300);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SS_SSucker))
                        {
                                g_DIO.SetDO(DO::SS_SSucker,true);
                                p_tm1MS->timeStart(5000);
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=409;
                        break;
                case 9:
                        if(p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(DO::SS_SSucker,false);
                                //m_nStripCount++;
                                bFront ? m_listPickTable.push_back("FRONT"):m_listPickTable.push_back("REAR");
                                bFront ? m_listPutTable.push_back("FRONT"):m_listPutTable.push_back("REAR");

                                p_tm1MS->timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 10:
                        if(g_DIO.GetDI(DI::SS_SSuckerUp))
                        {
                                g_DIO.SetDO(DO::SS_SDeVac,false);
                                m_bSSPickerReady=false;
                                m_bIsSSPickeLocked=false;
                                p_tm1MS->timeStart(300);

                                nThreadIndex++;
                        }
                        else if(g_DIO.GetDO(DO::SS_SSucker))
                        {
                                g_DIO.SetDO(DO::SS_SSucker,false);
                                p_tm1MS->timeStart(5000);
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=406;
                        break;
                case 11:
                        if(p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(oTableAlign,true);
                                g_DIO.SetDO(oTableClamp,bTableClampOn);
                                p_tm1MS->timeStart(500);
                                nThreadIndex++;
                        }
                        break;
                case 12:
                        if(p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(oTableAlign,false);
                                g_DIO.SetDO(oTableVac,true);

                                p_tm1MS->timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 13:
                        if(g_DIO.GetDI(iTableVacGauge) && g_DIO.GetDI(iTableAlignOff))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[13] = false;
                                    fmShowNow->m_arraybShape[14] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[3] = false;
                                    fmShowNow->m_arraybShape[4] = true;
                                }
                                p_tm1MS->timeStart(500);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp())
                        {
                                if(!g_DIO.GetDI(iTableVacGauge)) bFront ? g_IniFile.m_nErrorCode=410 : g_IniFile.m_nErrorCode=411;
                                if(!g_DIO.GetDI(iTableAlignOff)) bFront ? g_IniFile.m_nErrorCode=404 : g_IniFile.m_nErrorCode=405 ;
                        }
                        break;
                case 14:
                        if(p_tm1MS->timeUp() && !m_bIsMapCCDLocked)
                        {
                                m_bIsMapCCDLocked=true;
                                nCCDIndex=0;

                                //Initial Product Info
                                m_tmpProductInfo[bFront].m_nIndex=m_nStripCount;//-1;
                                m_tmpProductInfo[bFront].m_nMapNG=0;
                                m_tmpProductInfo[bFront].m_nMapOK=0;
                                m_tmpProductInfo[bFront].m_dOffsetAngle=0.0;
                                m_tmpProductInfo[bFront].m_nOffsetX=0.0;
                                m_tmpProductInfo[bFront].m_nOffsetY=0.0;
                                m_tmpProductInfo[bFront].m_nOffset2X=0.0;
                                m_tmpProductInfo[bFront].m_nOffset2Y=0.0;
                                m_tmpProductInfo[bFront].m_strVenderID="N/A";
                                m_tmpProductInfo[bFront].m_strLotID="N/A";
                                m_tmpProductInfo[bFront].m_strBoatID="N/A";
                                m_tmpProductInfo[bFront].m_strCoverID="N/A";
                                m_tmpProductInfo[bFront].m_bIsSBT2DOK[0]=false;
                                m_tmpProductInfo[bFront].m_bIsSBT2DOK[1]=false;
                                nThreadIndex++;
                        }
                        break;
                //___________________________________________________________\\
                case 15:
                case nTagVenderCode:nThreadIndex=15;
                        g_IniFile.m_bReadVenderID=false;
                        if(g_IniFile.m_bReadVenderID)
                        {
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTableVenderCodePosX[bFront]);
                                g_Motion.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableVenderCodePosY[bFront]);
                                nThreadIndex++;
                        }else nThreadIndex=nTagFMCCD;
                        break;
                case 16:
                        if(g_Motion.IsLastPosDone(nAxisTable) && g_Motion.IsLastPosDone(Axis_Const::CCD))
                        {
                                p_tm1MS->timeStart(100);
                                nThreadIndex++;
                        }
                        break;
                case 17:
                        if(p_tm1MS->timeUp())
                        {
                                //Send Reader Command
                                m_listVenderCodeReaderRX.clear();
                                m_listTX.push_back("VENDER_TRIG");
                                p_tm1MS->timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 18:
                        if(m_listVenderCodeReaderRX.size()>0)
                        {
                                if(m_listVenderCodeReaderRX.back()=="VENDER_NOREAD") g_IniFile.m_nErrorCode=412;
                                else if(m_listVenderCodeReaderRX.back()=="VENDER_LENGHT_ERROR") g_IniFile.m_nErrorCode=414;
                                else
                                {
                                        m_listLog.push_back("Vender ID OK");
                                        m_tmpProductInfo[bFront].m_strVenderID=m_listVenderCodeReaderRX.back(); 
                                        //Use Vender Map
                                        //Process something
                                        nThreadIndex++;
                                }

                                m_listVenderCodeReaderRX.clear();

                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=413;
                        break;
                //___________________________________________________________\\
                //使用電眼取得第一點Offset value
                case 19:
                case nTagFMCCD:nThreadIndex=19;
                        if(g_IniFile.m_bUseFMCCD)
                        {
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTableMarkPosX[bFront]);
                                g_Motion.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPosY[bFront]);
                                nThreadIndex++;
                        }
                        else nThreadIndex=nTagMapCCD;
                        break;
                case 20:
                        if(g_Motion.IsLastPosDone(nAxisTable) && g_Motion.IsLastPosDone(Axis_Const::CCD))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[14] = false;
                                    fmShowNow->m_arraybShape[15] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[4] = false;
                                    fmShowNow->m_arraybShape[5] = true;
                                }
                                p_tm1MS->timeStart(500);
                                nThreadIndex++;
                        }
                        break;
                case 21:
                        if(p_tm1MS->timeUp())
                        {
                                g_Grabber.Grab(1);
                                p_tm1MS->timeStart(2000);
                                nThreadIndex++;
                        }
                        break;
                case 22:
                        if(g_Grabber.m_bValidImage[1])
                        {
                                //LED OFF
                                //Process Image  get offset x,y

                                theVision.m_markMatch[2].SetMaxPositions(1);

                                nFounds=theVision.FindPatMatch(theVision.m_roiMark[2],theVision.m_markMatch[2]);

                                if(nFounds<1)
                                {
                                        nThreadIndex=nTagFMCCD;
                                        g_IniFile.m_nErrorCode=425;
                                }
                                else
                                {
                                        double dX=(theVision.GetMatchPosX(theVision.m_markMatch[2],2)-320.0)*g_IniFile.m_dFMCCDResolution[0] ;
                                        double dY=(theVision.GetMatchPosY(theVision.m_markMatch[2],2)-240.0)*g_IniFile.m_dFMCCDResolution[1];
                                        m_listLog.push_back("定位 Offset X="+FormatFloat("0.00 ",dX)+"Y="+FormatFloat("0.00",dY)+"mm");

                                        m_tmpProductInfo[bFront].m_nOffsetX=dX;
                                        m_tmpProductInfo[bFront].m_nOffsetY=dY;
                                        nThreadIndex++;
                                }
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=415;
                        break;
                //___________________________________________________________\\
                //使用電眼取得第二點Offset value
                case 23:
                case nTagFMCCD2:nThreadIndex=23;
                        if(g_IniFile.m_bUseFMCCD2)
                        {
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTableMarkPos2X[bFront]);
                                g_Motion.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPos2Y[bFront]);
                                nThreadIndex++;
                        }
                        else nThreadIndex=nTagMapCCD;
                        break;
                case 24:
                        if(g_Motion.IsLastPosDone(nAxisTable) && g_Motion.IsLastPosDone(Axis_Const::CCD))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[14] = false;
                                    fmShowNow->m_arraybShape[15] = false;
                                    fmShowNow->m_arraybShape[16] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[4] = false;
                                    fmShowNow->m_arraybShape[5] = false;
                                    fmShowNow->m_arraybShape[6] = true;
                                }
                                p_tm1MS->timeStart(500);
                                nThreadIndex++;
                        }
                        break;
                case 25:
                        if(p_tm1MS->timeUp())
                        {
                                g_Grabber.Grab(1);
                                p_tm1MS->timeStart(2000);
                                nThreadIndex++;
                        }
                        break;
                case 26:
                        if(g_Grabber.m_bValidImage[1])
                        {
                                //LED OFF
                                //Process Image  get offset x,y

                                theVision.m_markMatch[1].SetMaxPositions(1);

                                nFounds=theVision.FindPatMatch(theVision.m_roiMark[1],theVision.m_markMatch[1]);

                                if(nFounds<1)
                                {
                                        nThreadIndex=nTagFMCCD;
                                        g_IniFile.m_nErrorCode=425;
                                }
                                else
                                {
                                        double d2X=(theVision.GetMatchPosX(theVision.m_markMatch[1],1)-320.0)*g_IniFile.m_dFMCCDResolution[0];
                                        double d2Y=(theVision.GetMatchPosY(theVision.m_markMatch[1],1)-240.0)*g_IniFile.m_dFMCCDResolution[1];
                                        m_listLog.push_back("定位 Offset 2X="+FormatFloat("0.00 ",d2X)+"2Y="+FormatFloat("0.00",d2Y)+"mm");

                                        m_tmpProductInfo[bFront].m_nOffset2X=d2X;
                                        m_tmpProductInfo[bFront].m_nOffset2Y=d2Y;

                                        //-Count Rotation angle
                                        double dX = m_tmpProductInfo[bFront].m_nOffsetX;
                                        double dY = m_tmpProductInfo[bFront].m_nOffsetY;
                                        double dAx = g_IniFile.m_dTableMarkPosX[bFront];
                                        double dAy = g_IniFile.m_dTableMarkPosY[bFront];
                                        double dBx = g_IniFile.m_dTableMarkPos2X[bFront];
                                        double dBy = g_IniFile.m_dTableMarkPos2Y[bFront];
                                        double dAngle0; ((dAx-dBx)==0) ? dAngle0 = 0 : dAngle0 = atan((dAy-dBy)/(dAx-dBx))*180/3.141592653589793;
                                        double dAngle1; ((dX+dAx-d2X-dBx)==0) ? dAngle1 = 0 : dAngle1 = atan((dY+dAy-d2Y-dBy)/(dX+dAx-d2X-dBx))*180/3.141592653589793;

                                        if (fabs(dAngle1-dAngle0)<180.0)
                                        {
                                            m_tmpProductInfo[bFront].m_dOffsetAngle = dAngle1-dAngle0;
                                            m_listLog.push_back("定位 Offset Angle = "+FormatFloat("0.0000 ",dAngle1-dAngle0)+" degree");
                                        }
                                        else
                                        {
                                            m_tmpProductInfo[bFront].m_dOffsetAngle = 0.0;
                                            m_listLog.push_back("定位 Offset Angle = "+FormatFloat("0.0000 ",dAngle1-dAngle0)+" degree");
                                            m_listLog.push_back("Error!!!! Offset Angle over +-180 degree. Please call CLARE to fix this.");
                                        }

                                        nThreadIndex++;
                                }
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=415;
                        break;
                //___________________________________________________________\\
                case 27:
                case nTagMapCCD:nThreadIndex=27;
                        g_IniFile.m_bUseMapCCD=false;   //Option
                        if(g_IniFile.m_bUseMapCCD)
                        {
                                g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTableMapCCDPosX[bFront]-nCCDIndex*g_IniFile.m_dTableMapCCDPitch);
                                g_Motion.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMapCCDPosY[bFront]);
                                nThreadIndex++;
                        }
                        else nThreadIndex=nTagUnLockMapCCD;//nTagLaserMark;
                        break;
                case 28:
                       if(g_Motion.IsLastPosDone(nAxisTable)&& g_Motion.IsLastPosDone(Axis_Const::CCD))
                        {
                                //LED on
                                //LED Down
                                p_tm1MS->timeStart(100);
                                nThreadIndex++;
                        }
                        break;
                case 29:
                        if(p_tm1MS->timeUp())
                        {
                                g_Grabber.Grab(0);
                                nThreadIndex++;
                        }
                        break;
                case 30:
                        if(g_Grabber.m_bValidImage[0])
                        {
                                theVision.MergeImage(nCCDIndex,g_IniFile.m_nImageWidth,g_IniFile.m_dImageAngle);
                                nCCDIndex++;
                                if(nCCDIndex>=4) nThreadIndex++;
                                else nThreadIndex=nTagMapCCD;
                        }
                        break;
                case 31:
                        nCCDIndex=0;
                        //LED Off
                        //LED Up
                        theVision.m_markMatch[1].SetMaxPositions(1);

                       nFounds=theVision.FindPatMatch(theVision.m_roiMark[1],theVision.m_markMatch[1]);

                        if(nFounds<1)
                        {
                                nThreadIndex=nTagMapCCD;
                                g_IniFile.m_nErrorCode=426;
                        }
                        else nThreadIndex++;
                        break;
                case 32:
                        m_listVisionRX.clear();
                        if(bFront) m_listTX.push_back("PROCESS_MAP_FRONT");   //DoVisionProcess      //ExportMapFile
                        else m_listTX.push_back("PROCESS_MAP_REAR");
                        p_tm1MS->timeStart(3000);
                        nThreadIndex++;
                        break;
                case 33:
                        if(m_listVisionRX.size()>0)
                        {
                                if(m_listVisionRX.back()=="PROCESS_MAP_DONE")
                                {
                                        //Get NG Mark
                                        m_tmpProductInfo[bFront].m_nMapNG=m_nNGCount;
                                        m_tmpProductInfo[bFront].m_nMapOK=m_nOKCount;
                                        m_nOKSummary+=m_nOKCount;
                                        m_nNGSummary+=m_nNGCount;
                                        nThreadIndex++;
                                        m_listVisionRX.clear();

                                        if(!g_IniFile.m_bUseLaserMark)
                                        {
                                                AnsiString strLog;
                                                strLog="["+FormatFloat("0",m_tmpProductInfo[bFront].m_nIndex)+"]-->";
                                                strLog+="OK:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapOK);
                                                strLog+=" NG:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapNG);

                                                m_listVisionLog.push_back(strLog);
                                        }
                                }
                        }
                        else if(p_tm1MS->timeUp())
                        {
                                nThreadIndex=nTagMapCCD;
                                g_IniFile.m_nErrorCode=427;
                        }
                        break;
                //___________________________________________________________\\
                case 34:
                case nTagUnLockMapCCD:nThreadIndex=34;
                        m_bIsMapCCDLocked=false;
                        nThreadIndex++;
                        break;
                //___________________________________________________________\\
                case 35:
                case nTagLaserMark:nThreadIndex=35;
                        if(g_IniFile.m_bUseLaserMark)
                        {
                                if(!m_bLaserLocked)
                                {
                                        m_bLaserLocked=true;
                                        g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTableLaserPos[bFront]);
                                        if (bFront) g_DIO.SetDO(DO::Laser_BlowAir_Front, true);
                                        else g_DIO.SetDO(DO::Laser_BlowAir_Rear, true);
                                        nThreadIndex++;
                                }
                        }
                        else nThreadIndex=nTagTableFinish;
                        break;
                case 36:
                        if(g_Motion.IsLastPosDone(nAxisTable))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[14] = false;
                                    fmShowNow->m_arraybShape[15] = false;
                                    fmShowNow->m_arraybShape[16] = false;
                                    fmShowNow->m_arraybShape[17] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[4] = false;
                                    fmShowNow->m_arraybShape[5] = false;
                                    fmShowNow->m_arraybShape[6] = false;
                                    fmShowNow->m_arraybShape[7] = true;
                                }
                                //Select Laser File
                                m_listLaserRX.clear();
                                if(bFront) m_listTX.push_back("OPEN_LASER_FRONT_UP");
                                else m_listTX.push_back("OPEN_LASER_REAR_UP");

                                p_tm1MS->timeStart(10000);
                                nThreadIndex++;
                        }
                         break;
                case 37:
                        if(m_listLaserRX.size()>0)
                        {
                                if(m_listLaserRX.back()=="OPEN_LASER_OK") nThreadIndex++;
                                else
                                {
                                        g_IniFile.m_nErrorCode=417;
                                        nThreadIndex--;
                                }

                                m_listLaserRX.clear();

                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=416;
                        break;
                case 38:
                        g_SMSXML.QueryID();
                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 39:
                        if(g_SMSXML.m_strSerialID!="FAIL" && g_SMSXML.m_strSerialID!="NOT_VALID")
                        {
                                m_listLog.push_back("正面取得雷刻ID "+g_SMSXML.m_strSerialID);
                                m_tmpProductInfo[bFront].m_strLotID=g_SMSXML.m_strSerialID;

                                //Add to Marker Log
                                AnsiString strLog;
                                strLog="User ID:"+g_IniFile.m_strSMSUserID+" ["+m_tmpProductInfo[bFront].m_strLotID+"]-->"+g_SMSXML.m_strSerialID;
                                m_listMarkerLog.push_back(strLog);

                                nThreadIndex++;
                        }
                        else if(g_SMSXML.m_strSerialID=="FAIL")
                        {
                                g_IniFile.m_nErrorCode=430;
                                nThreadIndex--;
                        }
                        else if(p_tm1MS->timeUp())
                        {
                                g_IniFile.m_nErrorCode=431;
                                nThreadIndex--;
                        }
                        break;
                case 40:
                        m_listLaserRX.clear();
                        if(bFront) m_listTX.push_back("SET_LASER_OFFSET_FRONT_UP");
                        else m_listTX.push_back("SET_LASER_OFFSET_REAR_UP");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 41:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="SET_LASER_OFFSET_OK") nThreadIndex++;
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=418;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=420;
                        break;
                case 42:
                        m_listLaserRX.clear();
                        m_listTX.push_back("FIRE_LASER");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 43:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="FIRE_LASER_OK")
                                 {
                                        AnsiString strLog;
                                        strLog="["+m_tmpProductInfo[bFront].m_strLotID+"]-->";
                                        strLog+="OK:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapOK);
                                        strLog+=" NG:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapNG);

                                        m_listVisionLog.push_back(strLog);

                                         //m_bLaserLocked=false;
                                         m_nLaserCount++;
                                        nThreadIndex++;
                                 }
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=419;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=421;
                        break;
                case 44:
                        m_listLaserRX.clear();
                        if(bFront) m_listTX.push_back("RESET_LASER_OFFSET_FRONT_UP");
                        else m_listTX.push_back("RESET_LASER_OFFSET_REAR_UP");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 45:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="RESET_LASER_OFFSET_OK")
                                 {
                                        if(!g_IniFile.m_bDoubleSide)
                                        {
                                                m_bLaserLocked=false;
                                                nThreadIndex=nTagTableFinish;
                                        }
                                        else nThreadIndex++;
                                 }
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=428;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        else if(p_tm1MS->timeUp())  g_IniFile.m_nErrorCode=429;
                        break;
               case 46:
                        g_DIO.SetDO(oTableLock, false);
                        p_tm1MS->timeStart(3000);
                        nThreadIndex++;
                        break;
               case 47:
                        if(g_DIO.GetDI(iTableLockOff))
                        {
                                p_tm1MS->timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=436 : g_IniFile.m_nErrorCode=437 ;
                        break;
               case 48:
                        //Flip Table
                        if (p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(oTableFlip,true);
                                p_tm1MS->timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
               case 49:
                        if(g_DIO.GetDI(iTableNegative))
                        {
                                p_tm1MS->timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=434 : g_IniFile.m_nErrorCode=435 ;
                        break;
               case 50:
                        if(p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(oTableLock, true);
                                p_tm1MS->timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
               case 51:
                        if(g_DIO.GetDI(iTableLockOn))
                        {
                                p_tm1MS->timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=402 : g_IniFile.m_nErrorCode=403 ;
                        break;
               case 52:
                        if(p_tm1MS->timeUp())
                        {
                                //Select Laser File
                                m_listLaserRX.clear();
                                if(bFront) m_listTX.push_back("OPEN_LASER_FRONT_DOWN");
                                else m_listTX.push_back("OPEN_LASER_REAR_DOWN");

                                p_tm1MS->timeStart(10000);
                                nThreadIndex++;
                        }
                         break;
                case 53:
                        if(m_listLaserRX.size()>0)
                        {
                                if(m_listLaserRX.back()=="OPEN_LASER_OK") nThreadIndex++;
                                else
                                {
                                        g_IniFile.m_nErrorCode=417;
                                        nThreadIndex--;
                                }

                                m_listLaserRX.clear();

                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=416;
                        break;
                case 54:
                        //g_SMSXML.QueryID();          翻面不在取得lot number
                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 55:
                        if(g_SMSXML.m_strSerialID!="FAIL" && g_SMSXML.m_strSerialID!="NOT_VALID")
                        {
                                m_listLog.push_back("反面沿用雷刻ID "+m_tmpProductInfo[bFront].m_strLotID);
                                //m_listLog.push_back("取得雷刻ID "+g_SMSXML.m_strSerialID);
                                //m_tmpProductInfo[bFront].m_strLotID=g_SMSXML.m_strSerialID;

                                nThreadIndex++;
                        }
                        else if(g_SMSXML.m_strSerialID=="FAIL")
                        {
                                g_IniFile.m_nErrorCode=430;
                                nThreadIndex--;
                        }
                        else if(p_tm1MS->timeUp())
                        {
                                g_IniFile.m_nErrorCode=431;
                                nThreadIndex--;
                        }
                        break;
                case 56:
                        m_listLaserRX.clear();
                        if(bFront) m_listTX.push_back("SET_LASER_OFFSET_FRONT_DOWN");
                        else m_listTX.push_back("SET_LASER_OFFSET_REAR_DOWN");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 57:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="SET_LASER_OFFSET_OK") nThreadIndex++;
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=418;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=420;
                        break;
                case 58:
                        m_listLaserRX.clear();
                        m_listTX.push_back("FIRE_LASER");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 59:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="FIRE_LASER_OK")
                                 {
                                        AnsiString strLog;
                                        strLog="["+m_tmpProductInfo[bFront].m_strLotID+"]-->";
                                        strLog+="OK:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapOK);
                                        strLog+=" NG:"+FormatFloat("0",m_tmpProductInfo[bFront].m_nMapNG);

                                        m_listVisionLog.push_back(strLog);

                                         //m_bLaserLocked=false;
                                         m_nLaserCount++;
                                        nThreadIndex++;
                                 }
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=419;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        else if(p_tm1MS->timeUp()) g_IniFile.m_nErrorCode=421;
                        break;
                case 60:
                        m_listLaserRX.clear();
                        if(bFront) m_listTX.push_back("RESET_LASER_OFFSET_FRONT_DOWN");
                        else m_listTX.push_back("RESET_LASER_OFFSET_REAR_DOWN");

                        p_tm1MS->timeStart(10000);
                        nThreadIndex++;
                        break;
                case 61:
                        if(m_listLaserRX.size()>0)
                        {
                                 if(m_listLaserRX.back()=="RESET_LASER_OFFSET_OK")
                                 {
                                        nThreadIndex++;
                                 }
                                 else
                                 {
                                        g_IniFile.m_nErrorCode=428;
                                        nThreadIndex--;
                                 }

                                 m_listLaserRX.clear();
                        }
                        else if(p_tm1MS->timeUp())  g_IniFile.m_nErrorCode=429;
                        break;
                case 62:
                        g_DIO.SetDO(oTableLock, false);
                        p_tm1MS->timeStart(3000);
                        nThreadIndex++;
                        break;
               case 63:
                        if(g_DIO.GetDI(iTableLockOff))
                        {
                                p_tm1MS->timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=436 : g_IniFile.m_nErrorCode=437 ;
                        break;
               case 64:
                        //Flip Table
                        g_DIO.SetDO(oTableFlip,false);
                        p_tm1MS->timeStart(3000);
                        nThreadIndex++;
                        break;
               case 65:
                        if(g_DIO.GetDI(iTablePositive))
                        {
                                m_bLaserLocked=false;
                                p_tm1MS->timeStart(1000);
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=400 : g_IniFile.m_nErrorCode=401 ;
                        break;
               case 66:
                        if(p_tm1MS->timeUp())
                        {
                                g_DIO.SetDO(oTableLock, true);
                                p_tm1MS->timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
               case 67:
                        if(g_DIO.GetDI(iTableLockOn))
                        {
                                nThreadIndex++;
                        }
                        else if(p_tm1MS->timeUp()) bFront ? g_IniFile.m_nErrorCode=402 : g_IniFile.m_nErrorCode=403 ;
                        break;
                //___________________________________________________________\\
                case 68:
                case nTagTableFinish:nThreadIndex=68;
                        g_Motion.AbsMove(nAxisTable,g_IniFile.m_dTablePickUpPos[bFront]);
                        if (bFront) g_DIO.SetDO(DO::Laser_BlowAir_Front, false);
                        else g_DIO.SetDO(DO::Laser_BlowAir_Rear, false);
                        nThreadIndex++;
                        break;

                case 69:
                        if(g_Motion.IsMotionDone(nAxisTable))
                        {
                                //ShowNow
                                if (bFront)
                                {
                                    fmShowNow->m_arraybShape[14] = false;
                                    fmShowNow->m_arraybShape[15] = false;
                                    fmShowNow->m_arraybShape[16] = false;
                                    fmShowNow->m_arraybShape[17] = false;
                                    fmShowNow->m_arraybShape[18] = true;
                                }
                                else
                                {
                                    fmShowNow->m_arraybShape[4] = false;
                                    fmShowNow->m_arraybShape[5] = false;
                                    fmShowNow->m_arraybShape[6] = false;
                                    fmShowNow->m_arraybShape[7] = false;
                                    fmShowNow->m_arraybShape[8] = true;
                                }
                                p_tm1MS->timeStart(500);
                                nThreadIndex++;
                        }
                        break;
                case 70:
                        if(p_tm1MS->timeUp())
                        {
                                m_bTableReady[bFront]=true;
                                nThreadIndex++;
                        }
                        break;
                case 71:
                        if(!m_bTableReady[bFront])
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;

        }

}
//---------------------------------------------------------------------------
void __fastcall CMainThread::doSCPicker(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        const int nTagPickSubstrate=1000;
        const int nTagWaitReadyOff=2000;
        const int nTagRePickSubstrate=3000;
        const int nTagJudgeSBTCode=4000;
        static bool bIsSBT2DOk=false;

        const bool bTableClampOff=true;


        static bool bFrontTable=false;
        int nAxisTable[]={Axis_Const::RTX,Axis_Const::FTX};

        switch(nThreadIndex)
        {
                case 0:
                        if (g_DIO.GetDI(DI::SC_SSuckerUp))
                        {
                                if(m_listPickTable.size()>0)
                                {
                                        if((m_listPickTable.front()=="FRONT")) bFrontTable=true;
                                        else if( (m_listPickTable.front()=="REAR")) bFrontTable=false;

                                        g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dSCPickerPickSSPosY[bFrontTable]);
                                        nThreadIndex++;
                                }
                        }
                        break;
                case 1:
                        if((m_bTableReady[0] || m_bTableReady[1]) && !m_bSCPickerSSReady && g_Motion.IsLastPosDone(Axis_Const::SCY))
                        {
                                bIsSBT2DOk=false;
                                nThreadIndex++;
                        }
                        break;
                case 2:
                case nTagPickSubstrate:nThreadIndex=2;
                        if(!g_DIO.GetDI(DI::SC_SSuckerUp)) g_IniFile.m_nErrorCode=500;
                        else
                        {
                                if(m_listPickTable.size()>0)
                                {
                                        if(m_bTableReady[1] && (m_listPickTable.front()=="FRONT")) bFrontTable=true;
                                        else if(m_bTableReady[0] && (m_listPickTable.front()=="REAR")) bFrontTable=false;

                                        m_listPickTable.pop_front();

                                        g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dSCPickerPickSSPosY[bFrontTable]);
                                        g_Motion.AbsMove(nAxisTable[bFrontTable],g_IniFile.m_dTablePickUpPos[bFrontTable]);

                                        nThreadIndex++;
                                }

                        }
                        break;
                case 3:
                        if(g_Motion.IsLastPosDone(Axis_Const::SCY) && g_Motion.IsLastPosDone(nAxisTable[bFrontTable]))
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 4:
                case nTagRePickSubstrate:nThreadIndex=4;
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SC_SSucker,true);
                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                        break;
                case 5:
                        if(g_DIO.GetDI(DI::SC_SSuckerDown))
                        {
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SC_SSucker))
                        {
                                g_DIO.SetDO(DO::SC_SSucker,true);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=507;
                        break;
                case 6:
                        if(tm1MS.timeUp())
                        {
                                bFrontTable ? g_DIO.SetDO(DO::FT_Align2,bTableClampOff): g_DIO.SetDO(DO::RT_Align2,bTableClampOff);
                                g_DIO.SetDO(DO::SC_SSuckerVacOn,true);
                                g_DIO.SetDO(DO::SC_SSuckerVacOff,false);
                                g_DIO.SetDO(DO::SC_SSuckerDeVac,false);
                                if(bFrontTable) g_DIO.SetDO(DO::FT_Vac,false);
                                else g_DIO.SetDO(DO::RT_Vac,false);
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 7:
                        if(g_DIO.GetDI(DI::SC_SSuckerVacGauge))
                        {
                                tm1MS.timeStart(g_IniFile.m_nSubstrateVacTime);
                                nThreadIndex++;
                        }
                        else if(!g_DIO.GetDO(DO::SC_SSucker))
                        {
                                g_DIO.SetDO(DO::SC_SSucker,true);
                                tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp()) g_IniFile.m_nErrorCode=508;
                        break;
                case 8:
                        if(tm1MS.timeUp())
                        {
                                g_DIO.SetDO(DO::SC_SSucker,false);

                                tm1MS.timeStart(3000);
                                nThreadIndex++;
                        }
                       break;
                case 9:
                        if(g_DIO.GetDI(DI::SC_SSuckerUp) )
                        {
                                if(g_DIO.GetDI(DI::SC_SSuckerVacGauge))
                                {
                                        //ShowNow
                                        if (bFrontTable)
                                        {
                                            fmShowNow->m_arraybShape[10] = false;
                                            fmShowNow->m_arraybShape[18] = false;
                                            fmShowNow->m_arraybShape[22] = false;
                                            fmShowNow->m_arraybShape[23] = false;
                                            fmShowNow->m_arraybShape[19] = true;
                                        }
                                        else
                                        {
                                            fmShowNow->m_arraybShape[10] = false;
                                            fmShowNow->m_arraybShape[22] = false;
                                            fmShowNow->m_arraybShape[23] = false;
                                            fmShowNow->m_arraybShape[8] = false;
                                            fmShowNow->m_arraybShape[9] = true;
                                        }
                                        m_bTableReady[bFrontTable]=false;
                                        m_listProductInfo.push_back(m_tmpProductInfo[bFrontTable]);

                                        nThreadIndex++;
                                }
                                else
                                {
                                        nThreadIndex=nTagRePickSubstrate;
                                        g_IniFile.m_nErrorCode=508;
                                }

                        }
                        else if(g_DIO.GetDO(DO::SC_SSucker))
                        {
                                g_DIO.SetDO(DO::SC_SSucker,false);
                                 tm1MS.timeStart(3000);
                        }
                        else if(tm1MS.timeUp() && !g_DIO.GetDI(DI::SC_CSuckerUp)) g_IniFile.m_nErrorCode=511;
                        break;
                case 10:
                        if(g_IniFile.m_bUseLaserCodeReader)            //check Laser print quality
                        {
                                g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dLaserCodeReaderPos[0]);
                                nThreadIndex++;
                        }
                        else nThreadIndex=nTagWaitReadyOff;

                        break;
                case 11:
                        if(g_Motion.IsLastPosDone(Axis_Const::SCY))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[19] = false;
                                fmShowNow->m_arraybShape[9] = false;
                                fmShowNow->m_arraybShape[23] = true;
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 12:
                        if(tm1MS.timeUp())
                        {
                                m_listLaserCodeReaderRX.clear();
                                m_listTX.push_back("UP_LASER_READER_TRIG");
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 13:
                        if(m_listLaserCodeReaderRX.size()>0)
                        {
                                m_listProductInfo.back().m_bIsSBT2DOK[0]=false;
                                if(m_listLaserCodeReaderRX.back()=="LASER_READER_NOREAD") g_IniFile.m_nErrorCode=422;
                                else if(m_listLaserCodeReaderRX.back()=="LASER_READER_LENGHT_ERROR") g_IniFile.m_nErrorCode=424;
                                else
                                {
                                        m_listLog.push_back("[UP]Laser Reader ID OK");
                                        m_listProductInfo.back().m_bIsSBT2DOK[0]=true;
                                }

                                m_listLaserCodeReaderRX.clear();

                                nThreadIndex++;

                        }
                        else if(tm1MS.timeUp())
                        {
                                g_IniFile.m_nErrorCode=423;
                                nThreadIndex++;
                        }
                        break;
                 case 14:
                        if(g_IniFile.m_bDoubleSide)            //Use Double Side Laser Mark
                        {
                                g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dLaserCodeReaderPos[1]);
                                nThreadIndex++;
                        }
                        else nThreadIndex=nTagJudgeSBTCode;
                        break;
                case 15:
                        if(g_Motion.IsLastPosDone(Axis_Const::SCY))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[23] = false;
                                fmShowNow->m_arraybShape[19] = false;
                                fmShowNow->m_arraybShape[9] = false;
                                fmShowNow->m_arraybShape[24] = true;
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 16:
                        if(tm1MS.timeUp())
                        {
                                m_listCoverCodeReaderRX.clear();
                                m_listTX.push_back("DOWN_LASER_READER_TRIG");
                                tm1MS.timeStart(5000);
                                nThreadIndex++;
                        }
                        break;
                case 17:
                        if(m_listCoverCodeReaderRX.size()>0)
                        {
                                m_listProductInfo.back().m_bIsSBT2DOK[1]=false;
                                if(m_listCoverCodeReaderRX.back()=="COVER_READER_NOREAD") g_IniFile.m_nErrorCode=422;
                                else if(m_listCoverCodeReaderRX.back()=="COVER_READER_LENGHT_ERROR") g_IniFile.m_nErrorCode=424;
                                else if (m_listCoverCodeReaderRX.back()=="2DCODE_DIFFERENCE_ERROR") g_IniFile.m_nErrorCode=439;
                                else
                                {
                                        m_listLog.push_back("[DOWN]Laser Reader ID OK");
                                        m_listProductInfo.back().m_bIsSBT2DOK[1]=true;
                                }

                                m_listCoverCodeReaderRX.clear();

                                nThreadIndex++;

                        }
                        else if(tm1MS.timeUp())
                        {
                                g_IniFile.m_nErrorCode=423;
                                nThreadIndex++;
                        }
                        break;
                case 18:
                case nTagJudgeSBTCode:nThreadIndex=18;
                       if(g_IniFile.m_bDoubleSide && m_listProductInfo.back().m_bIsSBT2DOK[0] && m_listProductInfo.back().m_bIsSBT2DOK[1]) nThreadIndex=nTagWaitReadyOff;
                       else if(!g_IniFile.m_bDoubleSide && m_listProductInfo.back().m_bIsSBT2DOK[0]) nThreadIndex=nTagWaitReadyOff;
                       else nThreadIndex++;
                       break;
                case 19:
                         //NG BOX
                        if(g_DIO.GetDI(DI::SC_SSuckerUp))
                        {
                                g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dSBTNGBoxPos);
                                nThreadIndex++;
                        }
                        else g_IniFile.m_nErrorCode=511;
                        break;
                case 20:
                        if(g_Motion.IsLastPosDone(Axis_Const::SCY))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[9] = false;
                                fmShowNow->m_arraybShape[19] = false;
                                fmShowNow->m_arraybShape[23] = false;
                                fmShowNow->m_arraybShape[24] = false;
                                fmShowNow->m_arraybShape[22] = true;
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
                case 21:
                        if(tm1MS.timeUp())
                        {
                                m_nSubstrateInMachine--;
                                g_DIO.SetDO(DO::SC_SSuckerVacOn,false);
                                g_DIO.SetDO(DO::SC_SSuckerVacOff,true);
                                g_DIO.SetDO(DO::SC_SSuckerDeVac,true);
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        break;
                 case 22:
                        if(tm1MS.timeUp())
                        {
                                nThreadIndex=0;
                        }
                        break;
                case 23:
                case nTagWaitReadyOff:nThreadIndex=23;
                        g_Motion.AbsMove(Axis_Const::SCY,g_IniFile.m_dSCPickerPutSSPos);
                        nThreadIndex++;
                        break;
                case 24:
                        if(g_Motion.IsLastPosDone(Axis_Const::SCY))
                        {
                                //ShowNow
                                fmShowNow->m_arraybShape[9] = false;
                                fmShowNow->m_arraybShape[19] = false;
                                fmShowNow->m_arraybShape[23] = false;
                                fmShowNow->m_arraybShape[24] = false;
                                fmShowNow->m_arraybShape[22] = false;
                                fmShowNow->m_arraybShape[10] = true;
                                tm1MS.timeStart(300);
                                nThreadIndex++;
                        }
                        break;
               case 25:
                        if(tm1MS.timeUp())
                        {
                                m_bSCPickerSSReady=true;
                                nThreadIndex++;
                        }
                        break;
                case 26: 
                        if(!m_bSCPickerSSReady)
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        break;
        }

}
//---------------------------------------------------------------------------
bool __fastcall CMainThread::doPreAuto(int &nThreadIndex)
{
        static C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        static C_GetTime tm2MS(EX_SCALE::TIME_1MS,false);

        switch(nThreadIndex)
        {
                case 0:
                        if(!g_DIO.GetDI(DI::SS_SSuckerUp)) g_IniFile.m_nErrorCode=28;
                        else if(!g_DIO.GetDI(DI::SS_SpaSuckerUp)) g_IniFile.m_nErrorCode=29;
                        else if(!g_DIO.GetDI(DI::SC_SSuckerUp)) g_IniFile.m_nErrorCode=19;
                        else
                        {
                                if (g_IniFile.m_bUseLaserMark)
                                {
                                        g_DIO.SetDO(DO::Blower, true);
                                        m_bStopBlower = false;
                                        tm2MS.timeStart(5000);
                                        nThreadIndex++;
                                }
                                else nThreadIndex++;
                        }
                        break;
                case 1:
                        g_Motion.AbsMove(Axis_Const::RTX,g_Motion.m_dLastTargetPos[Axis_Const::RTX]);
                        g_Motion.AbsMove(Axis_Const::CCD,g_Motion.m_dLastTargetPos[Axis_Const::CCD]);
                        g_Motion.AbsMove(Axis_Const::FTX,g_Motion.m_dLastTargetPos[Axis_Const::FTX]);
                        g_Motion.AbsMove(Axis_Const::SCY,g_Motion.m_dLastTargetPos[Axis_Const::SCY]);
                        g_Motion.AbsMove(Axis_Const::SSY,g_Motion.m_dLastTargetPos[Axis_Const::SSY]);
                       
                        nThreadIndex++;
                        break;
                case 2:
                        if(g_Motion.IsPosDone(Axis_Const::CCD,g_Motion.m_dLastTargetPos[Axis_Const::CCD]) &&
                           g_Motion.IsPosDone(Axis_Const::SCY,g_Motion.m_dLastTargetPos[Axis_Const::SCY]) &&
                           g_Motion.IsPosDone(Axis_Const::SSY,g_Motion.m_dLastTargetPos[Axis_Const::SSY]) &&
                           g_Motion.IsPosDone(Axis_Const::RTX,g_Motion.m_dLastTargetPos[Axis_Const::RTX]) &&
                           g_Motion.IsPosDone(Axis_Const::FTX,g_Motion.m_dLastTargetPos[Axis_Const::FTX]) )
                        {
                                tm1MS.timeStart(1000);
                                nThreadIndex++;
                        }
                        break;
                case 3:
                        if(tm1MS.timeUp())
                        {
                                nThreadIndex++;
                        }
                        break;
                case 4:
                        if(tm2MS.timeUp())
                        {
                                nThreadIndex++;
                        }
                        break;
                default:
                        nThreadIndex=0;
                        return true;
                        break;
        }

        return false;
}
//---------------------------------------------------------------------------
void __fastcall CMainThread::ThreadTrace()
{
        if(m_listThreadTrace.size()>50) m_listThreadTrace.pop_front();

        AnsiString strMsg;
        AnsiString strMsgA;

        for(int nIndex=1;nIndex<=11;nIndex++)
        {
                strMsg+=strMsgA.sprintf("[%02d]%03d ",nIndex,nThreadIndex[nIndex]);
        }

        m_listThreadTrace.push_back(strMsg);

}





