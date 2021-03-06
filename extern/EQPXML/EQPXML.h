//---------------------------------------------------------------------------

#ifndef EQPXMLH
#define EQPXMLH
#include <vcl>
#include "tinyxml.h"
#include "tinystr.h"

#include <ScktComp.hpp>
#include <vector>
#include <list>
//---------------------------------------------------------------------------
class CEQPXML
{
private:
        TCustomWinSocket *m_pSocket;
        //std::vector<AnsiString> m_strCIMMsg;
       unsigned char *receiveRx;
       unsigned char *receive;

public:
        bool m_bOnLine;
        AnsiString m_EqpStatus;       //I:Idle R:Run D:Down
        AnsiString m_CIMStatus;       //0:Offline 1:online/local 2:online/remote
        AnsiString m_strMapDataPath;
        AnsiString m_strMapDataPath2;

        //key parameter;
        AnsiString m_strSupplierName;
        AnsiString m_strRecipeName;
        AnsiString m_strYearCode;
        AnsiString m_strScheduleNo;
        AnsiString m_strHostName;
        AnsiString m_strOperatorName;

        AnsiString m_strMagazineID;

        bool m_bIsGetAttributeAck;
        bool m_bIsCompareSS2Ack;

        std::list<AnsiString> m_listExportStrip;
        std::list<AnsiString> m_listExportMap;
        std::list<AnsiString> m_listSendEvent;

        AnsiString m_strCurrentSSID;
        AnsiString m_strIDUnderStripPassResult;
        AnsiString m_strStripPassResult;
        
public:
        __fastcall CEQPXML();
        __fastcall ~CEQPXML();

        void __fastcall StartComm( TCustomWinSocket *pSocket);
        void __fastcall EndComm();

        void __fastcall ProcessCIM();
        void __fastcall SendEventReport(char *pEvent);
        void __fastcall SendEventReportNew(char *pEvent);
        void __fastcall SendAlarmMessage(char *pID,char *pText);
        void __fastcall SendSetAttribute(char *pSubstrateID);
        void __fastcall SendGetAttribute(char *pSubstrateID);
        void __fastcall SendLotComplete(char *pLotID);
        //void __fastcall ExportMapXML(char *pFilePathName,char *pSSID);
        void __fastcall ExportMapXML(int nSub,int nMainStripNo,int nSubStripNo);
        void __fastcall ExportStripXML(int nSub,int nMainStripNo,int nSubStripNo);
        void __fastcall ExportLinkXML(int nSub,int nMainStripNo,int nSubStripSize);

        int __fastcall LoadStripXML(AnsiString strStripID);

        bool (*StartProcess)(bool bStart);
        bool (*OpenFile)(AnsiString strFileName);
        void (*LotCompleteAck)(AnsiString strAck);

private:
        void __fastcall doHostStatus(char *pRx);
        void __fastcall doDTSet(char *pRx);
        void __fastcall doCIMMsg(char *pRx);
        void __fastcall doQueryVID(char *pRx);
        void __fastcall doEventReportAck(char *pRx);
        void __fastcall doAlarmAck(char *pRx);
        void __fastcall doRCMD(char *pRx);
        void __fastcall doQueryPPID(char *pRx);
        void __fastcall doQueryPPIDNew(char *pRx);
        void __fastcall doQueryPPBody(char *pRx);
        void __fastcall doSetPPBody(char *pRx);
        void __fastcall doSetAttributeAck(char *pRx);
        void __fastcall doGetAttributeAck(char *pRx);
        void __fastcall doKeyParamater(char *pRx);
        void __fastcall doLotCompleteAck(char *pRx);

        void __fastcall SetKeyParameter();
       

        void __fastcall SendXML(char *pMSGID,char *pType,char *pName,char *pValue);
        void __fastcall SendXML(TiXmlDocument &theDoc,bool bAdd=false);
public:
        void __fastcall AddLog(char *pRx,int nSize);
        bool __fastcall Parse103Send101(AnsiString strName);

        void __fastcall UpLoadStrip(AnsiString strScheduleNo);
        void __fastcall UpLoadMap(AnsiString strScheduleNo);



};
#endif
