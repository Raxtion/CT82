//---------------------------------------------------------------------------

#ifndef PCIM114GLH
#define PCIM114GLH

#include <vector>
#include "DIODefine.h"

#define AXIS_SIZE 9
//---------------------------------------------------------------------------
namespace Axis_Const
{
        enum Axis_Status
        {
        RDY=0,ALM=1,PEL,MEL,ORG,DIR,EMG,PCS,ERC,EZ,CLR,LATCH,SD,INP,SVON,RALM
        };

        enum Axis
        {
                AXIS_0=0,AXIS_1,AXIS_2,AXIS_3,FTX,RTX,SSY,SCY,CCD
        };
}

class PCIM114GL
{
private:
        bool m_bInitOK;
        short m_nExistCard;
        unsigned short m_nStartRingNo;
        unsigned short m_nCardNo;
        HANDLE m_hEvent;
       
        unsigned __int64 m_nActiveTable;
        unsigned char   m_btSlaveType[64];
        std::vector<unsigned short> m_vectAxisMap; //1 Axis module
        std::vector<unsigned short> m_vectDIOMap;  //DI16/DO16 module

        unsigned char *m_byteDIPort;
        unsigned char *m_byteDOPort;
        double m_dStartVal[AXIS_SIZE], m_dMaxVal[AXIS_SIZE], m_dTAcc[AXIS_SIZE],  m_dTDec[AXIS_SIZE],m_dSVAcc[AXIS_SIZE];

        double m_dMMtoPLS[AXIS_SIZE];
       
 public:
        __fastcall PCIM114GL();
        __fastcall ~PCIM114GL();

        bool __fastcall Initial(unsigned short nCardNo);
        void ServoOn(unsigned short nAxis, unsigned short bOn);
        void SetMoveSpeed(unsigned short nAxis, double dMaxVal, double dTAcc,double dTDec);
        void ChangeMoveSpeed(unsigned short nAxis, double dSpeedVal);
        void AxisHome(unsigned short nAxis, bool bDir);
        void RelMove(unsigned short nAxis, double dDis);
        void AbsMove(unsigned short nAxis, double dDis);
        void AbsSMove(unsigned short nAxis, double dDis);
        bool IsMotionDone(unsigned short nAxis);
        double GetFeedbackPos(unsigned short nAxis);
        void SetFeedbackPos(unsigned short nAxis,double dPos);
        double GetCommandPos(unsigned short nAxis);
        void SetCommandPos(unsigned short nAxis,double dPos);
        void StartJog(unsigned short nAxis,bool bDir);
        void StopMove(unsigned short nAxis);
        void SetDO(int nBitNo, bool bOnOff);     //for DI16 DO16
        void SetDOPort(int nBitNo, byte nValue);
        bool GetDO(int nBitNo);
        bool GetDI(int nBitNo);
        bool GetAxisStatus(unsigned short nAxis, Axis_Const::Axis_Status nStatus);
        byte GetDIPort(int nPort);
        byte GetDOPort(int nPort);
       
        void ProcessMessage();
        bool WaitMotionDone(int nAxis, DWORD nWaitTime, bool bProcessMessage);
        bool IsPosDone(int nAxis,double dPos);
        bool IsLastPosDone(int nAxis);

        bool m_bAutoMode;
        double m_dLastTargetPos[10];    //0: Axis 0

        bool IsCommError(int nRingNo=0);

       
};
//---------------------------------------------------------------------------
#endif
