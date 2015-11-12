//---------------------------------------------------------------------------


#pragma hdrstop

#include "KenenceLaser.h"
#include "stdio.h"
#include <list>
//---------------------------------------------------------------------------

#pragma package(smart_init)
CKeyenceLaser g_Laser;

//---------------------------------------------------------------------------
__fastcall CKeyenceLaser::CKeyenceLaser()
{
}
//---------------------------------------------------------------------------

__fastcall CKeyenceLaser::~CKeyenceLaser()
{
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::OpenPort(int nPort)
{
        return Open(nPort,B38400,BIT_8|STOP_1|P_NONE);
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::IsLaserReady()
{
        char Buf[30]={0};
        sprintf(Buf,"RE\x0d");
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"RE,%d,%d\x0d",nRet,nRet+1);

        if(nRet[0]==0 && nRet[1]==0) return true;
        else return false;
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::OpenProgram(int nNo)
{
        char Buf[30]={0};
        sprintf(Buf,"GA,%04d\x0d",nNo);
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"GA,%d,S%d\x0d",nRet,nRet+1);

        if(nRet[0]==0) return true;
        else return false;
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::FireLaser()
{
        char Buf[30]={0};
        sprintf(Buf,"TX\x0d");
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"TX,%d\x0d",nRet);

        if(nRet[0]==0) return true;
        else return false;
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::SetText(int nPgmNo,int nTextNo,char *strText)
{
        char Buf[300]={0};
        sprintf(Buf,"C2,%04d,%03d,%s\x0d",nPgmNo,nTextNo,strText);
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"C2,%d,S%d\x0d",nRet,nRet+1);

        if(nRet[0]==0) return true;
        else return false;
}

void __fastcall CKeyenceLaser::SetPalette(int nPgmNo,int nSizeX,int nSizeY,char bResult[100][100])
{
        char Buf[300]={0};
        int nRet[2]={999,999};
        
        std::list<int> listArray;

        for(int nX=0;nX<nSizeX;nX++)
        for(int nY=1;nY<=nSizeY;nY++)
        {
                listArray.push_back(nSizeX*nY-nX);
        }

        AnsiString strData;
        AnsiString strCmd;
        AnsiString strHead="KW,"+FormatFloat("0",nPgmNo);

        int nSz=listArray.size();

        for(int nIndex=0;nIndex<nSz;nIndex++)
        {
                int nA=listArray.front();
                if(bResult[nA/nSizeX][nA%nSizeX]=='0') strData='1';
                else strData='0';
                strCmd=strCmd+","+FormatFloat("0",nIndex+1)+","+strData+",-1,0,0,0,0";
                listArray.pop_front();

                if(((nIndex+1)%100)==0 || (nIndex+1==nSz))
                {
                        strCmd=strHead+strCmd+'\x0d';
                        WriteData(strCmd.c_str());    

                        ReadData(Buf,'\x0d');
                        sscanf(Buf,"WK,%d,S%d\x0d",nRet,nRet+1);
                        strCmd="";
                }
        }

        return;

}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::SetTextPos(int nPgmNo,int nTextNo,double dPosX,double dPosY)
{
        char Buf[300]={0};
        sprintf(Buf,"C0,%04d,%03d,%.3f,%.3f\x0d",nPgmNo,nTextNo,dPosX,dPosY);
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"C0,%d,S%d\x0d",nRet,nRet+1);

        if(nRet[0]==0) return true;
        else return false;
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::SetAllTextPosOffset(int nPgmNo,double dOffsetX,double dOffsetY,double dOffsetZ,int nSpotOffset)
{
        char Buf[300]={0};
        sprintf(Buf,"AG,%04d,%.3f,%.3f,%.2f,%d\x0d",nPgmNo,dOffsetX,dOffsetY,dOffsetZ,nSpotOffset);
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"AG,%d,S%d\x0d",nRet,nRet+1);

        if(nRet[0]==0) return true;
        else return false;
}
//---------------------------------------------------------------------------
bool __fastcall CKeyenceLaser::SetToolPosOffset(int nPgmNo,double dOffsetX,double dOffsetY,double dOffsetT)
{
        char Buf[300]={0};
        sprintf(Buf,"VG,%04d,%.3f,%.3f,%.3f,%.3f,%.2f\x0d",nPgmNo,0.0,0.0,dOffsetX,dOffsetY,dOffsetT);
        WriteData(Buf);

        int nRet[2]={999,999};

        ReadData(Buf,'\x0d');

        sscanf(Buf,"VG,%d,S%d\x0d",nRet,nRet+1);

        if(nRet[0]==0) return true;
        else return false;
}
