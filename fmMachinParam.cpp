//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmMachinParam.h"
#include "fmMotorCheck.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TfrmMachineParam *frmMachineParam;

//---------------------------------------------------------------------------
__fastcall TfrmMachineParam::TfrmMachineParam(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall TfrmMachineParam::StaticText39Click(TObject *Sender)
{
        //BPZ=0,BLZ=1,SCZ=2,CCD=3,SCY=4,CRD=5,BPY=6,SSY=7,RTX=8,FTX=9

        TStaticText *pText=(TStaticText *)Sender;
        TfrmMotorCheck *pMotorCheckDlg;

        pMotorCheckDlg=new TfrmMotorCheck(this);
        pMotorCheckDlg->m_nActiveAxis=pText->Tag;
        pMotorCheckDlg->Caption=pText->Caption;

        if(pMotorCheckDlg->ShowModal()==mrOk)
        {
                TEdit *pEdit=(TEdit *)FindComponent(pText->Hint);
                if(pEdit) pEdit->Text=pMotorCheckDlg->m_dCurrPos;
                else ShowMessage("¼g¤J¥¢±Ñ");
        }


        delete pMotorCheckDlg;
}
//---------------------------------------------------------------------------


