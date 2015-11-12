//---------------------------------------------------------------------------

#ifndef SMSXMLH
#define SMSXMLH
#include <vcl>
#include "tinyxml.h"
#include "tinystr.h"

#include <ScktComp.hpp>
#include <vector>
#include <list>
//---------------------------------------------------------------------------
class CSMSXML
{

public:
        std::list<AnsiString> m_listServerTX;
        std::list<AnsiString> m_listClientTX;
        std::list<AnsiString> m_listRX;

        AnsiString m_strMachineID;
        AnsiString m_strUserID;
        AnsiString m_strPartNo;
        AnsiString m_strLotNo;

        AnsiString m_strSerialID;  //NOT_VALID ID FAIL
        AnsiString m_strLotENDResult;   //NOT_VALID SUCCESS FAIL

        int m_nOnLineMode;      //0:Off line 1:on line local 2:on line remote
       
        
public:
        __fastcall CSMSXML();
        __fastcall ~CSMSXML();

        void __fastcall SendXML(TiXmlDocument &theDoc,bool bServer);
        void __fastcall ProcessXML();

        bool __fastcall ModeChange(bool bRemote);       //true: remote false:local
        void __fastcall ReplyModeChange(AnsiString strTID,AnsiString strCommMode,bool bPass);
        void __fastcall QueryID();
        void __fastcall QueryIDEnd(int nCounts);




};
#endif
