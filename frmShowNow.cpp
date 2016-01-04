//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmShowNow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmShowNow *fmShowNow;
//---------------------------------------------------------------------------
__fastcall TfmShowNow::TfmShowNow(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfmShowNow::FormCreate(TObject *Sender)
{
    for (int nX=0;nX<25;nX++)
    {
        m_arraybShape[nX] = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TfmShowNow::timerShowTimer(TObject *Sender)
{
    timerShow->Enabled = false;
    TShape * shapeShowBox;
    AnsiString strComponentName;
    for (int nX=0;nX<25;nX++)
    {
        strComponentName.sprintf("Shape%02d", nX);
        shapeShowBox=(TShape *)FindComponent(strComponentName);
        if (m_arraybShape[nX] == true) shapeShowBox->Brush->Color = clYellow;
        else if (m_arraybShape[nX] == false) shapeShowBox->Brush->Color = clGreen;
    }
    timerShow->Enabled = true;
}
//---------------------------------------------------------------------------
