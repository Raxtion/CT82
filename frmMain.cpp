//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmMain.h"
#include "DominoVision.h"
#include "PCIM114GL.h"
#include "IniFile.h"
#include "MainThread.h"
#include "CEVision.h"

#include "time.h"

#include "fmIOCheck.h"
#include "fmChoiceMotor.h"
#include "fmMotorCheck.h"
#include "fmMachinParam.h"
#include "fmProductParam.h""
#include "frmPrivilege.h"
#include "fmPassword.h"
#include "C_GetTime.h"
#include "frmManual.h"
#include "DominoVision.h"
#include "frmShowNow.h"

#include "KenenceLaser.h"
#include "frmOption.h"

#include "dir.h"
#include "CtkLedControll.h"
#include "EQPXML.h"
#include "math.h"
#include "tlhelp32.h"
#include "SMSXML.h"
#include "fmUserID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;

extern CIniFile g_IniFile;
extern CMainThread *g_pMainThread;
extern PCIM114GL g_MNet;
extern CKeyenceLaser g_Laser;
extern bool g_bOnRefresh;
extern CEQPXML g_eqpXML;
extern CTK_Led g_LED;
extern CEVision theVision;
extern bool g_bStopMainThread;
extern DominoVision g_Grabber;
extern bool g_bOnRefresh;
extern CSMSXML g_SMSXML;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
        : TForm(Owner)
{   
        memset(m_nSubstrateMap,0,sizeof(__int16)*10000);

}
 //---------------------------------------------------------------------------
void TfmMain::RefreshImage()
{
        double nScaleTempX=1.0;
         double nScaleTempY=1.0;


         theVision.CreateMapArray(TRect(theVision.m_roiMark[0].GetOrgX()*nScaleTempX,theVision.m_roiMark[0].GetOrgY()*nScaleTempY,
                                theVision.m_roiMark[0].GetOrgX()*nScaleTempX+theVision.m_roiMark[0].GetWidth()*nScaleTempX,
                                theVision.m_roiMark[0].GetOrgY()*nScaleTempY+theVision.m_roiMark[0].GetHeight()*nScaleTempY),
                                g_IniFile.m_nPackageX,g_IniFile.m_nPackageY,g_IniFile.m_nPackageGap,
                                g_IniFile.m_nDeviceX,g_IniFile.m_nDeviceY);



        fmMain->ImagePaintBox->Width=theVision.m_ImageTmpBW8.GetWidth()*theVision.m_dScaleSizeX;
        fmMain->ImagePaintBox->Height=theVision.m_ImageTmpBW8.GetHeight()*theVision.m_dScaleSizeY;

        RECT RectImageSize = {fmMain->ImagePaintBox->Left, fmMain->ImagePaintBox->Top,
        fmMain->ImagePaintBox->Left+fmMain->ImagePaintBox->Width ,
        fmMain->ImagePaintBox->Top+fmMain->ImagePaintBox->Height};

        ::InvalidateRect(fmMain->ScrollBox1->Handle, &RectImageSize, false);

        
        RECT XXX = { fmMain->paintMap->BoundsRect.Left,
                fmMain->paintMap->BoundsRect.Top,
         fmMain->paintMap->BoundsRect.Left+fmMain->paintMap->BoundsRect.Width() ,
         fmMain->paintMap->BoundsRect.Top+fmMain->paintMap->BoundsRect.Height()};


        ::InvalidateRect(fmMain->Panel1->Handle, &XXX, false);
        

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ImagePaintBoxMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if(m_nUserLevel<1) return;

        if (Shift.Contains(ssLeft))
        {
        // Mouse button down, drag the ROI border
                if(checkShowSearchROI0->Checked) theVision.m_roiMark[0].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                if(checkShowPatternROI0->Checked) theVision.m_roiMarkPattern[0].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                if(checkShowSearchROI1->Checked) theVision.m_roiMark[1].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                if(checkShowPatternROI1->Checked) theVision.m_roiMarkPattern[1].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                if(checkShowSearchROI2->Checked) theVision.m_roiMark[2].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                if(checkShowPatternROI2->Checked) theVision.m_roiMarkPattern[2].Drag(theVision.m_eHandle, X, Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY) ;
                RefreshImage();
        }
        else
        {
                if(checkShowSearchROI0->Checked) theVision.m_eHandle=theVision.m_roiMark[0].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);
                 if(checkShowPatternROI0->Checked) theVision.m_eHandle=theVision.m_roiMarkPattern[0].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);
                 if(checkShowSearchROI1->Checked) theVision.m_eHandle=theVision.m_roiMark[1].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);
                 if(checkShowPatternROI1->Checked) theVision.m_eHandle=theVision.m_roiMarkPattern[1].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);
                 if(checkShowSearchROI2->Checked) theVision.m_eHandle=theVision.m_roiMark[2].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);
                 if(checkShowPatternROI2->Checked) theVision.m_eHandle=theVision.m_roiMarkPattern[2].HitTest(X,Y,theVision.m_dScaleSizeX,theVision.m_dScaleSizeY);

        }

        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnFileOpenClick(TObject *Sender)
{
        AnsiString strMsg;
  if(Application->MessageBoxA("開檔前是否要儲存目前檔案?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
  {

    g_IniFile.MachineFile(false);
    g_IniFile.ProductFile(Caption.c_str(),false,FILE_MODE_ALL);
    theVision.SaveTool(g_IniFile.GetFileNameWithNewExt(Caption.c_str(),"cev").c_str(),"Dummy");

    SaveProduct();

    ShowMessage("檔案儲存完成!");
  }

  OpenDialog1->DefaultExt = "INI";
  OpenDialog1->FileName = "*.ini";

  if(OpenDialog1->Execute())
  {
        g_IniFile.m_strLastFileName=OpenDialog1->FileName;
        Caption=g_IniFile.m_strLastFileName;

        g_IniFile.MachineFile(true);
        g_IniFile.ProductFile(Caption.c_str(),true,FILE_MODE_ALL);

        theVision.LoadTool(g_IniFile.GetFileNameWithNewExt(Caption.c_str(),"cev").c_str(),"Dummy");

        LoadProduct();

  }

  SetLEDDimmer();

  g_SMSXML.m_strMachineID=g_IniFile.m_strSMSMachineID;
  g_SMSXML.m_strUserID=g_IniFile.m_strSMSUserID;
  g_SMSXML.m_strPartNo=g_IniFile.m_strSMSPartNo;
  g_SMSXML.m_strLotNo=g_IniFile.m_strSMSLotNo;


}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnFileSaveClick(TObject *Sender)
{
        if(Application->MessageBoxA("確定要存檔?","Confi rm",MB_ICONQUESTION|MB_OKCANCEL)==IDCANCEL) return;

    g_IniFile.MachineFile(false);
    g_IniFile.ProductFile(Caption.c_str(),false,FILE_MODE_ALL);

    theVision.SaveTool(g_IniFile.GetFileNameWithNewExt(Caption.c_str(),"cev").c_str(),"Dummy");

    SaveProduct();
    
    ShowMessage("檔案儲存完成!");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnSaveAsClick(TObject *Sender)
{
  AnsiString InputString = InputBox("請輸入將要另存檔案名稱", "檔案名稱", "Default");


        
        MkDir("C:\\Product Data\\"+InputString+"\\");

        AnsiString strPathName="C:\\Product Data\\"+InputString+"\\"+InputString+".ini";
    g_IniFile.m_strLastFileName=strPathName;//pWnd->editFileName->Text;
    Caption=strPathName;//pWnd->editFileName->Text;

    g_IniFile.ProductFile(g_IniFile.m_strLastFileName.c_str(),false,FILE_MODE_ALL);
    g_IniFile.MachineFile(false);

    theVision.SaveTool(g_IniFile.GetFileNameWithNewExt(Caption.c_str(),"cev").c_str(),"Dummy");


    SaveProduct();

 
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::FormCreate(TObject *Sender)
{
    fmShowNow = new TfmShowNow(this);
    g_pMainThread=new CMainThread(false);

    g_IniFile.MachineFile(true);
    g_IniFile.ProductFile(g_IniFile.m_strLastFileName.c_str(),true,FILE_MODE_ALL);

    Caption=g_IniFile.m_strLastFileName;

    theVision.m_bShowMarkROI[0]=false;
    theVision.m_bShowMarkROI[1]=false;
    theVision.m_bShowMarkROI[2]=false;

    //ftp Map
    ftpMap->Vendor = NMOS_AUTO;
    ftpMap->Host=g_IniFile.m_strMapFtpIP;
    ftpMap->UserID=g_IniFile.m_strMapFtpUserName;
    ftpMap->Password=g_IniFile.m_strMapFtpPassword;

    //socket IP
    clientVenderID->Address=g_IniFile.m_strVenderID_IP;
    clientLaserID->Address=g_IniFile.m_strLaserID_IP;
    clientCoverID->Address=g_IniFile.m_strCoverID_IP;
    clientBoatID->Address=g_IniFile.m_strBoatID_IP;

    //clientVenderID->Active=true;
    clientLaserID->Active=true;     //SBT Up
    clientCoverID->Active=true;     //SBT Down
    //clientBoatID->Active=true;

    serverSMS->Port=g_IniFile.m_nSMSServerPort;
    serverSMS->Active=true;

    clientSMS->Address=g_IniFile.m_strSMSClientIP;
    clientSMS->Port=g_IniFile.m_nSMSClientPort;

    g_SMSXML.m_strMachineID=g_IniFile.m_strSMSMachineID;
    g_SMSXML.m_strUserID=g_IniFile.m_strSMSUserID;
    g_SMSXML.m_strPartNo=g_IniFile.m_strSMSPartNo;
    g_SMSXML.m_strLotNo=g_IniFile.m_strSMSLotNo;

    GetVersion();

    if(!g_Laser.OpenPort(1)) ShowMessage("開啟雷射通訊 COM1 失敗");

    g_LED.OpenPort(2);

    SetLEDDimmer();

    theVision.LoadTool(g_IniFile.GetFileNameWithNewExt(Caption.c_str(),"cev").c_str(),"Dummy");

    PageControl1->ActivePage=tabInfo;

    LoadProduct();
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::GetVersion()
{
  void *pValue;
  int n;
  DWORD infoHandle;
  unsigned int len;
  AnsiString exeName, tmpStr;

  exeName = Application->ExeName.c_str();
  n = GetFileVersionInfoSize( exeName.c_str(), &infoHandle );

  if(n>0)
  {
    char *pBuf = (char *) malloc(n);

    GetFileVersionInfo( exeName.c_str(), infoHandle, n, pBuf );
    VerQueryValue( pBuf, "\\VarFileInfo\\Translation", &pValue, &len );

    tmpStr = (AnsiString)"\\StringFileInfo\\" + IntToHex( *((__int16 *)pValue), 4 ) + IntToHex( *((__int16 *)pValue+1), 4 ) + "\\FileVersion";

    if ( VerQueryValue( pBuf, tmpStr.c_str(), &pValue, &len) )
        Version1->Caption =(AnsiString)"Ver:"+(char *)pValue;

    free(pBuf);
  }
  else Version1->Caption="[Ver 0.0.0.0]";
} 

//---------------------------------------------------------------------------

void __fastcall TfmMain::btnIOCheckClick(TObject *Sender)
{
        TIOCheckDlg *pIOCheckDlg=new TIOCheckDlg(this);

        //CreateCaptionFile(pIOCheckDlg);
        this->ReadCaptionFile(pIOCheckDlg);
        pIOCheckDlg->ShowModal();
        delete pIOCheckDlg;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnMotorCheckClick(TObject *Sender)
{
    TfrmChoiceMotor *pChoiceMotorDlg=new TfrmChoiceMotor(this);
    TfrmMotorCheck *pMotorCheckDlg;

    AnsiString sPath = ExtractFilePath(Application->ExeName);
    sPath = StringReplace(sPath, "\\exe\\", "",TReplaceFlags());

    while(pChoiceMotorDlg->ShowModal()!=mrCancel)
    {
        pMotorCheckDlg=new TfrmMotorCheck(this);

        //Change Arrow Glyph
        if (pChoiceMotorDlg->m_nSelectAxis == 4 || pChoiceMotorDlg->m_nSelectAxis == 5)
        {
                int nRWDLeft = pMotorCheckDlg->btnRWD->Left;
                int nFWDLeft = pMotorCheckDlg->btnFWD->Left;
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\right.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\left.bmp");
                pMotorCheckDlg->btnFWD->Left = nRWDLeft;
                pMotorCheckDlg->btnRWD->Left = nFWDLeft;
        }
        else if (pChoiceMotorDlg->m_nSelectAxis == 6)
        {
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
        }
        else if (pChoiceMotorDlg->m_nSelectAxis == 7)
        {
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
        }
        else if (pChoiceMotorDlg->m_nSelectAxis == 8)
        {
                pMotorCheckDlg->btnRWD->Glyph->LoadFromFile(sPath+"\\bmp\\up.bmp");
                pMotorCheckDlg->btnFWD->Glyph->LoadFromFile(sPath+"\\bmp\\down.bmp");
        }



        pMotorCheckDlg->m_nActiveAxis=pChoiceMotorDlg->m_nSelectAxis;
        pMotorCheckDlg->Caption=pChoiceMotorDlg->m_strCaption;
        pMotorCheckDlg->ShowModal();
        delete pMotorCheckDlg;
    }
    
    delete pChoiceMotorDlg;        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnExitClick(TObject *Sender)
{
        if(Application->MessageBoxA("確定離開程式?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDCANCEL) return;



  if(Application->MessageBoxA("離開前要存檔嗎?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
  {

    g_IniFile.MachineFile(false);
    g_IniFile.ProductFile(Caption.c_str(),false,FILE_MODE_ALL);

    ShowMessage("檔案儲存完成!");

  } 

  
  exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnMachineParaClick(TObject *Sender)
{
        TfrmMachineParam *pMachineDlg=new TfrmMachineParam(this);

        AnsiString strCtl;
        bool bRead=true;

        for(int nIndex=0;nIndex<10;nIndex++)
        {
        DDX_Float(bRead,g_IniFile.m_dACCSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editAcc%d",nIndex+1)) );
        DDX_Float(bRead,g_IniFile.m_dDECSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editDec%d",nIndex+1)));
        DDX_Float(bRead,g_IniFile.m_dJogSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editJogSpeed%d",nIndex+1)));
        DDX_Float(bRead,g_IniFile.m_dWorkSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editWorkSpeed%d",nIndex+1)));
        }

        DDX_Int(bRead,g_IniFile.m_nImageWidth,pMachineDlg->m_nImageWidth);
        DDX_Float(bRead,g_IniFile.m_dImageAngle,pMachineDlg->m_dImageAngle);

        DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosX[0],pMachineDlg->m_dTableMapCCDPosX0);
        DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosY[0],pMachineDlg->m_dTableMapCCDPosY0);
        DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosX[1],pMachineDlg->m_dTableMapCCDPosX1);
        DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosY[1],pMachineDlg->m_dTableMapCCDPosY1);

        DDX_Float(bRead,g_IniFile.m_dTableMapCCDPitch,pMachineDlg->m_dTableMapCCDPitch);
        DDX_Check(bRead,g_IniFile.m_bForceEject,pMachineDlg->m_bForceEject);

        DDX_Float(bRead,g_IniFile.m_dFMCCDResolution[0],pMachineDlg->m_dFMCCDResolution0);
        DDX_Float(bRead,g_IniFile.m_dFMCCDResolution[1],pMachineDlg->m_dFMCCDResolution1);

        DDX_String(bRead,g_IniFile.m_strSMSServerIP,pMachineDlg->m_strSMSServerIP);
        DDX_String(bRead,g_IniFile.m_strSMSClientIP,pMachineDlg->m_strSMSClientIP);
        DDX_Int(bRead,g_IniFile.m_nSMSServerPort,pMachineDlg->m_nSMSServerPort);
        DDX_Int(bRead,g_IniFile.m_nSMSClientPort,pMachineDlg->m_nSMSClientPort);

        DDX_Int(bRead,g_IniFile.m_nCoverVacTime,pMachineDlg->m_nCoverVacTime);
        DDX_Int(bRead,g_IniFile.m_nSubstrateVacTime,pMachineDlg->m_nSubstrateVacTime);
        DDX_Int(bRead,g_IniFile.m_nLoadingAlarmTime,pMachineDlg->m_nLoadingAlarmTime);

        DDX_Float(bRead,g_IniFile.m_dSSPickerPickPos,pMachineDlg->m_dSSPickerPickPos);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPickRailPos,pMachineDlg->m_dSSPickerPickRailPos);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[0],pMachineDlg->m_dSSPickerPutPos0);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[1],pMachineDlg->m_dSSPickerPutPos1);
        DDX_Float(bRead,g_IniFile.m_dSpaPickerPickPos,pMachineDlg->m_dSpaPickerPickPos);
        DDX_Float(bRead,g_IniFile.m_dSpaPickerThrowPos,pMachineDlg->m_dSpaPickerThrowPos);

        DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[0],pMachineDlg->m_dTablePutDownPos0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[0],pMachineDlg->m_dTableMarkPosX0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[0],pMachineDlg->m_dTableMarkPosY0);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[0],pMachineDlg->m_dTableVenderCodePosX0);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[0],pMachineDlg->m_dTableVenderCodePosY0);
        DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[1],pMachineDlg->m_dTablePutDownPos1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[1],pMachineDlg->m_dTableMarkPosX1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[1],pMachineDlg->m_dTableMarkPosY1);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[1],pMachineDlg->m_dTableVenderCodePosX1);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[1],pMachineDlg->m_dTableVenderCodePosY1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[0],pMachineDlg->m_dTableMarkPos2X0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[0],pMachineDlg->m_dTableMarkPos2Y0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[1],pMachineDlg->m_dTableMarkPos2X1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[1],pMachineDlg->m_dTableMarkPos2Y1);

        DDX_Float(bRead,g_IniFile.m_dTableLaserPos[0],pMachineDlg->m_dTableLaserPos0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[0],pMachineDlg->m_dTableLaserCodePosX0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[0],pMachineDlg->m_dTableLaserCodePosY0);
        DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[0],pMachineDlg->m_dTablePickUpPos0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserPos[1],pMachineDlg->m_dTableLaserPos1);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[1],pMachineDlg->m_dTableLaserCodePosX1);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[1],pMachineDlg->m_dTableLaserCodePosY1);
        DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[1],pMachineDlg->m_dTablePickUpPos1);

        DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[0],pMachineDlg->m_dSCPickerPickSSPosY0);
        DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[1],pMachineDlg->m_dSCPickerPickSSPosY1);

        DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[0],pMachineDlg->m_editLaserCodeReaderPos0);
        DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[1],pMachineDlg->m_editLaserCodeReaderPos1);

        DDX_Float(bRead,g_IniFile.m_dSBTNGBoxPos,pMachineDlg->m_editSBTNGBoxPos);
        DDX_Float(bRead,g_IniFile.m_dSCPickerPutSSPos,pMachineDlg->m_editSCPickerPutSSPos);

        if(pMachineDlg->ShowModal()==mrOk)
        {
                bRead=false;
                
                for(int nIndex=0;nIndex<10;nIndex++)
                {
                DDX_Float(bRead,g_IniFile.m_dACCSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editAcc%d",nIndex+1)) );
                DDX_Float(bRead,g_IniFile.m_dDECSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editDec%d",nIndex+1)));
                DDX_Float(bRead,g_IniFile.m_dJogSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editJogSpeed%d",nIndex+1)));
                DDX_Float(bRead,g_IniFile.m_dWorkSpeed[nIndex],(TEdit *)pMachineDlg->FindComponent(strCtl.sprintf("editWorkSpeed%d",nIndex+1)));
                }

                DDX_Int(bRead,g_IniFile.m_nImageWidth,pMachineDlg->m_nImageWidth);
                DDX_Float(bRead,g_IniFile.m_dImageAngle,pMachineDlg->m_dImageAngle);

                DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosX[0],pMachineDlg->m_dTableMapCCDPosX0);                 
                DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosY[0],pMachineDlg->m_dTableMapCCDPosY0);                 
                DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosX[1],pMachineDlg->m_dTableMapCCDPosX1);                 
                DDX_Float(bRead,g_IniFile.m_dTableMapCCDPosY[1],pMachineDlg->m_dTableMapCCDPosY1);                 
                                                                                                                   
                DDX_Float(bRead,g_IniFile.m_dTableMapCCDPitch,pMachineDlg->m_dTableMapCCDPitch);
                DDX_Check(bRead,g_IniFile.m_bForceEject,pMachineDlg->m_bForceEject);

                DDX_Float(bRead,g_IniFile.m_dFMCCDResolution[0],pMachineDlg->m_dFMCCDResolution0);
                DDX_Float(bRead,g_IniFile.m_dFMCCDResolution[1],pMachineDlg->m_dFMCCDResolution1);

                DDX_Int(bRead,g_IniFile.m_nSMSServerPort,pMachineDlg->m_nSMSServerPort);
                DDX_Int(bRead,g_IniFile.m_nSMSClientPort,pMachineDlg->m_nSMSClientPort);

                DDX_Int(bRead,g_IniFile.m_nCoverVacTime,pMachineDlg->m_nCoverVacTime);
                DDX_Int(bRead,g_IniFile.m_nSubstrateVacTime,pMachineDlg->m_nSubstrateVacTime);
                DDX_Int(bRead,g_IniFile.m_nLoadingAlarmTime,pMachineDlg->m_nLoadingAlarmTime);

                DDX_Float(bRead,g_IniFile.m_dSSPickerPickPos,pMachineDlg->m_dSSPickerPickPos);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPickRailPos,pMachineDlg->m_dSSPickerPickRailPos);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[0],pMachineDlg->m_dSSPickerPutPos0);
        DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[1],pMachineDlg->m_dSSPickerPutPos1);
        DDX_Float(bRead,g_IniFile.m_dSpaPickerPickPos,pMachineDlg->m_dSpaPickerPickPos);
        DDX_Float(bRead,g_IniFile.m_dSpaPickerThrowPos,pMachineDlg->m_dSpaPickerThrowPos);

        DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[0],pMachineDlg->m_dTablePutDownPos0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[0],pMachineDlg->m_dTableMarkPosX0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[0],pMachineDlg->m_dTableMarkPosY0);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[0],pMachineDlg->m_dTableVenderCodePosX0);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[0],pMachineDlg->m_dTableVenderCodePosY0);
        DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[1],pMachineDlg->m_dTablePutDownPos1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[1],pMachineDlg->m_dTableMarkPosX1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[1],pMachineDlg->m_dTableMarkPosY1);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[1],pMachineDlg->m_dTableVenderCodePosX1);
        DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[1],pMachineDlg->m_dTableVenderCodePosY1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[0],pMachineDlg->m_dTableMarkPos2X0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[0],pMachineDlg->m_dTableMarkPos2Y0);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[1],pMachineDlg->m_dTableMarkPos2X1);
        DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[1],pMachineDlg->m_dTableMarkPos2Y1);

        DDX_Float(bRead,g_IniFile.m_dTableLaserPos[0],pMachineDlg->m_dTableLaserPos0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[0],pMachineDlg->m_dTableLaserCodePosX0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[0],pMachineDlg->m_dTableLaserCodePosY0);
        DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[0],pMachineDlg->m_dTablePickUpPos0);
        DDX_Float(bRead,g_IniFile.m_dTableLaserPos[1],pMachineDlg->m_dTableLaserPos1);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[1],pMachineDlg->m_dTableLaserCodePosX1);
        DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[1],pMachineDlg->m_dTableLaserCodePosY1);
        DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[1],pMachineDlg->m_dTablePickUpPos1);

        DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[0],pMachineDlg->m_dSCPickerPickSSPosY0);
        DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[1],pMachineDlg->m_dSCPickerPickSSPosY1);

        DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[0],pMachineDlg->m_editLaserCodeReaderPos0);
        DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[1],pMachineDlg->m_editLaserCodeReaderPos1);

        DDX_Float(bRead,g_IniFile.m_dSBTNGBoxPos,pMachineDlg->m_editSBTNGBoxPos);
        DDX_Float(bRead,g_IniFile.m_dSCPickerPutSSPos,pMachineDlg->m_editSCPickerPutSSPos);


                serverSMS->Active=false;
                serverSMS->Port=g_IniFile.m_nSMSServerPort;
                serverSMS->Active=true;

                clientSMS->Active=false;
                clientSMS->Address=g_IniFile.m_strSMSClientIP;
                clientSMS->Port=g_IniFile.m_nSMSClientPort;



        }                                                                                                          
                                                                                                                   
}                                                                                                                  
//---------------------------------------------------------------------------
                                                                                                                   
                                                                                                                   
void __fastcall TfmMain::btnProductParaClick(TObject *Sender)                                                      
{                                                                                                                  
        TfrmProductParam *pWnd=new TfrmProductParam(this);
                                                                                                                   
        bool bRead=true;                                                                                                          
                                                                                                                   
        DDX_Int(bRead,g_IniFile.m_nPackageX,pWnd->m_nPackageX);
        DDX_Int(bRead,g_IniFile.m_nPackageY,pWnd->m_nPackageY);
        DDX_Int(bRead,g_IniFile.m_nDeviceX,pWnd->m_nDeviceX);
        DDX_Int(bRead,g_IniFile.m_nDeviceY,pWnd->m_nDeviceY);
        DDX_Int(bRead,g_IniFile.m_nDeviceY,pWnd->m_nDeviceY);                                                      
                                                                                                                   
        DDX_Int(bRead,g_IniFile.m_nPackageGap,pWnd->m_nPackageGap);
         DDX_Check(bRead,g_IniFile.m_bFindOKMark,pWnd->m_bFindOKMark);                                                
                                                                                                                   
        pWnd->m_dMarkScore0->Text=FormatFloat("0.00",theVision.m_markMatch[0].GetMinScore());
        pWnd->m_dMarkScore1->Text=FormatFloat("0.00",theVision.m_markMatch[1].GetMinScore());
        pWnd->m_dMarkScore2->Text=FormatFloat("0.00",theVision.m_markMatch[2].GetMinScore());
                                                                                                                   
        DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[0],pWnd->m_nLaserProgramNo0);
        DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[1],pWnd->m_nLaserProgramNo1);
        pWnd->UpDown1->Position=g_IniFile.m_nLaserProgramNo[0];
        pWnd->UpDown2->Position=g_IniFile.m_nLaserProgramNo[1];

        DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[2],pWnd->m_nLaserProgramNo2);
        DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[3],pWnd->m_nLaserProgramNo3);
        pWnd->UpDown3->Position=g_IniFile.m_nLaserProgramNo[2];
        pWnd->UpDown4->Position=g_IniFile.m_nLaserProgramNo[3];
        

        DDX_String(bRead,g_IniFile.m_strScheduleNo,pWnd->m_strScheduleNo);
        DDX_Int(bRead,g_IniFile.m_nSubLotSize,pWnd->m_nSubLotSize);

        pWnd->trackLED0->Position=g_IniFile.m_nLEDDimmer[0];
        pWnd->trackLED1->Position=g_IniFile.m_nLEDDimmer[1];

        DDX_String(bRead,g_IniFile.m_strSBTType,pWnd->m_strSBTType);
        DDX_String(bRead,g_IniFile.m_strSBTSize,pWnd->m_strSBTSize);

        DDX_Radio(bRead,g_IniFile.m_nSBTCorner,pWnd->m_nSBTCorner);

        DDX_Radio(bRead,g_IniFile.m_nSBTColWord,pWnd->m_nSBTColWord);
        DDX_Radio(bRead,g_IniFile.m_nSBTRowWord,pWnd->m_nSBTRowWord);

        if(pWnd->ShowModal()==mrOk)
        {                                                                                                                           
                bRead=false;                                                                                                        
                DDX_Int(bRead,g_IniFile.m_nPackageX,pWnd->m_nPackageX);                                                             
                DDX_Int(bRead,g_IniFile.m_nPackageY,pWnd->m_nPackageY);                                                             
                DDX_Int(bRead,g_IniFile.m_nDeviceX,pWnd->m_nDeviceX);                                                               
                DDX_Int(bRead,g_IniFile.m_nDeviceY,pWnd->m_nDeviceY);
                DDX_Int(bRead,g_IniFile.m_nPackageGap,pWnd->m_nPackageGap);                                                         

                DDX_Check(bRead,g_IniFile.m_bFindOKMark,pWnd->m_bFindOKMark);

                theVision.m_markMatch[0].SetMinScore(pWnd->m_dMarkScore0->Text.ToDouble());
                theVision.m_markMatch[1].SetMinScore(pWnd->m_dMarkScore1->Text.ToDouble());
                theVision.m_markMatch[2].SetMinScore(pWnd->m_dMarkScore2->Text.ToDouble());

                DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[0],pWnd->m_nLaserProgramNo0);
                DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[1],pWnd->m_nLaserProgramNo1);
                DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[2],pWnd->m_nLaserProgramNo2);
                DDX_Int(bRead,g_IniFile.m_nLaserProgramNo[3],pWnd->m_nLaserProgramNo3);



                DDX_String(bRead,g_IniFile.m_strScheduleNo,pWnd->m_strScheduleNo);
                DDX_Int(bRead,g_IniFile.m_nSubLotSize,pWnd->m_nSubLotSize);

                DDX_String(bRead,g_IniFile.m_strSBTType,pWnd->m_strSBTType);
                DDX_String(bRead,g_IniFile.m_strSBTSize,pWnd->m_strSBTSize);
                DDX_Radio(bRead,g_IniFile.m_nSBTCorner,pWnd->m_nSBTCorner);

                DDX_Radio(bRead,g_IniFile.m_nSBTColWord,pWnd->m_nSBTColWord);
                DDX_Radio(bRead,g_IniFile.m_nSBTRowWord,pWnd->m_nSBTRowWord);

                g_IniFile.m_nLEDDimmer[0]=pWnd->trackLED0->Position;
                g_IniFile.m_nLEDDimmer[1]=pWnd->trackLED1->Position;

                SetLEDDimmer();


        }



        RefreshImage();

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnPriviledgeClick(TObject *Sender)
{
        TfmPrivilege *pDlg=new TfmPrivilege(this);
    TfrmPassword *pPwdDlg=new TfrmPassword(this);
    int nD=pDlg->ShowModal()-1;
    delete pDlg;

    switch(nD)
    {
        case 1:
        case 2:
            pPwdDlg->labelOldPassword->Caption="請輸入密碼";
            pPwdDlg->labelNewPassword->Visible=false;
            pPwdDlg->editNewPassword->Visible=false;
            if(pPwdDlg->ShowModal()==mrOk)
            {
                if(pPwdDlg->editOldPassword->Text==g_IniFile.m_strENGPassword) m_nUserLevel=1;
                else if(pPwdDlg->editOldPassword->Text==g_IniFile.m_strARTPassword) m_nUserLevel=2;
                else {Application->MessageBox("密碼錯誤!!", "錯誤", MB_OK);m_nUserLevel=0;}
             }
             SetPrivilege(m_nUserLevel);
             break;
        case 0:
                m_nUserLevel=0;
            SetPrivilege(0);
            break;
        case 3:
            if(pPwdDlg->ShowModal()==mrOk)
            {
                if(pPwdDlg->editOldPassword->Text==g_IniFile.m_strENGPassword)
                    g_IniFile.m_strENGPassword=pPwdDlg->editNewPassword->Text;
            }
            break;
    }

    delete pPwdDlg;        
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SetPrivilege(int nLevel)
{
    switch(nLevel)
    {
        case 0:
            Parameter1->Enabled=false;
            Operate1->Enabled=false;
            Exit1->Enabled=false;

            PageControl1->ActivePage=tabInfo;

            break;
        case 1:
            Parameter1->Enabled=true;
            Operate1->Enabled=true;
            Exit1->Enabled=true;

            break;
        case 2:
            Parameter1->Enabled=true;
            Operate1->Enabled=true;
            Exit1->Enabled=true;

        break;
    }


}
//---------------------------------------------------------------------------  

void __fastcall TfmMain::btnMotorManulClick(TObject *Sender)
{
        if(AxisMoveCheck())
        {
                TfmManual *pWnd=new TfmManual(this);
                bool bRead=true;
                
                DDX_Float(bRead,g_IniFile.m_dSSPickerPickPos,pWnd->m_dSSPickerPickPos);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPickRailPos,pWnd->m_dSSPickerPickRailPos);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[0],pWnd->m_dSSPickerPutPos0);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[1],pWnd->m_dSSPickerPutPos1);
                DDX_Float(bRead,g_IniFile.m_dSpaPickerPickPos,pWnd->m_dSpaPickerPickPos);
                DDX_Float(bRead,g_IniFile.m_dSpaPickerThrowPos,pWnd->m_dSpaPickerThrowPos);

                DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[0],pWnd->m_dTablePutDownPos0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[0],pWnd->m_dTableMarkPosX0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[0],pWnd->m_dTableMarkPosY0);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[0],pWnd->m_dTableVenderCodePosX0);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[0],pWnd->m_dTableVenderCodePosY0);
                DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[1],pWnd->m_dTablePutDownPos1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[1],pWnd->m_dTableMarkPosX1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[1],pWnd->m_dTableMarkPosY1);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[1],pWnd->m_dTableVenderCodePosX1);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[1],pWnd->m_dTableVenderCodePosY1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[0],pWnd->m_dTableMarkPos2X0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[0],pWnd->m_dTableMarkPos2Y0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[1],pWnd->m_dTableMarkPos2X1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[1],pWnd->m_dTableMarkPos2Y1);

                DDX_Float(bRead,g_IniFile.m_dTableLaserPos[0],pWnd->m_dTableLaserPos0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[0],pWnd->m_dTableLaserCodePosX0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[0],pWnd->m_dTableLaserCodePosY0);
                DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[0],pWnd->m_dTablePickUpPos0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserPos[1],pWnd->m_dTableLaserPos1);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[1],pWnd->m_dTableLaserCodePosX1);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[1],pWnd->m_dTableLaserCodePosY1);
                DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[1],pWnd->m_dTablePickUpPos1);

                DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[0],pWnd->m_dSCPickerPickSSPosY0);
                DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[1],pWnd->m_dSCPickerPickSSPosY1);

                DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[0],pWnd->m_editLaserCodeReaderPos0);
                DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[1],pWnd->m_editLaserCodeReaderPos1);

                DDX_Float(bRead,g_IniFile.m_dSBTNGBoxPos,pWnd->m_editSBTNGBoxPos);
                DDX_Float(bRead,g_IniFile.m_dSCPickerPutSSPos,pWnd->m_editSCPickerPutSSPos);


                if(pWnd->ShowModal()==mrOk)
                {
                        if(Application->MessageBoxA("確定要儲存修改數據?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDCANCEL) return;
                        bRead=false;

                DDX_Float(bRead,g_IniFile.m_dSSPickerPickPos,pWnd->m_dSSPickerPickPos);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPickRailPos,pWnd->m_dSSPickerPickRailPos);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[0],pWnd->m_dSSPickerPutPos0);
                DDX_Float(bRead,g_IniFile.m_dSSPickerPutPos[1],pWnd->m_dSSPickerPutPos1);
                DDX_Float(bRead,g_IniFile.m_dSpaPickerPickPos,pWnd->m_dSpaPickerPickPos);
                DDX_Float(bRead,g_IniFile.m_dSpaPickerThrowPos,pWnd->m_dSpaPickerThrowPos);

                DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[0],pWnd->m_dTablePutDownPos0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[0],pWnd->m_dTableMarkPosX0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[0],pWnd->m_dTableMarkPosY0);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[0],pWnd->m_dTableVenderCodePosX0);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[0],pWnd->m_dTableVenderCodePosY0);
                DDX_Float(bRead,g_IniFile.m_dTablePutDownPos[1],pWnd->m_dTablePutDownPos1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosX[1],pWnd->m_dTableMarkPosX1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPosY[1],pWnd->m_dTableMarkPosY1);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosX[1],pWnd->m_dTableVenderCodePosX1);
                DDX_Float(bRead,g_IniFile.m_dTableVenderCodePosY[1],pWnd->m_dTableVenderCodePosY1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[0],pWnd->m_dTableMarkPos2X0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[0],pWnd->m_dTableMarkPos2Y0);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2X[1],pWnd->m_dTableMarkPos2X1);
                DDX_Float(bRead,g_IniFile.m_dTableMarkPos2Y[1],pWnd->m_dTableMarkPos2Y1);

                DDX_Float(bRead,g_IniFile.m_dTableLaserPos[0],pWnd->m_dTableLaserPos0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[0],pWnd->m_dTableLaserCodePosX0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[0],pWnd->m_dTableLaserCodePosY0);
                DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[0],pWnd->m_dTablePickUpPos0);
                DDX_Float(bRead,g_IniFile.m_dTableLaserPos[1],pWnd->m_dTableLaserPos1);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosX[1],pWnd->m_dTableLaserCodePosX1);
                DDX_Float(bRead,g_IniFile.m_dTableLaserCodePosY[1],pWnd->m_dTableLaserCodePosY1);
                DDX_Float(bRead,g_IniFile.m_dTablePickUpPos[1],pWnd->m_dTablePickUpPos1);


                DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[0],pWnd->m_dSCPickerPickSSPosY0);
                DDX_Float(bRead,g_IniFile.m_dSCPickerPickSSPosY[1],pWnd->m_dSCPickerPickSSPosY1);

                DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[0],pWnd->m_editLaserCodeReaderPos0);
                DDX_Float(bRead,g_IniFile.m_dLaserCodeReaderPos[1],pWnd->m_editLaserCodeReaderPos1);

                DDX_Float(bRead,g_IniFile.m_dSBTNGBoxPos,pWnd->m_editSBTNGBoxPos);
                DDX_Float(bRead,g_IniFile.m_dSCPickerPutSSPos,pWnd->m_editSCPickerPutSSPos);

                }
        }
} 
//--------------------------------------------------------------------------- 
void __fastcall TfmMain::btnOptionClick(TObject *Sender)
{
        TfmOption *pWnd=new TfmOption(this);

        bool bRead=true;

        DDX_Check(bRead,g_IniFile.m_bIsRailLoad,pWnd->m_bIsRailLoad);
        DDX_Check(bRead,g_IniFile.m_bReadVenderID,pWnd->m_bReadVenderID);

        DDX_Check(bRead,g_IniFile.m_bUseFMCCD,pWnd->m_bUseFMCCD);
        DDX_Check(bRead,g_IniFile.m_bUseFMCCD2,pWnd->m_bUseFMCCD2);
        DDX_Check(bRead,g_IniFile.m_bUseMapCCD,pWnd->m_bUseMapCCD);

        DDX_Check(bRead,g_IniFile.m_bUseLaserMark,pWnd->m_bUseLaserMark);
        DDX_Check(bRead,g_IniFile.m_bUseLaserCodeReader,pWnd->m_bUseLaserCodeReader);

        DDX_Check(bRead,g_IniFile.m_bUseCover,pWnd->m_bUseCover);
        DDX_Check(bRead,g_IniFile.m_bUseBoat,pWnd->m_bUseBoat);
        DDX_Check(bRead,g_IniFile.m_bEAPCoverControl,pWnd->m_bEAPCoverControl);
        DDX_Check(bRead,g_IniFile.m_bEAPBoatControl,pWnd->m_bEAPBoatControl);

        DDX_Check(bRead,g_IniFile.m_bIsSingleSubstrate,pWnd->m_bIsSingleSubstrate);

        DDX_Radio(bRead,g_IniFile.m_nUseTable,pWnd->m_nUseTable);

        DDX_Check(bRead,g_IniFile.m_bUseCoverHolder,pWnd->m_bUseCoverHolder);
        
        DDX_Check(bRead,g_IniFile.m_bShakeSubstarte,pWnd->m_bShakeSubstarte);

        DDX_Check(bRead,g_IniFile.m_bUsePQC,pWnd->m_bUsePQC);

        DDX_Check(bRead,g_IniFile.m_bDoubleSide,pWnd->m_bDoubleSide);

        if(pWnd->ShowModal()==mrOk)
        {
                bRead=false;

                DDX_Check(bRead,g_IniFile.m_bIsRailLoad,pWnd->m_bIsRailLoad);
                DDX_Check(bRead,g_IniFile.m_bReadVenderID,pWnd->m_bReadVenderID);

                DDX_Check(bRead,g_IniFile.m_bUseFMCCD,pWnd->m_bUseFMCCD);
                DDX_Check(bRead,g_IniFile.m_bUseFMCCD2,pWnd->m_bUseFMCCD2);
                DDX_Check(bRead,g_IniFile.m_bUseMapCCD,pWnd->m_bUseMapCCD);

                DDX_Check(bRead,g_IniFile.m_bUseLaserMark,pWnd->m_bUseLaserMark);
                DDX_Check(bRead,g_IniFile.m_bUseLaserCodeReader,pWnd->m_bUseLaserCodeReader);

                DDX_Check(bRead,g_IniFile.m_bUseCover,pWnd->m_bUseCover);
                DDX_Check(bRead,g_IniFile.m_bUseBoat,pWnd->m_bUseBoat);
                DDX_Check(bRead,g_IniFile.m_bEAPCoverControl,pWnd->m_bEAPCoverControl);
                DDX_Check(bRead,g_IniFile.m_bEAPBoatControl,pWnd->m_bEAPBoatControl);

                DDX_Check(bRead,g_IniFile.m_bIsSingleSubstrate,pWnd->m_bIsSingleSubstrate);

                DDX_Radio(bRead,g_IniFile.m_nUseTable,pWnd->m_nUseTable);

                DDX_Check(bRead,g_IniFile.m_bUseCoverHolder,pWnd->m_bUseCoverHolder);

                DDX_Check(bRead,g_IniFile.m_bShakeSubstarte,pWnd->m_bShakeSubstarte);

                DDX_Check(bRead,g_IniFile.m_bUsePQC,pWnd->m_bUsePQC);

                DDX_Check(bRead,g_IniFile.m_bDoubleSide,pWnd->m_bDoubleSide);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::CreateCaptionFile(TForm *pForm)
{ 
        AnsiString strFile;
        TIniFile *pIniFile;

        strFile.sprintf("%s%s","C:\\","Caption_C82.ini");
        pIniFile = new TIniFile(strFile);

        const char *Section=pForm->Name.c_str();

       for(int nIndex=0;nIndex<pForm->ControlCount;nIndex++)
        {

                if(pForm->Controls[nIndex]->ClassNameIs("TToolBar"))
                {
                        for(int nIndex2=0;nIndex2<((TToolBar *)pForm->Controls[nIndex])->ControlCount;nIndex2++)
                        {
                                if(((TToolBar *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TToolButton"))
                                {
                                        AnsiString strCaption=((TToolButton *)((TToolBar *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TToolButton *)((TToolBar *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }
                        }
                }

                if(pForm->Controls[nIndex]->ClassNameIs("TGroupBox"))
                {
                        for(int nIndex2=0;nIndex2<((TGroupBox *)pForm->Controls[nIndex])->ControlCount;nIndex2++)
                        {
                                 AnsiString strCaption=((TGroupBox *)pForm->Controls[nIndex])->Caption;
                                 AnsiString strName=((TGroupBox *)pForm->Controls[nIndex])->Name;

                                 DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                                if(((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TSpeedButton"))
                                {
                                        AnsiString strCaption=((TSpeedButton *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TSpeedButton *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TBitBtn"))
                                {
                                        AnsiString strCaption=((TBitBtn *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TBitBtn *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                 if(((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TCheckBox"))
                                {
                                        AnsiString strCaption=((TCheckBox *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TCheckBox *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TLabel"))
                                {
                                        AnsiString strCaption=((TLabel *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TLabel *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2]->ClassNameIs("TStaticText"))
                                {
                                        AnsiString strCaption=((TStaticText *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Caption;
                                        AnsiString strName=((TStaticText *)((TGroupBox *)pForm->Controls[nIndex])->Controls[nIndex2])->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }
                        }
                }

                if(pForm->Controls[nIndex]->ClassNameIs("TPageControl"))
                {
                        TPageControl *pPage=(TPageControl *)pForm->Controls[nIndex];
                        for(int nIndex2=0;nIndex2<pPage->ControlCount;nIndex2++)
                        {
                                if(pPage->Controls[nIndex2]->ClassNameIs("TTabSheet"))
                                {
                                        TTabSheet *pSheet=(TTabSheet *)pPage->Controls[nIndex2];
                                        AnsiString strCaption=pSheet->Caption;
                                        AnsiString strName=pSheet->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                                        for(int nIndex3=0;nIndex3<pSheet->ControlCount;nIndex3++)
                                        {
                                                if(pSheet->Controls[nIndex3]->ClassNameIs("TStaticText"))
                                                {
                                                        TStaticText *pText=(TStaticText *)pSheet->Controls[nIndex3];
                                                        AnsiString strCaption=pText->Caption;
                                                        AnsiString strName=pText->Name;

                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                }

                                                if(pSheet->Controls[nIndex3]->ClassNameIs("TGroupBox"))
                                                {
                                                        TGroupBox *pGroup=(TGroupBox *)pSheet->Controls[nIndex3];
                                                        AnsiString strCaption=pGroup->Caption;
                                                        AnsiString strName=pGroup->Name;

                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                                                        for(int nIndex4=0;nIndex4<pGroup->ControlCount;nIndex4++)
                                                        {
                                                                if(pGroup->Controls[nIndex4]->ClassNameIs("TStaticText"))
                                                                {
                                                                        TStaticText *pText=(TStaticText *)pGroup->Controls[nIndex4];
                                                                        AnsiString strCaption=pText->Caption;
                                                                        AnsiString strName=pText->Name;

                                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                                }
                                                        }
                                                }

                                                if(pSheet->Controls[nIndex3]->ClassNameIs("TSpeedButton"))
                                                {
                                                        TSpeedButton *pBtn=(TSpeedButton *)pSheet->Controls[nIndex3];
                                                        AnsiString strCaption=pBtn->Caption;
                                                        AnsiString strName=pBtn->Name;

                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                }

                                                if(pSheet->Controls[nIndex3]->ClassNameIs("TPanel"))
                                                {
                                                        TPanel *pPanel=(TPanel *)pSheet->Controls[nIndex3];
                                                        AnsiString strCaption=pPanel->Caption;
                                                        AnsiString strName=pPanel->Name;

                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                }


                                        }
                                }
                        }
                }


                if(pForm->Controls[nIndex]->ClassNameIs("TPanel"))
                {
                        TPanel *pPanel=(TPanel *)pForm->Controls[nIndex];
                        for(int nIndex2=0;nIndex2<pPanel->ControlCount;nIndex2++)
                        {
                                if(pPanel->Controls[nIndex2]->ClassNameIs("TLabel"))
                                {
                                        TLabel *pLabel=(TLabel *)pPanel->Controls[nIndex2];
                                        AnsiString strCaption=pLabel->Caption;
                                        AnsiString strName=pLabel->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(pPanel->Controls[nIndex2]->ClassNameIs("TBitBtn"))
                                {
                                        TBitBtn *pBtn=(TBitBtn *)pPanel->Controls[nIndex2];
                                        AnsiString strCaption=pBtn->Caption;
                                        AnsiString strName=pBtn->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(pPanel->Controls[nIndex2]->ClassNameIs("TStaticText"))
                                {
                                        TStaticText *pTxt=(TStaticText *)pPanel->Controls[nIndex2];
                                        AnsiString strCaption=pTxt->Caption;
                                        AnsiString strName=pTxt->Name;

                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                }

                                if(pPanel->Controls[nIndex2]->ClassNameIs("TPageControl"))
                                {
                                        TPageControl *pPage=(TPageControl *)pPanel->Controls[nIndex2];
                                        for(int nIndex3=0;nIndex3<pPage->ControlCount;nIndex3++)
                                        {
                                                if(pPage->Controls[nIndex3]->ClassNameIs("TTabSheet"))
                                                {
                                                        TTabSheet *pSheet=(TTabSheet *)pPage->Controls[nIndex3];
                                                        AnsiString strCaption=pSheet->Caption;
                                                        AnsiString strName=pSheet->Name;

                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                                                        for(int nIndex4=0;nIndex4<pSheet->ControlCount;nIndex4++)
                                                        {
                                                                if(pSheet->Controls[nIndex4]->ClassNameIs("TSpeedButton"))
                                                                {
                                                                        TSpeedButton *pBtn=(TSpeedButton *)pSheet->Controls[nIndex4];
                                                                        AnsiString strCaption=pBtn->Caption;
                                                                        AnsiString strName=pBtn->Name;

                                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                                }

                                                                if(pSheet->Controls[nIndex4]->ClassNameIs("TPanel"))
                                                                {
                                                                        TPanel *pPanel=(TPanel *)pSheet->Controls[nIndex4];
                                                                        AnsiString strCaption=pPanel->Caption;
                                                                        AnsiString strName=pPanel->Name;

                                                                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }

                if(pForm->Controls[nIndex]->ClassNameIs("TBitBtn"))
                {
                        AnsiString strCaption=((TBitBtn *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TBitBtn *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

                if(pForm->Controls[nIndex]->ClassNameIs("TSpeedButton"))
                {
                        AnsiString strCaption=((TSpeedButton *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TSpeedButton *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

                if(pForm->Controls[nIndex]->ClassNameIs("TButton"))
                {
                        AnsiString strCaption=((TButton *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TButton *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

                if(pForm->Controls[nIndex]->ClassNameIs("TLabel"))
                {
                        AnsiString strCaption=((TLabel *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TLabel *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

                if(pForm->Controls[nIndex]->ClassNameIs("TCheckBox"))
                {
                        AnsiString strCaption=((TLabel *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TLabel *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

                if(pForm->Controls[nIndex]->ClassNameIs("TStaticText"))
                {
                        AnsiString strCaption=((TStaticText *)pForm->Controls[nIndex])->Caption;
                        AnsiString strName=((TStaticText *)pForm->Controls[nIndex])->Name;

                        DDXFile_String(false,pIniFile,Section,strName,strCaption,"NA");

                }

        }

        delete pIniFile;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ReadCaptionFile(TForm *pForm,int nLanguage)
{
        AnsiString strFile;
        TIniFile *pIniFile;

        if(nLanguage>0) strFile.sprintf("%s%s","C:\\","Caption_C82_ENG.ini");
        else strFile.sprintf("%s%s","C:\\","Caption_C82.ini");

        const char *pSection=pForm->Name.c_str();

        pIniFile = new TIniFile(strFile);

        TStringList *TempList = new TStringList;

        pIniFile->ReadSection(pSection,TempList);

        AnsiString strClass;
        AnsiString strName;
        AnsiString strValue;

        for(int nIndex=0;nIndex<TempList->Count;nIndex++)
        {
                strName=TempList->Strings[nIndex];
                strValue=pIniFile->ReadString(pSection,strName,"NA");

                if(!pForm->FindComponent(strName)) continue;
                strClass=pForm->FindComponent(strName)->ClassName();

                if(strClass=="TLabel") ((TLabel *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TToolButton") ((TToolButton *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TSpeedButton") ((TSpeedButton *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TBitBtn") ((TBitBtn *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TGroupBox") ((TGroupBox *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TCheckBox") ((TCheckBox *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TStaticText") ((TStaticText *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TButton") ((TButton *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TTabSheet") ((TTabSheet *)pForm->FindComponent(strName))->Caption=strValue;
                else if(strClass=="TPanel") ((TPanel *)pForm->FindComponent(strName))->Caption=strValue;
                
        }


        delete TempList;
        

        delete pIniFile;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
        g_bStopMainThread=true;
        g_Grabber.StopLive(0);
        g_Grabber.StopLive(1);
        delete fmShowNow;
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::paintMapPaint(TObject *Sender)
{
        int nCols=g_IniFile.m_nDeviceX*g_IniFile.m_nPackageX;
        int nRows=g_IniFile.m_nDeviceY*g_IniFile.m_nPackageY;

        CreateMapArray(paintMap->ClientRect, g_IniFile.m_nPackageX, g_IniFile.m_nPackageY,5,
                                g_IniFile.m_nDeviceX,g_IniFile.m_nDeviceY);

        paintMap->Canvas->Pen->Color=clLime;
        paintMap->Canvas->Brush->Color=clGreen;
        for(int nIndex=0;nIndex<m_vectRect.size();nIndex++)
        {
                if(m_nSubstrateMap[nIndex]==1) paintMap->Canvas->Brush->Color=clGreen; //OK
                else if(m_nSubstrateMap[nIndex]==-1) paintMap->Canvas->Brush->Color=clRed;  //NG
                else if(m_nSubstrateMap[nIndex]==0)paintMap->Canvas->Brush->Color=clGray;    //Empty

              paintMap->Canvas->Rectangle(m_vectRect[nIndex]);
              //paintMap->Canvas->TextOutA(m_vectRect[nIndex].Left+3,m_vectRect[nIndex].top+3,FormatFloat("0",nIndex+1));
              //PaintBox1->Canvas->TextRect(m_rectRectFront[nIndex],1,1,FormatFloat("0",nIndex));

              //Top ABC

              if(nIndex<nCols)
              {
                        AnsiString strText;

                        if(g_IniFile.m_nSBTColWord==0) strText.sprintf("%d",nIndex+1);
                        else if(g_IniFile.m_nSBTColWord==1) strText.sprintf("%d",nCols-nIndex);
                        else if(g_IniFile.m_nSBTColWord==2) strText.sprintf("%C",nIndex+'A');
                        else if(g_IniFile.m_nSBTColWord==3) strText.sprintf("%C",nCols-nIndex+'A'-1);

                        paintMap->Canvas->TextOutA(m_vectRect[nIndex].Right-10,m_vectRect[nIndex].top+3,strText);
              }

              //Left ABC
              if((nIndex % nCols)==0)
              {
                        AnsiString strText;
                        int nCol=nIndex/nCols;

                        if(g_IniFile.m_nSBTRowWord==0) strText.sprintf("%d",nCol+1);
                        else if(g_IniFile.m_nSBTRowWord==1) strText.sprintf("%d",nCols-nCol);
                        else if(g_IniFile.m_nSBTRowWord==2) strText.sprintf("%C",nCol+'A');
                        else if(g_IniFile.m_nSBTRowWord==3) strText.sprintf("%C",nCols-nCol+'A'-1);

                        paintMap->Canvas->TextOutA(m_vectRect[nIndex].Left+3,m_vectRect[nIndex].Bottom-15,strText);
              }

        }

        TPoint points[3];

        //SBT Corner
        switch(g_IniFile.m_nSBTCorner)
        {
        case 0:
                points[0] = TPoint(0,0);
                points[1] = TPoint(20,0);
                points[2] = TPoint(0,20);
                break;
        case 1:
                points[0] = TPoint(paintMap->ClientRect.Right,0);
                points[1] = TPoint(paintMap->ClientRect.Right-20,0);
                points[2] = TPoint(paintMap->ClientRect.Right,20);
                break;
        case 2:
                points[0] = TPoint(0,paintMap->ClientRect.Bottom);
                points[1] = TPoint(20,paintMap->ClientRect.Bottom);
                points[2] = TPoint(0,paintMap->ClientRect.Bottom-20);
                break;
        case 3:
                points[0] = TPoint(paintMap->ClientRect.Right,paintMap->ClientRect.Bottom);
                points[1] = TPoint(paintMap->ClientRect.Right-20,paintMap->ClientRect.Bottom);
                points[2] = TPoint(paintMap->ClientRect.Right,paintMap->ClientRect.Bottom-20);
                break;
        }


        paintMap->Canvas->Pen->Color=clLime;
        paintMap->Canvas->Brush->Color=clBlack;
        paintMap->Canvas->Polygon(points,2);

        //SBT bar
        paintMap->Canvas->Pen->Color=clLime;
        paintMap->Canvas->Brush->Color=clYellow;

        for(int nIndex=0;nIndex<10000;nIndex++)
        {
                if(nIndex*20>paintMap->ClientRect.Right ) break;
                if(g_IniFile.m_nSBTCorner==2 || g_IniFile.m_nSBTCorner==3) paintMap->Canvas->Rectangle(0+nIndex*20,0,10+nIndex*20,5);
                else paintMap->Canvas->Rectangle(0+nIndex*20,paintMap->ClientRect.Bottom,10+nIndex*20,paintMap->ClientRect.Bottom-5);
        }

}
//---------------------------------------------------------------------------
void __fastcall TfmMain::CreateMapArray(TRect &rect,int nPackageX,int nPackageY,int nDeviceGap,int nSectX,int nSectY)
{
        const int nGap=0;

        if(nSectX<=0 || nPackageX<=0 || nSectY<=0 || nPackageY<=0) return;

        //m_nLeftColCnt=nPackageX*nSectX;
        //m_nLeftRowCnt=nPackageY*nSectY;
        int nPitchX;
        int nPitchY;

        nPitchX=(rect.Width()-nDeviceGap*(nPackageX-1))/(nSectX*nPackageX);
        nPitchY=(rect.Height()-nDeviceGap*(nPackageY-1))/(nSectY*nPackageY);


        m_vectRect.clear();

        for(int nY=0;nY<nSectY*nPackageY;nY++)
        //for(int nX=0;nX<nSectX*nPackageX;nX++)
        for(int nX=nSectX*nPackageX-1;nX>=0;nX--)
        {
               m_vectRect.push_back(TRect(rect.right-nPitchX*nX-nPitchX-nGap-(nX/nSectX)*nDeviceGap ,rect.top+nPitchY*nY+nGap+(nY/nSectY)*nDeviceGap,
                        rect.right-nPitchX*nX-nGap-(nX/nSectX)*nDeviceGap,rect.top+nPitchY*nY+nPitchY-nGap+(nY/nSectY)*nDeviceGap));
        }
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::ImagePaintBoxPaint(TObject *Sender)
{
        
        theVision.DrawAll(ImagePaintBox->Canvas->Handle);
        g_bOnRefresh=false;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn6Click(TObject *Sender)
{
        theVision.IncScaleSize();
        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn3Click(TObject *Sender)
{
        theVision.DecScaleSize();
        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn8Click(TObject *Sender)
{

        theVision.SetScaleSize(0.5,0.5);
        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn5Click(TObject *Sender)
{
        theVision.SetScaleSize(1.0,1.0);
        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::Load1Click(TObject *Sender)
{
        int nTag=((TMenuItem *)Sender)->Tag;
        OpenPictureDialog1->DefaultExt="bmp";
        if(OpenPictureDialog1->Execute())
        {
                theVision.m_ImageTmpBW8.Load(OpenPictureDialog1->FileName.c_str());
                theVision.m_ImageSizeX=theVision.m_ImageTmpBW8.GetWidth();
                theVision.m_ImageSizeY=theVision.m_ImageTmpBW8.GetHeight();

                if(nTag>0)
                {
                        theVision.MergeImage(nTag-1,g_IniFile.m_nImageWidth,g_IniFile.m_dImageAngle);
                }
        }

        RefreshImage();        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::Save2Click(TObject *Sender)
{
        SavePictureDialog1->DefaultExt="bmp";
        if(SavePictureDialog1->Execute())
        {
                theVision.m_ImageTmpBW8.Save(SavePictureDialog1->FileName.c_str());
        }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::checkShowSearchROI0Click(TObject *Sender)
{
        TCheckBox *pCheck=(TCheckBox *)Sender;
        
        theVision.m_bShowMarkROI[pCheck->Tag]=pCheck->Checked;
        //pCheck->Checked=!pCheck->Checked;
        RefreshImage();        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::checkShowPatternROI0Click(TObject *Sender)
{
        TCheckBox *pCheck=(TCheckBox *)Sender;

        theVision.m_bShowPatternROI[pCheck->Tag]=pCheck->Checked;
        //pCheck->Checked=!pCheck->Checked;
        RefreshImage();         
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::checkShowLayoutClick(TObject *Sender)
{
        theVision.m_bShowLayout=checkShowLayout->Checked;


        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::checkShowResult0Click(TObject *Sender)
{
        TCheckBox *pCheck=(TCheckBox *)Sender;

        theVision.m_bShowMatchResult[pCheck->Tag]=pCheck->Checked;
        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnGrabClick(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        g_Grabber.Grab(pBtn->Tag);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnLiveClick(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        if(pBtn->Down) g_Grabber.StartLive(pBtn->Tag);
        else g_Grabber.StopLive(pBtn->Tag);        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn7Click(TObject *Sender)
{
        TBitBtn *pBtn=(TBitBtn *)Sender;
        theVision.LearnPatMatch(theVision.m_roiMarkPattern[pBtn->Tag],theVision.m_markMatch[pBtn->Tag]);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnVisionProcessClick(TObject *Sender)
{
        DoVisionProcess();
        RefreshImage();
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::DoVisionProcess()
{
        int  nFounds=0;

        theVision.m_markMatch[0].SetMaxPositions(g_IniFile.m_nDeviceX*g_IniFile.m_nDeviceY*g_IniFile.m_nPackageX*g_IniFile.m_nPackageY);

        nFounds=theVision.FindPatMatch(theVision.m_roiMark[0],theVision.m_markMatch[0]);

        if(nFounds<1)
        {
                //ShowMessage("找不到!!");
                //int nMark=0;

                //g_IniFile.m_bFindOKMark ? nMark=0:nMark=1;

                //memset(m_nSubstrateMap,nMark,sizeof(__int16)*10000);

                for(int nMap=0;nMap<theVision.m_vectRect.size();nMap++)
                         g_IniFile.m_bFindOKMark ? m_nSubstrateMap[nMap]=0:m_nSubstrateMap[nMap]=1;
        }
        else
        {
                for(int nMap=0;nMap<theVision.m_vectRect.size();nMap++)
                {
                        m_nSubstrateMap[nMap]=0;
                        for(int nIndex=0;nIndex<nFounds;nIndex++)
                        {

                                if(PtInRect(theVision.m_vectRect[nMap],TPoint(theVision.GetMatchPosX(nIndex),theVision.GetMatchPosY(nIndex))) )
                                {
                                       g_IniFile.m_bFindOKMark ? m_nSubstrateMap[nMap]=1:m_nSubstrateMap[nMap]=0; //Found
                                       
                                        break;
                                }
                                else g_IniFile.m_bFindOKMark ? m_nSubstrateMap[nMap]=0:m_nSubstrateMap[nMap]=1;
                        }
                }
        }

       //RefreshImage();
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::timerMessageTimer(TObject *Sender)
{
        static int nErrorCode=0;

        timerMessage->Enabled=false;

        //Caption = DateTimeToStr(Now());

        // 20 min SetPrivilege 0 to OP
        if(tm1MSLogOut.timeDevEnd()>1200000)
        {
                SetPrivilege(0);
                tm1MSLogOut.timeDevStart();
        }
        /*if (g_pMainThread->m_bIsAutoMode == true)
        {
                SetPrivilege(0);
                tm1MSLogOut.timeDevStart();
        }*/

        //--Thread Log---
        if(g_pMainThread->m_listLog.size()>0)
        {
                AnsiString strLog=g_pMainThread->m_listLog.front();
                AddActionLog(strLog);
                AddList(strLog);
                g_pMainThread->m_listLog.pop_front();
        }
        //---Vision Log
        if(theVision.m_listLog.size()>0)
        {
                AnsiString strLog=theVision.m_listLog.front();

                AddList(strLog);
                theVision.m_listLog.pop_front();
        }
        if(g_pMainThread->m_listVisionLog.size()>0)
        {
                AnsiString strLog=g_pMainThread->m_listVisionLog.front();
                AddVisionLog(strLog);
                AddList(strLog);
                g_pMainThread->m_listVisionLog.pop_front();
        }
        //---Marker Code
        if (g_pMainThread->m_listMarkerLog.size()>0)
        {
                AnsiString strLog = g_pMainThread->m_listMarkerLog.front();
                AddMarkerLog(strLog);
                AddList(strLog);
                g_pMainThread->m_listMarkerLog.pop_front();
        }
        //---Error Code
	    if(g_IniFile.m_nErrorCode>0 && (nErrorCode!=g_IniFile.m_nErrorCode))
	    {
                AnsiString strMsg=g_IniFile.GetErrorString("SYSTEM",g_IniFile.m_nErrorCode);
                AddErrorLog(strMsg);
                AddList(strMsg);
	    }


        if(g_DIO.GetDO(DO::Buzzer)) listHistory->Color=clRed;
        else listHistory->Color=clBlack;

        //----Motion
        if(!g_pMainThread->m_bIsAutoMode)
        {

        }

        //---Refresh
        if(g_pMainThread->m_bRefresh)
        {

                g_pMainThread->m_bRefresh=false;
        }

        nErrorCode=g_IniFile.m_nErrorCode;

        if(g_pMainThread->m_bStopLoad) SpeedButton9->Down=true;

        //show Option status
        this->m_bIsRailLoad->Checked = g_IniFile.m_bIsRailLoad;
        this->m_bShakeSubstarte->Checked = g_IniFile.m_bShakeSubstarte;
        this->m_bUseFMCCD->Checked = g_IniFile.m_bUseFMCCD;
        this->m_bUseFMCCD2->Checked = g_IniFile.m_bUseFMCCD2;
        this->m_bUseLaserMark->Checked = g_IniFile.m_bUseLaserMark;
        this->m_bDoubleSide->Checked = g_IniFile.m_bDoubleSide;
        this->m_bUseLaserCodeReader->Checked = g_IniFile.m_bUseLaserCodeReader;

        //Synchronize MainForm Object
        ScrollBox1->Height = Splitter1->Top;
        PageControl1->Width = Panel2->Width-20;
        listMarkerLog->Width = tabMarker->Width-50;
        listActionLog->Width = tabAction->Width-50;
        listErrorLog->Width = tabError->Width-50;

        //change listbox behavior create herizontal scrollbar
        int maxwidth = 0;
        const int border = 3;
        if (listMarkerLog->Items->Count>0)
        {
            for(int ii=0;ii<listMarkerLog->Items->Count;ii++)
            {
                String text = listMarkerLog->Items->Strings[ii];
                //int width = listMarkerLog->Canvas->TextWidth(text);
                int width = listMarkerLog->Items->Strings[ii].Length();
                if(width >maxwidth) maxwidth = width;
            }
            //SendMessage(listMarkerLog->Handle, LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
            listMarkerLog->Perform(LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
        }
        maxwidth = 0;
        if (listActionLog->Items->Count>0)
        {
            for(int ii=0;ii<listActionLog->Items->Count;ii++)
            {
                String text = listActionLog->Items->Strings[ii];
                //int width = listActionLog->Canvas->TextWidth(text);
                int width = listActionLog->Items->Strings[ii].Length();
                if(width >maxwidth) maxwidth = width;
            }
            //SendMessage(listActionLog->Handle, LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
            listActionLog->Perform(LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
        }
        maxwidth = 0;
        if (listErrorLog->Items->Count>0)
        {
            for(int ii=0;ii<listErrorLog->Items->Count;ii++)
            {
                String text = listErrorLog->Items->Strings[ii];
                //int width = listErrorLog->Canvas->TextWidth(text);
                int width = listErrorLog->Items->Strings[ii].Length();
                if(width >maxwidth) maxwidth = width;
            }
            //SendMessage(listErrorLog->Handle, LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
            listErrorLog->Perform(LB_SETHORIZONTALEXTENT, 8*maxwidth+2*border,0);
        }

        timerMessage->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::AddList(AnsiString strMessage)
{
        //listHistory->AddItem(TimeToStr(Time())+"-->"+strMessage,NULL);    
        listHistory->AddItem(DateTimeToStr(Now())+"--->"+strMessage,NULL);
        listHistory->ItemIndex=listHistory->Count-1;


        g_IniFile.AddLog(strMessage.c_str(),strMessage.Length());

}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddVisionLog(AnsiString strLog)
{
        listVisionLog->AddItem(strLog,NULL);
        listVisionLog->ItemIndex=listVisionLog->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddMarkerLog(AnsiString strLog)
{
        listMarkerLog->AddItem(DateTimeToStr(Now())+"--->"+strLog,NULL);
        listMarkerLog->ItemIndex=listMarkerLog->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddActionLog(AnsiString strLog)
{
        listActionLog->AddItem(DateTimeToStr(Now())+"--->"+strLog,NULL);
        listActionLog->ItemIndex=listActionLog->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::AddErrorLog(AnsiString strLog)
{
        listErrorLog->AddItem(DateTimeToStr(Now())+"--->"+strLog,NULL);
        listErrorLog->ItemIndex=listErrorLog->Count-1;
}

//---------------------------------------------------------------------------
void __fastcall TfmMain::timerCommTimer(TObject *Sender)
{
        if(g_pMainThread->m_listTX.size()>0 )
        {
                bool bRet;
                AnsiString strCommand=g_pMainThread->m_listTX.front();
                 g_pMainThread->m_listTX.pop_front();
                AddList(strCommand);

                AnsiString strCMD;
                strCMD.sprintf("TRIG%c",0x0d);

                char *strOpenLaserCMD[]={"OPEN_LASER_REAR_UP","OPEN_LASER_FRONT_UP","OPEN_LASER_REAR_DOWN","OPEN_LASER_FRONT_DOWN"};
                char *strSetOffsetLaserCMD[]={"SET_LASER_OFFSET_REAR_UP","SET_LASER_OFFSET_FRONT_UP","SET_LASER_OFFSET_REAR_DOWN","SET_LASER_OFFSET_FRONT_DOWN"};
                char *strReSetOffsetLaserCMD[]={"RESET_LASER_OFFSET_REAR_UP","RESET_LASER_OFFSET_FRONT_UP","RESET_LASER_OFFSET_REAR_DOWN","RESET_LASER_OFFSET_FRONT_DOWN"};

                if(strCommand=="VENDER_TRIG")
                {
                        //if(serverVenderID->Socket->Connected) serverVenderID->Socket->Connections[0]->SendText("TRIG");
                        if(clientVenderID->Socket->Connected) clientVenderID->Socket->SendText(strCMD);
                        else AddList("基板2D讀取器沒有連線");

                        //g_pMainThread->m_listTX.pop_front();
                }

                if(strCommand=="UP_LASER_READER_TRIG")
                {
                        //if(serverLaserID->Socket->Connected) serverLaserID->Socket->Connections[0]->SendText("TRIG");
                        if(clientLaserID->Socket->Connected) clientLaserID->Socket->SendText(strCMD);
                        else AddList("(上)雷刻完2D讀取器沒有連線");

                        //g_pMainThread->m_listTX.pop_front();
                }

                if(strCommand=="DOWN_LASER_READER_TRIG")
                {
                        //if(serverLaserID->Socket->Connected) serverLaserID->Socket->Connections[0]->SendText("TRIG");
                        if(clientCoverID->Socket->Connected) clientCoverID->Socket->SendText(strCMD);
                        else AddList("(下)雷刻完2D讀取器沒有連線");

                        //g_pMainThread->m_listTX.pop_front();
                }


                if(strCommand=="PROCESS_MAP_FRONT")
                {
                        btnVisionProcessClick(btnVisionProcess);         //do vision process
                        //g_pMainThread->m_listTX.pop_front();

                        //export
                        ExportMapFileTmp(true);

                        g_pMainThread->m_listVisionRX.push_back("PROCESS_MAP_DONE");
                }

                if(strCommand=="PROCESS_MAP_REAR")
                {
                        btnVisionProcessClick(btnVisionProcess);         //do vision process
                        //g_pMainThread->m_listTX.pop_front();

                        //export
                        ExportMapFileTmp(false);

                        g_pMainThread->m_listVisionRX.push_back("PROCESS_MAP_DONE");
                }

                for(int nIndex=0;nIndex<4;nIndex++)
                {
                        if(strCommand==strOpenLaserCMD[nIndex])
                        {
                                bRet=g_Laser.OpenProgram(g_IniFile.m_nLaserProgramNo[nIndex]);
                                //bRet=true;
                                if(bRet) g_pMainThread->m_listLaserRX.push_back("OPEN_LASER_OK");
                                else g_pMainThread->m_listLaserRX.push_back("OPEN_LASER_NG");

                         //g_pMainThread->m_listTX.pop_front();
                        }

                        if(strCommand==strSetOffsetLaserCMD[nIndex])
                        {
                                //Set Text
                                bRet=g_Laser.SetText(g_IniFile.m_nLaserProgramNo[nIndex],0,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
                                bRet=g_Laser.SetText(g_IniFile.m_nLaserProgramNo[nIndex],2,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
                                //Set Offset
                                bRet=g_Laser.SetToolPosOffset(g_IniFile.m_nLaserProgramNo[nIndex],g_pMainThread->m_tmpProductInfo[nIndex % 2].m_nOffsetX,g_pMainThread->m_tmpProductInfo[nIndex % 2].m_nOffsetY,g_pMainThread->m_tmpProductInfo[nIndex % 2].m_dOffsetAngle);
                                // bRet=true;
                                if(bRet) g_pMainThread->m_listLaserRX.push_back("SET_LASER_OFFSET_OK");
                                else g_pMainThread->m_listLaserRX.push_back("SET_LASER_OFFSET_NG");

                                //g_pMainThread->m_listTX.pop_front();
                        }

                        if(strCommand==strReSetOffsetLaserCMD[nIndex])
                        {
                                //Set Offset
                                bRet=g_Laser.SetToolPosOffset(g_IniFile.m_nLaserProgramNo[nIndex % 2],0.0,0.0,0.0);
                                // bRet=true;
                                if(bRet) g_pMainThread->m_listLaserRX.push_back("RESET_LASER_OFFSET_OK");
                                else g_pMainThread->m_listLaserRX.push_back("RESET_LASER_OFFSET_NG");

                                //g_pMainThread->m_listTX.pop_front();
                        }

                }

                if(strCommand=="FIRE_LASER")
                {

                        //Fire
                        bRet=g_Laser.FireLaser();
                        //bRet=true;
                        //::Sleep(1000);
                        if(bRet) g_pMainThread->m_listLaserRX.push_back("FIRE_LASER_OK");
                        else g_pMainThread->m_listLaserRX.push_back("FIRE_LASER_NG");

                        //g_pMainThread->m_listTX.pop_front();

                        RenameMapFile(true);
                }

        }
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::serverVenderIDClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("基板2D 讀取器連線:"+Socket->RemoteAddress);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverVenderIDClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("基板2D 讀取器斷線!");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverVenderIDClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        AddList("基板2D 讀取器-->"+strMsg);

        if(strMsg=="NO_READ") g_pMainThread->m_listVenderCodeReaderRX.push_back("VENDER_NOREAD");
        else if(strMsg.Length()>8)
        {
                g_pMainThread->m_listVenderCodeReaderRX.push_back(strMsg);
                //Send to EAP
        }
        else g_pMainThread->m_listVenderCodeReaderRX.push_back("VENDER_LENGHT_ERROR");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverLaserIDClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("(上)雷刻完2D 讀取器連線:"+Socket->RemoteAddress);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverLaserIDClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("(上)雷刻完2D 讀取器斷線!");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverLaserIDClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        AddList("(上)雷刻完2D 讀取器-->"+strMsg);

        if(strMsg=="NO_READ") g_pMainThread->m_listLaserCodeReaderRX.push_back("LASER_READER_NOREAD");
        else if(strMsg.Length()>8)
        {
                g_pMainThread->m_listLaserCodeReaderRX.push_back(strMsg);
                AddList("(上)-->"+strMsg);
        }
        else g_pMainThread->m_listLaserCodeReaderRX.push_back("LASER_READER_LENGHT_ERROR");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverCoverIDClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        //AddList("上蓋板2D 讀取器連線:"+Socket->RemoteAddress);
        AddList("(下)雷刻完2D 讀取器連線:"+Socket->RemoteAddress);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverCoverIDClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        //AddList("上蓋板2D 讀取器斷線!");
        AddList("(下)雷刻完2D 讀取器斷線!");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverCoverIDClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        //AddList("下蓋板2D 讀取器-->"+strMsg);
        AddList("(下)雷刻完2D 讀取器-->"+strMsg);

        if(strMsg=="NO_READ") g_pMainThread->m_listCoverCodeReaderRX.push_back("COVER_READER_NOREAD");
        else if(strMsg.Length()>3)
        {
                g_pMainThread->m_listCoverCodeReaderRX.push_back(strMsg);
                AddList("(下)-->"+strMsg);
                //Send to EAP
        }
        else g_pMainThread->m_listCoverCodeReaderRX.push_back("COVER_READER_LENGHT_ERROR");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverBoatIDClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
         AddList("下蓋板2D 讀取器連線:"+Socket->RemoteAddress);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverBoatIDClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("下蓋板2D 讀取器斷線!");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverBoatIDClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        AddList("下蓋板2D 讀取器-->"+strMsg);

        if(strMsg=="NO_READ") g_pMainThread->m_listBoatCodeReaderRX.push_back("BOAT_READER_NOREAD");
        else if(strMsg.Length()>3)
        {
                g_pMainThread->m_listBoatCodeReaderRX.push_back(strMsg);
                //Send to EAP
        }
        else g_pMainThread->m_listBoatCodeReaderRX.push_back("BOAT_READER_LENGHT_ERROR");
}
//---------------------------------------------------------------------------



void __fastcall TfmMain::SpeedButton9Click(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        g_pMainThread->m_bStopLoad=pBtn->Down;
        if(g_pMainThread->m_bStopLoad) g_pMainThread->m_bLoadLifterReady=false;
}
//---------------------------------------------------------------------------



void __fastcall TfmMain::SpeedButton2Click(TObject *Sender)
{
        char *strCMD[]={"VENDER_TRIG","UP_LASER_READER_TRIG","DOWN_LASER_READER_TRIG","BOAT_TRIG"};

        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        g_pMainThread->m_listTX.push_back(strCMD[pBtn->Tag]);

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton12Click(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        switch(pBtn->Tag)
        {
                case 0:
                        clientVenderID->Active=false;
                        clientVenderID->Active=true;
                        break;
                case 1:
                        clientLaserID->Active=false;
                        clientLaserID->Active=true;
                        break;
                case 2:
                        clientCoverID->Active=false;
                        clientCoverID->Active=true;
                        break;
                case 3:
                        clientBoatID->Active=false;
                        clientBoatID->Active=true;
                        break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton19Click(TObject *Sender)
{
        g_pMainThread->m_nLaserCount=0;

        g_Laser.SetText(g_IniFile.m_nLaserProgramNo[1],0,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
        g_Laser.SetText(g_IniFile.m_nLaserProgramNo[1],2,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton20Click(TObject *Sender)
{
        g_pMainThread->m_nLaserCount=0;
        
        g_Laser.SetText(g_IniFile.m_nLaserProgramNo[0],0,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
        g_Laser.SetText(g_IniFile.m_nLaserProgramNo[0],2,GetSchedule(g_pMainThread->m_nLaserCount).c_str());
}
//---------------------------------------------------------------------------
AnsiString __fastcall TfmMain::GetSchedule(int nIndex)
{
        return g_SMSXML.m_strSerialID;
        /*
        int nSubNo=g_pMainThread->m_nLaserCount / g_IniFile.m_nSubLotSize;
        int nSN=g_pMainThread->m_nLaserCount % g_IniFile.m_nSubLotSize;

        AnsiString strText=g_IniFile.m_strScheduleNo.SubString(1,6)+FormatFloat("B0",nSubNo+1)+FormatFloat(" 0",nSN+1);

        return strText;
        */
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SpeedButton21Click(TObject *Sender)
{
        g_Laser.FireLaser();
              
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::TrackBar1Change(TObject *Sender)
{
        labelLED0->Caption=TrackBar1->Position;
        g_IniFile.m_nLEDDimmer[0]=TrackBar1->Position;
        g_LED.SetCurrent(0,0,TrackBar1->Position,0);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::TrackBar2Change(TObject *Sender)
{
        labelLED1->Caption=TrackBar2->Position;
        g_IniFile.m_nLEDDimmer[1]=TrackBar2->Position;
        g_LED.SetVoltage(0,TrackBar2->Position);
        
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SetLEDDimmer()
{

        TrackBar1->Position=g_IniFile.m_nLEDDimmer[0];
        TrackBar2->Position=g_IniFile.m_nLEDDimmer[1];
}
//---------------------------------------------------------------------------
bool __fastcall TfmMain::AxisMoveCheck()
{
        return true;    //debug

        if(!g_pMainThread->m_bIsHomeDone)
        {
                ShowMessage("請先執行機台原點復歸");
                return false;
        }

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
void __fastcall TfmMain::SpeedButton16Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int nTable=radioTable->ItemIndex;
        int nAxis[2]={Axis_Const::RTX,Axis_Const::FTX};

         C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        g_MNet.AbsMove(nAxis[nTable],g_IniFile.m_dTableMapCCDPosX[nTable]);
        g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMapCCDPosY[nTable]);

        while(1)
        {
                if( g_MNet.IsPosDone(nAxis[nTable],g_IniFile.m_dTableMapCCDPosX[nTable])  &&
                        g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMapCCDPosY[nTable])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TfmMain::SpeedButton17Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int nTable=radioTable->ItemIndex;

        int nAxis[2]={Axis_Const::RTX,Axis_Const::FTX};

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        //int nCCDIndex=0;
        //for(int nXX=0;nXX<10;nXX++)
        for(int nIndex=0;nIndex<4;nIndex++)
        {
                g_MNet.AbsMove(nAxis[nTable],g_IniFile.m_dTableMapCCDPosX[nTable]-g_IniFile.m_dTableMapCCDPitch*nIndex);
                g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMapCCDPosY[nTable]);
                tm1MS.timeStart(30000);
                while(1)
                {
                        if( g_MNet.IsPosDone(nAxis[nTable],g_IniFile.m_dTableMapCCDPosX[nTable]-g_IniFile.m_dTableMapCCDPitch*nIndex)  &&
                                g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMapCCDPosY[nTable])) break;
                        if(tm1MS.timeUp()) break;
                        Application->ProcessMessages();
                }

                ::Sleep(100);
                g_Grabber.Grab(0);

                tm1MS.timeStart(1000);

                while(1)
                {
                         if(tm1MS.timeUp() || g_Grabber.m_bValidImage[0]) break;
                         Application->ProcessMessages();
                }

                theVision.MergeImage(nIndex,g_IniFile.m_nImageWidth,g_IniFile.m_dImageAngle);

                RefreshImage();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton18Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int nTable=radioTable->ItemIndex;

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        int nAxis;
        if(nTable==1) nAxis=Axis_Const::FTX;
        else if(nTable==0) nAxis=Axis_Const::RTX;

        g_MNet.AbsMove(nAxis,g_IniFile.m_dTableMarkPosX[nTable]);
        g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPosY[nTable]);

        while(1)
        {
                if( g_MNet.IsPosDone(nAxis,g_IniFile.m_dTableMarkPosX[nTable])  &&
                        g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMarkPosY[nTable])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SpeedButton4Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int nTable=radioTable->ItemIndex;

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        int nAxis;
        if(nTable==1) nAxis=Axis_Const::FTX;
        else if(nTable==0) nAxis=Axis_Const::RTX;

        g_MNet.AbsMove(nAxis,g_IniFile.m_dTableMarkPos2X[nTable]);
        g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPos2Y[nTable]);

        while(1)
        {
                if( g_MNet.IsPosDone(nAxis,g_IniFile.m_dTableMarkPos2X[nTable])  &&
                        g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMarkPos2Y[nTable])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn10Click(TObject *Sender)
{
        int  nFounds=0;

        theVision.m_markMatch[1].SetMaxPositions(1);

        nFounds=theVision.FindPatMatch(theVision.m_roiMark[1],theVision.m_markMatch[1]);

        if(nFounds<1)
        {
                ShowMessage("找不到標記!!");

        }
        else
        {
                double dX=theVision.GetMatchPosX(theVision.m_markMatch[1],1)-320.0;
                double dY=theVision.GetMatchPosY(theVision.m_markMatch[1],1)-240.0;
                AddList("2X="+FormatFloat("0.00 ",dX)+"2Y="+FormatFloat("0.00",dY));

        }

        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn1Click(TObject *Sender)
{
        int  nFounds=0;

        theVision.m_markMatch[2].SetMaxPositions(1);

        nFounds=theVision.FindPatMatch(theVision.m_roiMark[2],theVision.m_markMatch[2]);

        if(nFounds<1)
        {
                ShowMessage("找不到標記!!");

        }
        else
        {
                double dX=theVision.GetMatchPosX(theVision.m_markMatch[2],2)-320.0;
                double dY=theVision.GetMatchPosY(theVision.m_markMatch[2],2)-240.0;
                AddList("X="+FormatFloat("0.00 ",dX)+"Y="+FormatFloat("0.00",dY));

        }

        RefreshImage();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton22Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int  nFounds=0;
        double dX=0;
        double dY=0;

        theVision.m_markMatch[2].SetMaxPositions(1);

        nFounds=theVision.FindPatMatch(theVision.m_roiMark[2],theVision.m_markMatch[2]);

        if(nFounds<1)
        {
                ShowMessage("找不到標記!!");
                pBtn->Enabled=true;
                return;

        }
        else
        {
                dX=theVision.GetMatchPosX(theVision.m_markMatch[2],2)-320.0;
                dY=theVision.GetMatchPosY(theVision.m_markMatch[2],2)-240.0;
                AddList("X="+FormatFloat("0.00 ",dX)+"Y="+FormatFloat("0.00",dY));

        }

        RefreshImage();

        int nTable=radioTable->ItemIndex;

         C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        g_MNet.AbsMove(Axis_Const::FTX,g_IniFile.m_dTableMarkPosX[nTable]-dX*g_IniFile.m_dFMCCDResolution[0]);
        g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPosY[nTable]+dY*g_IniFile.m_dFMCCDResolution[1]);

        while(1)
        {
                if( g_MNet.IsPosDone(Axis_Const::FTX,g_IniFile.m_dTableMarkPosX[nTable])  &&
                        g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMarkPosY[nTable])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SpeedButton5Click(TObject *Sender)
{
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        int  nFounds=0;
        double dX=0;
        double dY=0;

        theVision.m_markMatch[1].SetMaxPositions(1);

        nFounds=theVision.FindPatMatch(theVision.m_roiMark[1],theVision.m_markMatch[1]);

        if(nFounds<1)
        {
                ShowMessage("找不到標記!!");
                pBtn->Enabled=true;
                return;

        }
        else
        {
                dX=theVision.GetMatchPosX(theVision.m_markMatch[1],1)-320.0;
                dY=theVision.GetMatchPosY(theVision.m_markMatch[1],1)-240.0;
                AddList("2X="+FormatFloat("0.00 ",dX)+"2Y="+FormatFloat("0.00",dY));

        }

        RefreshImage();

        int nTable=radioTable->ItemIndex;

        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        tm1MS.timeStart(10000);

        g_MNet.AbsMove(Axis_Const::FTX,g_IniFile.m_dTableMarkPos2X[nTable]-dX*g_IniFile.m_dFMCCDResolution[0]);
        g_MNet.AbsMove(Axis_Const::CCD,g_IniFile.m_dTableMarkPos2Y[nTable]+dY*g_IniFile.m_dFMCCDResolution[1]);

        while(1)
        {
                if( g_MNet.IsPosDone(Axis_Const::FTX,g_IniFile.m_dTableMarkPos2X[nTable])  &&
                        g_MNet.IsPosDone(Axis_Const::CCD,g_IniFile.m_dTableMarkPos2Y[nTable])) break;
                if(tm1MS.timeUp()) break;
                Application->ProcessMessages();
        }

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------




void __fastcall TfmMain::SpeedButton23Click(TObject *Sender)
{
        //g_Laser.SetTextPos(0,0,110.110,-73.3);
        g_Laser.SetAllTextPosOffset(0,10,10,0);       
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton6Click(TObject *Sender)
{
        C_GetTime tm1MS(EX_SCALE::TIME_1MS,false);
        if(!AxisMoveCheck()) return;

        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        pBtn->Enabled=false;

        g_Motion.AbsMove(Axis_Const::SSY,g_IniFile.m_dSSPickerPutPos[1]);

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

        g_pMainThread->m_bLoadLifterReady=false;

        pBtn->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::clientSMSConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("clientSMS:"+Socket->RemoteAddress);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverSMSClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("serverSMS:"+Socket->RemoteAddress);        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverSMSClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("serverSMS Disconnected");        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientSMSDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AddList("clientSMS Disconnected");         
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::serverSMSClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        AddList("serverSMS<--"+strMsg);

        g_SMSXML.m_listRX.push_back(strMsg);
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientSMSRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        AnsiString strMsg=Socket->ReceiveText();

        AddList("clientSMS<--"+strMsg);

        g_SMSXML.m_listRX.push_back(strMsg);

        clientSMS->Active=false;      
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton24Click(TObject *Sender)
{
        clientSMS->Active=false;
        clientSMS->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::timerSMSTimer(TObject *Sender)
{
        if(g_SMSXML.m_listRX.size()>0)
        {
                g_SMSXML.ProcessXML();
        }

        if(g_SMSXML.m_listClientTX.size()>0)
        {
                //clientSMS->Active=false;
                clientSMS->Active=true;
                if(clientSMS->Socket->Connected)
                {
                        AddList("clientSMS-->"+g_SMSXML.m_listClientTX.front());
                        clientSMS->Socket->SendText(g_SMSXML.m_listClientTX.front());
                        g_SMSXML.m_listClientTX.pop_front();
                }

        }

        if(g_SMSXML.m_listServerTX.size()>0)
        {
                if(serverSMS->Socket->ActiveConnections>0)
                {
                        AddList("serverSMS-->"+g_SMSXML.m_listServerTX.front());
                        serverSMS->Socket->Connections[0]->SendText(g_SMSXML.m_listServerTX.front());
                        g_SMSXML.m_listServerTX.pop_front();
                }


        }

        char *SMSStatus[]={"Off Line","On Line Local","On Line Remote"};

        textSMSStatus->Caption=SMSStatus[g_SMSXML.m_nOnLineMode];
        textSMSStatus2->Caption=SMSStatus[g_SMSXML.m_nOnLineMode];
        labelSerialID->Caption= g_SMSXML.m_strSerialID;
        labelLotEnd->Caption=g_SMSXML.m_strLotENDResult;

        char *MAPFTPStatus[]={"Map FTP 斷線","Map FTP 連線"};
        textMapFtpStatus->Caption=MAPFTPStatus[ftpMap->Connected];

        textLaserCount->Caption=g_pMainThread->m_nStripCount; //g_pMainThread->m_nLaserCount;
        textOKSummary->Caption=g_pMainThread->m_nOKSummary;
        textNGSummary->Caption=g_pMainThread->m_nNGSummary;
        labelSubstrateRemains->Caption=g_pMainThread->m_nSubstrateRemains;

        labelMachineID->Caption=g_IniFile.m_strSMSMachineID;
        labelUserID->Caption=g_IniFile.m_strSMSUserID;
        labelPartNo->Caption=g_IniFile.m_strSMSPartNo;
        labelLotNo->Caption=g_IniFile.m_strSMSLotNo;
        labelProductID->Caption=g_IniFile.m_strProductID;
        labelSBTLotNo->Caption=g_IniFile.m_strSBTLotNo;


}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton25Click(TObject *Sender)
{
        g_SMSXML.ModeChange(true);
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::clientSMSError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        g_SMSXML.m_listClientTX.clear();
        AddList("[clientSMS Error]連線遠端電腦發生異常");
        ErrorCode=0;
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::serverSMSClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        AddList("serverSMS Error");
        ErrorCode=0;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientVenderIDError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        AddList("[clientVenderID Error]連線基板2D讀取器發生異常");
        ErrorCode=0;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientLaserIDError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        AddList("[clientLaserID Error]連線雷刻完2D讀取器發生異常");
        ErrorCode=0;        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientCoverIDError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        AddList("[clientCoverID Error]連線上蓋2D讀取器發生異常");
        ErrorCode=0;        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::clientBoatIDError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        AddList("[clientBoatID Error]連線Carrier 2D讀取器發生異常");
        ErrorCode=0;        
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::SpeedButton26Click(TObject *Sender)
{
        g_SMSXML.QueryID();        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton27Click(TObject *Sender)
{
        g_SMSXML.QueryIDEnd(g_pMainThread->m_nLaserCount);        
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::SpeedButton28Click(TObject *Sender)
{
        g_SMSXML.ModeChange(false); 
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::SpeedButton29Click(TObject *Sender)
{
        if(Application->MessageBoxA("確定要歸零嗎?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDCANCEL) return;

        g_pMainThread->m_nLaserCount=0;
        g_pMainThread->m_nOKSummary=0;
        g_pMainThread->m_nNGSummary=0;
        g_pMainThread->m_nStripCount=0;

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton30Click(TObject *Sender)
{
        TfrmUserID *pWnd=new TfrmUserID(this);

        bool bRead=true;

        DDX_String(bRead,g_IniFile.m_strSMSMachineID,pWnd->m_strSMSMachineID);
        DDX_String(bRead,g_IniFile.m_strSMSUserID,pWnd->m_strSMSUserID);
        DDX_String(bRead,g_IniFile.m_strSMSPartNo,pWnd->m_strSMSPartNo);
        DDX_String(bRead,g_IniFile.m_strSMSLotNo,pWnd->m_strSMSLotNo);
        DDX_String(bRead,g_IniFile.m_strProductID,pWnd->m_strProductID);
        DDX_String(bRead,g_IniFile.m_strSBTLotNo,pWnd->m_strSBTLotNo);

        //DDX_String(bRead,g_IniFile.m_strProductPgm,pWnd->m_strProductPgm);
        //DDX_String(bRead,g_IniFile.m_strMachinePgm,pWnd->m_strMachinePgm);

        pWnd->cmbProduct->Text=g_IniFile.m_strProductPgm;
        pWnd->cmbMachine->Text=g_IniFile.m_strMachinePgm;

        DDX_Int(bRead,g_IniFile.m_nIssueQty,pWnd->m_nIssueQty);

    while (1)
    {
        if (pWnd->ShowModal()== mrOk)
        {

            if (pWnd->m_strSMSUserID->Text == "")
            {
				Application->MessageBoxA("使用者ID不可以空白","Confirm",MB_OK);
            }
            else
            {
                bRead = false;
                break;
            }
        }
        else
        {
            break;
        }
    }

        //if(pWnd->ShowModal()==mrOk)
        if (bRead == false)
        {
                bRead=false;

                DDX_String(bRead,g_IniFile.m_strSMSMachineID,pWnd->m_strSMSMachineID);
                DDX_String(bRead,g_IniFile.m_strSMSUserID,pWnd->m_strSMSUserID);
                DDX_String(bRead,g_IniFile.m_strSMSPartNo,pWnd->m_strSMSPartNo);
                DDX_String(bRead,g_IniFile.m_strSMSLotNo,pWnd->m_strSMSLotNo);
                DDX_String(bRead,g_IniFile.m_strProductID,pWnd->m_strProductID);
                DDX_String(bRead,g_IniFile.m_strSBTLotNo,pWnd->m_strSBTLotNo);

                //DDX_String(bRead,g_IniFile.m_strProductPgm,pWnd->m_strProductPgm);
                //DDX_String(bRead,g_IniFile.m_strMachinePgm,pWnd->m_strMachinePgm);

                g_IniFile.m_strProductPgm=pWnd->cmbProduct->Text;
                g_IniFile.m_strMachinePgm=pWnd->cmbMachine->Text;

                DDX_Int(bRead,g_IniFile.m_nIssueQty,pWnd->m_nIssueQty);

                //open MachinePgm
                AnsiString strName1="C:\\Product Data\\C77Machine\\"+g_IniFile.m_strMachinePgm+"\\"+g_IniFile.m_strMachinePgm+".ini";
                g_IniFile.ProductFile(strName1.c_str(),true,FILE_MODE_MACHINE);
                //open ProductPgm
                AnsiString strName2="C:\\Product Data\\C77Product\\"+g_IniFile.m_strProductPgm+"\\"+g_IniFile.m_strProductPgm+".ini";
                g_IniFile.ProductFile(strName2.c_str(),true,FILE_MODE_PRODUCT);
                theVision.LoadTool(g_IniFile.GetFileNameWithNewExt(strName2.c_str(),"cev").c_str(),"Dummy");

        }

        g_SMSXML.m_strMachineID=g_IniFile.m_strSMSMachineID;
        g_SMSXML.m_strUserID=g_IniFile.m_strSMSUserID;
        g_SMSXML.m_strPartNo=g_IniFile.m_strSMSPartNo;
        g_SMSXML.m_strLotNo=g_IniFile.m_strSMSLotNo;

        RefreshImage();
        
        delete pWnd;
                
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::Version1Click(TObject *Sender)
{
        for(int nIndex=0;nIndex<g_pMainThread->m_listThreadTrace.size();nIndex++)
        {
                AddList(g_pMainThread->m_listThreadTrace.front());
                
        }
}
//---------------------------------------------------------------------------
bool __fastcall TfmMain::ExportMapFile()
{
        AnsiString strPath="C:\\MapData\\";
        mkdir(strPath.c_str());

        AnsiString strSubstrateID=g_SMSXML.m_strSerialID;
        AnsiString strProductID=g_IniFile.m_strProductID;
        AnsiString strFileName=strProductID+strSubstrateID+".xml";
        int nRows=g_IniFile.m_nPackageY*g_IniFile.m_nDeviceY;
        int nColumns=g_IniFile.m_nPackageX*g_IniFile.m_nDeviceX;

        TiXmlDocument doc;
        TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
        TiXmlElement *pMap=new TiXmlElement("Map");
                pMap->SetAttribute("xmlns:semi","http://www.semi.org");
                pMap->SetAttribute("SubstrateType","Strip");
                pMap->SetAttribute("SubstrateID",strSubstrateID.c_str());
                pMap->SetAttribute("FormatRevision","SEMI G85-0703");
                pMap->SetAttribute("CarrierType","Cassette");
                pMap->SetAttribute("FileName",strFileName.c_str());
                pMap->SetAttribute("CreateDate",FormatDateTime("yyyymmddhhnnss",Now()).c_str());

        TiXmlElement *pDevice=new TiXmlElement("Device");
                pDevice->SetAttribute("ProductID",strProductID.c_str());
                pDevice->SetAttribute("LotID",g_SMSXML.m_strLotNo.c_str());
                pDevice->SetAttribute("OriginLocation",3);
                pDevice->SetAttribute("Orientation",0);
                pDevice->SetAttribute("Rows",nRows);
                pDevice->SetAttribute("Columns",nColumns);
                pDevice->SetAttribute("BinType","Decimal");
                pDevice->SetAttribute("NullBin",0);
                pDevice->SetAttribute("SubstrateSide","Both");
                pDevice->SetAttribute("PackageType","UBGA");
                pDevice->SetAttribute("MfgArea","StripTest");

        //TiXmlComment *pComm=new  TiXmlComment("AtgBackLink: BoardName=txi6720ec LotNumber=1, RunNumber=38, SampleNumber=1");

        TiXmlElement *pBin=new TiXmlElement("Bin");
                pBin->SetAttribute("BinCode",1);
                pBin->SetAttribute("BinCount",nRows*nColumns);
                pBin->SetAttribute("BinQuality","Pass");

        TiXmlElement *pData=new TiXmlElement("Data");
                pData->SetAttribute("MapName","CellGrade");


        //------------------
        int nPassCount=0;
        int nFailCount=0;
        char bin[100][500]={0};

        for(int nYY=0;nYY<nRows;nYY++)
        for(int nXX=0;nXX<nColumns;nXX++)
        {

           if( m_nSubstrateMap[nYY*nColumns+nXX]==1)
           {
                nPassCount++;
                strcat(&bin[nYY][0],"1 ");
           }
           else
           {
                nFailCount++;
                strcat(&bin[nYY][0],"0 ");    //Null Bin
           }
        }

        g_pMainThread->m_nOKCount=nPassCount;
        g_pMainThread->m_nNGCount=nFailCount;

        TiXmlElement *pRow;
        for(int nIndex=0;nIndex<nRows;nIndex++)
        {
                pRow=new TiXmlElement("Row");
                TiXmlText *pText=new TiXmlText(bin[nIndex]);          //Map Data Array
                pText->SetCDATA(true);
                pRow->LinkEndChild(pText);

                //pBinCode->LinkEndChild();
                pData->LinkEndChild(pRow);
        }

        //------------------

        //pDevice->LinkEndChild(pComm);
        pDevice->LinkEndChild(pBin);
        pDevice->LinkEndChild(pData);

        pMap->LinkEndChild(pDevice);


        doc.LinkEndChild(decl);
        doc.LinkEndChild(pMap);

        strPath+=strFileName;
        doc.SaveFile(strPath.c_str());

        return true;
}
//---------------------------------------------------------------------------
bool __fastcall TfmMain::ExportMapFileTmp(bool bFront)
{
        AnsiString strPath="C:\\MapData\\";
        mkdir(strPath.c_str());

        AnsiString strSubstrateID=g_SMSXML.m_strSerialID;
        AnsiString strProductID=g_IniFile.m_strProductID;
        AnsiString strFileName=strProductID+strSubstrateID+".xml";
        int nRows=g_IniFile.m_nPackageY*g_IniFile.m_nDeviceY;
        int nColumns=g_IniFile.m_nPackageX*g_IniFile.m_nDeviceX;

        bFront ? strFileName="FrontMap.xml" : strFileName="RearMap.xml" ;

        TiXmlDocument doc;
        TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
        TiXmlElement *pMap=new TiXmlElement("Map");
                pMap->SetAttribute("xmlns:semi","http://www.semi.org");
                pMap->SetAttribute("SubstrateType","Strip");
                pMap->SetAttribute("SubstrateID",strSubstrateID.c_str());
                pMap->SetAttribute("FormatRevision","SEMI G85-0703");
                pMap->SetAttribute("CarrierType","Cassette");
                pMap->SetAttribute("FileName",strFileName.c_str());
                pMap->SetAttribute("CreateDate",FormatDateTime("yyyymmddhhnnss",Now()).c_str());

        TiXmlElement *pDevice=new TiXmlElement("Device");
                pDevice->SetAttribute("ProductID",strProductID.c_str());
                pDevice->SetAttribute("LotID",g_SMSXML.m_strLotNo.c_str());
                pDevice->SetAttribute("OriginLocation",3);
                pDevice->SetAttribute("Orientation",0);
                pDevice->SetAttribute("Rows",nRows);
                pDevice->SetAttribute("Columns",nColumns);
                pDevice->SetAttribute("BinType","Decimal");
                pDevice->SetAttribute("NullBin",0);
                pDevice->SetAttribute("SubstrateSide","Both");
                pDevice->SetAttribute("PackageType","UBGA");
                pDevice->SetAttribute("MfgArea","StripTest");

        //TiXmlComment *pComm=new  TiXmlComment("AtgBackLink: BoardName=txi6720ec LotNumber=1, RunNumber=38, SampleNumber=1");

        TiXmlElement *pBin=new TiXmlElement("Bin");
                pBin->SetAttribute("BinCode",1);
                pBin->SetAttribute("BinCount",nRows*nColumns);
                pBin->SetAttribute("BinQuality","Pass");

        TiXmlElement *pData=new TiXmlElement("Data");
                pData->SetAttribute("MapName","CellGrade");


        //------------------
        int nPassCount=0;
        int nFailCount=0;
        char bin[100][500]={0};

        for(int nYY=0;nYY<nRows;nYY++)
        for(int nXX=0;nXX<nColumns;nXX++)
        {

           if( m_nSubstrateMap[nYY*nColumns+nXX]==1)
           {
                nPassCount++;
                strcat(&bin[nYY][0],"1 ");
           }
           else
           {
                nFailCount++;
                strcat(&bin[nYY][0],"0 ");    //Null Bin
           }
        }

        g_pMainThread->m_nOKCount=nPassCount;
        g_pMainThread->m_nNGCount=nFailCount;

        TiXmlElement *pRow;
        for(int nIndex=0;nIndex<nRows;nIndex++)
        {
                pRow=new TiXmlElement("Row");
                TiXmlText *pText=new TiXmlText(bin[nIndex]);          //Map Data Array
                pText->SetCDATA(true);
                pRow->LinkEndChild(pText);

                //pBinCode->LinkEndChild();
                pData->LinkEndChild(pRow);
        }

        //------------------

        //pDevice->LinkEndChild(pComm);
        pDevice->LinkEndChild(pBin);
        pDevice->LinkEndChild(pData);

        pMap->LinkEndChild(pDevice);


        doc.LinkEndChild(decl);
        doc.LinkEndChild(pMap);

        strPath+=strFileName;
        doc.SaveFile(strPath.c_str());

        return true;
}
//---------------------------------------------------------------------------
bool __fastcall TfmMain::RenameMapFile(bool bFront)
{
        AnsiString strFileNameTmp;

        bFront ? strFileNameTmp="C:\\MapData\\FrontMap.xml" : strFileNameTmp="C:\\MapData\\RearMap.xml" ;

        AnsiString strSubstrateID=g_SMSXML.m_strSerialID;
        AnsiString strProductID=g_IniFile.m_strProductID;
        AnsiString strFileName=strProductID+strSubstrateID+".xml";

        TiXmlDocument doc;
        if(!doc.LoadFile(strFileNameTmp.c_str())) return false;

        TiXmlHandle docHandle( &doc );

        TiXmlElement *pMap=docHandle.FirstChild("Map").Element();
        pMap->SetAttribute("SubstrateID",strSubstrateID.c_str());
        pMap->SetAttribute("FileName",strFileName.c_str());

        mkdir(AnsiString("C:\\MapData\\"+g_IniFile.m_strSMSLotNo).c_str());
        strFileName="C:\\MapData\\"+g_IniFile.m_strSMSLotNo+"\\"+strFileName;
        doc.SaveFile(strFileName.c_str());

        return true;
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SpeedButton31Click(TObject *Sender)
{
        ExportMapFileTmp(true);
        g_SMSXML.m_strSerialID="A123456789";
        RenameMapFile(true);
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::PageControl1Change(TObject *Sender)
{
        if(m_nUserLevel<=0 && PageControl1->TabIndex<4 ) PageControl1->ActivePage=tabInfo;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnClearLogClick(TObject *Sender)
{

        TSpeedButton *pBtn=(TSpeedButton *)Sender;

        if(Application->MessageBox("即將清除所有紀錄", "Look", MB_OKCANCEL)==IDCANCEL) return;

        if (pBtn->Hint == "Vision")
        {
            listVisionLog->Clear();
            g_pMainThread->m_listVisionLog.clear();

            g_pMainThread->m_listVisionLog.push_back("Lot No :"+g_IniFile.m_strSMSLotNo);
            g_pMainThread->m_listVisionLog.push_back("Part No:"+g_IniFile.m_strSMSPartNo);
            g_pMainThread->m_listVisionLog.push_back("User ID:"+g_IniFile.m_strSMSUserID);
            g_pMainThread->m_listVisionLog.push_back("***********************************");
        }
        else if (pBtn->Hint == "Marker")
        {
            listMarkerLog->Clear();
            g_pMainThread->m_listMarkerLog.push_back("Marker Log Clear.");
            g_pMainThread->m_listLog.push_back("Marker Log Clear.");
        }
        else if (pBtn->Hint == "Action")
        {
            listActionLog->Clear();
            g_pMainThread->m_listLog.push_back("Action Log Clear.");
        }
        else if (pBtn->Hint == "Error")
        {
            listErrorLog->Clear();
            g_pMainThread->m_listLog.push_back("Error Log Clear.");
        }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::btnExportLogClick(TObject *Sender)
{
        TSpeedButton *pBtn=(TSpeedButton *)Sender;
        TStrings *strsInp;

        if (pBtn->Hint == "Marker")
        {
            strsInp = listMarkerLog->Items;
            g_pMainThread->m_listMarkerLog.push_back("Marker Log Save to C:\\C82 Log\\CSV.");
            g_pMainThread->m_listLog.push_back("Marker Log Save to C:\\C82 Log\\CSV.");
        }
        else if (pBtn->Hint == "Action")
        {
            strsInp = listActionLog->Items;

            g_pMainThread->m_listLog.push_back("Action Log Save to C:\\C82 Log\\CSV.");
        }
        else if (pBtn->Hint == "Error")
        {
            strsInp = listErrorLog->Items;

            g_pMainThread->m_listLog.push_back("Error Log Save to C:\\C82 Log\\CSV.");
        }

        try
        {
            AnsiString strFileName;
            time_t timer = time(NULL);
            struct tm *tblock = localtime(&timer);
            strFileName.sprintf("C:\\C82 Log\\CSV\\%4d_%02d_%02d_%2d_%02d_%02d.csv"
                ,tblock->tm_year+1900,tblock->tm_mon+1,tblock->tm_mday
                ,tblock->tm_hour,tblock->tm_min, tblock->tm_sec);

            int iFileHandle;
            iFileHandle = FileCreate(strFileName);
            int iPos = 0;
            for (int nX=0;nX<strsInp->Count;nX++)
            {
                AnsiString strOup = ReplaceString(strsInp->Strings[nX], "--->", ",");
                strOup = strOup + "\r\n";
                FileWrite(iFileHandle, strOup.c_str(), strOup.Length());
            }
            FileClose(iFileHandle);
            ShowMessage("存檔完成");
        }
        catch (...)
        {
            ShowMessage("存檔失敗");
        }

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton34Click(TObject *Sender)
{
        AnsiString strFoldNameSrc="C:\\MapData\\"+g_IniFile.m_strSMSLotNo+"\\";

        TSearchRec sr;
        int iAttributes = 0;

        iAttributes |= faAnyFile ;

        if (FindFirst(strFoldNameSrc+"*.xml", iAttributes, sr) == 0)
        {
                do
                {
                        if ((sr.Attr & iAttributes) == sr.Attr)
                        {
                                //ftpMap->Upload(OpenDialog1->FileName,strFoldNameDest+sr.Name);
                                AddVisionLog(strFoldNameSrc+sr.Name);
                        }
                } while (FindNext(sr) == 0);
                FindClose(sr);
        }
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton35Click(TObject *Sender)
{
        ftpMap->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton36Click(TObject *Sender)
{

        if(!ftpMap->Connected)
        {
                ShowMessage("FTP 沒有連線,請連線後重試");
                return;
        }
        
        ftpMap->MakeDirectory("\\IDPrinterStripMap\\test");
        OpenDialog1->DefaultExt = "xml";
        OpenDialog1->FileName = "*.xml";

        AnsiString strName="\\IDPrinterStripMap\\Test\\"+FormatDateTime("yyyymmddhhnnss",Now())+".xml";

        if(OpenDialog1->Execute())
        {
                ftpMap->Upload(OpenDialog1->FileName,"\\IDPrinterStripMap\\Test\\aaaa.xml");
        }

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ftpMapFailure(bool &Handled, TCmdType Trans_Type)
{
        Handled=true;

        char *strErrorType[]={"cmdChangeDir", "cmdMakeDir", "cmdDelete", "cmdRemoveDir",
                "cmdList", "cmdRename", "cmdUpRestore", "cmdDownRestore", "cmdDownload",
                "cmdUpload", "cmdAppend", "cmdReInit" , "cmdAllocate", "cmdNList",
                "cmdDoCommand", "cmdCurrentDir"};

        AddList("FTP Failure:"+AnsiString(strErrorType[Trans_Type]));
        //g_IniFile.m_nErrorCode=100;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ftpMapConnect(TObject *Sender)
{
        AddList("MAP FTP Connected");        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ftpMapConnectionFailed(TObject *Sender)
{
        AddList("MAP FTP Connection Failure!");        
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::ftpMapDisconnect(TObject *Sender)
{
        AddList("MAP FTP Disconnect");        
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::SpeedButton37Click(TObject *Sender)
{
        if(Application->MessageBoxA("即將關閉所有真空請注意掉落?","Confirm",MB_ICONQUESTION|MB_OKCANCEL)==IDCANCEL) return;

         for(int nIndex=0;nIndex<80;nIndex++)
         {
                g_DIO.SetDO(nIndex,false);
         }
         
        g_MNet.SetDO(DO::SS_SVacOn,false);
        g_MNet.SetDO(DO::SS_SVacOff,true);
        g_MNet.SetDO(DO::SS_SpaVacOn,false);
        g_MNet.SetDO(DO::SS_SpaVacOff,true);
        g_MNet.SetDO(DO::SC_SSuckerVacOn,false);
        g_MNet.SetDO(DO::SC_SSuckerVacOff,true);
        g_MNet.SetDO(DO::SC_CSuckerVacOn,false);
        g_MNet.SetDO(DO::SC_CSuckerVacOff,true);

        g_pMainThread->m_bNeedHome=true;
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::N1Click(TObject *Sender)
{
        AnsiString InputString = InputBox("請輸入將要新增 產品檔案 名稱", "檔案名稱", "Default");

        MkDir("C:\\Product Data\\C77Product\\");
        MkDir("C:\\Product Data\\C77Product\\"+InputString+"\\");

        AnsiString strPathName="C:\\Product Data\\C77Product\\"+InputString+"\\"+InputString+".ini";

        g_IniFile.ProductFile(strPathName.c_str(),false,FILE_MODE_PRODUCT);

        theVision.SaveTool(g_IniFile.GetFileNameWithNewExt(strPathName.c_str(),"cev").c_str(),"Dummy");

        ShowMessage("新增完成");
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::N2Click(TObject *Sender)
{
        AnsiString InputString = InputBox("請輸入將要新增 機構檔案 名稱", "檔案名稱", "Default");
        MkDir("C:\\Product Data\\C77Machine\\");
        MkDir("C:\\Product Data\\C77Machine\\"+InputString+"\\");

        AnsiString strPathName="C:\\Product Data\\C77Machine\\"+InputString+"\\"+InputString+".ini";

        g_IniFile.ProductFile(strPathName.c_str(),false,FILE_MODE_MACHINE);

        ShowMessage("新增完成");


}
//---------------------------------------------------------------------------
void __fastcall TfmMain::SaveProduct()
{
        //ProductPgm
    MkDir("C:\\Product Data\\C77Product\\");

    AnsiString strPathName="C:\\Product Data\\C77Product\\"+g_IniFile.m_strProductPgm+"\\"+g_IniFile.m_strProductPgm+".ini";
    MkDir("C:\\Product Data\\C77Product\\"+g_IniFile.m_strProductPgm+"\\");

    g_IniFile.ProductFile(strPathName.c_str(),false,FILE_MODE_PRODUCT);

    theVision.SaveTool(g_IniFile.GetFileNameWithNewExt(strPathName.c_str(),"cev").c_str(),"Dummy");

    //MachinePgm
    AnsiString strPathName2="C:\\Product Data\\C77Machine\\"+g_IniFile.m_strMachinePgm+"\\"+g_IniFile.m_strMachinePgm+".ini";
    MkDir("C:\\Product Data\\C77Machine\\"+g_IniFile.m_strMachinePgm+"\\");

    g_IniFile.ProductFile(strPathName2.c_str(),false,FILE_MODE_MACHINE);
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::LoadProduct()
{
        //open MachinePgm
        AnsiString strName1="C:\\Product Data\\C77Machine\\"+g_IniFile.m_strMachinePgm+"\\"+g_IniFile.m_strMachinePgm+".ini";
        if(FileExists(strName1)) g_IniFile.ProductFile(strName1.c_str(),true,FILE_MODE_PRODUCT);
        else ShowMessage("Mechanical File Does Not Exist!");
        //open ProductPgm
        AnsiString strName2="C:\\Product Data\\C77Product\\"+g_IniFile.m_strProductPgm+"\\"+g_IniFile.m_strProductPgm+".ini";
        if(FileExists(strName2))
        {
                g_IniFile.ProductFile(strName2.c_str(),true,FILE_MODE_PRODUCT);
                theVision.LoadTool(g_IniFile.GetFileNameWithNewExt(strName2.c_str(),"cev").c_str(),"Dummy");
        }
        else ShowMessage("Product File Not Exist");
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::BitBtn4Click(TObject *Sender)
{
        g_pMainThread->m_listVisionLog.push_back("***********************************");
        g_pMainThread->m_listVisionLog.push_back("Total    :"+FormatFloat("0",g_pMainThread->m_nOKSummary+g_pMainThread->m_nNGSummary));
        g_pMainThread->m_listVisionLog.push_back("Strip Qty:"+textLaserCount->Caption);
        g_pMainThread->m_listVisionLog.push_back("OK unit  :"+textOKSummary->Caption);
        g_pMainThread->m_listVisionLog.push_back("NG unit  :"+textNGSummary->Caption);

        

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::BitBtn11Click(TObject *Sender)
{
        mkdir("C:\\C77 Report");

        if(Application->MessageBox("即將匯出檔案", "Look", MB_OKCANCEL)==IDCANCEL) return;

        listVisionLog->Items->SaveToFile("C:\\C77 Report\\"+g_IniFile.m_strSMSLotNo+".txt");
}
//---------------------------------------------------------------------------


void __fastcall TfmMain::SpeedButton38Click(TObject *Sender)
{
        if(!ftpMap->Connected)
        {
                ShowMessage("FTP 沒有連線,請連線後重試");
                return;
        }
        
        ftpMap->MakeDirectory("\\IDPrinterStripMap\\"+g_IniFile.m_strSMSMachineID+"\\");
        ftpMap->MakeDirectory("\\IDPrinterStripMap\\"+g_IniFile.m_strSMSMachineID+"\\"+g_IniFile.m_strSMSLotNo);

        AnsiString strFoldNameDest="\\IDPrinterStripMap\\"+g_IniFile.m_strSMSMachineID+"\\"+g_IniFile.m_strSMSLotNo+"\\";
        AnsiString strFoldNameSrc="C:\\MapData\\"+g_IniFile.m_strSMSLotNo+"\\";

        TSearchRec sr;
        int iAttributes = 0;

        iAttributes |= faAnyFile ;

        if (FindFirst(strFoldNameSrc+".xml", iAttributes, sr) == 0)
        {
                do
                {
                        if ((sr.Attr & iAttributes) == sr.Attr)
                        {
                                ftpMap->Upload(strFoldNameSrc+sr.Name,strFoldNameDest+sr.Name);
                                AddList("FTP 上傳檔案:"+sr.Name);
                        }
                } while (FindNext(sr) == 0);
                FindClose(sr);
        }


        ShowMessage("上傳結束");


        //ftpMap->Upload(OpenDialog1->FileName,"\\IDPrinterStripMap\\Test\\aaaa.xml");

}
//---------------------------------------------------------------------------

void __fastcall TfmMain::SpeedButton8Click(TObject *Sender)
{
    fmShowNow->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfmMain::timerLoaderSigTimer(TObject *Sender)
{
    timerLoaderSig->Enabled = false;
    if (g_DIO.GetDI(DI::LoaderNoSubstrate) && this->SpeedButton9->Down == false)
    {
        this->SpeedButton9->Down = true;
        g_pMainThread->m_bStopLoad = true;
        g_pMainThread->m_bLoadLifterReady=false;
    }
    else if (g_pMainThread->m_bReLoad == true)
    {
        this->SpeedButton9->Down = false;
        g_pMainThread->m_bReLoad = false;
    }
    timerLoaderSig->Enabled = true;
}
//---------------------------------------------------------------------------



