//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmUserID.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TfrmUserID *frmUserID;
//---------------------------------------------------------------------------
__fastcall TfrmUserID::TfrmUserID(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmUserID::FormCreate(TObject *Sender)
{

        TSearchRec sr;
        int iAttributes = 0;
       
        //iAttributes |= faReadOnly;
        //iAttributes |= faHidden;
        //iAttributes |= faSysFile;
        //iAttributes |= faVolumeID;
        iAttributes |= faDirectory;
        //iAttributes |= faArchive;
        //iAttributes |= faAnyFile;

        cmbProduct->Clear();
        if (FindFirst("C:\\Product Data\\C77Product\\*.*", iAttributes, sr) == 0)
        {
                do
                {
                        if ((sr.Attr & iAttributes) == sr.Attr)
                        {

                                if(sr.Name!="." && sr.Name!="..") cmbProduct->AddItem(sr.Name,NULL);
                        }
                } while (FindNext(sr) == 0);
                FindClose(sr);
        }

        cmbMachine->Clear();
        if (FindFirst("C:\\Product Data\\C77Machine\\*.*", iAttributes, sr) == 0)
        {
                do
                {
                        if ((sr.Attr & iAttributes) == sr.Attr)
                        {

                                if(sr.Name!="." && sr.Name!="..") cmbMachine->AddItem(sr.Name,NULL);
                        }
                } while (FindNext(sr) == 0);
                FindClose(sr);
        }




}
//---------------------------------------------------------------------------

void __fastcall TfrmUserID::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        if(ModalResult==mrOk)
        {

                //open MachinePgm
                //AnsiString strName1="C:\\Product Data\\C77Machine\\"+m_strSMSPartNo->Text+"\\"+m_strSMSPartNo->Text+".ini";
                //open ProductPgm
                AnsiString strName2="C:\\Product Data\\C77Product\\"+m_strSMSPartNo->Text+"\\"+m_strSMSPartNo->Text+".ini";

                if(/*FileExists(strName1) &&*/  FileExists(strName2))
                {
                        cmbProduct->Text=m_strSMSPartNo->Text;
                        //cmbMachine->Text=m_strSBTLotNo->Text;
                        CanClose = true;
                }
                else
                {
                        ShowMessage("找不到跟 Part No. 相對應的設定參數,請重新輸入");
                        CanClose = false;
                }
        }
        else CanClose=true;

}
//---------------------------------------------------------------------------




