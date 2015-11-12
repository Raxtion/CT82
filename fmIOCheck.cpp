//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "fmIOCheck.h"
#include "math.h"
#include "iniFile.h"
#include "PCIM114GL.h"

extern PCIM114GL g_MNet;
//---------------------------------------------------------------------
#pragma resource "*.dfm" 

extern CIniFile g_IniFile;
//--------------------------------------------------------------------- 
__fastcall TIOCheckDlg::TIOCheckDlg(TComponent* AOwner)
	: TForm(AOwner)
{
  //SetInputCaption();
  //SetOutputCaption();
}
//---------------------------------------------------------------------

void __fastcall TIOCheckDlg::timerInputTimer(TObject *Sender)
{
  TPanel *pInputPanel;
  AnsiString strComponentName;

  timerInput->Enabled=false;

  byte nPortData=0;
  int nTag=0;
  for(int nIndex2=0;nIndex2<12;nIndex2++)                //Port
  {
        nPortData=g_MNet.GetDIPort(nIndex2);

        for(int nIndex=0;nIndex<8;nIndex++)             //Byte
        {
                if(nIndex2<8) strComponentName.sprintf("InputPanel%d",nTag);
                else strComponentName.sprintf("Panel%d",nTag-64+3);
                pInputPanel=(TPanel *)FindComponent(strComponentName);
                if(pInputPanel==NULL) return;
                if((nPortData & (byte)(0x01<<nIndex))>0)
                        pInputPanel->Color=clLime;
                else
                        pInputPanel->Color=clGreen;
                nTag++;
        }

  }

  timerInput->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TIOCheckDlg::timerOutputTimer(TObject *Sender)
{
  TSpeedButton *pOutputButton;
  AnsiString strComponentName;

  timerOutput->Enabled=false;

 byte nPortData=0;
 int nTag=0;
 for(int nIndex2=0;nIndex2<12;nIndex2++)
 {
        nPortData=g_MNet.GetDOPort(nIndex2);
        for(int nIndex=0;nIndex<8;nIndex++)
        {
        if(nIndex2<4) strComponentName.sprintf("SpeedButton%d",nTag+1);
        else strComponentName.sprintf("OutputButton%d",nTag-32);
        pOutputButton=(TSpeedButton *)FindComponent(strComponentName);
        if(pOutputButton==NULL) return;
        if((nPortData & (byte)(0x01<<nIndex))>0)
                pOutputButton->Down=true;
        else
                pOutputButton->Down=false;
        nTag++;
        }
 }
  timerOutput->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TIOCheckDlg::OutputButton0Click(TObject *Sender)
{
  bool bSetValue;

  TSpeedButton *pOutputButton=(TSpeedButton *)Sender;
  if(pOutputButton->Down)
    bSetValue=true;
  else
    bSetValue=false;

  g_MNet.SetDO(pOutputButton->GroupIndex-1,bSetValue);  

}
//---------------------------------------------------------------------------
void __fastcall TIOCheckDlg::SetOutputCaption()
{ 
  char * strCaption[]={
"�����j��q�ϻ�",
"���j���l�L�W�U�T���q�ϻ�",
"���j���u�Ų��ͥ��}�q�ϻ�",
"���j���u�Ų��������q�ϻ�",
"���j���u�ů}�a�q�ϻ�",
"��O�l�L�W�U�T���q�ϻ�",
"��O�u�Ų��ͥ��}�q�ϻ�",
"��O�u�Ų��������q�ϻ�",
"��O�u�ů}�a�q�ϻ�",
"����1_�q�ϻ�",
"����2_�q�ϻ�",
"����3_�q�ϻ�",
"CCD���k�T���q�ϻ�",
"LED�O��",
"Boat�y�D�P�����F_2 ���",
"Boat�y�D2_�a��T���q�ϻ�",

"Boat�y�D2 STOP �q�ϻ�",
"Boat�y�D�P�����F_3 ���",
"Boat�y�D3_�a��T���q�ϻ�",
"Boat�y�D3 STOP �q�ϻ�",
"Boat�y�D�P�����F_1���",
"Boat Lock �T���q�ϻ�",
"Boat �W�U�T���q�ϻ�",
"Boat �W�U�T������q�ϻ�",
"�\�O�W�U�P�����F�W��",
"�\�O�W�U�P�����F�U��",
"�\�O�a��T���ʧ@�q�ϻ�",
"��O�u�Ų��ͥ��}�q�ϻ�",
"��O�u�Ų��������q�ϻ�",
"��O�u�ů}�a�q�ϻ�",
"�\�O�l�L�W�U�T���q�ϻ�",
"�\�O�u�Ų��ͥ��}�q�ϻ�",

"�\�O�u�Ų��������q�ϻ�",
"�\�O�u�ů}�a�q�ϻ�",
"�T��ORed",
"�T��OGreen",
"�T��OYellow",
"Buzzer",
"�ҰʿO",
"����O",
"�_�k�O",
"Boat �W�U�T��",
"Laser Blow Air",
"�y�D��O�l�u��",
"Lanchanger NG",
"Laser��O�a��",
"��O�a��T���ʧ@�q�ϻ�",
"47",

"48",
"49",
"50",
"51",
"52",
"53",
"54",
"55",
"56",
"57",
"58",
"59",
"60",
"61",
"62",
"63"};

AnsiString strMsg;
  
  for(int nIndex=0;nIndex<64;nIndex++)
  {
         strMsg.sprintf("OutputButton%d",nIndex);
        ((TSpeedButton *)FindComponent(strMsg))->Caption=strCaption[nIndex];
   }
}
//---------------------------------------------------------------------------
void __fastcall TIOCheckDlg::SetInputCaption()
{
  char *strCaption[]={
"���j���Ʋ����L�˪�",
"�ƭܨ�����m�˪�",
"���j���l�L�W��",
"���j���L�U��",
"���j���l�L�u���˪�",
"��O�l�L�W��",
"��O�l�L�U��",
"��O�l�L�u���˪�",
"����1_�W���˪�",
"����1_�U���˪�",
"����1_��O�w���˪�",
"����2_�W���˪�",
"����2_�U���˪�",
"����2_��O�w���˪�",
"����3_�W���˪�",
"����3_�U���˪�",

"����3_��O�w���˪�",
"��m�ϰ�O���L�˪�",
"CCD�ϰ�O���L�˪�",
"LASER�ϰ�O���L�˪�",
"�����ϰ�O���L�˪�",
"CCD�T�����w��",
"CCD�T���k�w��",
"Boat�y�D2 ���L�˪�",
"Boat�y�D2 �w���˪�",
"Boat�y�D2 STOP �W���˪�",
"Boat�y�D2 STOP �U���˪�",
"Boat�y�D3 ���L�˪�",
"Boat�y�D3 �w���˪�",
"Boat�y�D3 STOP �W���˪�",
"Boat�y�D3 STOP �U���˪�",
"�\�O�����˪�(�y�X�ɰ���)",

"Boat�y�D1 ���L�˪�",
"Boat�����˪�(�y�X�ɰ���)",
"Boat Lock �T��LOCK�˪�",
"Boat Lock �T�����}�˪�",
"Boat �W�U�T���U���˪�",
"Boat �W�U�T�������˪�",
"Boat �W�U�T���W���˪�",
"�\�OLOADER�U��",
"�\�OLOADER�W��",
"�\�O���L�˪�",
"�\�O�a��T�����I��",
"�l��O�u���˪�",
"�\�O�l�L�W��",
"�\�O�l�L�U��",
"�l�\�O�u���˪�",
"�氱",

"�q��",
"�Ұ�",
"����",
"�_�k",
"�D������",
"��O��m���`",
"",
"",
"��O���L",
"�w����",
"58",
"Boat���L",
"���j�����L",
"Lane changer Ready",
"Laser Finished",
"���j�����L"};

  AnsiString strMsg;
  
  for(int nIndex=0;nIndex<64;nIndex++)
  {
         strMsg.sprintf("InputPanel%d",nIndex);
        ((TPanel *)FindComponent(strMsg))->Caption=strCaption[nIndex];
   }

}
//---------------------------------------------------------------------------

void __fastcall TIOCheckDlg::FormCreate(TObject *Sender)
{
    AnsiString strMsg,strStatic;

    for(int nIndex=0;nIndex<95;nIndex++)
    {
        strMsg.sprintf("X%03d",nIndex);
        strStatic.sprintf("StaticText%d",nIndex+1);
        ((TStaticText *)FindComponent(strStatic))->Caption=strMsg;

        strMsg.sprintf("Y%03d",nIndex);
        strStatic.sprintf("StaticText%d",nIndex+97);
        ((TStaticText *)FindComponent(strStatic))->Caption=strMsg; 
    }

}
//---------------------------------------------------------------------------


