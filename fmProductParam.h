//---------------------------------------------------------------------------

#ifndef fmProductParamH
#define fmProductParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmProductParam : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox6;
        TStaticText *StaticText35;
        TEdit *m_strSBTSize;
        TStaticText *StaticText36;
        TEdit *m_strScheduleNo;
        TStaticText *StaticText37;
        TEdit *m_nSubLotSize;
        TStaticText *StaticText38;
        TStaticText *StaticText39;
        TEdit *editScheduleQty;
        TGroupBox *GroupBox5;
        TEdit *m_nLaserProgramNo0;
        TStaticText *StaticText33;
        TGroupBox *GroupBox3;
        TStaticText *StaticText23;
        TStaticText *StaticText24;
        TEdit *m_nPackageX;
        TEdit *m_nPackageY;
        TStaticText *StaticText25;
        TEdit *m_nDeviceX;
        TStaticText *StaticText26;
        TEdit *m_nDeviceY;
        TStaticText *StaticText27;
        TEdit *m_nPackageGap;
        TUpDown *UpDown1;
        TStaticText *StaticText58;
        TEdit *m_strSBTType;
        TGroupBox *GroupBox4;
        TLabel *Label2;
        TEdit *m_dMarkScore0;
        TCheckBox *m_bFindOKMark;
        TGroupBox *GroupBox10;
        TLabel *labelLED0;
        TLabel *labelLED1;
        TTrackBar *trackLED0;
        TTrackBar *trackLED1;
        TStaticText *StaticText28;
        TUpDown *UpDown2;
        TEdit *m_nLaserProgramNo1;
        TGroupBox *GroupBox12;
        TLabel *Label1;
        TEdit *m_dMarkScore1;
        TGroupBox *GroupBox13;
        TLabel *Label3;
        TEdit *m_dMarkScore2;
        TRadioGroup *m_nSBTCorner;
        TRadioGroup *m_nSBTColWord;
        TRadioGroup *m_nSBTRowWord;
        TGroupBox *GroupBox1;
        TEdit *m_nLaserProgramNo2;
        TStaticText *StaticText1;
        TUpDown *UpDown3;
        TStaticText *StaticText2;
        TEdit *m_nLaserProgramNo3;
        TUpDown *UpDown4;
    TGroupBox *GroupBox2;
    TComboBox *m_cmbLaserQualityThreshold;
    TLabel *Label4;
        void __fastcall trackLED0Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall trackLED1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmProductParam(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmProductParam *frmProductParam;
//---------------------------------------------------------------------------
#endif
