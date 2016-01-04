//---------------------------------------------------------------------------

#ifndef MainThreadH
#define MainThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <list>
#define MAX_PROCESS 20

#define InitialMachine_Index 0
#define DoTrayLoader_Index 1
#define DoStage_Index 2
#define DoHSLifter_Index 3
#define DoHSPicker_Index 4

#define g_Motion g_MNet
#define ReadDIBit GetDI
#define g_DIO g_MNet
#define ReadDOBit GetDO
//---------------------------------------------------------------------------
struct ProductInfo
{
        int m_nIndex;
        int m_nMapOK;                        //Map OK
        int m_nMapNG;                        //Map NG
        double m_dOffsetAngle;               //Angle for Laser
        double m_nOffsetX;                   //FM CCD for Laser
        double m_nOffsetY;
        double m_nOffset2X;                  //FM CCD for Laser
        double m_nOffset2Y;
        AnsiString m_strVenderID;
        AnsiString m_strLotID;               //Laser print ID
        AnsiString m_strBoatID;
        AnsiString m_strCoverID;
        bool m_bIsSBT2DOK[2];
};

//---------------------------------------------------------------------------
class CMainThread : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        std::list<AnsiString> m_listLog;
        std::list<AnsiString> m_listMarkerLog;
        std::list<AnsiString> m_listTX;     //for all serial command
        std::list<AnsiString> m_listVenderCodeReaderRX;
        std::list<AnsiString> m_listLaserRX;
        std::list<AnsiString> m_listVisionRX;
        std::list<AnsiString> m_listLaserCodeReaderRX;
        std::list<AnsiString> m_listCoverCodeReaderRX;
        std::list<AnsiString> m_listBoatCodeReaderRX;
        std::list<AnsiString> m_listThreadTrace;
        std::list<AnsiString> m_listVisionLog;  
        std::list<AnsiString> m_listPickTable;
        std::list<AnsiString> m_listPutTable;

        std::list<ProductInfo> m_listProductInfo;            
        ProductInfo m_tmpProductInfo[2];

        int nThreadIndex[MAX_PROCESS];		//0:Inti 1:Start Measure
        bool m_bRefresh;

        bool m_bIsHomeDone;
        bool m_bIsAutoMode;
        bool m_bNeedHome;

        //Thread HandShake
        bool m_bLoadRailReady;       //Substrate ready to be pick up
        bool m_bLoadLifterReady;        //Substrate ready to be pick up
        bool m_bSSPickerReady;
        bool m_bTableReady[2];             //Table,Substrate ready to be pick up

        bool m_bSCPickerSSReady;

        bool m_bSSPickerDown;
        bool m_bSpaPickerDown;
        bool m_bSSPicker2Down;
        bool m_bCoverPickerDown;
        bool m_bLEDDown;

        bool m_bStopLoad;
        bool m_bReLoad;
        int m_nSubstrateRemains;
        
        bool m_bStopBlower;
        bool bFrontTable;

        //Lock
        bool m_bIsSSPickeLocked;
        bool m_bIsMapCCDLocked;        //Vender FM MAP CCD Lock
        bool m_bLaserLocked;
        bool m_bLaserReaderLocked;

        //Counter;
        int m_nLaserCount;
        int m_nNGCount;         //Single strip
        int m_nOKCount;         //Single strip
        int m_nOKSummary;
        int m_nNGSummary;
        int m_nStripCount;

        __fastcall CMainThread(bool CreateSuspended);
        void __fastcall SetWorkSpeed();
        void __fastcall SetManualSpeed();

        //Manual Mode
        
        //Homing
        bool __fastcall InitialMachine(int &nThreadIndex);

       //Auto Mode
       void __fastcall doLoadRail(int &nThreadIndex);
       void __fastcall doLoadLifter(int &nThreadIndex);
       void __fastcall doSSPickerFromLifter(int &nThreadIndex);
       void __fastcall doSSPickerFromRail(int &nThreadIndex);
       void __fastcall doTable(int &nThreadIndex,bool bFront);
       void __fastcall doSCPicker(int &nThreadIndex);
       void __fastcall doUnLoadRail(int &nThreadIndex);

       //PreAuto
       bool __fastcall doPreAuto(int &nThreadIndex);

       void __fastcall CheckAlarm();
       void __fastcall ThreadTrace();
};
//---------------------------------------------------------------------------
#endif
