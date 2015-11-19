//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmProductParam.h"
 #include "EQPXML.h"
#include "CtkLedControll.h"
#include "fmMotorCheck.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern CEQPXML g_eqpXML;
//TfrmProductParam *frmProductParam;
CTK_Led g_LED;
//---------------------------------------------------------------------------
__fastcall TfrmProductParam::TfrmProductParam(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TfrmProductParam::trackLED0Change(TObject *Sender)
{
        g_LED.SetCurrent(0,0,trackLED0->Position,0);

        labelLED0->Caption=trackLED0->Position;
        labelLED1->Caption=trackLED1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TfrmProductParam::FormShow(TObject *Sender)
{
        labelLED0->Caption=trackLED0->Position;
        labelLED1->Caption=trackLED1->Position;         
}
//---------------------------------------------------------------------------

void __fastcall TfrmProductParam::trackLED1Change(TObject *Sender)
{
        g_LED.SetCurrent(1,0,trackLED1->Position,0);

        labelLED1->Caption=trackLED1->Position;
}
//--------------------------------------------------------------------------- 


