//---------------------------------------------------------------------------

#ifndef frmManualH
#define frmManualH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfmManual : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TTimer *Timer1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TGroupBox *GroupBox5;
        TSpeedButton *btnSSY;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton14;
        TShape *X48;
        TShape *X49;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton32;
        TShape *X52;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton54;
        TShape *X50;
        TShape *X51;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton53;
        TShape *X53;
        TSpeedButton *SpeedButton1;
        TShape *X32;
        TShape *X38;
        TShape *X33;
        TSpeedButton *SpeedButton2;
        TStaticText *StaticText1;
        TEdit *m_dSSPickerPickPos;
        TStaticText *StaticText2;
        TStaticText *StaticText4;
        TEdit *m_dSSPickerPickRailPos;
        TStaticText *StaticText6;
        TStaticText *StaticText9;
        TEdit *m_dSSPickerPutPos0;
        TStaticText *StaticText10;
        TStaticText *StaticText21;
        TEdit *m_dSpaPickerPickPos;
        TStaticText *StaticText22;
        TStaticText *StaticText23;
        TEdit *m_dSpaPickerThrowPos;
        TStaticText *StaticText24;
        TStaticText *StaticText25;
        TEdit *m_dSSPickerPutPos1;
        TStaticText *StaticText26;
        TGroupBox *GroupBox8;
        TSpeedButton *SpeedButton34;
        TSpeedButton *SpeedButton42;
        TSpeedButton *SpeedButton60;
        TSpeedButton *SpeedButton61;
        TShape *X16;
        TShape *X17;
        TShape *X20;
        TStaticText *StaticText78;
        TEdit *m_dSCPickerPickSSPosY1;
        TStaticText *StaticText80;
        TStaticText *StaticText74;
        TEdit *m_dSCPickerPickSSPosY0;
        TStaticText *StaticText76;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox1;
        TSpeedButton *btnFTX;
        TSpeedButton *SpeedButton15;
        TSpeedButton *SpeedButton16;
        TSpeedButton *SpeedButton22;
        TSpeedButton *SpeedButton17;
        TSpeedButton *SpeedButton18;
        TSpeedButton *SpeedButton21;
        TSpeedButton *SpeedButton20;
        TSpeedButton *SpeedButton19;
        TSpeedButton *SpeedButton57;
        TSpeedButton *SpeedButton56;
        TShape *X2;
        TStaticText *StaticText13;
        TEdit *m_dTablePutDownPos1;
        TStaticText *StaticText15;
        TStaticText *StaticText17;
        TEdit *m_dTableMarkPosX1;
        TStaticText *StaticText19;
        TStaticText *StaticText20;
        TEdit *m_dTableMarkPosY1;
        TStaticText *StaticText27;
        TStaticText *StaticText28;
        TStaticText *StaticText29;
        TEdit *m_dTableVenderCodePosX1;
        TEdit *m_dTableVenderCodePosY1;
        TStaticText *StaticText30;
        TStaticText *StaticText31;
        TStaticText *StaticText32;
        TEdit *m_dTableLaserPos1;
        TStaticText *StaticText33;
        TStaticText *StaticText34;
        TStaticText *StaticText35;
        TEdit *m_dTableLaserCodePosX1;
        TEdit *m_dTableLaserCodePosY1;
        TStaticText *StaticText36;
        TStaticText *StaticText40;
        TStaticText *StaticText41;
        TEdit *m_dTablePickUpPos1;
        TStaticText *StaticText42;
        TGroupBox *GroupBox7;
        TSpeedButton *SpeedButton23;
        TSpeedButton *SpeedButton24;
        TSpeedButton *SpeedButton25;
        TSpeedButton *SpeedButton28;
        TSpeedButton *SpeedButton31;
        TSpeedButton *SpeedButton26;
        TSpeedButton *SpeedButton30;
        TSpeedButton *SpeedButton29;
        TSpeedButton *SpeedButton27;
        TSpeedButton *SpeedButton58;
        TSpeedButton *SpeedButton59;
        TShape *X10;
        TStaticText *StaticText43;
        TEdit *m_dTablePutDownPos0;
        TStaticText *StaticText44;
        TStaticText *StaticText45;
        TEdit *m_dTableMarkPosX0;
        TStaticText *StaticText46;
        TStaticText *StaticText47;
        TEdit *m_dTableMarkPosY0;
        TStaticText *StaticText48;
        TStaticText *StaticText49;
        TStaticText *StaticText59;
        TEdit *m_dTableVenderCodePosX0;
        TEdit *m_dTableVenderCodePosY0;
        TStaticText *StaticText60;
        TStaticText *StaticText61;
        TStaticText *StaticText62;
        TEdit *m_dTableLaserPos0;
        TStaticText *StaticText63;
        TStaticText *StaticText64;
        TStaticText *StaticText65;
        TEdit *m_dTableLaserCodePosX0;
        TEdit *m_dTableLaserCodePosY0;
        TStaticText *StaticText66;
        TStaticText *StaticText67;
        TStaticText *StaticText68;
        TEdit *m_dTablePickUpPos0;
        TStaticText *StaticText69;
        TSpeedButton *SpeedButton7;
        TBitBtn *BitBtn2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label18;
        TLabel *Label20;
        TLabel *Label21;
    TGroupBox *GroupBox14;
    TStaticText *StaticText100;
    TEdit *m_editSBTNGBoxPos;
    TStaticText *StaticText102;
    TStaticText *StaticText104;
    TEdit *m_editSCPickerPutSSPos;
    TStaticText *StaticText106;
    TGroupBox *GroupBox13;
    TStaticText *StaticText95;
    TEdit *m_editLaserCodeReaderPos1;
    TStaticText *StaticText96;
    TStaticText *StaticText97;
    TEdit *m_editLaserCodeReaderPos0;
    TStaticText *StaticText98;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton5;
    TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton33;
        TSpeedButton *SpeedButton35;
        TSpeedButton *SpeedButton36;
        TSpeedButton *SpeedButton37;
        TSpeedButton *SpeedButton38;
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall btnSSYClick(TObject *Sender);
        void __fastcall btnFTXClick(TObject *Sender);
        void __fastcall btnSCYClick(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton14Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall StaticText1Click(TObject *Sender);
        void __fastcall SpeedButton53Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfmManual(TComponent* Owner);
        bool __fastcall AxisMoveCheck();

        void __fastcall EnableAllButton(bool bEnabled);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmManual *fmManual;
//---------------------------------------------------------------------------
#endif
