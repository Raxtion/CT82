//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmOption.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TfmOption *fmOption;
//---------------------------------------------------------------------------
__fastcall TfmOption::TfmOption(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmOption::m_bUseFMCCD2Click(TObject *Sender)
{
    if (this->m_bUseFMCCD2->Checked == true) m_bUseFMCCD->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfmOption::m_bUseFMCCDClick(TObject *Sender)
{
    if (this->m_bUseFMCCD->Checked == false) m_bUseFMCCD2->Checked = false;
}
//---------------------------------------------------------------------------

