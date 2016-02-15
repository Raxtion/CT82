//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmShowNow.h"
#include "MainThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmShowNow *fmShowNow;
extern CMainThread *g_pMainThread;
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

void __fastcall TfmShowNow::Image1Click(TObject *Sender)
{
    TImage* Img = (TImage*)Sender;
    switch (Img->Tag)
    {
        case 0:
            if(Application->MessageBox("是否重置 入料流道?", "Info", MB_OKCANCEL)==IDCANCEL) return;
            g_pMainThread->nThreadIndex[1] = 0;
            g_pMainThread->m_bLoadRailReady = false;
            break;
        case 1:
            if(Application->MessageBox("是否重置 入料吸盤?", "Info", MB_OKCANCEL)==IDCANCEL) return;
            g_pMainThread->nThreadIndex[2] = 0;
            g_pMainThread->nThreadIndex[3] = 0;
            g_pMainThread->nThreadIndex[4] = 0;
            g_pMainThread->m_bSSPickerReady = false;
            g_pMainThread->m_bSSPickerReady = false;
            g_pMainThread->m_bLoadLifterReady = false;
            break;
        case 2:
            if(Application->MessageBox("是否重置 雙軌平台?", "Info", MB_OKCANCEL)==IDCANCEL) return;
            g_pMainThread->nThreadIndex[5] = 0;
            g_pMainThread->nThreadIndex[6] = 0;
            g_pMainThread->m_bTableReady[0] = false;
            g_pMainThread->m_bTableReady[1] = false;
            g_pMainThread->m_bIsMapCCDLocked = false;
            g_pMainThread->m_listPutTable.clear();
            g_pMainThread->m_listPickTable.clear();
            g_pMainThread->m_bLaserLocked = false;
            break;
        case 3:
            if(Application->MessageBox("是否重置 出料吸盤?", "Info", MB_OKCANCEL)==IDCANCEL) return;
            g_pMainThread->nThreadIndex[7] = 0;
            g_pMainThread->m_bSCPickerSSReady = false;
            g_pMainThread->m_listProductInfo.clear();
            break;
        case 4:
            if(Application->MessageBox("是否重置 出料流道?", "Info", MB_OKCANCEL)==IDCANCEL) return;
            g_pMainThread->nThreadIndex[8] = 0;
            break;
        default:
            break;
    }
}
//---------------------------------------------------------------------------


