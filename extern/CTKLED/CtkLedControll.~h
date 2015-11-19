//---------------------------------------------------------------------------

#ifndef CtkLedControllH
#define CtkLedControllH
#include <vcl>
#include "SerialPort.h"

//---------------------------------------------------------------------------
class CTK_Led :private CSerialPort
{
public:
        __fastcall CTK_Led();
        __fastcall ~CTK_Led();
        bool __fastcall OpenPort(int nPort);
        bool __fastcall SetMaxCurrent(int nA,int nB,int nC,int nD);
        bool __fastcall SetCurrent(int nCh,int nM,int nC,int nP);       //nM: 0:constant 1:extern 2:strobe nC:Current nP:Pulse
        bool __fastcall SetVoltage(int nCh,int nValue);                 //nCh: 0 or 1; nValue: 0~500 for 創勢捷調光器
        void __fastcall Try();

        
};
#endif

