//---------------------------------------------------------------------------


#pragma hdrstop

#include "EQPXML.h"
//#include "tinyxml.h"
//#include "tinystr.h"
#include "IniFile.h"
#include "frmMain.h"
#include <dir.h>

#include "time.h"
#include <dir.h>

#include "stdlib.h"

CEQPXML g_eqpXML;
extern CIniFile g_IniFile;
extern TfmMain *fmMain;; 

#define MAX_SEND_BUFF 10000//2500
//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall CEQPXML::CEQPXML()
{
        m_pSocket=NULL;
        m_EqpStatus="I";
        m_CIMStatus="0";

         mkdir("C:\\EQPXML Log\\");

        mkdir("C:\\UpLoadData");
        mkdir("C:\\UpLoadData\\Strip");
        mkdir("C:\\UpLoadData\\Map");

         receiveRx=(char *)malloc(30000);//new char[30000];
        receive=(char *)malloc(30000);//new char[30000];

        m_strSupplierName="XL MAP";
        m_strRecipeName="KKK";
        m_strYearCode=m_strYearCode=FormatDateTime("yyyy",Now()).SubString(4,1);//"4";
        m_strScheduleNo="99IE00";
        m_strHostName="ASEF3-2845-01";
        m_strOperatorName="2845";
}
//---------------------------------------------------------------------------
__fastcall CEQPXML::~CEQPXML()
{
        free( receiveRx);
        free( receive);
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::StartComm( TCustomWinSocket *pSocket)
{
        m_pSocket=pSocket;
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::EndComm()
{
        m_pSocket=NULL;
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::ProcessCIM()
{
        long nSize=0;
        //char *receiveRx;
        //char *receive;

        try
        {

        //receiveRx=(char *)VirtualAlloc(NULL, 30000, MEM_COMMIT, PAGE_READWRITE);//(char *)malloc(30000);//new char[30000];
        //receive=(char *)VirtualAlloc(NULL, 30000, MEM_COMMIT, PAGE_READWRITE);///(char *)malloc(30000);//new char[30000];

        //char receive[30000];
        if(receive==NULL || receiveRx==NULL) return;

        memset(receiveRx,0x00,30000);
        memset(receive,0x00,30000);

        m_pSocket->ReceiveBuf(receiveRx,30000);
        AddLog(receiveRx,30000);

        TiXmlDocument doc;

        int nIndex=0;

        while(1)
        {
                doc.Clear();
                memset(receive,0x00,30000);
                
                if(nIndex>=30000) break;

                nSize=(receiveRx[0+nIndex]<<24)+(receiveRx[1+nIndex]<<16)+(receiveRx[2+nIndex]<<8)+receiveRx[3+nIndex]+4;//+5;
                 if(nSize<=5 || nSize>=30000)
                        break;

                 AnsiString strXX=FormatFloat("Size=0",nSize);
                AddLog(strXX.c_str(),strXX.Length());

                memcpy(receive,receiveRx+nIndex,nSize);
                nIndex+=nSize;
                if(nIndex>=30000) break;

                AddLog(receive,nSize);

                doc.Parse(receive+5);
                TiXmlElement* pRoot = doc.FirstChildElement("Root");
                if(pRoot==NULL) break;
                //TiXmlElement* pData=pRoot->FirstChildElement("DATA");
        
                AnsiString strMsgID(pRoot->Attribute("MSGID"));
                //AnsiString strData=pData->GetText();

                if(strMsgID=="HOST_STATUS") doHostStatus(receive+5);
                else if(strMsgID=="DTSET") doDTSet(receive+5);
                else if(strMsgID=="CIMMSG") doCIMMsg(receive+5);
                else if(strMsgID=="QUERY_VID") doQueryVID(receive+5);
                else if(strMsgID=="EVENT_REPORT") doEventReportAck(receive+5);
                else if(strMsgID=="ALARM") doAlarmAck(receive+5);
                else if(strMsgID=="RCMD") doRCMD(receive+5);
                else if(strMsgID=="QUERY_PPID") doQueryPPIDNew(receive+5);
                else if(strMsgID=="QUERY_PPBODY") doQueryPPBody(receive+5);
                else if(strMsgID=="SET_PPBODY") doSetPPBody(receive+5);
                else if(strMsgID=="SET_ATTRIBUTE") doSetAttributeAck(receive+5);
                else if(strMsgID=="GET_ATTRIBUTE") doGetAttributeAck(receive+5);
                else if(strMsgID=="KEY_PARAMETER") doKeyParamater(receive+5);
                else if(strMsgID=="ICMD") doLotCompleteAck(receive+5);

        }

       //delete receive;
       //delete receiveRx;
       
       }
       catch(const EAccessViolation &e)
       {
        //Application->MessageBox(e.Message.c_str(), "Look", MB_OK);
        //g_IniFile.AddLog("catch ProcessCIM");
        AddLog("DoProcessCIM Exception!",100);
        
        //delete receive;
        //delete receiveRx;
       }

}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendXML(char *pMSGID,char *pType,char *pTextName,char *pValue)
{
        char send[MAX_SEND_BUFF]={0};
        char A[MAX_SEND_BUFF]={0};

        try
        {
        sprintf(A,"<?xml version=\"1.0\" encoding=\"utf-8\" ?><Root MSGID=\"%s\" TYPE=\"%s\" ><%s>%s</%s></Root>",pMSGID,pType,pTextName,pValue,pTextName);
        
        sprintf(send,"%c%c%c%c%c%s",0x00,0x00,0x00,strlen(A)+1,0x00,A);


       if(m_pSocket!=NULL && m_bOnLine)
       {
                m_pSocket->SendBuf(send,strlen(A)+5);
                AddLog(send,strlen(A)+5);
                
                //m_pSocket->SendBuf(send,MAX_SEND_BUFF);
                //g_IniFile.AddLog(send);
       }
       }
       catch(const EAccessViolation &e)
       {
        //Application->MessageBox(e.Message.c_str(), "Look2", MB_OK);
        AddLog("Send XML Exception",18);

       }

}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doHostStatus(char *pRx)
{
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("DATA");

        AnsiString strMsgID(pRoot->Attribute("MSGID"));
        AnsiString strData=pData->GetText();

        if(strData=="1") m_CIMStatus="1";
        else if(strData=="0") m_CIMStatus="0";
        else if(strData=="2") m_CIMStatus="2";
        else m_CIMStatus="0";

        //SendXML("HOST_STATUS","ACK","ACK","");

        pRoot->SetAttribute("TYPE","ACK");
        pData->SetValue("ACK");
        TiXmlNode *pNode3=pData->FirstChild();
        pNode3->SetValue("");

        SendXML(doc);

}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doDTSet(char *pRx)
{
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("DATA");

        AnsiString strMsgID(pRoot->Attribute("MSGID"));
        AnsiString strData=pData->GetText();
        //Set System Date Time Here

        SendXML("DTSET","ACK","ACK","0");           //0:OK 1:NG
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doCIMMsg(char *pRx)
{
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("DATA");

        AnsiString strMsgID(pRoot->Attribute("MSGID"));
        AnsiString strData=pData->GetText();
        //do something whith that message
        //m_strCIMMsg.push_back(strData);
        //g_pAutoRunThread->AddMessage(strData);
        //if(!g_pAutoRunThread->m_bIsRunning) g_pAutoRunThread->ShowAlarmMessage();


        SendXML("CIMMSG","ACK","ACK","0");           //0:OK 1:NG
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendEventReport(char *pEvent)
{

        SendXML("EVENT_REPORT","RPT","CEID",pEvent);

}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendEventReportNew(char *pEvent)
{
        char drive[MAXDRIVE];
        char dir[MAXDIR];
        char file[MAXFILE];
        char ext[MAXEXT];
        int flags;

        flags=fnsplit(g_IniFile.m_strLastFileName.c_str(),drive,dir,file,ext);


         TiXmlDocument doc2;
         TiXmlElement* pRoot=new TiXmlElement("Root");
         pRoot->SetAttribute("MSGID","EVENT_REPORT");
         pRoot->SetAttribute("TYPE","RPT");
         //pRoot->SetAttribute("TID","");


           TiXmlElement* pCEID=new TiXmlElement("CEID");
         pCEID->LinkEndChild(new TiXmlText(pEvent));

         TiXmlElement* pData=new TiXmlElement("DATA");
         //pData->SetAttribute("CEID",pCEID);
         //pData->SetAttribute("SxFy",pSxFy);


        TiXmlElement* pSVID;
        TiXmlElement* pID;
        TiXmlElement* pValue;

        char SVID[21][300]={0};     //100->300
       TDateTime DT=TDateTime::CurrentDateTime();


       //SVID 1
       strcpy(SVID[0],DT.FormatString("yyyymmddhhnnss").c_str());
       strcpy(SVID[1],"CT-11");
       strcpy(SVID[2],g_IniFile.m_nEQPID.c_str());
       strcpy(SVID[3],fmMain->labelVersion->Caption.c_str());
       strcpy(SVID[4],/*fmMain->labelID->Caption.c_str()*/"OP");
       strcpy(SVID[5],file);
       strcpy(SVID[6],m_EqpStatus.c_str());             //Equipment process state (I=Idle, R=Run, D=Down)
       strcpy(SVID[7],m_CIMStatus.c_str());            //CIM control state (0=Offline, 1=Online/Local, 2=Online/Remote)
       strcpy(SVID[8],"Lot ID");
       strcpy(SVID[9],"MID");
       strcpy(SVID[10],"Material package");
       strcpy(SVID[11],g_IniFile.m_strScheduleNo.c_str());
       //strcpy(SVID[12],g_IniFile.m_vectMoveInData[0].m_strPartNo.c_str());
       //strcpy(SVID[13],g_IniFile.m_vectMoveInData[0].m_strLotNo.c_str());
       //if(g_pAutoRunThread->m_listBatchProfile.size()>0 && strcmp(pEvent,"11")==0)
       {
                //strcpy(SVID[14],FormatFloat("0",g_pAutoRunThread->m_listBatchProfile.front().nOKCount ).c_str());  //ok count

       }
       //else strcpy(SVID[14],"0");
       strcpy(SVID[15],FormatFloat("0",g_IniFile.m_nStripPerMgz).c_str());
       //if(g_pAutoRunThread->m_listBatchProfile.size()>0 && strcmp(pEvent,"11")==0)
       {
                //strcpy(SVID[16],FormatFloat("0",g_pAutoRunThread->m_listBatchProfile.front().nNGCount ).c_str());  //ng count
                //g_pAutoRunThread->m_listBatchProfile.pop_front();
       }
       //else strcpy(SVID[16],"0");
       strcpy(SVID[17],m_strMagazineID.c_str()); //MgzID
       strcpy(SVID[18],g_IniFile.m_vectMoveInData[0].m_strVenderCode.c_str());


       AnsiString strVenderCode,strPartNo,strLotNo;

       for(int nIndex=0;nIndex<g_IniFile.m_vectMoveInData.size();nIndex++)
       {
                if(g_IniFile.m_vectMoveInData[nIndex].m_strVenderCode.Length()>1) strVenderCode+=g_IniFile.m_vectMoveInData[nIndex].m_strVenderCode+"_";
                if(g_IniFile.m_vectMoveInData[nIndex].m_strPartNo.Length()>1) strPartNo+=g_IniFile.m_vectMoveInData[nIndex].m_strPartNo+"_";
                if(g_IniFile.m_vectMoveInData[nIndex].m_strLotNo.Length()>1) strLotNo+=g_IniFile.m_vectMoveInData[nIndex].m_strLotNo+"_";
       }

       strcpy(SVID[12],strPartNo.c_str());
       strcpy(SVID[13],strLotNo.c_str());
       strcpy(SVID[18],strVenderCode.c_str());

       int nX,nY;
        nX=g_IniFile.m_nDeviceX[0]*g_IniFile.m_nPackageX[0]+g_IniFile.m_nDeviceX[1]*g_IniFile.m_nPackageX[1]*(g_IniFile.m_nTotalPackage-1);
        nY=g_IniFile.m_nDeviceY[0];

        strcpy(SVID[19],FormatFloat("0",nX).c_str());
        strcpy(SVID[20],FormatFloat("0",nY).c_str());


       //SVID 1
        for(int nIndex=0;nIndex<21;nIndex++)
        {
        pSVID=new TiXmlElement("SVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(SVID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

        //SVID 50
        AnsiString strSSID2D="NO_ID_AVALIABLE";
        //if(g_pAutoRunThread->m_listSSID_2D.size()>0 ) strSSID2D=g_pAutoRunThread->m_listSSID_2D.front().c_str();
        pSVID=new TiXmlElement("SVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",49+1).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(strSSID2D.c_str()));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);


        char ECID[10][100]={0};
        //501
        strcpy(ECID[0],FormatFloat("0",g_IniFile.m_bUseSSPicker).c_str());
        strcpy(ECID[1],FormatFloat("0",g_IniFile.m_bUseCoverPicker).c_str());
        strcpy(ECID[2],FormatFloat("0",g_IniFile.m_bUseCoverLifter).c_str());
        strcpy(ECID[3],FormatFloat("0",g_IniFile.m_bUseSafetyDoor).c_str());
        strcpy(ECID[4],FormatFloat("0",g_IniFile.m_nPickSSDelayTime).c_str());
        strcpy(ECID[5],FormatFloat("0",g_IniFile.m_nPickSpacerDelayTime).c_str());
        strcpy(ECID[6],FormatFloat("0",g_IniFile.m_nPickSpacerUpDelayTime).c_str());
        strcpy(ECID[7],FormatFloat("0",g_IniFile.m_nPickSSUpDelayTime).c_str());
        strcpy(ECID[8],FormatFloat("0",g_IniFile.m_dSSLifterRelMoveDis).c_str());
        //601
        strcpy(ECID[9],FormatFloat("0",g_IniFile.m_bStripMap).c_str());

        for(int nIndex=0;nIndex<9;nIndex++)
        {
        pSVID=new TiXmlElement("ECID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+501).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(ECID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

         for(int nIndex=9;nIndex<10;nIndex++)
        {
        pSVID=new TiXmlElement("ECID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",(nIndex-9)+601).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(ECID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }



        char DVID[15][100]={0};
        AnsiString strSchedule;

        if(g_IniFile.m_strScheduleNo.Length()>=10)
        {
                /*
             strSchedule=strSchedule.sprintf("%s%03d %02d",g_IniFile.m_strScheduleNo.SubString(1,7),
                        g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+(g_pAutoRunThread->m_nStripCount/g_IniFile.m_nStripPerMgz),
                                (g_pAutoRunThread->m_nStripCount%g_IniFile.m_nStripPerMgz));
                        */
        }
        else strSchedule="01ABCDE001 01";

        strcpy(DVID[0],"60");
        strcpy(DVID[2],FormatFloat("0",g_IniFile.m_bStripMap).c_str());

        int nSub=g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+((g_pAutoRunThread->m_nStripCount-1)/g_IniFile.m_nStripPerMgz);
        int nSubStripNo;
        if(g_pAutoRunThread->m_nStripCount>0)
                nSubStripNo=((g_pAutoRunThread->m_nStripCount-1)%g_IniFile.m_nStripPerMgz)+1;
        else nSubStripNo=1;

       if(strcmp(pEvent,"101")!=0)
       {
        AnsiString strStripID=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",nSubStripNo);
        m_strMapDataPath2="C:\\UpLoadData\\Map\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+FormatFloat("000",nSub)+"\\"+strStripID+".xml";
       }
       else if(m_listExportMap.size()>0)
       {
                m_strMapDataPath2=m_listExportMap.front();
                m_listExportMap.pop_front();

       }

       if(!FileExists(m_strMapDataPath2)) m_strMapDataPath2="C:\\MapData1\\99-99IE00-001-001.xml";
       strcpy(DVID[3],m_strMapDataPath2.c_str());

      if(strcmp(pEvent,"103")!=0)
       {
        int nSub2=g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+(g_pAutoRunThread->m_nStripCount/g_IniFile.m_nStripPerMgz);
        m_strMapDataPath="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub2)+".xml";
      }
      else if(m_listExportStrip.size()>0)
       {
                m_strMapDataPath=m_listExportStrip.front();
                m_listExportStrip.pop_front();

       }

      if(!FileExists(m_strMapDataPath)) m_strMapDataPath="C:\\MapData\\99-99IE00-001.xml";

      strcpy(DVID[1],m_strMapDataPath.c_str());

      strcpy(DVID[4],"Clare");//SupplierName
      strcpy(DVID[5],"AAA");//RecipeName -->Operation ID
      strcpy(DVID[6],"BBB");//YearCode


      strcpy(DVID[7],strSchedule.c_str());//ScheduleNo
      strcpy(DVID[8],"1");//WaferLot
      strcpy(DVID[9],"1");//WaferId
      strcpy(DVID[10],"1");//WaferNo
      strcpy(DVID[11],"1");//CarrierNo
      strcpy(DVID[12],"1");//SlotNo
      strcpy(DVID[13],FormatFloat("0",g_IniFile.m_nDeviceX[0]+g_IniFile.m_nDeviceX[1]).c_str() );//ColumnCount
      strcpy(DVID[14],FormatFloat("0",g_IniFile.m_nDeviceY[0]).c_str() );//RowCount

        for(int nIndex=0;nIndex<1;nIndex++)
        {
        pSVID=new TiXmlElement("DVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1001).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(DVID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

        for(int nIndex=1;nIndex<15;nIndex++)
        {
        pSVID=new TiXmlElement("DVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1100).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(DVID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

        pRoot->LinkEndChild(pCEID);
        pRoot->LinkEndChild(pData);
        doc2.LinkEndChild(pRoot);



        SendXML(doc2,false);
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendXML(TiXmlDocument &theDoc,bool bAdd)
{
try
{
         TiXmlPrinter printer;
        theDoc.Accept(&printer);
        const char *NewString=printer.CStr();
        AnsiString strNewString="<?xml version=\"1.0\" encoding=\"utf-8\"?>";

        long nLen=0;
        if(bAdd)
        {
                strNewString=strNewString+NewString;
                NewString=strNewString.c_str();
                //nLen=strNewString.Length()+1;
        }

        nLen=strlen(NewString)+1;
        /*
        while(1)
        {
                if(NewString[nLen]==0x00 ) break;
                nLen++;
        }
        */
        
        char *send=(char *)malloc(30000);//(strlen(NewString)+5);
        memset(send,0x00,strlen(NewString)+5);
        //char *send=new char[MAX_SEND_BUFF];
        if(send==NULL) return;

        unsigned char strLen[4]={0};
        strLen[0]=(nLen & 0xff000000)>>24;
        strLen[1]=(nLen & 0x00ff0000)>>16;
        strLen[2]=(nLen & 0x0000ff00)>>8;
        strLen[3]=(nLen & 0x000000ff);

        if(send!=NULL) sprintf(send,"%c%c%c%c%c%s",strLen[0],strLen[1],strLen[2],strLen[3],0x00,NewString);

       if(m_pSocket!=NULL && m_bOnLine)
       {
                m_pSocket->SendBuf(send,strlen(NewString)+5);
                AddLog(send,strlen(NewString)+5   );
                //m_pSocket->SendBuf(send,MAX_SEND_BUFF);
                //g_IniFile.AddLog("Send XML");
       }
       

       free(send);

}
catch(const EAccessViolation &e)
       {
        //Application->MessageBox(e.Message.c_str(), "Look3", MB_OK);
        AddLog("Send XML Exception!!",20);
        //delete send;
       }
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doQueryVID(char *pRx)
{
        char drive[MAXDRIVE];
        char dir[MAXDIR];
        char file[MAXFILE];
        char ext[MAXEXT];
        int flags;

        flags=fnsplit(g_IniFile.m_strLastFileName.c_str(),drive,dir,file,ext);

         TiXmlDocument doc;
         doc.Clear();

        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("DATA");

        AnsiString strMsgID(pRoot->Attribute("MSGID"));
        AnsiString strData=pData->GetText();

        //const char *pTID=pRoot->Attribute("TID");
        const char *pCEID=pData->Attribute("CEID");
        const char *pSxFy=pData->Attribute("SxFy");
        //do something whith that message

        pRoot->SetAttribute("TYPE","ACK");


         TiXmlDocument doc2;
         pRoot=new TiXmlElement("Root");
         pRoot->SetAttribute("MSGID","QUERY_VID");
         pRoot->SetAttribute("TYPE","ACK");
         //pRoot->SetAttribute("TID","");

         pData=new TiXmlElement("DATA");

         pData->SetAttribute("CEID",pCEID);
         pData->SetAttribute("SxFy",pSxFy);


        TiXmlElement* pSVID;
        TiXmlElement* pID;
        TiXmlElement* pValue;

        char SVID[21][300]={0};
       TDateTime DT=TDateTime::CurrentDateTime();


       //SVID 1
       strcpy(SVID[0],DT.FormatString("yyyymmddhhnnss").c_str());
       strcpy(SVID[1],"CT-11");
       strcpy(SVID[2],g_IniFile.m_nEQPID.c_str());
       strcpy(SVID[3],fmMain->labelVersion->Caption.c_str());
       strcpy(SVID[4],/*fmMain->labelID->Caption.c_str()*/"OP");
       strcpy(SVID[5],file);
       strcpy(SVID[6],m_EqpStatus.c_str());             //Equipment process state (I=Idle, R=Run, D=Down)
       strcpy(SVID[7],m_CIMStatus.c_str());            //CIM control state (0=Offline, 1=Online/Local, 2=Online/Remote)
       strcpy(SVID[8],"Lot ID");
       strcpy(SVID[9],"MID");
       strcpy(SVID[10],"Material package");
       strcpy(SVID[11],g_IniFile.m_strScheduleNo.c_str());
       strcpy(SVID[12],g_IniFile.m_vectMoveInData[0].m_strPartNo.c_str());
       strcpy(SVID[13],g_IniFile.m_vectMoveInData[0].m_strLotNo.c_str());
       strcpy(SVID[14],FormatFloat("0",0).c_str());  //ok count
       strcpy(SVID[15],FormatFloat("0",g_IniFile.m_nStripPerMgz).c_str());
       strcpy(SVID[16],FormatFloat("0",0).c_str()); //ng count
       strcpy(SVID[17],"MgzID"); //MgzID
       strcpy(SVID[18],g_IniFile.m_vectMoveInData[0].m_strVenderCode.c_str());


       AnsiString strVenderCode;
       
       for(int nIndex=0;nIndex<g_IniFile.m_vectMoveInData.size();nIndex++)
        strVenderCode+=g_IniFile.m_vectMoveInData[nIndex].m_strVenderCode+"_";

       strcpy(SVID[18],strVenderCode.c_str());

       int nX,nY;
        nX=g_IniFile.m_nDeviceX[0]*g_IniFile.m_nPackageX[0]+g_IniFile.m_nDeviceX[1]*g_IniFile.m_nPackageX[1]*(g_IniFile.m_nTotalPackage-1);
        nY=g_IniFile.m_nDeviceY[0];

        strcpy(SVID[19],FormatFloat("0",nX).c_str());
        strcpy(SVID[20],FormatFloat("0",nY).c_str());
       //SVID 1
        for(int nIndex=0;nIndex<21;nIndex++)
        {
                pSVID=new TiXmlElement("SVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(SVID[nIndex]));
                pSVID->LinkEndChild(pID);
                pSVID->LinkEndChild(pValue);
                pData->LinkEndChild(pSVID);
        }

        //SVID 48,49
        pSVID=new TiXmlElement("SVID");
        pID=new TiXmlElement("ID");
        pID->LinkEndChild(new TiXmlText(FormatFloat("0",48).c_str()));
        pValue=new TiXmlElement("VALUE");
        pValue->LinkEndChild(new TiXmlText(m_strStripPassResult.c_str()));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);

        pSVID=new TiXmlElement("SVID");
        pID=new TiXmlElement("ID");
        pID->LinkEndChild(new TiXmlText(FormatFloat("0",49).c_str()));
        pValue=new TiXmlElement("VALUE");
        pValue->LinkEndChild(new TiXmlText(m_strIDUnderStripPassResult.c_str()));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);


        char ECID[10][100]={0};
        //501
        strcpy(ECID[0],FormatFloat("0",g_IniFile.m_bUseSSPicker).c_str());
        strcpy(ECID[1],FormatFloat("0",g_IniFile.m_bUseCoverPicker).c_str());
        strcpy(ECID[2],FormatFloat("0",g_IniFile.m_bUseCoverLifter).c_str());
        strcpy(ECID[3],FormatFloat("0",g_IniFile.m_bUseSafetyDoor).c_str());
        strcpy(ECID[4],FormatFloat("0",g_IniFile.m_nPickSSDelayTime).c_str());
        strcpy(ECID[5],FormatFloat("0",g_IniFile.m_nPickSpacerDelayTime).c_str());
        strcpy(ECID[6],FormatFloat("0",g_IniFile.m_nPickSpacerUpDelayTime).c_str());
        strcpy(ECID[7],FormatFloat("0",g_IniFile.m_nPickSSUpDelayTime).c_str());
        strcpy(ECID[8],FormatFloat("0",g_IniFile.m_dSSLifterRelMoveDis).c_str());
        //601
        strcpy(ECID[9],FormatFloat("0",g_IniFile.m_bStripMap).c_str());

        for(int nIndex=0;nIndex<9;nIndex++)
        {
        pSVID=new TiXmlElement("ECID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+501).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(ECID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

         for(int nIndex=9;nIndex<10;nIndex++)
        {
        pSVID=new TiXmlElement("ECID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",(nIndex-9)+601).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(ECID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }



        char DVID[15][100]={0};
        AnsiString strSchedule;

        if(g_IniFile.m_strScheduleNo.Length()>=10)
        {
             strSchedule=strSchedule.sprintf("%s%03d %02d",g_IniFile.m_strScheduleNo.SubString(1,7),
                        g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+(g_pAutoRunThread->m_nStripCount/g_IniFile.m_nStripPerMgz),
                                (g_pAutoRunThread->m_nStripCount%g_IniFile.m_nStripPerMgz));
        }
        else strSchedule="01ABCDE001 01";

        strcpy(DVID[0],"60");
        strcpy(DVID[2],FormatFloat("0",g_IniFile.m_bStripMap).c_str());

        int nSub=g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+((g_pAutoRunThread->m_nStripCount-1)/g_IniFile.m_nStripPerMgz);
        int nSubStripNo;
        if(g_pAutoRunThread->m_nStripCount>0)
                nSubStripNo=((g_pAutoRunThread->m_nStripCount-1)%g_IniFile.m_nStripPerMgz)+1;
        else nSubStripNo=1;


      //if(strcmp(pCEID,"101")!=0)
       {
        AnsiString strStripID=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",nSubStripNo);
        m_strMapDataPath2="C:\\UpLoadData\\Map\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+FormatFloat("000",nSub)+"\\"+strStripID+".xml";
       }
       /*
       else if(m_listExportMap.size()>0)
       {
                m_strMapDataPath2=m_listExportMap.front();
                m_listExportMap.pop_front();

       }
       */

       if(!FileExists(m_strMapDataPath2)) m_strMapDataPath2="C:\\MapData1\\99-99IE00-001-001.xml";
       strcpy(DVID[3],m_strMapDataPath2.c_str());

      //if(strcmp(pCEID,"103")!=0)
       {
        int nSub2=g_IniFile.m_strScheduleNo.SubString(8,3).ToInt()+(g_pAutoRunThread->m_nStripCount/g_IniFile.m_nStripPerMgz);
        m_strMapDataPath="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub2)+".xml";
      }
      /*
      else if(m_listExportStrip.size()>0)
       {
                m_strMapDataPath=m_listExportStrip.front();
                m_listExportStrip.pop_front();

       }
       */

      if(!FileExists(m_strMapDataPath)) m_strMapDataPath="C:\\MapData\\99-99IE00-001.xml";
      strcpy(DVID[1],m_strMapDataPath.c_str());

      strcpy(DVID[4],"Clare");//SupplierName
      strcpy(DVID[5],"AAA");//RecipeName -->Operation ID
      strcpy(DVID[6],"BBB");//YearCode


      strcpy(DVID[7],strSchedule.c_str());//ScheduleNo
      strcpy(DVID[8],"1");//WaferLot
      strcpy(DVID[9],"1");//WaferId
      strcpy(DVID[10],"1");//WaferNo
      strcpy(DVID[11],"1");//CarrierNo
      strcpy(DVID[12],"1");//SlotNo
      strcpy(DVID[13],FormatFloat("0",g_IniFile.m_nDeviceX[0]+g_IniFile.m_nDeviceX[1]).c_str() );//ColumnCount
      strcpy(DVID[14],FormatFloat("0",g_IniFile.m_nDeviceY[0]).c_str() );//RowCount

        for(int nIndex=0;nIndex<1;nIndex++)
        {
        pSVID=new TiXmlElement("DVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1001).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(DVID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

        for(int nIndex=1;nIndex<15;nIndex++)
        {
        pSVID=new TiXmlElement("DVID");
                pID=new TiXmlElement("ID");
                pID->LinkEndChild(new TiXmlText(FormatFloat("0",nIndex+1100).c_str()));
                pValue=new TiXmlElement("VALUE");
                pValue->LinkEndChild(new TiXmlText(DVID[nIndex]));
        pSVID->LinkEndChild(pID);
        pSVID->LinkEndChild(pValue);
        pData->LinkEndChild(pSVID);
        }

        pRoot->LinkEndChild(pData);
        doc2.LinkEndChild(pRoot);



        SendXML(doc2,true);



}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doEventReportAck(char *pRx)
{
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("ACK");

        //do something for that
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendAlarmMessage(char *pID,char *pText)
{
        TiXmlDocument doc;
        TiXmlElement* pRoot;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","ALARM");
        pRoot->SetAttribute("TYPE","RPT");

        TiXmlElement *pIDE=new TiXmlElement("ID");
        pIDE->LinkEndChild(new TiXmlText(pID));

         TiXmlElement *pTxt=new TiXmlElement("TEXT");
        pTxt->LinkEndChild(new TiXmlText(pText));

        pRoot->LinkEndChild(pIDE);
        pRoot->LinkEndChild(pTxt);

        doc.LinkEndChild(pRoot);
        SendXML(doc);


}

//---------------------------------------------------------------------------
void __fastcall CEQPXML::doAlarmAck(char *pRx)
{
        /*
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("ACK");
        */
        //do something for that
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doRCMD(char *pRx)
{
        bool bRet=false;
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pData=pRoot->FirstChildElement("DATA");

        AnsiString strData=pData->GetText();            //RUN/STOP/PAUSE/RESUME/PPSELECT,PPID/LOCAL/REMOTE
        AnsiString strSub=strData.SubString(0,8);

        
        if(strSub=="RUN") bRet=StartProcess(true);
        else if(strSub=="RESUME") bRet=StartProcess(true);
        else if(strSub=="STOP") bRet=StartProcess(false);
        else if(strSub=="PAUSE")bRet=StartProcess(false);
        else if(strSub=="PPSELECT")
        {
                AnsiString strName=strData.SubString(10,strData.Length()-9);
                AnsiString strFile;
                strFile.sprintf("C:\\Product Data\\%s\\%s.ini",strName,strName);
                bRet=OpenFile(strFile);

        }
        else if(strSub=="EQPDATA")
        {
                TiXmlElement* pStripType=pData->FirstChildElement("StripType");
                if(pStripType) g_IniFile.m_strSupplierName=pStripType->GetText();

                TiXmlElement* pScheduleQty=pData->FirstChildElement("ScheduleQty");
                if(pScheduleQty) g_IniFile.m_nScheduleQty=atoi(pScheduleQty->GetText());

                TiXmlElement* pYearCode=pData->FirstChildElement("YearCode");
                if(pYearCode) m_strYearCode=pYearCode->GetText();
                else m_strYearCode=FormatDateTime("yyyy",Now()).SubString(4,1);

                TiXmlElement* pStripNum=pData->FirstChildElement("StripNum");
                if(pStripNum) g_IniFile.m_nStripPerMgz=atoi(pStripNum->GetText());

                TiXmlElement* pChk2DByPass=pData->FirstChildElement("Chk2DByPass");
                if(pChk2DByPass)
                {
                        strData=pChk2DByPass->GetText();
                        if( strData== "Y" ) g_IniFile.m_bByPassCheckSS2D=true;
                        else g_IniFile.m_bByPassCheckSS2D=false;
                }

                if(g_IniFile.m_strSupplierName=="X4L2 MAP") g_IniFile.m_nSubstrateBlocks=2;
                else if(g_IniFile.m_strSupplierName=="L DOFU") g_IniFile.m_nSubstrateBlocks=4;
                else g_IniFile.m_nSubstrateBlocks=1;            //XL MAP , L MAP

                TiXmlElement* pSubCommandName=pData->FirstChildElement("SubCommandName");
                TiXmlElement* pSTATUS=pData->FirstChildElement("STATUS");
                if(pSubCommandName)
                {
                        AnsiString strSubCommandName=pSubCommandName->GetText();
                        if(strSubCommandName=="Vendor2DIDCheck")
                        {
                                if(pSTATUS)
                                {
                                        strData=pSTATUS->GetText();
                                        if(strData=="PASS") m_bIsCompareSS2Ack=true;
                                        else m_bIsCompareSS2Ack=false;
                                }
                        }
                }

                 g_IniFile.m_bEQPDataAck=true;

                bRet=true;

        }
        else if(strSub=="LOCAL")
        {
                m_CIMStatus="1";
                bRet=true;
        }
        else if(strSub=="REMOTE")
        {
                m_CIMStatus="2";
                bRet=true;
        }
        else
        {
                SendXML("RCMD","ACK","ACK","1");
                return;
        }

         if(bRet) SendXML("RCMD","ACK","ACK","0");
         else SendXML("RCMD","ACK","ACK","2");
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doQueryPPID(char *pRx)
{

         TiXmlDocument doc;
        TiXmlElement* pRoot;
        TiXmlElement *pIDE;
        AnsiString strName;
        WIN32_FIND_DATA FindFileData;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","QUERY_PPID");
        pRoot->SetAttribute("TYPE","ACK");

        strName.sprintf("%s*.ini",IniFile_Dir);
        HANDLE hFile=FindFirstFile(strName.c_str(),&FindFileData);
        if(hFile!=INVALID_HANDLE_VALUE)
        {
                do
                { 
                        strName.sprintf("%s%s",IniFile_Dir,FindFileData.cFileName);
                        pIDE=new TiXmlElement("PPID");
                        pIDE->LinkEndChild(new TiXmlText(strName.c_str()));
                        pRoot->LinkEndChild(pIDE);
                }while(FindNextFile(hFile,&FindFileData)!=0);
        }
        else
        {
                pIDE=new TiXmlElement("PPID");
                pIDE->LinkEndChild(new TiXmlText(""));
                pRoot->LinkEndChild(pIDE);
        }

        doc.LinkEndChild(pRoot);
        SendXML(doc,true);


}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doQueryPPIDNew(char *pRx)
{
         TiXmlDocument doc;
        TiXmlElement* pRoot;
        TiXmlElement *pIDE;
        AnsiString strName;
        WIN32_FIND_DATA FindFileData;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","QUERY_PPID");
        pRoot->SetAttribute("TYPE","ACK");

        TSearchRec sr;
        //int iAttributes = 0;

        int nRes=FindFirst("C:\\Product Data\\*",faDirectory,sr);
        if(nRes==0)
        {
                do
                {
                        if(sr.Attr==faDirectory)
                        {
                                if(sr.Name!="." && sr.Name!=".." && sr.Name!="Message History")
                                {
                                        pIDE=new TiXmlElement("PPID");
                                        pIDE->LinkEndChild(new TiXmlText(sr.Name.c_str()));
                                        pRoot->LinkEndChild(pIDE);
                                }
                        }
                }while(FindNext(sr)==0);
        }
        else
        {
                pIDE=new TiXmlElement("PPID");
                pIDE->LinkEndChild(new TiXmlText(""));
                pRoot->LinkEndChild(pIDE);
        }
        FindClose(sr);

        doc.LinkEndChild(pRoot);
        SendXML(doc,true);


}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doQueryPPBody(char *pRx)
{
        TiXmlDocument doc1;
        doc1.Parse(pRx);
        TiXmlElement* pRoot1 = doc1.FirstChildElement("Root");
        TiXmlElement* pData1=pRoot1->FirstChildElement("DATA");

        AnsiString strData=pData1->GetText();           //Recipe Name
        AnsiString strSxFx=pData1->Attribute("SxFy");

        TIniFile *pIniFile = new TIniFile("C:\\Product Data\\"+strData+"\\"+strData+".ini");

         TiXmlDocument doc;
        TiXmlElement* pRoot;
        TiXmlElement *pData;
        TiXmlElement *pParam;
        TiXmlElement *pProperty;
        AnsiString strName;
        WIN32_FIND_DATA FindFileData;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","QUERY_PPBODY");
        pRoot->SetAttribute("TYPE","ACK");

       AnsiString strTmp;
       pData=new TiXmlElement("DATA");
       pData->SetAttribute("PPID",strData.c_str());
       pData->SetAttribute("SxFy",strSxFx.c_str());

       char *ParamItem[]={"m_dPickSpacerPosY","mm","F4","0","1000",
                        "m_dPutSpacerPosY","mm","F4","0","1000",
                        "m_dPutSSPosY","mm","F4","0","1000",
                        "m_dSSRailMoveNextPos","mm","F4","0","1000",
                        "m_dSSPicker2PickPosY","mm","F4","0","1000",
                        "m_dSSPicker2PickPosZ","mm","F4","0","300",
                        "m_dSSPicker2PutPosY0","mm","F4","0","1000",
                        "m_dSSPicker2PutPosY1","mm","F4","0","1000",
                        "m_dSSPicker2PutPosZ","mm","F4","0","300",
                        "m_dCoverPickerPickPosY","mm","F4","0","1000",
                        "m_dCoverPickerPutPosY","mm","F4","0","1000",
                        "m_dCheckSSPlacePos0","mm","F4","0","1000",
                        "m_dCheckSSPlacePos1","mm","F4","0","1000",
                        "m_dCheckSSPlacePos2","mm","F4","0","1000",
                        "m_dCheckSSPlacePos3","mm","F4","0","1000",
                        "m_rectROILeft","mm","F4","0","640",
                        "m_rectROITop","mm","F4","0","480",
                        "m_rectROIRight","mm","F4","0","640",
                        "m_rectROIButtom","mm","F4","0","480",
                        "m_rectROILeft2","mm","F4","0","640",
                        "m_rectROITop2","mm","F4","0","480",
                        "m_rectROIRight2","mm","F4","0","640",
                        "m_rectROIButtom2","mm","F4","0","480",
                        "m_nMarkROILeft","mm","F4","0","640",
                        "m_nMarkROITop","mm","F4","0","480",
                        "m_nMarkROIRight","mm","F4","0","640",
                        "m_nMarkROIButton","mm","F4","0","480",
                        "m_bUseSSPicker","mm","F4","0","1",
                        "m_bUseCoverPicker","mm","F4","0","1",
                        "m_bUseCoverLifter","mm","F4","0","1",
                        "m_bUseSafetyDoor","mm","F4","0","1",
                        "m_bUseLaser","mm","F4","0","1",
                        "m_bUseCodeReader","mm","F4","0","1",
                        "m_bUseEAPServer","mm","F4","0","1",
                        "m_bUnLoadByPass","mm","F4","0","1",
                        "m_bCheckSSPosBypass","mm","F4","0","1",
                        "m_bSingleSubstrate","mm","F4","0","1",
                        "m_nPackageX0","mm","F4","0","100",
                        "m_nPackageY0","mm","F4","0","100",
                        "END"};           //E:End

       int nX=0;
       while(1)
       {
                if(strcmp(ParamItem[nX*5],"END")==0) break;
                pParam=new TiXmlElement("PARAMETER");
                pParam->SetAttribute("NAME",ParamItem[nX*5]);
                ///strTmp.sprintf("%s,%s",ParamItem[nX],pIniFile->ReadString(Product_Section,ParamItem[nX],"Not Valid"));
                //pParam->LinkEndChild(new TiXmlText(strTmp.c_str()));

                pProperty=new TiXmlElement("PROPERTY");
                pProperty->LinkEndChild(new TiXmlText("TRUE"));
                pParam->LinkEndChild(pProperty);

                for(int t=0;t<3; t++)
                {
                        pProperty=new TiXmlElement("PROPERTY");
                        pProperty->LinkEndChild(new TiXmlText(ParamItem[nX*5+t]));
                        pParam->LinkEndChild(pProperty);
                }

                pProperty=new TiXmlElement("PROPERTY");
                pProperty->LinkEndChild(new TiXmlText(pIniFile->ReadString(Product_Section,ParamItem[nX*5],"0").c_str()));
                pParam->LinkEndChild(pProperty);

                for(int t=3;t<5; t++)
                {
                        pProperty=new TiXmlElement("PROPERTY");
                        pProperty->LinkEndChild(new TiXmlText(ParamItem[nX*5+t]));
                        pParam->LinkEndChild(pProperty);
                }


                pData->LinkEndChild(pParam);
                nX++;
       }



       pRoot->LinkEndChild(pData);


        doc.LinkEndChild(pRoot);

        SendXML(doc);
       
        delete pIniFile;


}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doSetPPBody(char *pRx)
{
         TiXmlDocument doc1;
        doc1.Parse(pRx);
        TiXmlElement* pRoot1 = doc1.FirstChildElement("Root");
        TiXmlElement* pData1=pRoot1->FirstChildElement("DATA");

        AnsiString strData=pData1->Attribute("PPID");
        AnsiString strSxFx=pData1->Attribute("SxFy");
        char *strRet="0";

        TIniFile *pIniFile = new TIniFile("C:\\Product Data\\"+strData+"\\"+strData+".ini");
        if(FileExists("C:\\Product Data\\"+strData+"\\"+strData+".ini"))
        {
                TiXmlElement* pParam=pData1->FirstChildElement("PARAMETER");

                while(1)
                {
                        if(pParam==NULL) break;
                        /*
                        AnsiString strParam=pParam->GetText();
                        int nPos=strParam.Pos(",");
                        AnsiString strA=strParam.SubString(1,nPos-1);
                        AnsiString strB=strParam.SubString(nPos+1,strParam.Length()-strA.Length()+1);
                        pIniFile->WriteString(Product_Section,strA,strB);
                        */
                        TiXmlElement* pProperty=pParam->FirstChildElement("PROPERTY");
                        int i=1;
                        while(1)
                        {
                                 if(pProperty==NULL) break;
                                 if(i==5)
                                 {
                                        pIniFile->WriteString(Product_Section,pParam->Attribute("NAME"),pProperty->GetText());

                                 }
                                pProperty=pProperty->NextSiblingElement("PROPERTY");
                                i++;
                        }

                        pParam=pParam->NextSiblingElement("PARAMETER");
                }

                //SendXML("SET_PPBODY","ACK","ACK","0");
                 strRet="0";


        }
        else strRet="3"; 



        TiXmlDocument doc;
        TiXmlElement* pRoot;
        TiXmlElement *pData;

        TiXmlElement *pProperty;


        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","SET_PPBODY");
        pRoot->SetAttribute("TYPE","ACK");


        pData=new TiXmlElement("ACK");
        pData->SetAttribute("SxFy",strSxFx.c_str());
        pData->LinkEndChild(new TiXmlText(strRet));
        pRoot->LinkEndChild(pData);
        doc.LinkEndChild(pRoot);
        SendXML(doc);
        
        delete pIniFile;
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendSetAttribute(char *pSubstrateID)
{
        TiXmlDocument doc;
        TiXmlElement* pRoot;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","SET_ATTRIBUTE");
        pRoot->SetAttribute("TYPE","CMD");

        TiXmlElement *pDATA=new TiXmlElement("DATA");
        TiXmlElement *pSSID=new TiXmlElement("SubstrateId");
                pSSID->LinkEndChild(new TiXmlText(pSubstrateID));
                pDATA->LinkEndChild(pSSID);

        TiXmlElement *pOri=new TiXmlElement("Orientation");
                pOri->LinkEndChild(new TiXmlText("0"));
                pDATA->LinkEndChild(pOri);

        TiXmlElement *pOriginLocation=new TiXmlElement("OriginLocation");
                pOriginLocation->LinkEndChild(new TiXmlText("UpperRight"));
                 pDATA->LinkEndChild(pOriginLocation);

        TiXmlElement *pSubstrateSide=new TiXmlElement("SubstrateSide");
                pSubstrateSide->LinkEndChild(new TiXmlText("Topside"));
                pDATA->LinkEndChild(pSubstrateSide);

        TiXmlElement *pAxisDirection=new TiXmlElement("AxisDirection");
                pAxisDirection->LinkEndChild(new TiXmlText("DownLeft"));
                pDATA->LinkEndChild(pAxisDirection);


        pRoot->LinkEndChild(pDATA);
        doc.LinkEndChild(pRoot);
        SendXML(doc);
}

//---------------------------------------------------------------------------
void __fastcall CEQPXML::doSetAttributeAck(char *pRx)
{
        try
        {
          TiXmlDocument doc1;
        doc1.Parse(pRx);


        TiXmlElement* pRoot1 = doc1.FirstChildElement("Root");
        TiXmlElement* pData=pRoot1->FirstChildElement("DATA");

        TiXmlElement* pRow=pData->FirstChildElement("ROW");
        AnsiString strRow=pRow->GetText();

        TiXmlElement* pCol=pData->FirstChildElement("COLUMN");
        AnsiString strCol=pCol->GetText();
        /*
        g_IniFile.m_nDeviceX[0]=strCol.ToInt()/2;
        g_IniFile.m_nDeviceX[1]=strCol.ToInt()/2;
        g_IniFile.m_nDeviceY[0]=strRow.ToInt();
        g_IniFile.m_nDeviceY[1]=strRow.ToInt();
        */
        }
        catch(const EAccessViolation &e)
        {
                //Application->MessageBox(e.Message.c_str(), "doSetAttributeAck", MB_OK);
                AddLog("doSetAttributeAck Exception!!",29);
        }




}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendGetAttribute(char *pSubstrateID)
{
        m_bIsGetAttributeAck=false;

        TiXmlDocument doc;
        TiXmlElement* pRoot;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","GET_ATTRIBUTE");
        pRoot->SetAttribute("TYPE","CMD");

        TiXmlElement *pDATA=new TiXmlElement("DATA");
        TiXmlElement *pSSID=new TiXmlElement("SUBSTRATE_ID");
        pSSID->LinkEndChild(new TiXmlText(pSubstrateID));
        pDATA->LinkEndChild(pSSID);

                TiXmlElement *pAtt=new TiXmlElement("ATTRIBUTE");
                        TiXmlElement *pAttID=new TiXmlElement("ATTRIBUTE_ID");
                        pAttID->LinkEndChild(new TiXmlText("SubstrateType"));
                        pAtt->LinkEndChild(pAttID);

                        TiXmlElement *pAttData=new TiXmlElement("ATTRIBUTE_DATA");
                        pAttData->LinkEndChild(new TiXmlText("Strip"));
                        pAtt->LinkEndChild(pAttData);

                        TiXmlElement *pAttRelationShip=new TiXmlElement("ATTRIBUTE_RELATIONSHIP");
                        pAttRelationShip->LinkEndChild(new TiXmlText("0"));
                        pAtt->LinkEndChild(pAttRelationShip);

        pDATA->LinkEndChild(pAtt);



        pRoot->LinkEndChild(pDATA);
        doc.LinkEndChild(pRoot);
        SendXML(doc);
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doGetAttributeAck(char *pRx)
{
        try
        {
          TiXmlDocument doc1;
        doc1.Parse(pRx);


        TiXmlElement* pRoot1 = doc1.FirstChildElement("Root");
        TiXmlElement* pData=pRoot1->FirstChildElement("DATA");

        TiXmlElement* pSSID=pData->FirstChildElement("SUBSTRATE_ID");
        AnsiString strSSID=pSSID->GetText();
        m_strCurrentSSID=strSSID;

        TiXmlElement* pAtt=pData->FirstChildElement("ATTRIBUTE");
        TiXmlElement* pAttData=pAtt->FirstChildElement("ATTRIBUTE_DATA");
                m_strMapDataPath=pAttData->GetText();

        m_bIsGetAttributeAck=true;
        }
        catch(const EAccessViolation &e)
        {
                //Application->MessageBox(e.Message.c_str(), "doSetAttributeAck", MB_OK);
                AddLog("doSetAttributeAck exception!!",30);

        }




}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::ExportMapXML(int nSub,int nMainStripNo,int nSubStripNo)                //Event 101
{

        int nX,nY;
        nX=g_IniFile.m_nDeviceX[0]*g_IniFile.m_nPackageX[0] +g_IniFile.m_nDeviceX[1]*g_IniFile.m_nPackageX[1]*(g_IniFile.m_nTotalPackage-1);
        nY=g_IniFile.m_nDeviceY[0];

         SetKeyParameter();

        AnsiString strStripID=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",nSubStripNo);
         AnsiString strCode;

        TiXmlDocument doc;
        //if(!doc.LoadFile(pFilePathName)) return;
        if(!doc.LoadFile("C:\\MapData\\Default.xml")) return;

        TiXmlHandle docHandle( &doc );
        TiXmlHandle hLayouts=docHandle.FirstChild("MapData").FirstChild("Layouts");
        TiXmlElement *pMatrix=hLayouts.FirstChild("Layout").Element();
        TiXmlElement *pChildLayout=hLayouts.FirstChild("Layout").FirstChild("ChildLayouts").FirstChild("ChildLayout").Element();
        strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
        pChildLayout->SetAttribute("LayoutId",strCode.c_str());

        TiXmlElement *pChildLayout2=hLayouts.FirstChild("Layout").Element()->NextSiblingElement();
        pChildLayout2->SetAttribute("LayoutId",strCode.c_str());

        TiXmlElement *pBlock=pMatrix->NextSiblingElement();
        //TiXmlElement *pCell=pBlock->NextSiblingElement();
        pBlock->FirstChildElement("Dimension")->SetAttribute("X",nX);
        pBlock->FirstChildElement("Dimension")->SetAttribute("Y",nY);

        TiXmlHandle hSubstrates=docHandle.FirstChild("MapData").FirstChild("Substrates");
        TiXmlElement *pSubstrate=hSubstrates.FirstChild("Substrate").Element();
        pSubstrate->SetAttribute("SubstrateType","Strip");
		pSubstrate->SetAttribute("SubstrateId",strStripID.c_str());
	/*
        if(!g_IniFile.m_bUseVenderMap || g_IniFile.m_bByPassSS2DReader) pSubstrate->SetAttribute("SubstrateId",strStripID.c_str());
        else if(g_pAutoRunThread->m_listSSID_2D.size()>0) pSubstrate->SetAttribute("SubstrateId",g_pAutoRunThread->m_listSSID_2D.front().c_str());
        else pSubstrate->SetAttribute("SubstrateId","22AABBVVDD");
	*/
        pSubstrate->SetAttribute("SupplierName",m_strSupplierName.c_str());
        pSubstrate->SetAttribute("HostName",m_strHostName.c_str());strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
        pSubstrate->SetAttribute("LotNo",strCode.c_str());
        pSubstrate->SetAttribute("ScheduleNo",m_strScheduleNo.c_str());
        pSubstrate->SetAttribute("CarrierNo",nSub);                      // CarrierNo //第幾個子批
        pSubstrate->SetAttribute("SubstrateNumber",nMainStripNo);               //WaferNo  //母批的第幾條 1~1000
        pSubstrate->SetAttribute("SlotNumber",nSubStripNo);             //SlotNo //子批的第幾條  1~10
        pSubstrate->SetAttribute("MapCreateTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()).c_str());
        pSubstrate->SetAttribute("MapUpdateTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()+0.0001).c_str());

        //strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
        //pSubstrate->SetAttribute("WaferLot",strCode.c_str());strCode=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",nSubStripNo);
        //pSubstrate->SetAttribute("WaferId",strCode.c_str());
        //pSubstrate->SetAttribute("WaferNo",nMainStripNo);
        //pSubstrate->SetAttribute("ColumnCount",nX);
        //pSubstrate->SetAttribute("RowCount",nY);
        //pSubstrate->SetAttribute("YearCode",m_strYearCode.c_str());
        //pSubstrate->SetAttribute("OperatorName",m_strOperatorName.c_str());
        //pSubstrate->SetAttribute("RecipeName",m_strRecipeName.c_str());


        TiXmlHandle hSubstrateMaps=docHandle.FirstChild("MapData").FirstChild("SubstrateMaps");
        TiXmlElement *pSubstrateMap=hSubstrateMaps.FirstChild("SubstrateMap").Element();
        pSubstrateMap->SetAttribute("SubstrateType","Strip");
		pSubstrateMap->SetAttribute("SubstrateId",strStripID.c_str());strCode="Strip/"+m_strScheduleNo+"B"+FormatFloat("000",nSub);
		/*
        if(!g_IniFile.m_bUseVenderMap || g_IniFile.m_bByPassSS2DReader) pSubstrateMap->SetAttribute("SubstrateId",strStripID.c_str());
        else if(g_pAutoRunThread->m_listSSID_2D.size()>0) pSubstrateMap->SetAttribute("SubstrateId",g_pAutoRunThread->m_listSSID_2D.front().c_str());
        else pSubstrateMap->SetAttribute("SubstrateId","22AABBVVDD");
        */
        strCode="Strip/"+m_strScheduleNo+"B"+FormatFloat("000",nSub);
        pSubstrateMap->SetAttribute("LayoutSpecifier",strCode.c_str());
        pSubstrateMap->SetAttribute("TestStartTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()).c_str());
        pSubstrateMap->SetAttribute("TestEndTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()+0.0001).c_str());
        pSubstrateMap->SetAttribute("ProberType","CT-11");
        pSubstrateMap->SetAttribute("MaxX",nX);
        pSubstrateMap->SetAttribute("MaxY",nY);


        TiXmlElement *pBinCodeMap=pSubstrateMap->FirstChildElement("Overlay")->FirstChildElement("BinCodeMap");
        //TiXmlElement *pBinDefinitions=pBinCodeMap->FirstChildElement("BinDefinitions");
        //pBinDefinitions->FirstChildElement("BinDefinition")->SetAttribute("BinCount",nX*nY);

        TiXmlElement *pBinCode;
        char bin[100][500]={0};
        /*
        bin[0]="___1___1___1";
        bin[1]="___1___1___1";
        bin[2]="___1___1___1";
        bin[3]="___1___1___1";
        bin[4]="___1___1___1";
        bin[5]="___1___1___1";
        */

        //theVision.m_bResultNew[nRow][nCol];

        int nPassCount=0;
        int nFailCount=0;

        for(int nYY=0;nYY<nY;nYY++)
        for(int nXX=0;nXX<nX;nXX++)
        {

           if( theVision.m_bResultNew[nYY][nXX]=='1')
           {
                nPassCount++;
                strcat(&bin[nYY][0],"___1");
           }
           else if( theVision.m_bResultNew[nYY][nXX]=='2')
           {

                strcat(&bin[nYY][0],"____");    //Null Bin
           }
           else 
           {
                nFailCount++;
                strcat(&bin[nYY][0],"___0");    //NG Bin
                //strcat(&bin[nYY][0],"____");    //temporary
           }

        }

        pSubstrate->SetAttribute("PassCount",nPassCount);
        pSubstrate->SetAttribute("FailCount",nFailCount);

         TiXmlElement *pBinDefinitions=pBinCodeMap->FirstChildElement("BinDefinitions");
         pBinDefinitions->FirstChildElement("BinDefinition")->SetAttribute("BinCode",1);
         pBinDefinitions->FirstChildElement("BinDefinition")->SetAttribute("BinQuality","Pass");
         pBinDefinitions->FirstChildElement("BinDefinition")->SetAttribute("BinDescription","");
         pBinDefinitions->FirstChildElement("BinDefinition")->SetAttribute("BinCount",nPassCount);

        TiXmlElement *pBinDefinition=new TiXmlElement("BinDefinition");
        pBinDefinition->SetAttribute("BinCode",0);
        pBinDefinition->SetAttribute("BinQuality","Bad");
        pBinDefinition->SetAttribute("BinDescription","");
        pBinDefinition->SetAttribute("BinCount",nFailCount);

        pBinDefinitions->LinkEndChild(pBinDefinition);


        for(int nIndex=0;nIndex<nY;nIndex++)
        {
        pBinCode=new TiXmlElement("BinCode");
        TiXmlText *pText=new TiXmlText(bin[nIndex]);          //Map Data Array
        pText->SetCDATA(true);
        pBinCode->LinkEndChild(pText);

        //pBinCode->LinkEndChild();
        pBinCodeMap->LinkEndChild(pBinCode);
        }



        //strCode="C:\\MapData1\\"+strStripID+".xml";
        strCode="C:\\UpLoadData\\Map\\"+m_strYearCode+"-"+m_strScheduleNo+"\\B"+FormatFloat("000",nSub)+"\\"+strStripID+".xml";
        AnsiString strDir="C:\\UpLoadData\\Map\\"+m_strYearCode+"-"+m_strScheduleNo;
        mkdir(strDir.c_str());
        strDir+="\\B"+FormatFloat("000",nSub);
        mkdir(strDir.c_str());
        doc.SaveFile(strCode.c_str());

        if(m_listExportMap.size()>0)
        {
                if(m_listExportMap.back() != strCode)
                {
                        AddLog(strCode.c_str(),strCode.Length());
                        m_listExportMap.push_back(strCode);
                }
        }
        else
        {
                AddLog(strCode.c_str(),strCode.Length());
                m_listExportMap.push_back(strCode);
        }
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::ExportStripXML(int nSub,int nMainStripNo,int nSubStripSize)    //Event 103
{
        int nX,nY;
        nX=g_IniFile.m_nDeviceX[0]*g_IniFile.m_nPackageX[0]+g_IniFile.m_nDeviceX[1]*g_IniFile.m_nPackageX[1]*(g_IniFile.m_nTotalPackage-1);
        nY=g_IniFile.m_nDeviceY[0];

        SetKeyParameter();

        AnsiString strStripID=m_strYearCode+"-"+m_strScheduleNo+"-B"+FormatFloat("000",nSub);

        TiXmlDocument doc;

        if(!doc.LoadFile("C:\\MapData\\Header.xml")) return;

        TiXmlHandle docHandle( &doc );
        TiXmlElement *pNewDataSet=docHandle.FirstChild("NewDataSet").Element();

         TiXmlElement *pMaps;
         TiXmlElement *pSupplierName;
         TiXmlElement *pRecipeName;
         TiXmlElement *pYearCode;
         TiXmlElement *pScheduleNo;
         TiXmlElement *pWaferLot;
         TiXmlElement *pWaferId;
         TiXmlElement *pWaferNo;
         TiXmlElement *pCarrierNo;
         TiXmlElement *pSlotNo;
         TiXmlElement *pColumnCount;
         TiXmlElement *pRowCount;
         TiXmlElement *pHostName;
         TiXmlElement *pOperatorName;

         AnsiString strCode;

         for(int nSubStripNo=1;nSubStripNo<=nSubStripSize;nSubStripNo++)
         {
                pMaps=new TiXmlElement("Maps");
                pSupplierName=new TiXmlElement("SupplierName");
                pRecipeName=new TiXmlElement("RecipeName");
                pYearCode=new TiXmlElement("YearCode");
                pScheduleNo=new TiXmlElement("ScheduleNo");
                pWaferLot=new TiXmlElement("WaferLot");
                pWaferId=new TiXmlElement("WaferId");
                pWaferNo=new TiXmlElement("WaferNo");
                pCarrierNo=new TiXmlElement("CarrierNo");
                pSlotNo=new TiXmlElement("SlotNo");
                pColumnCount=new TiXmlElement("ColumnCount");
                pRowCount=new TiXmlElement("RowCount");
                pHostName=new TiXmlElement("HostName");
                pOperatorName=new TiXmlElement("OperatorName");

                pSupplierName->LinkEndChild(new TiXmlText(m_strSupplierName.c_str()));
                pRecipeName->LinkEndChild(new TiXmlText("2845"));//new TiXmlText(m_strRecipeName.c_str()));
                pYearCode->LinkEndChild(new TiXmlText(m_strYearCode.c_str()));
                pScheduleNo->LinkEndChild(new TiXmlText(m_strScheduleNo.c_str()));strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
                pWaferLot->LinkEndChild(new TiXmlText(strCode.c_str()));strCode=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",nSubStripNo);
                pWaferId->LinkEndChild(new TiXmlText(strCode.c_str()));
                pWaferNo->LinkEndChild(new TiXmlText(IntToStr(nMainStripNo+nSubStripNo).c_str()));  //母批的第幾條 1~1000
                pCarrierNo->LinkEndChild(new TiXmlText(IntToStr(nSub).c_str()));                        // 第幾個子批
                pSlotNo->LinkEndChild(new TiXmlText(IntToStr(nSubStripNo).c_str()));                    //子批的第幾條  1~10
                pColumnCount->LinkEndChild(new TiXmlText(IntToStr(nX).c_str()));
                pRowCount->LinkEndChild(new TiXmlText(IntToStr(nY).c_str()));
                pHostName->LinkEndChild(new TiXmlText(m_strHostName.c_str()));
                pOperatorName->LinkEndChild(new TiXmlText(m_strOperatorName.c_str()));

                pMaps->LinkEndChild(pSupplierName);
                pMaps->LinkEndChild(pRecipeName);
                pMaps->LinkEndChild(pYearCode);
                pMaps->LinkEndChild(pScheduleNo);
                pMaps->LinkEndChild(pWaferLot);
                pMaps->LinkEndChild(pWaferId);
                pMaps->LinkEndChild(pWaferNo);
                pMaps->LinkEndChild(pCarrierNo);
                pMaps->LinkEndChild(pSlotNo);
                pMaps->LinkEndChild(pColumnCount);
                pMaps->LinkEndChild(pRowCount);
                pMaps->LinkEndChild(pHostName);
                pMaps->LinkEndChild(pOperatorName);

                pNewDataSet->LinkEndChild(pMaps);
         }



        //strCode="C:\\MapData\\"+strStripID+".xml";  m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub);
        strCode="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo+"\\B"+strStripID+".xml";
        AnsiString strDir="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo;
        mkdir(strDir.c_str());
        doc.SaveFile(strCode.c_str());

        if(m_listExportStrip.size()>0)
        {
                if(m_listExportStrip.back() != strCode)
                {
                        AddLog(strCode.c_str(),strCode.Length());
                        m_listExportStrip.push_back(strCode);

                }
        }
        else
        {
                AddLog(strCode.c_str(),strCode.Length());
                m_listExportStrip.push_back(strCode);
        }
}
//---------------------------------------------------------------------------
 void __fastcall CEQPXML::doKeyParamater(char *pRx)
 {
         try
        {
          TiXmlDocument doc1;
        doc1.Parse(pRx);


        TiXmlElement* pRoot1 = doc1.FirstChildElement("Root");
        TiXmlElement* pData=pRoot1->FirstChildElement("DATA");

        TiXmlElement* pPar1=pData->FirstChildElement("PARAMETER1");
        m_strSupplierName=pPar1->GetText();
        TiXmlElement* pPar2=pData->FirstChildElement("PARAMETER2");
        m_strRecipeName=pPar2->GetText();
        TiXmlElement* pPar3=pData->FirstChildElement("PARAMETER3");
        m_strYearCode=pPar3->GetText();
        TiXmlElement* pPar4=pData->FirstChildElement("PARAMETER4");
        m_strScheduleNo=pPar4->GetText();
        /*
        TiXmlElement* pPar5=pData->FirstChildElement("PARAMETER5");
        AnsiString strPar5=pPar5->GetText();
        TiXmlElement* pPar6=pData->FirstChildElement("PARAMETER6");
        AnsiString strPar6=pPar6->GetText();
        */
         SendXML("KEY_PARAMETER","ACK","ACK","0");           //0:OK 1:NG

         g_pAutoRunThread->m_bExportMapXMLA=true;            

        }
        catch(const EAccessViolation &e)
        {
                 SendXML("KEY_PARAMETER","ACK","ACK","1");           //0:OK 1:NG
                //Application->MessageBox(e.Message.c_str(), "doSetAttributeAck", MB_OK);
        }

 }

//---------------------------------------------------------------------------
 void __fastcall CEQPXML::AddLog(char *pRx,int nSize)
 {
       //return;//debug
        AnsiString strTime;
        time_t timer;
  struct tm *tblock;

   timer = time(NULL);
   tblock = localtime(&timer);

  

   try{

  FILE *pFile;

  strTime.sprintf("C:\\EQPXML Log\\%04d_%02d_%02d.txt",tblock->tm_year+1900,tblock->tm_mon+1,tblock->tm_mday);

  pFile=fopen(strTime.c_str(),"a+");

  if(pFile!=NULL)
  {
          fprintf(pFile,"\n[%2d:%02d:%02d]\n",tblock->tm_hour,tblock->tm_min, tblock->tm_sec);

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
 void __fastcall CEQPXML::SetKeyParameter()
 {
         char drive[MAXDRIVE];
        char dir[MAXDIR];
        char file[MAXFILE];
        char ext[MAXEXT];
        int flags;

        //FormatDateTime("yyyyMMddHHmmsszzzz",Now());

        flags=fnsplit(g_IniFile.m_strLastFileName.c_str(),drive,dir,file,ext);

        m_strSupplierName=g_IniFile.m_strSupplierName;  //"XL MAP";
        m_strRecipeName=file;           //"KKK";
        //m_strYearCode=FormatDateTime("yyyy",Now()).SubString(4,1);      //20141215 disabled, year code download from EQPDATA
        m_strScheduleNo=g_IniFile.m_strScheduleNo.SubString(1,6);       //"99IE00";
        m_strHostName=g_IniFile.m_strHostName;  //"ASEF3-2845-01";
        m_strOperatorName=g_IniFile.m_strOperatorName;  //"2845";
 }
  //---------------------------------------------------------------------------
 int __fastcall CEQPXML::LoadStripXML(AnsiString strStripID)
 {
         TiXmlDocument doc;

         //AnsiString strName="C:\\DownloadData\\"+strStripID+".xml";
         AnsiString strName="C:\\MapData\\"+strStripID+".xml";
         if(!doc.LoadFile(strName.c_str()) )return -1;

        TiXmlHandle docHandle( &doc );
        TiXmlHandle hLayouts=docHandle.FirstChild("MapData").FirstChild("Layouts");
        TiXmlElement *pMatrix=hLayouts.FirstChild("Layout").Element();
        TiXmlElement *pChildLayout=hLayouts.FirstChild("Layout").FirstChild("ChildLayouts").FirstChild("ChildLayout").Element();

        TiXmlElement *pChildLayout2=hLayouts.FirstChild("Layout").Element()->NextSiblingElement();
        AnsiString strLayoutID=pChildLayout2->Attribute("LayoutId");

        TiXmlElement *pBlock=pMatrix->NextSiblingElement();
        //TiXmlElement *pCell=pBlock->NextSiblingElement();
        int nDimX,nDimY;
        pBlock->FirstChildElement("Dimension")->Attribute("X",&nDimX);
        pBlock->FirstChildElement("Dimension")->Attribute("Y",&nDimY);

        TiXmlHandle hSubstrates=docHandle.FirstChild("MapData").FirstChild("Substrates");
        TiXmlElement *pSubstrate=hSubstrates.FirstChild("Substrate").Element();
        /*
        pSubstrate->SetAttribute("SubstrateType","Strip");
        pSubstrate->SetAttribute("SubstrateId",strStripID.c_str());
        pSubstrate->SetAttribute("SupplierName",m_strSupplierName.c_str());
        pSubstrate->SetAttribute("HostName",m_strHostName.c_str());strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
        pSubstrate->SetAttribute("LotNo",strCode.c_str());
        pSubstrate->SetAttribute("ScheduleNo",m_strScheduleNo.c_str());
        pSubstrate->SetAttribute("CarrierNo",nSub);                      // CarrierNo //第幾個子批
        pSubstrate->SetAttribute("SubstrateNumber",nMainStripNo);               //WaferNo  //母批的第幾條 1~1000
        pSubstrate->SetAttribute("SlotNumber",nSubStripNo);             //SlotNo //子批的第幾條  1~10
        pSubstrate->SetAttribute("MapCreateTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()).c_str());
        pSubstrate->SetAttribute("MapUpdateTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()+0.0001).c_str());
        */


        TiXmlHandle hSubstrateMaps=docHandle.FirstChild("MapData").FirstChild("SubstrateMaps");
        TiXmlElement *pSubstrateMap=hSubstrateMaps.FirstChild("SubstrateMap").Element();
         int nPassCount=0;
        pSubstrate->Attribute("PassCount",&nPassCount);
        /*
        pSubstrateMap->SetAttribute("SubstrateType","Strip");
        pSubstrateMap->SetAttribute("SubstrateId",strStripID.c_str());strCode="Strip/"+m_strScheduleNo+"B"+FormatFloat("000",nSub);
        pSubstrateMap->SetAttribute("LayoutSpecifier",strCode.c_str());
        pSubstrateMap->SetAttribute("TestStartTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()).c_str());
        pSubstrateMap->SetAttribute("TestEndTime",FormatDateTime("yyyy/mm/dd hh:nn:ss",Now()+0.0001).c_str());
        pSubstrateMap->SetAttribute("ProberType","CT-11");
        pSubstrateMap->SetAttribute("MaxX",nX);
        pSubstrateMap->SetAttribute("MaxY",nY);
        */

        TiXmlElement *pBinCodeMap=pSubstrateMap->FirstChildElement("Overlay")->FirstChildElement("BinCodeMap");

        TiXmlElement *pBinDefinitions=pBinCodeMap->FirstChildElement("BinDefinitions");
        int nBinCount;
        pBinDefinitions->FirstChildElement("BinDefinition")->Attribute("BinCount",&nBinCount);

        TiXmlElement *pBinCode;
        char bin[100][500]={0};
        /*
        bin[0]="___1___1___1";
        bin[1]="___1___1___1";
        bin[2]="___1___1___1";
        bin[3]="___1___1___1";
        bin[4]="___1___1___1";
        bin[5]="___1___1___1";
        */

        //theVision.m_bResultNew[nRow][nCol];



        pBinCode=pBinCodeMap->FirstChildElement("BinCode");

        const char *pCode=pBinCode->FirstChild()->Value();

        for(int nYY=0;nYY<nDimY;nYY++)
        {
                for(int nXX=0;nXX<nDimX;nXX++)
                {
                        if(pCode[nXX*4+3]!='1') theVision.m_bResult[nYY][nXX]='0';   //bin[nYY][nXX]='0';
                        else theVision.m_bResult[nYY][nXX]='1';                      //bin[nYY][nXX]='1';
                }
                pBinCode=pBinCode->NextSiblingElement();
                if(pBinCode!=NULL) pCode=pBinCode->FirstChild()->Value();
                else break;
        }

        g_IniFile.m_nDeviceX[0]=nDimX;
        g_IniFile.m_nDeviceY[0]=nDimY;

        g_IniFile.m_nDeviceX[1]=nDimX;
        g_IniFile.m_nDeviceY[1]=nDimY;

        g_IniFile.m_nTotalPackage=1;
        g_IniFile.m_nPackageX[0]=1;
        g_IniFile.m_nPackageY[0]=1;
        g_IniFile.m_nPackageX[1]=1;
        g_IniFile.m_nPackageY[1]=1;

        /*
         for(int nYY=0;nYY<nY;nYY++)
        for(int nXX=0;nXX<nX;nXX++)
        {
           if( theVision.m_bResultNew[nYY][nXX]=='0')
           {

                strcat(&bin[nYY][0],"____");    //Null Bin
                //strcat(&bin[nYY][0],"___X");    //NG Bin
           }
           else
           {
                nPassCount++;
                strcat(&bin[nYY][0],"___1");
           }
        }
        */


      return nPassCount;

 }

 //---------------------------------------------------------------------------
void __fastcall CEQPXML::ExportLinkXML(int nSub,int nMainStripNo,int nSubStripSize)    //Event 103
{
        int nX,nY;
        nX=g_IniFile.m_nDeviceX[0]*g_IniFile.m_nPackageX[0]+g_IniFile.m_nDeviceX[1]*g_IniFile.m_nPackageX[1]*(g_IniFile.m_nTotalPackage-1);
        nY=g_IniFile.m_nDeviceY[0];

        SetKeyParameter();
        
        AnsiString strStripID=m_strYearCode+"-"+m_strScheduleNo+"-B"+FormatFloat("000",nSub);

        TiXmlDocument doc;

        AnsiString strFullPath="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+strStripID+".xml";
        if(FileExists(strFullPath))
        {
                doc.LoadFile(strFullPath.c_str());
        }
        else if(!doc.LoadFile("C:\\MapData\\Header.xml")) return;

        TiXmlHandle docHandle( &doc );
        TiXmlElement *pNewDataSet=docHandle.FirstChild("NewDataSet").Element();

         TiXmlElement *pMaps;
         TiXmlElement *pSupplierName;
         TiXmlElement *pRecipeName;
         TiXmlElement *pYearCode;
         TiXmlElement *pScheduleNo;
         TiXmlElement *pWaferLot;
         TiXmlElement *pWaferId;
         TiXmlElement *pWaferNo;
         TiXmlElement *pCarrierNo;
         TiXmlElement *pSlotNo;
         TiXmlElement *pColumnCount;
         TiXmlElement *pRowCount;
         TiXmlElement *pHostName;
         TiXmlElement *pOperatorName;

         AnsiString strCode;

                pMaps=new TiXmlElement("Maps");
                pSupplierName=new TiXmlElement("SupplierName");
                pRecipeName=new TiXmlElement("RecipeName");
                pYearCode=new TiXmlElement("YearCode");
                pScheduleNo=new TiXmlElement("ScheduleNo");
                pWaferLot=new TiXmlElement("WaferLot");
                pWaferId=new TiXmlElement("WaferId");
                pWaferNo=new TiXmlElement("WaferNo");
                pCarrierNo=new TiXmlElement("CarrierNo");
                pSlotNo=new TiXmlElement("SlotNo");
                pColumnCount=new TiXmlElement("ColumnCount");
                pRowCount=new TiXmlElement("RowCount");
                pHostName=new TiXmlElement("HostName");
                pOperatorName=new TiXmlElement("OperatorName");

                pSupplierName->LinkEndChild(new TiXmlText(m_strSupplierName.c_str()));
                pRecipeName->LinkEndChild(new TiXmlText("2845"));//new TiXmlText(m_strRecipeName.c_str()));
                pYearCode->LinkEndChild(new TiXmlText(m_strYearCode.c_str()));
                pScheduleNo->LinkEndChild(new TiXmlText(m_strScheduleNo.c_str()));strCode=m_strScheduleNo+"B"+FormatFloat("000",nSub);
                pWaferLot->LinkEndChild(new TiXmlText(strCode.c_str()));
                /*if(!g_IniFile.m_bByPassSS2DReader && g_IniFile.m_bUseVenderMap)
                {
                        if(g_pAutoRunThread->m_listSSID_2D.size()>0) strCode=g_pAutoRunThread->m_listSSID_2D.front();
                        else strCode="22AABBVVDD";
                }
                else */strCode=m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub)+"-"+FormatFloat("000",((nMainStripNo-1)%nSubStripSize)+1);
                pWaferId->LinkEndChild(new TiXmlText(strCode.c_str()));
                pWaferNo->LinkEndChild(new TiXmlText(IntToStr(nMainStripNo).c_str()));  //母批的第幾條 1~1000
                pCarrierNo->LinkEndChild(new TiXmlText(IntToStr(nSub).c_str()));                        // 第幾個子批
                if( (nMainStripNo%nSubStripSize)!=0 ) pSlotNo->LinkEndChild(new TiXmlText(IntToStr( nMainStripNo%nSubStripSize ).c_str()));                    //子批的第幾條  1~10
                else pSlotNo->LinkEndChild(new TiXmlText(IntToStr(nSubStripSize).c_str()));
                pColumnCount->LinkEndChild(new TiXmlText(IntToStr(nX).c_str()));
                pRowCount->LinkEndChild(new TiXmlText(IntToStr(nY).c_str()));
                pHostName->LinkEndChild(new TiXmlText(m_strHostName.c_str()));
                pOperatorName->LinkEndChild(new TiXmlText(m_strOperatorName.c_str()));

                pMaps->LinkEndChild(pSupplierName);
                pMaps->LinkEndChild(pRecipeName);
                pMaps->LinkEndChild(pYearCode);
                pMaps->LinkEndChild(pScheduleNo);
                pMaps->LinkEndChild(pWaferLot);
                pMaps->LinkEndChild(pWaferId);
                pMaps->LinkEndChild(pWaferNo);
                pMaps->LinkEndChild(pCarrierNo);
                pMaps->LinkEndChild(pSlotNo);
                pMaps->LinkEndChild(pColumnCount);
                pMaps->LinkEndChild(pRowCount);
                pMaps->LinkEndChild(pHostName);
                pMaps->LinkEndChild(pOperatorName);

                pNewDataSet->LinkEndChild(pMaps);


        //strCode="C:\\MapData\\"+strStripID+".xml";  m_strYearCode+"-"+m_strScheduleNo+"-"+FormatFloat("000",nSub);
        strCode="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo+"\\"+strStripID+".xml";
        AnsiString strDir="C:\\UpLoadData\\Strip\\"+m_strYearCode+"-"+m_strScheduleNo;
        mkdir(strDir.c_str());
        doc.SaveFile(strCode.c_str());

        if(m_listExportStrip.size()>0)
        {
                if(m_listExportStrip.back() != strCode)
                {
                        AddLog(strCode.c_str(),strCode.Length());
                        m_listExportStrip.push_back(strCode);

                }
        }
        else
        {
                AddLog(strCode.c_str(),strCode.Length());
                m_listExportStrip.push_back(strCode);
        }
}
 //---------------------------------------------------------------------------
bool __fastcall CEQPXML::Parse103Send101(AnsiString strName)
{
         TiXmlDocument doc;


         if(!doc.LoadFile(strName.c_str()) )return false;

        TiXmlHandle docHandle( &doc );
        TiXmlElement *pMaps=docHandle.FirstChild("NewDataSet").FirstChild("Maps").Element();

        while(1)
        {
                if(!pMaps) break;
                AddLog("Push 101",9);
                m_listSendEvent.push_back("101");
                pMaps=pMaps->NextSiblingElement();

        }

        return true;
}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::SendLotComplete(char *pLotID)
{
        TiXmlDocument doc;
        TiXmlElement* pRoot;

        pRoot=new TiXmlElement("Root");
        pRoot->SetAttribute("MSGID","ICMD");
        pRoot->SetAttribute("TYPE","CMD");

        TiXmlElement *pDATA=new TiXmlElement("DATA");
        TiXmlElement *pMsgName=new TiXmlElement("MsgName");
        TiXmlElement *pMsgOwner=new TiXmlElement("MsgOwner");
        TiXmlElement *pPARAMETERS=new TiXmlElement("PARAMETERS");
        TiXmlElement *pStripPath=new TiXmlElement("StripPath");
        TiXmlElement *pStripCEID=new TiXmlElement("StripCEID");
        TiXmlElement *pMapCEID=new TiXmlElement("MapCEID");
        TiXmlElement *pStripDVID=new TiXmlElement("StripDVID");
        TiXmlElement *pMapDVID=new TiXmlElement("MapDVID");


        pMsgName->LinkEndChild(new TiXmlText("LotComplete"));
        pMsgOwner->LinkEndChild(new TiXmlText("EQP"));
        pStripPath->LinkEndChild(new TiXmlText(pLotID));
        pStripCEID->LinkEndChild(new TiXmlText("103"));
        pMapCEID->LinkEndChild(new TiXmlText("101"));
        pStripDVID->LinkEndChild(new TiXmlText("1101"));
        pMapDVID->LinkEndChild(new TiXmlText("1103"));

        pPARAMETERS->LinkEndChild(pStripPath);
        pPARAMETERS->LinkEndChild(pStripCEID);
        pPARAMETERS->LinkEndChild(pMapCEID);
        pPARAMETERS->LinkEndChild(pStripDVID);
        pPARAMETERS->LinkEndChild(pMapDVID);

        pDATA->LinkEndChild(pMsgName);
        pDATA->LinkEndChild(pMsgOwner);
        pDATA->LinkEndChild(pPARAMETERS);
        pRoot->LinkEndChild(pDATA);
        doc.LinkEndChild(pRoot);
        SendXML(doc);

}
//---------------------------------------------------------------------------
void __fastcall CEQPXML::doLotCompleteAck(char *pRx)
{
        TiXmlDocument doc;
        doc.Parse(pRx);
        TiXmlElement* pRoot = doc.FirstChildElement("Root");
        TiXmlElement* pAck=pRoot->FirstChildElement("ACK");

        AnsiString strACK=pAck->GetText();
        LotCompleteAck(strACK);
        //do something for that
}




