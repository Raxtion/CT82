//---------------------------------------------------------------------------


#pragma hdrstop

#include "IniFile.h"
#include <IniFiles.hpp>
#include "time.h"
#include <dir.h>
#include "stdlib.h"
#include <stdio.h>

#define ErrorMessage_Dir "Error Message\\"
#define ErrorMessageFileName "C82ErrorMessage.ini"
#define ErrorMessageEngFileName "C82ErrorMessageEng.ini"
#define UserName "User.sis"
#define MachineFileName "C82Machine.sis"

CIniFile g_IniFile;

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

void __fastcall CIniFile::MachineFile(bool bRead)
{
  AnsiString strFile;
  TIniFile *pIniFile;
                    
  strFile.sprintf("%s%s",IniFile_Dir,MachineFileName);
  pIniFile = new TIniFile(strFile);

 //System
  DDXFile_Int(bRead,pIniFile,System_Section,"Language",m_nLanguageMode);
  DDXFile_Int(bRead,pIniFile,System_Section,"Priviledge",m_nPriviledge);
  DDXFile_String(bRead,pIniFile,System_Section,"ARTPassword",m_strARTPassword,"CLARE");
  DDXFile_String(bRead,pIniFile,System_Section,"ENGPassword",m_strENGPassword,"123");
  DDXFile_String(bRead,pIniFile,System_Section,"LastFileName",m_strLastFileName,"C:\\Product Data\\Default.ini");

  //Machine
  for(int nIndex=0;nIndex<10;nIndex++)
  {
        DDXFile_Float(bRead,pIniFile,Machine_Section,"JogSpeed"+FormatFloat("0",nIndex+1),m_dJogSpeed[nIndex],30.0);
        DDXFile_Float(bRead,pIniFile,Machine_Section,"ACCSpeed"+FormatFloat("0",nIndex+1),m_dACCSpeed[nIndex],0.1);
        DDXFile_Float(bRead,pIniFile,Machine_Section,"DECSpeed"+FormatFloat("0",nIndex+1),m_dDECSpeed[nIndex],0.1);
        DDXFile_Float(bRead,pIniFile,Machine_Section,"WorkSpeed"+FormatFloat("0",nIndex+1),m_dWorkSpeed[nIndex],50.0); 
  }

  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nImageWidth",m_nImageWidth,500);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dImageAngle",m_dImageAngle,0.0);

  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dTableMapCCDPosX0",m_dTableMapCCDPosX[0],0.0);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dTableMapCCDPosY0",m_dTableMapCCDPosY[0],0.0);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dTableMapCCDPosX1",m_dTableMapCCDPosX[1],0.0);                               
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dTableMapCCDPosY1",m_dTableMapCCDPosY[1],0.0);                               
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dTableMapCCDPitch",m_dTableMapCCDPitch,0.0);

  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dSCPickerPickSSPosY0",m_dSCPickerPickSSPosY[0],0.0);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dSCPickerPickSSPosY1",m_dSCPickerPickSSPosY[1],0.0);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dLaserCodeReaderPos0",m_dLaserCodeReaderPos[0],0.0);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dLaserCodeReaderPos1",m_dLaserCodeReaderPos[1],0.0);

  DDXFile_Bool(bRead,pIniFile,Machine_Section,"m_bForceEject",m_bForceEject,false);

  //IP
  DDXFile_String(bRead,pIniFile,System_Section,"m_strVenderID_IP",m_strVenderID_IP,"192.168.100.101");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strLaserID_IP",m_strLaserID_IP,"192.168.100.102");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strCoverID_IP",m_strCoverID_IP,"192.168.100.103");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strBoatID_IP",m_strBoatID_IP,"192.168.100.104");

  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dFMCCDResolution0",m_dFMCCDResolution[0],0.012433);
  DDXFile_Float(bRead,pIniFile,Machine_Section,"m_dFMCCDResolution1",m_dFMCCDResolution[1],0.014583);

  //SMS
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSServerIP",m_strSMSServerIP,"127.0.0.1");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSClientIP",m_strSMSClientIP,"127.0.0.1");

  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nSMSServerPort",m_nSMSServerPort,9588);
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nSMSClientPort",m_nSMSClientPort,9566);

  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSMachineID",m_strSMSMachineID,"SMS-IDPRN-01");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSUserID",m_strSMSUserID,"A977168");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSPartNo",m_strSMSPartNo,"5B-12-0060G");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSMSLotNo",m_strSMSLotNo,"130599249.00");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strSBTLotNo",m_strSBTLotNo,"SBT Lot No");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strProductPgm",m_strProductPgm,"Product_Defauly");
  DDXFile_String(bRead,pIniFile,System_Section,"m_strMachinePgm",m_strMachinePgm,"Machine_Default");
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nIssueQty",m_nIssueQty,0);

  //Map
  DDXFile_String(bRead,pIniFile,System_Section,"m_strProductID",m_strProductID,"txi6701ec");

  //Map ftp Server
  DDXFile_String(bRead,pIniFile,System_Section,"m_strMapFtpIP",m_strMapFtpIP,"192.168.0.74");                        //"smsap01//IDPrinterStripMap"
  DDXFile_String(bRead,pIniFile,System_Section,"m_strMapFtpUserName",m_strMapFtpUserName,"user");            //"SMS_USER"
  DDXFile_String(bRead,pIniFile,System_Section,"m_strMapFtpPassword",m_strMapFtpPassword,"123456");            //"PTISMSUSER"
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nMapFtpPort",m_nMapFtpPort,21);

  //Delay Time
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nCoverVacTime",m_nCoverVacTime,1000);
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nSubstrateVacTime",m_nSubstrateVacTime,1000);
  DDXFile_Int(bRead,pIniFile,Machine_Section,"m_nLoadingAlarmTime",m_nLoadingAlarmTime,600000);
  delete pIniFile;
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::ProductFile(char *strFileName,bool bRead,int nMode)
{                                                                                                                              
  AnsiString strName;

  TIniFile *pIniFile;          //General

  pIniFile = new TIniFile(strFileName); 

  //pIniFile
  if(nMode==FILE_MODE_ALL || nMode==FILE_MODE_PRODUCT)
  {
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nCols",m_nCols,8);                                                             
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nRows",m_nRows,3);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dColPitch",m_dColPitch,10.0);                                                
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dRowPitch",m_dRowPitch,10.0);                                                
                                                                                                                           
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nPackageX",m_nPackageX,4);                                                     
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nPackageY",m_nPackageY,1);                                                     
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nDeviceX",m_nDeviceX,4);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nDeviceY",m_nDeviceY,4);                                                          
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nPackageGap",m_nPackageGap,5);

  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nSBTColWord",m_nSBTColWord,0);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nSBTRowWord",m_nSBTRowWord,0);

  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLaserProgramNo0",m_nLaserProgramNo[0],0);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLaserProgramNo1",m_nLaserProgramNo[1],1);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLaserProgramNo2",m_nLaserProgramNo[2],2);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLaserProgramNo3",m_nLaserProgramNo[3],3);
                                                                                                                               
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bFindOKMark",m_bFindOKMark,false);                                            
                                                                                                                               
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bIsRailLoad",m_bIsRailLoad,false);                                            
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bReadVenderID",m_bReadVenderID,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseFMCCD",m_bUseFMCCD,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseFMCCD2",m_bUseFMCCD2,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseMapCCD",m_bUseMapCCD,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseLaserMark",m_bUseLaserMark,false);                                        
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseLaserCodeReader",m_bUseLaserCodeReader,false);                            
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseCover",m_bUseCover,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseBoat",m_bUseBoat,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bEAPCoverControl",m_bEAPCoverControl,false);                              
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bEAPBoatControl",m_bEAPBoatControl,false);                                
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bIsSingleSubstrate",m_bIsSingleSubstrate,true);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bUseCoverHolder",m_bUseCoverHolder,false);
  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bShakeSubstarte",m_bShakeSubstarte,false);

  DDXFile_Bool(bRead,pIniFile,Product_Section,"m_bDoubleSide",m_bDoubleSide,false);                           
                                                                                                                           
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nUseTable",m_nUseTable,2);

  DDXFile_String(bRead,pIniFile,Product_Section,"m_strScheduleNo",m_strScheduleNo,"ABCDEFB01");
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nSubLotSize",m_nSubLotSize,10);

  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLEDDimmer0",m_nLEDDimmer[0],0);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLEDDimmer1",m_nLEDDimmer[1],0);

  DDXFile_String(bRead,pIniFile,Product_Section,"m_strSBTType",m_strSBTType,"X4L");
  DDXFile_String(bRead,pIniFile,Product_Section,"m_strSBTSize",m_strSBTSize,"15X15*0.5");

  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nSBTCorner",m_nSBTCorner,0);
  DDXFile_Int(bRead,pIniFile,Product_Section,"m_nLaserQualityThreshold",m_nLaserQualityThreshold,1);
  }
  //pIniFile2
  if(nMode==FILE_MODE_ALL || nMode==FILE_MODE_MACHINE)
  {
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSSPickerPickPos",m_dSSPickerPickPos,0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSSPickerPickRailPos",m_dSSPickerPickRailPos,0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSSPickerPutPos0",m_dSSPickerPutPos[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSSPickerPutPos1",m_dSSPickerPutPos[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSpaPickerPickPos",m_dSpaPickerPickPos,0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSpaPickerThrowPos",m_dSpaPickerThrowPos,0.0);

  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTablePutDownPos0",m_dTablePutDownPos[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTablePutDownPos1",m_dTablePutDownPos[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPosX0",m_dTableMarkPosX[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPosX1",m_dTableMarkPosX[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPosY0",m_dTableMarkPosY[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPosY1",m_dTableMarkPosY[1],0.0);  
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPos2X0",m_dTableMarkPos2X[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPos2X1",m_dTableMarkPos2X[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPos2Y0",m_dTableMarkPos2Y[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableMarkPos2Y1",m_dTableMarkPos2Y[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableVenderCodePosX0",m_dTableVenderCodePosX[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableVenderCodePosX1",m_dTableVenderCodePosX[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableVenderCodePosY0",m_dTableVenderCodePosY[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableVenderCodePosY1",m_dTableVenderCodePosY[1],0.0);


  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserPos0",m_dTableLaserPos[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserPos1",m_dTableLaserPos[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserCodePosX0",m_dTableLaserCodePosX[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserCodePosX1",m_dTableLaserCodePosX[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserCodePosY0",m_dTableLaserCodePosY[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableLaserCodePosY1",m_dTableLaserCodePosY[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTablePickUpPos0",m_dTablePickUpPos[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTablePickUpPos1",m_dTablePickUpPos[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableBackSpeedDown0",m_dTableBackSpeedDown[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableBackSpeedDown1",m_dTableBackSpeedDown[1],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableBackSpeedUp0",m_dTableBackSpeedUp[0],0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dTableBackSpeedUp1",m_dTableBackSpeedUp[1],0.0);


  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSBTNGBoxPos",m_dSBTNGBoxPos,0.0);
  DDXFile_Float(bRead,pIniFile,Product_Section,"m_dSCPickerPutSSPos",m_dSCPickerPutSSPos,0.0);
  }
  //


  delete pIniFile;
}
//---------------------------------------------------------------------------                                              
AnsiString __fastcall CIniFile::GetErrorString(char *SectionName,int nCode)                                                
{                                                                                                                          
  AnsiString strFileName,strErrMsg,strErrMsg1,strCode,strErrName;
  TIniFile *pIniFile;

  if(m_nLanguageMode==0) strErrName=ErrorMessageFileName;
  else strErrName=ErrorMessageEngFileName;

  strFileName.sprintf("%s%s%s",IniFile_Dir,ErrorMessage_Dir,strErrName);
  pIniFile = new TIniFile(strFileName);

  strCode.sprintf("E%04d",nCode);
  if(m_nLanguageMode==0) strErrMsg=pIniFile->ReadString(SectionName,strCode,"未定義錯誤碼!!");
  else strErrMsg=pIniFile->ReadString(SectionName,strCode,"Not Defined Error Code!!!");
  strErrMsg1.sprintf("[%s] %s=%s",SectionName,strCode,strErrMsg);
  delete pIniFile;

  return strErrMsg1+"\n";
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::StoreHistory(int nYear,int nMonth,int nDate,AnsiString strMessage)
{
  AnsiString strFileName;
  TIniFile *pIniFile;
  int nFileMonth,nIndex; 

  strFileName.sprintf("%s\\Message History\\%4d_%02d_%02d.ini",IniFile_Dir,nYear,nMonth,nDate);
  pIniFile = new TIniFile(strFileName);

  nFileMonth=pIniFile->ReadInteger("Control","Month",1);
  nIndex=pIniFile->ReadInteger("Control","Index",1);

  if(nFileMonth!=nMonth)
  {
    nIndex=1;
    pIniFile->WriteInteger("Control","Month",nMonth);
  }

  AnsiString strID;
  strID.sprintf("No%08d",nIndex);
  pIniFile->WriteString("History",strID,strMessage);

  nIndex++;

  strID.sprintf("No%08d",nIndex);
  pIniFile->WriteString("History",strID,"//-------------以下做作廢--------------------//");

  pIniFile->WriteInteger("Control","Index",nIndex);

  delete pIniFile;
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::StoreHistoryNew()
{
  AnsiString strFileName;
  TIniFile *pIniFile;
  int nFileMonth,nIndex;
  time_t timer;
  struct tm *tblock;

  int nSize=m_vecMsg.size();
  if(nSize==0) return;

  AnsiString strMsg;
  strMsg.sprintf("訊息共有 %d 筆\n每筆花費時間約 10 ms\n是否要儲存訊息??",nSize);
  if(Application->MessageBoxA(strMsg.c_str(),"Confirm",MB_ICONQUESTION|MB_OKCANCEL)!=IDOK) return;

   /* gets time of day */
   timer = time(NULL);
   /* converts date/time to a structure */
   tblock = localtime(&timer);
   int nMonth=tblock->tm_mon;
   int nDate=tblock->tm_mday;

  strFileName.sprintf("%s\\Message History\\%d.ini",IniFile_Dir,nDate);
  pIniFile = new TIniFile(strFileName);

  nFileMonth=pIniFile->ReadInteger("Control","Month",1);
  nIndex=pIniFile->ReadInteger("Control","Index",1);

  if(nFileMonth!=nMonth)
  {
    DeleteFile(strFileName);
    nIndex=1;
    pIniFile->WriteInteger("Control","Month",nMonth);
  }

  AnsiString strID;

  for(int nSz=0;nSz<nSize;nSz++)
  {
    strID.sprintf("No%08d",nIndex);
    pIniFile->WriteString("History",strID,m_vecMsg[nSz]);

    nIndex++;
  }
 
  m_vecMsg.clear();
  
  strID.sprintf("No%08d",nIndex);
  pIniFile->WriteString("History",strID,"//-------------以下做作廢--------------------//");

  pIniFile->WriteInteger("Control","Index",nIndex);

  delete pIniFile;
}
//---------------------------------------------------------------------------
bool __fastcall CIniFile::SearchFile(AnsiString strBarCode,AnsiString &strFileName)
{
  WIN32_FIND_DATA FindFileData;
  AnsiString strName;
  char *pFileName;
  TIniFile *pIniFile;
  bool bResult=false;
  
  strName.sprintf("%s*.ini",IniFile_Dir);
  HANDLE hFile=FindFirstFile(strName.c_str(),&FindFileData);
  if(hFile!=INVALID_HANDLE_VALUE)
  {
    while(FindNextFile(hFile,&FindFileData)!=0)
    {
      pFileName=FindFileData.cFileName;
      strName.sprintf("%s%s",IniFile_Dir,pFileName);
      pIniFile = new TIniFile(strName);
      AnsiString strCode=pIniFile->ReadString(Product_Section,"BarCode","0000");
      delete pIniFile;
      if(strCode==strBarCode)
      {
        strFileName=strName;
        bResult=true;
        break;
      }
    }
    FindClose(hFile);
  }

  return bResult;
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::AddNewID(int nLevel,char *strID,char *strPassword)
{
  AnsiString strFile;
  TIniFile *pIniFile;
  char *Level[]={"Operator","Engineer","Supervisor"};

  if(nLevel<0 || nLevel>2) nLevel=0;
                    
  strFile.sprintf("%s%s",IniFile_Dir,UserName);
  pIniFile = new TIniFile(strFile);

  pIniFile->WriteString(Level[nLevel],strID,strPassword);

  delete pIniFile;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CIniFile::ReadPassword(int nLevel,char *strID)
{
         AnsiString strFile;
  TIniFile *pIniFile;
  char *Level[]={"Operator","Engineer","Supervisor"};

  if(nLevel<0 || nLevel>2) nLevel=0;
                    
  strFile.sprintf("%s%s",IniFile_Dir,UserName);
  pIniFile = new TIniFile(strFile);

  AnsiString Pwd=pIniFile->ReadString(Level[nLevel],strID,"NOTFOUND");

  delete pIniFile;

  return Pwd;
}
//---------------------------------------------------------------------------
void __fastcall CIniFile::AddLog(char *pRx,int nSize)
{

    AnsiString strTime;
    time_t timer;
    struct tm *tblock;

    timer = time(NULL);
    tblock = localtime(&timer);

    try{
        FILE *pFile;

        strTime.sprintf("C:\\C82 Log\\%04d_%02d_%02d.txt",tblock->tm_year+1900,tblock->tm_mon+1,tblock->tm_mday);

        pFile=fopen(strTime.c_str(),"a+");

        if(pFile!=NULL)
        {
            fprintf(pFile,"\n[%2d:%02d:%02d] ",tblock->tm_hour,tblock->tm_min, tblock->tm_sec);

                int nIndex=0;
                while(nIndex<nSize)
                {
                    //if(pRx[nIndex]=='>') fprintf(pFile,"%c\n  ",pRx[nIndex]);
                    //else
                    fprintf(pFile,"%c",pRx[nIndex]);
                    nIndex++;
                }
                fclose(pFile);
        }

    } catch(const EAccessViolation &e)
    {

                //Application->MessageBox(e.Message.c_str(), "AddLog Exception",MB_OK);
    }
}
//---------------------------------------------------------------------------
__fastcall CIniFile::CIniFile()
{
    mkdir("C:\\C82 Log");
    mkdir("C:\\C82 Log\\CSV");
}
//---------------------------------------------------------------------------
AnsiString __fastcall CIniFile::GetFileNameWithoutExt(char *strFileName)
{
    char drive[MAXDRIVE];
    char dir[MAXDIR];
    char file[MAXFILE];
    char ext[MAXEXT];
    int flags;

    flags=fnsplit(strFileName,drive,dir,file,ext);

    return file;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CIniFile::GetFileNameWithNewExt(char *strFileName,char *strExtension)
{
    char drive[MAXDRIVE];
    char dir[MAXDIR];
    char file[MAXFILE];
    char ext[MAXEXT];
    int flags;

    flags=fnsplit(strFileName,drive,dir,file,ext);
    AnsiString strName;
    strName.sprintf("%s%s%s.%s",drive,dir,file,strExtension);

    return strName;
}

//---------------------------------------------------------------------------
AnsiString __fastcall CIniFile::GetFileNameWithNewPath(char *strFileName,char *strPathName)
{
    char drive[MAXDRIVE];
    char dir[MAXDIR];
    char file[MAXFILE];
    char ext[MAXEXT];
    int flags;

    flags=fnsplit(strFileName,drive,dir,file,ext);
    AnsiString strName;
    strName.sprintf("%s%s.%s",strPathName,file,ext);

    return strName;
}

