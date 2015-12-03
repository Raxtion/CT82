object frmUserID: TfrmUserID
  Left = 530
  Top = 249
  Width = 340
  Height = 491
  Caption = #35531#36664#20837
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 20
  object BitBtn1: TBitBtn
    Left = 32
    Top = 392
    Width = 100
    Height = 50
    TabOrder = 0
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 192
    Top = 392
    Width = 100
    Height = 50
    TabOrder = 1
    Kind = bkCancel
  end
  object StaticText58: TStaticText
    Left = 16
    Top = 22
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Machine ID'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 2
  end
  object m_strSMSMachineID: TEdit
    Left = 148
    Top = 22
    Width = 150
    Height = 28
    TabOrder = 3
    Text = 'XL MAP'
  end
  object StaticText35: TStaticText
    Left = 16
    Top = 62
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'User ID'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 4
  end
  object m_strSMSUserID: TEdit
    Left = 148
    Top = 62
    Width = 150
    Height = 28
    TabOrder = 5
    Text = '13 X 13 * 0.9'
  end
  object StaticText36: TStaticText
    Left = 16
    Top = 94
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Part No.'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 6
  end
  object m_strSMSPartNo: TEdit
    Left = 148
    Top = 94
    Width = 150
    Height = 28
    TabOrder = 7
    Text = 'ABCDEFG123B1'
  end
  object StaticText37: TStaticText
    Left = 16
    Top = 126
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Lot No.'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 8
  end
  object m_strSMSLotNo: TEdit
    Left = 149
    Top = 126
    Width = 150
    Height = 28
    TabOrder = 9
    Text = '14'
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 318
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Product ID'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 10
    Visible = False
  end
  object m_strProductID: TEdit
    Left = 149
    Top = 318
    Width = 150
    Height = 28
    TabOrder = 11
    Text = '14'
    Visible = False
  end
  object cmbProduct: TComboBox
    Left = 148
    Top = 166
    Width = 169
    Height = 28
    Color = clCaptionText
    ItemHeight = 20
    TabOrder = 12
  end
  object StaticText2: TStaticText
    Left = 16
    Top = 166
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Product Pgm.'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 13
  end
  object StaticText3: TStaticText
    Left = 16
    Top = 206
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Machine Pgm.'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 14
  end
  object cmbMachine: TComboBox
    Left = 149
    Top = 206
    Width = 167
    Height = 28
    ItemHeight = 20
    TabOrder = 15
    Text = 'ComboBox1'
  end
  object StaticText4: TStaticText
    Left = 16
    Top = 246
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'Issue Qty'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 16
  end
  object m_nIssueQty: TEdit
    Left = 149
    Top = 246
    Width = 156
    Height = 28
    TabOrder = 17
    Text = '14'
  end
  object StaticText5: TStaticText
    Left = 16
    Top = 286
    Width = 122
    Height = 28
    Alignment = taRightJustify
    AutoSize = False
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelOuter = bvNone
    BorderStyle = sbsSingle
    Caption = 'SBT Lot No.'
    Color = clSkyBlue
    ParentColor = False
    TabOrder = 18
    Visible = False
  end
  object m_strSBTLotNo: TEdit
    Left = 149
    Top = 286
    Width = 150
    Height = 28
    TabOrder = 19
    Text = '14'
    Visible = False
  end
end
