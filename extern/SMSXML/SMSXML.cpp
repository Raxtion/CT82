//---------------------------------------------------------------------------


#pragma hdrstop

#include "SMSXML.h"
//#include "tinyxml.h"
//#include "tinystr.h"

#include "time.h"
#include <dir.h>

#include "stdlib.h"

CSMSXML g_SMSXML;

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall CSMSXML::CSMSXML()
{
        m_strMachineID="SMD-IDPRN-01";
        m_strUserID="A977168";
        m_strPartNo="5B-12-0060G";
        m_strLotNo="130599249.00";
        m_strSerialID="NOT_VALID";

        m_strLotENDResult="NOT_VALID";

        m_nOnLineMode=0;
}
//---------------------------------------------------------------------------
__fastcall CSMSXML::~CSMSXML()
{
        
}

//---------------------------------------------------------------------------
void __fastcall CSMSXML::SendXML(TiXmlDocument &theDoc,bool bServer)
{
        try
        {
                TiXmlPrinter printer;
                theDoc.Accept(&printer);
                const char *NewString=printer.CStr();

                if(bServer) m_listServerTX.push_back(NewString);
                else m_listClientTX.push_back(NewString);

        }
        catch(const EAccessViolation &e)
       {
       
       }
}
//---------------------------------------------------------------------------
void __fastcall CSMSXML::ProcessXML()
{
        if(m_listRX.size()<1) return;

        AnsiString strRX=m_listRX.front();
        m_listRX.pop_front();

        TiXmlDocument doc;
        doc.Parse(strRX.c_str());
        TiXmlElement* pResponse = doc.FirstChildElement("response");
        TiXmlElement* pRequest = doc.FirstChildElement("request");
        TiXmlElement* pRoot=NULL;
        
        if(pResponse) pRoot=pResponse;
        else if(pRequest) pRoot=pRequest;
        else return;

        TiXmlElement* pIdentity= pRoot->FirstChildElement("identity");      if(!pIdentity) return;
        TiXmlElement* pCommandID = pIdentity->FirstChildElement("COMMAND_ID");   if(!pCommandID) return;
        AnsiString strCommandID=pCommandID->GetText();
        TiXmlElement* pTID = pIdentity->FirstChildElement("TID");   if(!pTID) return;
        AnsiString strTID=pTID->GetText();
        TiXmlElement* pMsgType = pIdentity->FirstChildElement("MSG_TYPE");   if(!pMsgType) return;
        AnsiString strMsgType=pMsgType->GetText();

        if(strCommandID=="COMM_MODE_REQUEST")
        {
                if(strMsgType=="R")
                {
                        TiXmlElement* pReturnValue=pRoot->FirstChildElement("returnvalue"); if(!pReturnValue) return;
                        TiXmlElement* pCommMode=pReturnValue->FirstChildElement("COMM_MODE");   if(!pCommMode) return;
                        AnsiString strCommMode=pCommMode->GetText();
                        TiXmlElement* pResult=pReturnValue->FirstChildElement("RESULT");        if(!pResult) return;

                        AnsiString strResult=pResult->GetText();
                        if( (strCommMode=="ONLINE_REMOTE") && (strResult=="SUCCESS") ) m_nOnLineMode=2;
                        else if( (strCommMode=="ONLINE_LOCAL") && (strResult=="SUCCESS") ) m_nOnLineMode=1;
                        else m_nOnLineMode=1;
                }
                else if(strMsgType=="C")
                {
                        TiXmlElement* pParameter=pRoot->FirstChildElement("parameter");     if(!pParameter) return;
                        TiXmlElement* pCommMode=pParameter->FirstChildElement("COMM_MODE");     if(!pCommMode) return;
                        AnsiString strCommMode=pCommMode->GetText();

                        bool bRet=true;
                        if( strCommMode=="ONLINE_REMOTE" ) m_nOnLineMode=2;
                        else if( strCommMode=="ONLINE_LOCAL" ) m_nOnLineMode=1;
                        else bRet=false;

                        ReplyModeChange(strTID,strCommMode,bRet);

                }
        }
        else if(strCommandID=="ID_REQUEST")
        {
                if(strMsgType=="R")
                {
                        TiXmlElement* pReturnValue=pRoot->FirstChildElement("returnvalue"); if(!pReturnValue) return;
                        TiXmlElement* pResult=pReturnValue->FirstChildElement("RESULT");        if(!pResult) return;

                        AnsiString strResult=pResult->GetText();
                        if(strResult=="SUCCESS")
                        {
                                TiXmlElement* pSerialID=pReturnValue->FirstChildElement("SERIAL_ID");        if(!pSerialID) return;
                                m_strSerialID=pSerialID->GetText();
                        }
                        else m_strSerialID="FAIL";
                }
        }
        else if(strCommandID=="ID_REQUEST_END")
        {
                if(strMsgType=="R")
                {
                        TiXmlElement* pReturnValue=pRoot->FirstChildElement("returnvalue"); if(!pReturnValue) return;
                        TiXmlElement* pResult=pReturnValue->FirstChildElement("RESULT");        if(!pResult) return;

                        AnsiString strResult=pResult->GetText();
                        if(strResult=="SUCCESS")
                        {
                                m_strLotENDResult="SUCCESS";
                        }
                        else m_strLotENDResult="FAIL";
                }
        }

}
//---------------------------------------------------------------------------
bool __fastcall CSMSXML::ModeChange(bool bRemote)
{
        //if(m_nOnLineMode==0) return false;
        
        AnsiString strCommandID="COMM_MODE_REQUEST";
        AnsiString strTID="SMS"+FormatDateTime("yyyymmddhhnnss",Now());          //"SMS2008091115059";
        AnsiString strEventTime=FormatDateTime("yyyy/mm/dd hh:nn:ss",Now());    //"2008/09/01 11:50:59";  //GetEventTime()
        AnsiString strCommMode;

        if(bRemote) strCommMode="ONLINE_REMOTE";
        else strCommMode="ONLINE_LOCAL";

        TiXmlDocument doc;
        
        TiXmlElement* pRequest=new TiXmlElement("request");
        //<identity>
        TiXmlElement *pIdentity=new TiXmlElement("identity");
        TiXmlElement *pTID=new TiXmlElement("TID");
                pTID->LinkEndChild(new TiXmlText(strTID.c_str()));
        TiXmlElement *pCommandID=new TiXmlElement("COMMAND_ID");
                pCommandID->LinkEndChild(new TiXmlText(strCommandID.c_str()));
        TiXmlElement *pMsgType=new TiXmlElement("MSG_TYPE");
                pMsgType->LinkEndChild(new TiXmlText("C"));
        TiXmlElement *pMachineID=new TiXmlElement("MACHINE_ID");
                pMachineID->LinkEndChild(new TiXmlText(m_strMachineID.c_str()));
        TiXmlElement *pUserID=new TiXmlElement("USER_ID");
                pUserID->LinkEndChild(new TiXmlText(m_strUserID.c_str()));
        TiXmlElement *pEventTime=new TiXmlElement("EVENTTIME");
                pEventTime->LinkEndChild(new TiXmlText(strEventTime.c_str()));

        pIdentity->LinkEndChild(pTID);
        pIdentity->LinkEndChild(pCommandID);
        pIdentity->LinkEndChild(pMsgType);
        pIdentity->LinkEndChild(pMachineID);
        pIdentity->LinkEndChild(pUserID);
        pIdentity->LinkEndChild(pEventTime);
        
        //<parameter>
        TiXmlElement *pParameter=new TiXmlElement("parameter");
        TiXmlElement *pCommMode=new TiXmlElement("COMM_MODE");
                pCommMode->LinkEndChild(new TiXmlText(strCommMode.c_str()));

        pParameter->LinkEndChild(pCommMode);



        pRequest->LinkEndChild(pIdentity);
        pRequest->LinkEndChild(pParameter);


        doc.LinkEndChild(pRequest);
        SendXML(doc,false);

        return true;
}
//---------------------------------------------------------------------------
void __fastcall CSMSXML::ReplyModeChange(AnsiString strTID,AnsiString strCommMode,bool bPass)
{
        //if(m_nOnLineMode==0) return;
        
        AnsiString strCommandID="COMM_MODE_REQUEST";
        //AnsiString strTID=FormatDateTime("SMSyyyymmddhhnnss",Now());          //"SMS2008091115059";
        AnsiString strEventTime=FormatDateTime("yyyy/mm/dd hh:nn:ss",Now());    //"2008/09/01 11:50:59";  //GetEventTime()
        AnsiString strResult;

        if(bPass) strResult="SUCCESS";
        else strResult="FAIL";

        TiXmlDocument doc;
        
        TiXmlElement* pResponse=new TiXmlElement("response");
        //<identity>
        TiXmlElement *pIdentity=new TiXmlElement("identity");
        TiXmlElement *pTID=new TiXmlElement("TID");
                pTID->LinkEndChild(new TiXmlText(strTID.c_str()));
        TiXmlElement *pCommandID=new TiXmlElement("COMMAND_ID");
                pCommandID->LinkEndChild(new TiXmlText(strCommandID.c_str()));
        TiXmlElement *pMsgType=new TiXmlElement("MSG_TYPE");
                pMsgType->LinkEndChild(new TiXmlText("C"));
        TiXmlElement *pMachineID=new TiXmlElement("MACHINE_ID");
                pMachineID->LinkEndChild(new TiXmlText(m_strMachineID.c_str()));
        TiXmlElement *pUserID=new TiXmlElement("USER_ID");
                pUserID->LinkEndChild(new TiXmlText(m_strUserID.c_str()));
        TiXmlElement *pEventTime=new TiXmlElement("EVENTTIME");
                pEventTime->LinkEndChild(new TiXmlText(strEventTime.c_str()));

        pIdentity->LinkEndChild(pTID);
        pIdentity->LinkEndChild(pCommandID);
        pIdentity->LinkEndChild(pMsgType);
        pIdentity->LinkEndChild(pMachineID);
        pIdentity->LinkEndChild(pUserID);
        pIdentity->LinkEndChild(pEventTime);
        
        //<returnvalue>
        TiXmlElement *pReturnvalue=new TiXmlElement("returnvalue");
        TiXmlElement *pCommMode=new TiXmlElement("COMM_MODE");
                pCommMode->LinkEndChild(new TiXmlText(strCommMode.c_str()));
        TiXmlElement *pResult=new TiXmlElement("RESULT");
                pResult->LinkEndChild(new TiXmlText(strResult.c_str()));

        pReturnvalue->LinkEndChild(pCommMode);
        pReturnvalue->LinkEndChild(pResult);



        pResponse->LinkEndChild(pIdentity);
        pResponse->LinkEndChild(pReturnvalue);


        doc.LinkEndChild(pResponse);
        SendXML(doc,true);
}
//---------------------------------------------------------------------------
void __fastcall CSMSXML::QueryID()
{
        //if(m_nOnLineMode==0) return false;
        m_strSerialID="NOT_VALID";

        AnsiString strCommandID="ID_REQUEST";
        AnsiString strTID="SMS"+FormatDateTime("yyyymmddhhnnss",Now());          //"SMS2008091115059";
        AnsiString strEventTime=FormatDateTime("yyyy/mm/dd hh:nn:ss",Now());    //"2008/09/01 11:50:59";  //GetEventTime()
        
        TiXmlDocument doc;
        
        TiXmlElement* pRequest=new TiXmlElement("request");
        //<identity>
        TiXmlElement *pIdentity=new TiXmlElement("identity");
        TiXmlElement *pTID=new TiXmlElement("TID");
                pTID->LinkEndChild(new TiXmlText(strTID.c_str()));
        TiXmlElement *pCommandID=new TiXmlElement("COMMAND_ID");
                pCommandID->LinkEndChild(new TiXmlText(strCommandID.c_str()));
        TiXmlElement *pMsgType=new TiXmlElement("MSG_TYPE");
                pMsgType->LinkEndChild(new TiXmlText("C"));
        TiXmlElement *pMachineID=new TiXmlElement("MACHINE_ID");
                pMachineID->LinkEndChild(new TiXmlText(m_strMachineID.c_str()));
        TiXmlElement *pUserID=new TiXmlElement("USER_ID");
                pUserID->LinkEndChild(new TiXmlText(m_strUserID.c_str()));
        TiXmlElement *pEventTime=new TiXmlElement("EVENTTIME");
                pEventTime->LinkEndChild(new TiXmlText(strEventTime.c_str()));

        pIdentity->LinkEndChild(pTID);
        pIdentity->LinkEndChild(pCommandID);
        pIdentity->LinkEndChild(pMsgType);
        pIdentity->LinkEndChild(pMachineID);
        pIdentity->LinkEndChild(pUserID);
        pIdentity->LinkEndChild(pEventTime);
        
        //<parameter>
        TiXmlElement *pParameter=new TiXmlElement("parameter");
        TiXmlElement *pSBTPartNo=new TiXmlElement("SBT_PART_NO");
                pSBTPartNo->LinkEndChild(new TiXmlText(m_strPartNo.c_str()));
         TiXmlElement *pSBTLotNo=new TiXmlElement("SBT_LOT_NO");
                pSBTLotNo->LinkEndChild(new TiXmlText(m_strLotNo.c_str()));

        pParameter->LinkEndChild(pSBTPartNo);
        pParameter->LinkEndChild(pSBTLotNo);



        pRequest->LinkEndChild(pIdentity);
        pRequest->LinkEndChild(pParameter);


        doc.LinkEndChild(pRequest);
        SendXML(doc,false);

}
//---------------------------------------------------------------------------
void __fastcall CSMSXML::QueryIDEnd(int nCounts)
{
        //if(m_nOnLineMode==0) return false;

        m_strLotENDResult="NOT_VALID";
        
        AnsiString strCommandID="ID_REQUEST_END";
        AnsiString strTID="SMS"+FormatDateTime("yyyymmddhhnnss",Now());          //"SMS2008091115059";
        AnsiString strEventTime=FormatDateTime("yyyy/mm/dd hh:nn:ss",Now());    //"2008/09/01 11:50:59";  //GetEventTime()
        
        TiXmlDocument doc;
        
        TiXmlElement* pRequest=new TiXmlElement("request");
        //<identity>
        TiXmlElement *pIdentity=new TiXmlElement("identity");
        TiXmlElement *pTID=new TiXmlElement("TID");
                pTID->LinkEndChild(new TiXmlText(strTID.c_str()));
        TiXmlElement *pCommandID=new TiXmlElement("COMMAND_ID");
                pCommandID->LinkEndChild(new TiXmlText(strCommandID.c_str()));
        TiXmlElement *pMsgType=new TiXmlElement("MSG_TYPE");
                pMsgType->LinkEndChild(new TiXmlText("C"));
        TiXmlElement *pMachineID=new TiXmlElement("MACHINE_ID");
                pMachineID->LinkEndChild(new TiXmlText(m_strMachineID.c_str()));
        TiXmlElement *pUserID=new TiXmlElement("USER_ID");
                pUserID->LinkEndChild(new TiXmlText(m_strUserID.c_str()));
        TiXmlElement *pEventTime=new TiXmlElement("EVENTTIME");
                pEventTime->LinkEndChild(new TiXmlText(strEventTime.c_str()));

        pIdentity->LinkEndChild(pTID);
        pIdentity->LinkEndChild(pCommandID);
        pIdentity->LinkEndChild(pMsgType);
        pIdentity->LinkEndChild(pMachineID);
        pIdentity->LinkEndChild(pUserID);
        pIdentity->LinkEndChild(pEventTime);
        
        //<parameter>
        TiXmlElement *pParameter=new TiXmlElement("parameter");
        TiXmlElement *pSBTPartNo=new TiXmlElement("SBT_PART_NO");
                pSBTPartNo->LinkEndChild(new TiXmlText(m_strPartNo.c_str()));
         TiXmlElement *pSBTLotNo=new TiXmlElement("SBT_LOT_NO");
                pSBTLotNo->LinkEndChild(new TiXmlText(m_strLotNo.c_str()));
         TiXmlElement *pSBTCounts=new TiXmlElement("SBT_COUNTS");
                pSBTCounts->LinkEndChild(new TiXmlText(FormatFloat("0",nCounts).c_str()));

        pParameter->LinkEndChild(pSBTPartNo);
        pParameter->LinkEndChild(pSBTLotNo);
        pParameter->LinkEndChild(pSBTCounts);



        pRequest->LinkEndChild(pIdentity);
        pRequest->LinkEndChild(pParameter);


        doc.LinkEndChild(pRequest);
        SendXML(doc,false);

}

