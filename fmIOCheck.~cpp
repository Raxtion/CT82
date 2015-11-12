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
"分離吹氣電磁閥",
"間隔材吸盤上下汽缸電磁閥",
"間隔材真空產生打開電磁閥",
"間隔材真空產生關閉電磁閥",
"間隔材真空破壞電磁閥",
"基板吸盤上下汽缸電磁閥",
"基板真空產生打開電磁閥",
"基板真空產生關閉電磁閥",
"基板真空破壞電磁閥",
"推桿1_電磁閥",
"推桿2_電磁閥",
"推桿3_電磁閥",
"CCD左右汽缸電磁閥",
"LED燈源",
"Boat流道感應馬達_2 轉動",
"Boat流道2_靠邊汽缸電磁閥",

"Boat流道2 STOP 電磁閥",
"Boat流道感應馬達_3 轉動",
"Boat流道3_靠邊汽缸電磁閥",
"Boat流道3 STOP 電磁閥",
"Boat流道感應馬達_1轉動",
"Boat Lock 汽缸電磁閥",
"Boat 上下汽缸電磁閥",
"Boat 上下汽缸中位電磁閥",
"蓋板上下感應馬達上升",
"蓋板上下感應馬達下降",
"蓋板靠邊汽缸動作電磁閥",
"基板真空產生打開電磁閥",
"基板真空產生關閉電磁閥",
"基板真空破壞電磁閥",
"蓋板吸盤上下汽缸電磁閥",
"蓋板真空產生打開電磁閥",

"蓋板真空產生關閉電磁閥",
"蓋板真空破壞電磁閥",
"三色燈Red",
"三色燈Green",
"三色燈Yellow",
"Buzzer",
"啟動燈",
"停止燈",
"復歸燈",
"Boat 上下汽缸",
"Laser Blow Air",
"流道基板吸真空",
"Lanchanger NG",
"Laser基板靠邊",
"基板靠邊汽缸動作電磁閥",
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
"間隔材料盒有無檢知",
"料倉取片位置檢知",
"間隔材吸盤上位",
"間隔材盤下位",
"間隔材吸盤真空檢知",
"基板吸盤上位",
"基板吸盤下位",
"基板吸盤真空檢知",
"推桿1_上位檢知",
"推桿1_下位檢知",
"推桿1_基板定位檢知",
"推桿2_上位檢知",
"推桿2_下位檢知",
"推桿2_基板定位檢知",
"推桿3_上位檢知",
"推桿3_下位檢知",

"推桿3_基板定位檢知",
"放置區基板有無檢知",
"CCD區基板有無檢知",
"LASER區基板有無檢知",
"取片區基板有無檢知",
"CCD汽缸左定位",
"CCD汽缸右定位",
"Boat流道2 有無檢知",
"Boat流道2 定位檢知",
"Boat流道2 STOP 上位檢知",
"Boat流道2 STOP 下位檢知",
"Boat流道3 有無檢知",
"Boat流道3 定位檢知",
"Boat流道3 STOP 上位檢知",
"Boat流道3 STOP 下位檢知",
"蓋板高度檢知(流出時偵測)",

"Boat流道1 有無檢知",
"Boat正反檢知(流出時偵測)",
"Boat Lock 汽缸LOCK檢知",
"Boat Lock 汽缸打開檢知",
"Boat 上下汽缸下位檢知",
"Boat 上下汽缸中位檢知",
"Boat 上下汽缸上位檢知",
"蓋板LOADER下位",
"蓋板LOADER上位",
"蓋板有無檢知",
"蓋板靠邊汽缸後點位",
"吸基板真空檢知",
"蓋板吸盤上位",
"蓋板吸盤下位",
"吸蓋板真空檢知",
"急停",

"電源",
"啟動",
"停止",
"復歸",
"主氣壓源",
"基板放置異常",
"",
"",
"基板有無",
"安全門",
"58",
"Boat有無",
"間隔材有無",
"Lane changer Ready",
"Laser Finished",
"間隔材有無"};

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


