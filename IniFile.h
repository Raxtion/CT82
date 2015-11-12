//---------------------------------------------------------------------------

#ifndef IniFileH
#define IniFileH

#include "vcl.h"
#include <vector>
#include "GlobalFunction.h"


#define System_Section "System"
#define Machine_Section "Machine"
#define Product_Section "Product"

#define FILE_MODE_ALL 0
#define FILE_MODE_PRODUCT 1
#define FILE_MODE_MACHINE 2


#define IniFile_Dir "C:\\Product Data\\"



//---------------------------------------------------------------------------
class CIniFile
{
//Variable
public:
   int m_nErrorCode;
  //System
  int m_nLanguageMode;    //0=Chinese 1=English
  int m_nPriviledge;
  AnsiString m_strARTPassword;
  AnsiString m_strENGPassword;
  AnsiString m_strLastFileName;
  double m_dCycleTimeOut;

  std::vector<AnsiString> m_vecMsg;

  __fastcall CIniFile();

  //-----------------Machine-----------------
   double m_dACCSpeed[10];
  double m_dDECSpeed[10];
  double m_dJogSpeed[10];
  double m_dWorkSpeed[10];

  int m_nImageWidth;
  double m_dImageAngle;

  //IP
  AnsiString m_strVenderID_IP;
  AnsiString m_strLaserID_IP;
  AnsiString m_strCoverID_IP;
  AnsiString m_strBoatID_IP;

  //SMS
  AnsiString m_strSMSServerIP;
  AnsiString m_strSMSClientIP;
  int m_nSMSServerPort;
  int m_nSMSClientPort;
  AnsiString m_strSMSMachineID;
  AnsiString m_strSMSUserID;
  AnsiString m_strSMSPartNo;
  AnsiString m_strSMSLotNo;
  AnsiString m_strSBTLotNo;
  AnsiString m_strProductPgm;
  AnsiString m_strMachinePgm;
  int m_nIssueQty;
  //Map
  AnsiString m_strProductID;

  
  //pos
  double m_dTableMapCCDPosX[2];
  double m_dTableMapCCDPosY[2];
  double m_dTableMapCCDPitch;

  //CCD
  double m_dFMCCDResolution[2];       //0:X 1:Y

  //Map ftp Server
  AnsiString m_strMapFtpIP;
  int m_nMapFtpPort;
  AnsiString m_strMapFtpUserName;
  AnsiString m_strMapFtpPassword;

  //delay time
  int m_nCoverVacTime;              //Vacuum on delay time
  int m_nSubstrateVacTime;


  //-----------------Product-----------------
  AnsiString m_strSBTType;
  AnsiString m_strSBTSize;
  int m_nSBTCorner;     //0: left top 1:right top 2:left down 3: right down

  //Layout
  int m_nCols;
  int m_nRows;
  double m_dColPitch;
  double m_dRowPitch;

  int m_nPackageX;
  int m_nPackageY;
  int m_nDeviceX;
  int m_nDeviceY;
  int m_nPackageGap;

  int m_nSBTColWord;            //0: 1~10  1:10~1 2:A~Z 3:Z~A
  int m_nSBTRowWord;            //0: 1~10  1:10~1 2:A~Z 3:Z~A

  int m_nLEDDimmer[2];

  bool m_bFindOKMark;

  //pos
  double m_dSSPickerPickPos;
  double m_dSSPickerPickRailPos;
  double m_dSSPickerPutPos[2];          //0:Rear Table 1:Front Table
  double m_dSpaPickerPickPos;
  double m_dSpaPickerThrowPos;

  double m_dTablePutDownPos[2];         //0:Rear Table 1:Front Table
  double m_dTableMarkPosX[2];
  double m_dTableMarkPosY[2];
  double m_dTableVenderCodePosX[2];
  double m_dTableVenderCodePosY[2];

  double m_dTableLaserPos[2];
  double m_dTableLaserCodePosX[2];
  double m_dTableLaserCodePosY[2];
  double m_dTablePickUpPos[2];

  double m_dSCPickerPickSSPosY[2];

  double m_dLaserCodeReaderPos[2];      //0: Up Size 1:Down Side
  double m_dSBTNGBoxPos;
  double m_dSCPickerPutSSPos;

  //Laser
  int m_nLaserProgramNo[4];
  AnsiString m_strScheduleNo;
  int m_nSubLotSize;

  //Option
  bool m_bIsRailLoad;   //true:Load Rail false:Load Lifter

  bool m_bReadVenderID;
  bool m_bUseVenderMap;
  bool m_bUseFMCCD;
  bool m_bUseMapCCD;

  bool m_bUseLaserMark;
  bool m_bUseLaserCodeReader;

  bool m_bUseCover;
  bool m_bUseBoat;
  bool m_bEAPCoverControl;
  bool m_bEAPBoatControl;

  bool m_bIsSingleSubstrate;

  int m_nUseTable;

  bool m_bUseCoverHolder;

  bool m_bShakeSubstarte;

  bool m_bForceEject;

  bool m_bDoubleSide;   //

  bool m_bUsePQC;       //non save

//Function
public:
  void __fastcall MachineFile(bool bRead);
  void __fastcall ProductFile(char *strFileName,bool bRead,int nMode);          //Mode 0: All  1: Product   2:Product Pos.
  AnsiString __fastcall GetErrorString(char *SectionName,int nCode);
  void __fastcall StoreHistory(int nYear,int nMonth,int nDate,AnsiString strMessage);
  void __fastcall StoreHistoryNew();
  bool __fastcall SearchFile(AnsiString strBarCode,AnsiString &strFileName);

  void __fastcall AddNewID(int nLevel,char *strID,char *strPassword);
  AnsiString __fastcall ReadPassword(int nLevel,char *strID);
  void __fastcall AddLog(char *pRx,int nSize);

  AnsiString __fastcall GetFileNameWithNewExt(char *strFileName,char *strExtension);
  AnsiString __fastcall GetFileNameWithoutExt(char *strFileName);
  AnsiString __fastcall GetFileNameWithNewPath(char *strFileName,char *strPathName);
};
#endif
