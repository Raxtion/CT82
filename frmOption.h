//---------------------------------------------------------------------------

#ifndef frmOptionH
#define frmOptionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfmOption : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TGroupBox *GroupBox1;
        TCheckBox *m_bIsRailLoad;
        TCheckBox *m_bReadVenderID;
        TCheckBox *m_bUseFMCCD;
        TCheckBox *m_bUseMapCCD;
        TCheckBox *m_bUseLaserMark;
        TCheckBox *m_bUseLaserCodeReader;
        TCheckBox *m_bUseCover;
        TCheckBox *m_bUseBoat;
        TCheckBox *m_bEAPCoverControl;
        TCheckBox *m_bEAPBoatControl;
        TCheckBox *m_bIsSingleSubstrate;
        TRadioGroup *m_nUseTable;
        TCheckBox *m_bUseCoverHolder;
        TCheckBox *m_bShakeSubstarte;
        TCheckBox *m_bUsePQC;
        TCheckBox *m_bDoubleSide;
private:	// User declarations
public:		// User declarations
        __fastcall TfmOption(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmOption *fmOption;
//---------------------------------------------------------------------------
#endif
