//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmManual.h"
#include "PCIM114GL.h"
#include "IniFile.h"
#include "C_GetTime.h"
#include "fmMotorCheck.h" 
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TfmManual *fmManual;

extern PCIM114GL g_MNet;
extern CIniFile g_IniFile;
//---------------------------------------------------------------------------
__fastcall TfmManual::TfmManual(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TfmManual::SpeedButton1Click(TObject *Sender)
{
         C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        if(!g_MNet.GetDI(DI::SL_Exist))
        {
                ShowMessage("基板有無檢知off");
                return;
        }

        if(g_MNet.GetDI(DI::SL_Inp)) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        g_MNet.SetDO(DO::SL_Start,true);
        g_MNet.SetDO(DO::SL_Dir,false);
        tm1MS.timeStart(10000);

        while(1)
        {
                if(g_MNet.GetDI(DI::SL_Inp)) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        g_MNet.SetDO(DO::SL_Start,false);

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TfmManual::SpeedButton2Click(TObject *Sender)
{
        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        g_MNet.SetDO(DO::SL_Start,true);
        g_MNet.SetDO(DO::SL_Dir,true);
        tm1MS.timeStart(10000);

        while(1)
        {
                if(g_MNet.GetDI(DI::SL_Down)) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        g_MNet.SetDO(DO::SL_Start,false);

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------





void __fastcall TfmManual::btnSSYClick(TObject *Sender)
{
        double dPos[20]={0};

        if(!g_MNet.GetDI(DI::SS_SSuckerUp) || !g_MNet.GetDI(DI::SS_SpaSuckerUp))
        {
                ShowMessage("吸盤沒有在上位");
                return;
        }

        dPos[0]=g_IniFile.m_dSSPickerPickPos;
        dPos[1]=g_IniFile.m_dSSPickerPickRailPos;
        dPos[2]=g_IniFile.m_dSSPickerPutPos[0];
        dPos[3]=g_IniFile.m_dSSPickerPutPos[1];
        dPos[4]=g_IniFile.m_dSpaPickerPickPos;
        dPos[5]=g_IniFile.m_dSpaPickerThrowPos;


        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        //pBtn->Enabled=false;
        EnableAllButton(false);

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        g_MNet.AbsMove(Axis_Const::SSY,dPos[pBtn->Tag]);

        while(1)
        {
                if(g_MNet.IsPosDone(Axis_Const::SSY,dPos[pBtn->Tag])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        //pBtn->Enabled=true;
        EnableAllButton(true);
}
//---------------------------------------------------------------------------

void __fastcall TfmManual::btnFTXClick(TObject *Sender)
{
        double dPos[30]={0};


        dPos[0]=g_IniFile.m_dTablePutDownPos[1];
        dPos[1]=g_IniFile.m_dTableMarkPosX[1];
        dPos[2]=g_IniFile.m_dTableMarkPosY[1];
        dPos[3]=g_IniFile.m_dTableVenderCodePosX[1];
        dPos[4]=g_IniFile.m_dTableVenderCodePosY[1];
        dPos[5]=g_IniFile.m_dTableLaserPos[1];
        dPos[6]=g_IniFile.m_dTableLaserCodePosX[1];
        dPos[7]=g_IniFile.m_dTableLaserCodePosY[1];
        dPos[8]=g_IniFile.m_dTablePickUpPos[1];
        dPos[18]=g_IniFile.m_dTableMarkPos2X[1];
        dPos[19]=g_IniFile.m_dTableMarkPos2Y[1];
        dPos[22]=g_IniFile.m_dTableBackSpeedDown[1];
        dPos[23]=g_IniFile.m_dTableBackSpeedUp[1];

        dPos[9]=g_IniFile.m_dTablePutDownPos[0];
        dPos[10]=g_IniFile.m_dTableMarkPosX[0];
        dPos[11]=g_IniFile.m_dTableMarkPosY[0];
        dPos[12]=g_IniFile.m_dTableVenderCodePosX[0];
        dPos[13]=g_IniFile.m_dTableVenderCodePosY[0];
        dPos[14]=g_IniFile.m_dTableLaserPos[0];
        dPos[15]=g_IniFile.m_dTableLaserCodePosX[0];
        dPos[16]=g_IniFile.m_dTableLaserCodePosY[0];
        dPos[17]=g_IniFile.m_dTablePickUpPos[0];
        dPos[20]=g_IniFile.m_dTableMarkPos2X[0];
        dPos[21]=g_IniFile.m_dTableMarkPos2Y[0];
        dPos[24]=g_IniFile.m_dTableBackSpeedDown[0];
        dPos[25]=g_IniFile.m_dTableBackSpeedUp[0];

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        //pBtn->Enabled=false;
        EnableAllButton(false);

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        int nAxis;
        if(pBtn->Hint=="X") nAxis=Axis_Const::FTX;
        else if(pBtn->Hint=="X1") nAxis=Axis_Const::RTX;
        else if(pBtn->Hint=="Y") nAxis=Axis_Const::CCD;

        if(!g_MNet.GetDI(DI::SS_SSuckerUp) || !g_MNet.GetDI(DI::SS_SpaSuckerUp))
        {
                ShowMessage("入料區吸盤沒有在上位");
                return;
        }

        if(!g_MNet.GetDI(DI::SC_SSuckerUp))
        {
                ShowMessage("出料區吸盤沒有在上位");
                return;
        }

        if(pBtn->Hint=="X" && !g_MNet.GetDI(DI::FT_Positive))
        {
                ShowMessage("前平台沒有在正面");
                return;
        }
        
        if(pBtn->Hint=="X1" && !g_MNet.GetDI(DI::RT_Positive))
        {
                ShowMessage("後平台沒有在正面");
                return;
        }

        g_MNet.AbsMove(nAxis,dPos[pBtn->Tag]);

        while(1)
        {
                if(g_MNet.IsPosDone(nAxis,dPos[pBtn->Tag])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        //pBtn->Enabled=true;
        EnableAllButton(true);
}
//---------------------------------------------------------------------------

void __fastcall TfmManual::btnSCYClick(TObject *Sender)
{
        double dPos[20]={0};

        if(!g_MNet.GetDI(DI::SC_SSuckerUp))
        {
                ShowMessage("出料區吸盤沒有在上位");
                return;
        }


        //dPos[0]=g_IniFile.m_dSCPickerPickCoverPosY;
        //dPos[1]=g_IniFile.m_dSCPickerPickCoverPosZ;
        dPos[2]=g_IniFile.m_dSCPickerPickSSPosY[1];
        //dPos[3]=g_IniFile.m_dSCPickerPickSSPosZ[1];
        dPos[4]=g_IniFile.m_dSCPickerPickSSPosY[0];
        //dPos[5]=g_IniFile.m_dSCPickerPickSSPosZ[0];
        //dPos[6]=g_IniFile.m_dSCPickerPutSSPosY[0];
        //dPos[7]=g_IniFile.m_dSCPickerPutSSPosZ[0];
        //dPos[8]=g_IniFile.m_dSCPickerPutSSPosY[1];
        //dPos[9]=g_IniFile.m_dSCPickerPutSSPosZ[1];
        //dPos[10]=g_IniFile.m_dSCPickerPutCoverPosY;
        //dPos[11]=g_IniFile.m_dSCPickerPutCoverPosZ;
        //dPos[12]=g_IniFile.m_dSCPickerPutNGCoverPosY;
        //dPos[13]=g_IniFile.m_dSCPickerPutNGCoverPosZ;
        dPos[14]=g_IniFile.m_dLaserCodeReaderPos[0];
        dPos[15]=g_IniFile.m_dLaserCodeReaderPos[1];
        dPos[16]=g_IniFile.m_dSCPickerPutSSPos;
        dPos[17]=g_IniFile.m_dSBTNGBoxPos;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        //pBtn->Enabled=false;
        EnableAllButton(false);

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        int nAxis=Axis_Const::SCY;

        if(pBtn->Hint=="Y") nAxis=Axis_Const::SCY;
        //else nAxis=Axis_Const::SCZ;

        g_MNet.AbsMove(nAxis,dPos[pBtn->Tag]);

        while(1)
        {
                if(g_MNet.IsPosDone(nAxis,dPos[pBtn->Tag])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        //pBtn->Enabled=true;
        EnableAllButton(true);
}
//---------------------------------------------------------------------------


void __fastcall TfmManual::SpeedButton7Click(TObject *Sender)
{
        g_MNet.SetDO(DO::SS_SVacOn,false);
        g_MNet.SetDO(DO::SS_SVacOff,true);
        g_MNet.SetDO(DO::SS_SpaVacOn,false);
        g_MNet.SetDO(DO::SS_SpaVacOff,true);
        g_MNet.SetDO(DO::SC_SSuckerVacOn,false);
        g_MNet.SetDO(DO::SC_SSuckerVacOff,true);


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool __fastcall TfmManual::AxisMoveCheck()
{
        /*
        if(!g_pMainThread->m_bIsHomeDone)
        {
                ShowMessage("請先執行機台原點復歸");
                return false;
        }
        */

        if(!g_MNet.GetDI(DI::SS_SSuckerUp) || !g_MNet.GetDI(DI::SS_SpaSuckerUp))
        {
                ShowMessage("入料區吸盤沒有在上位");
                return false;
        }

        if(!g_MNet.GetDI(DI::SC_SSuckerUp) || !g_MNet.GetDI(DI::SC_CSuckerUp))
        {
                ShowMessage("出料區吸盤沒有在上位");
                return false;
        }

        return true;

}
//---------------------------------------------------------------------------
void __fastcall TfmManual::SpeedButton14Click(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        if (pBtn->Tag == 0 || pBtn->Tag == 8)
        {
                //g_Motion.AbsMove(Axis_Const::SSY, 878.460);
                if ( g_MNet.GetAxisStatus(Axis_Const::SSY,Axis_Const::PEL) && g_MNet.GetDI(DI::FT_LockerOff)
                    && !g_MNet.GetDI(DI::FT_Align2Off) && g_MNet.GetDI(DI::FT_AlignOff) && pBtn->Tag == 0
                    && (fabs(g_MNet.GetFeedbackPos(Axis_Const::FTX)-g_IniFile.m_dTableLaserPos[1])<=5
                        || fabs(g_MNet.GetFeedbackPos(Axis_Const::FTX)-g_IniFile.m_dTablePutDownPos[1])<=5) )
                {
                        g_MNet.SetDO(pBtn->Tag,!g_MNet.GetDO(pBtn->Tag));
                }
                else if ( g_MNet.GetAxisStatus(Axis_Const::SSY,Axis_Const::PEL) && g_MNet.GetDI(DI::RT_LockerOff)
                    && !g_MNet.GetDI(DI::RT_Align2Off) && g_MNet.GetDI(DI::RT_AlignOff) && pBtn->Tag == 8
                    && (fabs(g_MNet.GetFeedbackPos(Axis_Const::RTX)-g_IniFile.m_dTableLaserPos[0])<=5
                        || fabs(g_MNet.GetFeedbackPos(Axis_Const::RTX)-g_IniFile.m_dTablePutDownPos[0])<=5) )
                {
                        g_MNet.SetDO(pBtn->Tag,!g_MNet.GetDO(pBtn->Tag));
                }
                else
                {
                    if (Application->MessageBox("翻轉條件不合規定! 是否移動入料夾爪到前極限?", "Error", MB_OKCANCEL)==IDCANCEL)
                    {
                        g_IniFile.m_nErrorCode=438;
                        return;
                    }
                    // OK checked
                    C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
                    tm1MS.timeStart(5000);
                    while (true)
                    {
                        if (g_MNet.GetAxisStatus(Axis_Const::SSY,Axis_Const::PEL) == true) break;
                        g_MNet.AbsMove(Axis_Const::SSY,1200.0);
                        Application->ProcessMessages();
                        if(tm1MS.timeUp()) break;
                    }

                    if ( g_MNet.GetAxisStatus(Axis_Const::SSY,Axis_Const::PEL) && g_MNet.GetDI(DI::FT_LockerOff)
                        && !g_MNet.GetDI(DI::FT_Align2Off) && g_MNet.GetDI(DI::FT_AlignOff) && pBtn->Tag == 0
                        && (fabs(g_MNet.GetFeedbackPos(Axis_Const::FTX)-g_IniFile.m_dTableLaserPos[1])<=5
                            || fabs(g_MNet.GetFeedbackPos(Axis_Const::FTX)-g_IniFile.m_dTablePutDownPos[1])<=5) )
                    {
                        g_MNet.SetDO(pBtn->Tag,!g_MNet.GetDO(pBtn->Tag));
                    }
                    else if ( g_MNet.GetAxisStatus(Axis_Const::SSY,Axis_Const::PEL) && g_MNet.GetDI(DI::RT_LockerOff)
                        && !g_MNet.GetDI(DI::RT_Align2Off) && g_MNet.GetDI(DI::RT_AlignOff) && pBtn->Tag == 8
                        && (fabs(g_MNet.GetFeedbackPos(Axis_Const::RTX)-g_IniFile.m_dTableLaserPos[0])<=5
                            || fabs(g_MNet.GetFeedbackPos(Axis_Const::RTX)-g_IniFile.m_dTablePutDownPos[0])<=5) )
                    {
                        g_MNet.SetDO(pBtn->Tag,!g_MNet.GetDO(pBtn->Tag));
                    }
                    else g_IniFile.m_nErrorCode=439;
                }
        }
        else
        {
                g_MNet.SetDO(pBtn->Tag,!g_MNet.GetDO(pBtn->Tag));
        }

}
//---------------------------------------------------------------------------

void __fastcall TfmManual::Timer1Timer(TObject *Sender)
{
        TShape *pShape;
  AnsiString strComponentName;

  Timer1->Enabled=false;

  byte nPortData=0;
  int nTag=0;
  for(int nIndex2=0;nIndex2<12;nIndex2++)                //Port
  {
        nPortData=g_MNet.GetDIPort(nIndex2);

        for(int nIndex=0;nIndex<8;nIndex++)             //Byte
        {
                strComponentName.sprintf("X%d",nTag);

                pShape=(TShape *)FindComponent(strComponentName);
                if(pShape!=NULL)
                {
                        if((nPortData & (byte)(0x01<<nIndex))>0)
                                pShape->Brush->Color=clLime;
                        else
                                pShape->Brush->Color=clGray;
                }
                nTag++;
        }

  }

  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfmManual::StaticText1Click(TObject *Sender)
{
         //BPZ=0,BLZ=1,SCZ=2,CCD=3,SCY=4,CRD=5,BPY=6,SSY=7,RTX=8,FTX=9

        TStaticText *pText=(TStaticText *)Sender;
        TfrmMotorCheck *pMotorCheckDlg;

        AnsiString sPath = ExtractFilePath(Application->ExeName);
        sPath = StringReplace(sPath, "\\exe\\", "",TReplaceFlags());

        pMotorCheckDlg=new TfrmMotorCheck(this);
        pMotorCheckDlg->m_nActiveAxis=pText->Tag;
        pMotorCheckDlg->Caption=pText->Caption;
        //Change Arrow Glyph
        if (pMotorCheckDlg->m_nActiveAxis == 4 || pMotorCheckDlg->m_nActiveAxis == 5)
        {
                int nRWDLeft = pMotorCheckDlg->btnRWD->Left;
                int nFWDLeft = pMotorCheckDlg->btnFWD->Left;
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\right.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\left.bmp");
                pMotorCheckDlg->btnFWD->Left = nRWDLeft;
                pMotorCheckDlg->btnRWD->Left = nFWDLeft;
        }
        else if (pMotorCheckDlg->m_nActiveAxis == 6)
        {
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
        }
        else if (pMotorCheckDlg->m_nActiveAxis == 7)
        {
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
        }
        else if (pMotorCheckDlg->m_nActiveAxis == 8)
        {
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
        }


        if(pMotorCheckDlg->ShowModal()==mrOk)
        {
                TEdit *pEdit=(TEdit *)FindComponent(pText->Hint);
                if(pEdit) pEdit->Text=pMotorCheckDlg->m_dCurrPos;
                else ShowMessage("寫入失敗");
        }


        delete pMotorCheckDlg;
}
//---------------------------------------------------------------------------
void __fastcall TfmManual::EnableAllButton(bool bEnabled)
{
        TPageControl *pPage=PageControl1;

        for(int nIndex2=0;nIndex2<pPage->ControlCount;nIndex2++)
        {
                if(pPage->Controls[nIndex2]->ClassNameIs("TTabSheet"))
                {
                        TTabSheet *pSheet=(TTabSheet *)pPage->Controls[nIndex2];

                        for(int nIndex3=0;nIndex3<pSheet->ControlCount;nIndex3++)
                        {
                                if(pSheet->Controls[nIndex3]->ClassNameIs("TSpeedButton"))
                                {
                                        TSpeedButton *pBtn=(TSpeedButton *)pSheet->Controls[nIndex3];
                                        pBtn->Enabled=bEnabled;

                                }

                                if(pSheet->Controls[nIndex3]->ClassNameIs("TGroupBox"))
                                {
                                        TGroupBox *pGroup=(TGroupBox *)pSheet->Controls[nIndex3];

                                        for(int nIndex4=0;nIndex4<pGroup->ControlCount;nIndex4++)
                                        {
                                                if(pGroup->Controls[nIndex4]->ClassNameIs("TSpeedButton"))
                                                {
                                                        TSpeedButton *pBtn=(TSpeedButton *)pGroup->Controls[nIndex4];
                                                        pBtn->Enabled=bEnabled;

                                                }
                                        }


                                }

                        }
                }
        }

        ::Sleep(500);

}


void __fastcall TfmManual::SpeedButton53Click(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        int bitA = pBtn->Tag;
        int bitB = pBtn->Hint.ToInt();

        bool bOnOff = g_MNet.GetDO(bitA);
        g_MNet.SetDO(bitA,!bOnOff);
        g_MNet.SetDO(bitB,bOnOff);
}
//---------------------------------------------------------------------------


