object frmChoiceMotor: TfrmChoiceMotor
  Left = 528
  Top = 11
  BorderStyle = bsDialog
  BorderWidth = 5
  Caption = #36984#25799#39340#36948
  ClientHeight = 576
  ClientWidth = 458
  Color = 13430215
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = #26032#32048#26126#39636
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 16
  object BitBtn11: TBitBtn
    Tag = 2
    Left = 16
    Top = 176
    Width = 185
    Height = 65
    Caption = '(2)'
    Enabled = False
    ModalResult = 1
    TabOrder = 10
    Visible = False
    OnClick = btnPickAxisClick
  end
  object BitBtn8: TBitBtn
    Tag = 1
    Left = 16
    Top = 96
    Width = 185
    Height = 65
    Caption = '(1)'
    Enabled = False
    ModalResult = 1
    TabOrder = 7
    Visible = False
    OnClick = btnPickAxisClick
  end
  object BitBtn7: TBitBtn
    Left = 16
    Top = 16
    Width = 185
    Height = 65
    Caption = '(0)'
    Enabled = False
    ModalResult = 1
    TabOrder = 6
    Visible = False
    OnClick = btnPickAxisClick
  end
  object BitBtn5: TBitBtn
    Tag = 3
    Left = 16
    Top = 256
    Width = 185
    Height = 65
    Caption = '(3)'
    Enabled = False
    ModalResult = 1
    TabOrder = 4
    Visible = False
    OnClick = btnPickAxisClick
  end
  object BitBtn2: TBitBtn
    Tag = 9
    Left = 16
    Top = 336
    Width = 185
    Height = 65
    Caption = '(9)'
    Enabled = False
    ModalResult = 1
    TabOrder = 1
    Visible = False
    OnClick = btnPickAxisClick
  end
  object BitBtn1: TBitBtn
    Tag = 3
    Left = 120
    Top = 464
    Width = 185
    Height = 57
    TabOrder = 0
    Kind = bkClose
  end
  object BitBtn3: TBitBtn
    Tag = 8
    Left = 128
    Top = 336
    Width = 185
    Height = 65
    Caption = #35222#35258'(CCD)'
    ModalResult = 1
    TabOrder = 2
    OnClick = btnPickAxisClick
  end
  object BitBtn4: TBitBtn
    Tag = 7
    Left = 128
    Top = 256
    Width = 185
    Height = 65
    Caption = #20986#26009#21560#30436'(SCY)'
    ModalResult = 1
    TabOrder = 3
    OnClick = btnPickAxisClick
  end
  object BitBtn6: TBitBtn
    Tag = 6
    Left = 128
    Top = 176
    Width = 185
    Height = 65
    Caption = #20837#26009#21560#30436'(SSY)'
    ModalResult = 1
    TabOrder = 5
    OnClick = btnPickAxisClick
  end
  object BitBtn9: TBitBtn
    Tag = 5
    Left = 128
    Top = 96
    Width = 185
    Height = 65
    Caption = #24460#32763#36681#24179#21488'(RTX)'
    ModalResult = 1
    TabOrder = 8
    OnClick = btnPickAxisClick
  end
  object BitBtn10: TBitBtn
    Tag = 4
    Left = 128
    Top = 16
    Width = 185
    Height = 65
    Caption = #21069#32763#36681#24179#21488'(FTX)'
    ModalResult = 1
    TabOrder = 9
    OnClick = btnPickAxisClick
  end
end
