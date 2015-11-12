//---------------------------------------------------------------------------

#ifndef fmMachinParamH
#define fmMachinParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmMachineParam : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TCheckBox *m_bForceEject;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TGroupBox *GroupBox3;
        TStaticText *StaticText28;
        TEdit *m_dTableMapCCDPosX1;
        TStaticText *StaticText29;
        TStaticText *StaticText17;
        TEdit *m_dTableMapCCDPosY1;
        TStaticText *StaticText18;
        TStaticText *StaticText19;
        TStaticText *StaticText20;
        TEdit *m_dTableMapCCDPosX0;
        TEdit *m_dTableMapCCDPosY0;
        TStaticText *StaticText21;
        TStaticText *StaticText22;
        TStaticText *StaticText24;
        TEdit *m_dTableMapCCDPitch;
        TStaticText *StaticText25;
        TGroupBox *GroupBox2;
        TStaticText *StaticText26;
        TEdit *m_dFMCCDResolution0;
        TStaticText *StaticText27;
        TStaticText *StaticText30;
        TEdit *m_dFMCCDResolution1;
        TStaticText *StaticText31;
        TGroupBox *GroupBox4;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *m_nImageWidth;
        TEdit *m_dImageAngle;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox5;
        TLabel *Label3;
        TEdit *m_strSMSServerIP;
        TLabel *Label4;
        TEdit *m_nSMSServerPort;
        TGroupBox *GroupBox6;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *m_strSMSClientIP;
        TEdit *m_nSMSClientPort;
        TTabSheet *TabSheet3;
        TGroupBox *GroupBox7;
        TStaticText *StaticText32;
        TEdit *m_nCoverVacTime;
        TStaticText *StaticText33;
        TStaticText *StaticText34;
        TEdit *m_nSubstrateVacTime;
        TStaticText *StaticText35;
        TTabSheet *TabSheet4;
        TGroupBox *GroupBox1;
        TEdit *editAcc1;
        TEdit *editDec1;
        TEdit *editJogSpeed1;
        TEdit *editWorkSpeed1;
        TEdit *editAcc2;
        TEdit *editDec2;
        TEdit *editJogSpeed2;
        TEdit *editWorkSpeed2;
        TEdit *editAcc3;
        TEdit *editDec3;
        TEdit *editJogSpeed3;
        TEdit *editWorkSpeed3;
        TEdit *editAcc4;
        TEdit *editDec4;
        TEdit *editJogSpeed4;
        TEdit *editWorkSpeed4;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TStaticText *StaticText3;
        TStaticText *StaticText4;
        TStaticText *StaticText5;
        TStaticText *StaticText6;
        TStaticText *StaticText7;
        TStaticText *StaticText8;
        TStaticText *StaticText9;
        TStaticText *StaticText10;
        TStaticText *StaticText11;
        TStaticText *StaticText12;
        TStaticText *StaticText13;
        TStaticText *StaticText14;
        TEdit *editAcc5;
        TEdit *editDec5;
        TEdit *editJogSpeed5;
        TEdit *editWorkSpeed5;
        TStaticText *StaticText15;
        TEdit *editAcc6;
        TEdit *editDec6;
        TEdit *editJogSpeed6;
        TEdit *editWorkSpeed6;
        TStaticText *StaticText16;
        TStaticText *StaticText23;
        TEdit *editAcc7;
        TEdit *editDec7;
        TEdit *editJogSpeed7;
        TEdit *editWorkSpeed7;
        TStaticText *StaticText36;
        TEdit *editAcc8;
        TEdit *editDec8;
        TEdit *editJogSpeed8;
        TEdit *editWorkSpeed8;
        TStaticText *StaticText37;
        TEdit *editAcc9;
        TEdit *editDec9;
        TEdit *editJogSpeed9;
        TEdit *editWorkSpeed9;
        TStaticText *StaticText38;
        TEdit *editAcc10;
        TEdit *editDec10;
        TEdit *editJogSpeed10;
        TEdit *editWorkSpeed10;
        TTabSheet *TabSheet5;
        TGroupBox *GroupBox8;
        TStaticText *StaticText39;
        TEdit *m_dSSPickerPickPos;
        TStaticText *StaticText40;
        TStaticText *StaticText41;
        TEdit *m_dSSPickerPickRailPos;
        TStaticText *StaticText42;
        TStaticText *StaticText43;
        TEdit *m_dSSPickerPutPos0;
        TStaticText *StaticText44;
        TStaticText *StaticText45;
        TEdit *m_dSpaPickerPickPos;
        TStaticText *StaticText46;
        TStaticText *StaticText47;
        TEdit *m_dSpaPickerThrowPos;
        TStaticText *StaticText48;
        TStaticText *StaticText49;
        TEdit *m_dSSPickerPutPos1;
        TStaticText *StaticText50;
        TGroupBox *GroupBox9;
        TStaticText *StaticText51;
        TEdit *editCheckSSPlacePos1;
        TStaticText *StaticText52;
        TStaticText *StaticText53;
        TEdit *editCheckSSPlacePos2;
        TStaticText *StaticText54;
        TStaticText *StaticText55;
        TEdit *editCheckSSPlacePos3;
        TStaticText *StaticText56;
        TStaticText *StaticText57;
        TEdit *editCheckSSPlacePos4;
        TStaticText *StaticText58;
        TGroupBox *GroupBox10;
        TStaticText *StaticText59;
        TEdit *m_dTablePutDownPos1;
        TStaticText *StaticText60;
        TStaticText *StaticText61;
        TEdit *m_dTableMarkPosX1;
        TStaticText *StaticText62;
        TStaticText *StaticText63;
        TEdit *m_dTableMarkPosY1;
        TStaticText *StaticText64;
        TStaticText *StaticText65;
        TStaticText *StaticText66;
        TEdit *m_dTableVenderCodePosX1;
        TEdit *m_dTableVenderCodePosY1;
        TStaticText *StaticText67;
        TStaticText *StaticText68;
        TStaticText *StaticText69;
        TEdit *m_dTableLaserPos1;
        TStaticText *StaticText70;
        TStaticText *StaticText71;
        TStaticText *StaticText72;
        TEdit *m_dTableLaserCodePosX1;
        TEdit *m_dTableLaserCodePosY1;
        TStaticText *StaticText73;
        TStaticText *StaticText74;
        TStaticText *StaticText75;
        TEdit *m_dTablePickUpPos1;
        TStaticText *StaticText76;
        TGroupBox *GroupBox11;
        TStaticText *StaticText77;
        TEdit *m_dTablePutDownPos0;
        TStaticText *StaticText78;
        TStaticText *StaticText79;
        TEdit *m_dTableMarkPosX0;
        TStaticText *StaticText80;
        TStaticText *StaticText81;
        TEdit *m_dTableMarkPosY0;
        TStaticText *StaticText82;
        TStaticText *StaticText83;
        TStaticText *StaticText84;
        TEdit *m_dTableVenderCodePosX0;
        TEdit *m_dTableVenderCodePosY0;
        TStaticText *StaticText85;
        TStaticText *StaticText86;
        TStaticText *StaticText87;
        TEdit *m_dTableLaserPos0;
        TStaticText *StaticText88;
        TStaticText *StaticText89;
        TStaticText *StaticText90;
        TEdit *m_dTableLaserCodePosX0;
        TEdit *m_dTableLaserCodePosY0;
        TStaticText *StaticText91;
        TStaticText *StaticText92;
        TStaticText *StaticText93;
        TEdit *m_dTablePickUpPos0;
        TStaticText *StaticText94;
        TTabSheet *TabSheet6;
        TGroupBox *GroupBox12;
        TStaticText *StaticText99;
        TEdit *m_dSCPickerPickSSPosY0;
        TStaticText *StaticText101;
        TStaticText *StaticText103;
        TEdit *m_dSCPickerPickSSPosY1;
        TStaticText *StaticText105;
    TGroupBox *GroupBox13;
    TEdit *m_editLaserCodeReaderPos1;
    TStaticText *StaticText96;
    TStaticText *StaticText97;
    TEdit *m_editLaserCodeReaderPos0;
    TStaticText *StaticText98;
    TGroupBox *GroupBox14;
    TStaticText *StaticText100;
    TEdit *m_editSBTNGBoxPos;
    TStaticText *StaticText102;
    TStaticText *StaticText104;
    TEdit *m_editSCPickerPutSSPos;
    TStaticText *StaticText106;
        TStaticText *StaticText200;
        void __fastcall StaticText39Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmMachineParam(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMachineParam *frmMachineParam;
//---------------------------------------------------------------------------
#endif
