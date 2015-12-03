object frmProductParam: TfrmProductParam
  Left = 424
  Top = 312
  BorderStyle = bsDialog
  Caption = 'frmProductParam'
  ClientHeight = 607
  ClientWidth = 943
  Color = 13430215
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = #26032#32048#26126#39636
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object BitBtn1: TBitBtn
    Left = 800
    Top = 48
    Width = 121
    Height = 41
    TabOrder = 0
    Kind = bkOK
  end
  object BitBtn2: TBitBtn
    Left = 800
    Top = 128
    Width = 121
    Height = 41
    TabOrder = 1
    Kind = bkCancel
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 761
    Height = 601
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #29986#21697#35215#26684
      object GroupBox6: TGroupBox
        Left = 8
        Top = 16
        Width = 393
        Height = 105
        Caption = #29986#21697#35215#26684
        Color = clAqua
        ParentColor = False
        TabOrder = 0
        object StaticText35: TStaticText
          Left = 32
          Top = 62
          Width = 74
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #29986#21697#23610#23544
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 0
        end
        object m_strSBTSize: TEdit
          Left = 112
          Top = 62
          Width = 241
          Height = 24
          TabOrder = 1
          Text = '13 X 13 * 0.9'
        end
        object StaticText36: TStaticText
          Left = 16
          Top = 118
          Width = 122
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #25209'        '#34399
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 2
        end
        object m_strScheduleNo: TEdit
          Left = 144
          Top = 118
          Width = 217
          Height = 24
          TabOrder = 3
          Text = 'ABCDEFG123B1'
        end
        object StaticText37: TStaticText
          Left = 16
          Top = 150
          Width = 122
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #27599#30418#26781#25976
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object m_nSubLotSize: TEdit
          Left = 144
          Top = 150
          Width = 129
          Height = 24
          TabOrder = 5
          Text = '14'
        end
        object StaticText38: TStaticText
          Left = 280
          Top = 150
          Width = 81
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'L/F'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 6
        end
        object StaticText39: TStaticText
          Left = 16
          Top = 182
          Width = 122
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #30332#26009#25976#37327
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 7
        end
        object editScheduleQty: TEdit
          Left = 144
          Top = 182
          Width = 129
          Height = 24
          TabOrder = 8
          Text = '6000'
        end
        object StaticText58: TStaticText
          Left = 32
          Top = 22
          Width = 74
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #22522#26495#22411#24907
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 9
        end
        object m_strSBTType: TEdit
          Left = 112
          Top = 22
          Width = 241
          Height = 24
          TabOrder = 10
          Text = 'XL MAP'
        end
      end
      object GroupBox5: TGroupBox
        Left = 8
        Top = 136
        Width = 393
        Height = 105
        Caption = #27491#38754#36984#29992#38647#21051#27284#26696#32232#34399
        TabOrder = 1
        object m_nLaserProgramNo0: TEdit
          Left = 96
          Top = 56
          Width = 121
          Height = 24
          TabOrder = 0
          Text = '0'
        end
        object StaticText33: TStaticText
          Left = 32
          Top = 54
          Width = 58
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #24460#24179#21488
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object UpDown1: TUpDown
          Left = 217
          Top = 56
          Width = 16
          Height = 24
          Associate = m_nLaserProgramNo0
          Min = 0
          Max = 1999
          Position = 0
          TabOrder = 2
          Wrap = False
        end
        object StaticText28: TStaticText
          Left = 32
          Top = 22
          Width = 58
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #21069#24179#21488
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_nLaserProgramNo1: TEdit
          Left = 96
          Top = 24
          Width = 121
          Height = 24
          TabOrder = 4
          Text = '0'
        end
        object UpDown2: TUpDown
          Left = 217
          Top = 24
          Width = 16
          Height = 24
          Associate = m_nLaserProgramNo1
          Min = 0
          Max = 1999
          Position = 0
          TabOrder = 5
          Wrap = False
        end
      end
      object m_nSBTCorner: TRadioGroup
        Left = 432
        Top = 16
        Width = 201
        Height = 225
        Caption = #22522#26495#32570#35282#20301#32622
        ItemIndex = 0
        Items.Strings = (
          #24038#19978
          #21491#19978
          #24038#19979
          #21491#19979)
        TabOrder = 2
        Visible = False
      end
      object m_nSBTColWord: TRadioGroup
        Left = 8
        Top = 360
        Width = 281
        Height = 185
        Caption = #22522#26495#39023#31034#23383#20803#25490#21015'('#19978#26041')'
        ItemIndex = 0
        Items.Strings = (
          '1,2,3,4,5,6,7.....'
          '.......7,6,5,4,3,2,1'
          'A,B,C,D,........'
          '..........D,C,B,A')
        TabOrder = 3
        Visible = False
      end
      object m_nSBTRowWord: TRadioGroup
        Left = 296
        Top = 360
        Width = 281
        Height = 185
        Caption = #22522#26495#39023#31034#23383#20803#25490#21015'('#24038#26041')'
        ItemIndex = 0
        Items.Strings = (
          '1,2,3,4,5,6,7.....'
          '.......7,6,5,4,3,2,1'
          'A,B,C,D,........'
          '..........D,C,B,A')
        TabOrder = 4
        Visible = False
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 248
        Width = 393
        Height = 105
        Caption = #21453#38754#36984#29992#38647#21051#27284#26696#32232#34399
        TabOrder = 5
        object m_nLaserProgramNo2: TEdit
          Left = 96
          Top = 56
          Width = 121
          Height = 24
          TabOrder = 0
          Text = '0'
        end
        object StaticText1: TStaticText
          Left = 32
          Top = 54
          Width = 58
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #24460#24179#21488
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object UpDown3: TUpDown
          Left = 217
          Top = 56
          Width = 16
          Height = 24
          Associate = m_nLaserProgramNo2
          Min = 0
          Max = 1999
          Position = 0
          TabOrder = 2
          Wrap = False
        end
        object StaticText2: TStaticText
          Left = 32
          Top = 22
          Width = 58
          Height = 28
          Alignment = taRightJustify
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = #21069#24179#21488
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 3
        end
        object m_nLaserProgramNo3: TEdit
          Left = 96
          Top = 24
          Width = 121
          Height = 24
          TabOrder = 4
          Text = '0'
        end
        object UpDown4: TUpDown
          Left = 217
          Top = 24
          Width = 16
          Height = 24
          Associate = m_nLaserProgramNo3
          Min = 0
          Max = 1999
          Position = 0
          TabOrder = 5
          Wrap = False
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #35222#35258#21443#25976
      ImageIndex = 1
      object GroupBox3: TGroupBox
        Left = 16
        Top = 169
        Width = 257
        Height = 241
        Caption = #22522#26495#21443#25976
        TabOrder = 0
        Visible = False
        object StaticText23: TStaticText
          Left = 32
          Top = 30
          Width = 97
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'Package X'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 0
        end
        object StaticText24: TStaticText
          Left = 32
          Top = 62
          Width = 97
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'Package Y'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 1
        end
        object m_nPackageX: TEdit
          Left = 136
          Top = 30
          Width = 81
          Height = 24
          TabOrder = 2
          Text = 'editPickSpacerPosY'
        end
        object m_nPackageY: TEdit
          Left = 136
          Top = 62
          Width = 81
          Height = 24
          TabOrder = 3
          Text = 'editDotPosition'
        end
        object StaticText25: TStaticText
          Left = 32
          Top = 150
          Width = 97
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'Device X'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 4
        end
        object m_nDeviceX: TEdit
          Left = 136
          Top = 150
          Width = 81
          Height = 24
          TabOrder = 5
          Text = 'editDotPosition'
        end
        object StaticText26: TStaticText
          Left = 32
          Top = 182
          Width = 97
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'Device Y'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 6
        end
        object m_nDeviceY: TEdit
          Left = 136
          Top = 182
          Width = 81
          Height = 24
          TabOrder = 7
          Text = 'editDotPosition'
        end
        object StaticText27: TStaticText
          Left = 32
          Top = 94
          Width = 97
          Height = 28
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          BevelOuter = bvNone
          BorderStyle = sbsSingle
          Caption = 'Package  Gap'
          Color = clSkyBlue
          ParentColor = False
          TabOrder = 8
        end
        object m_nPackageGap: TEdit
          Left = 136
          Top = 94
          Width = 81
          Height = 24
          TabOrder = 9
          Text = 'editDotPosition'
        end
      end
      object GroupBox4: TGroupBox
        Left = 16
        Top = 416
        Width = 257
        Height = 121
        Caption = #40670#37327'CCD '#21443#25976
        TabOrder = 1
        Visible = False
        object Label2: TLabel
          Left = 21
          Top = 32
          Width = 68
          Height = 16
          Caption = 'Min. Score'
        end
        object m_dMarkScore0: TEdit
          Left = 96
          Top = 30
          Width = 81
          Height = 24
          TabOrder = 0
          Text = 'editPickSpacerPosY'
        end
        object m_bFindOKMark: TCheckBox
          Left = 16
          Top = 64
          Width = 177
          Height = 33
          Caption = #25945#23566#27161#30340#28858#33391#21697
          TabOrder = 1
        end
      end
      object GroupBox10: TGroupBox
        Left = 296
        Top = 8
        Width = 161
        Height = 305
        Caption = #20809#28304#20142#24230
        TabOrder = 2
        object labelLED0: TLabel
          Left = 40
          Top = 280
          Width = 8
          Height = 16
          Caption = '0'
        end
        object labelLED1: TLabel
          Left = 104
          Top = 280
          Width = 8
          Height = 16
          Caption = '0'
          Visible = False
        end
        object trackLED0: TTrackBar
          Left = 32
          Top = 40
          Width = 41
          Height = 241
          Max = 70
          Orientation = trVertical
          Frequency = 10
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = trackLED0Change
        end
        object trackLED1: TTrackBar
          Left = 96
          Top = 40
          Width = 41
          Height = 241
          Max = 255
          Orientation = trVertical
          Frequency = 10
          Position = 0
          SelEnd = 0
          SelStart = 0
          TabOrder = 1
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          Visible = False
          OnChange = trackLED1Change
        end
      end
      object GroupBox12: TGroupBox
        Left = 16
        Top = 88
        Width = 257
        Height = 73
        Caption = #22522#26495#27491#21453#38754'CCD '#21443#25976
        TabOrder = 3
        Visible = False
        object Label1: TLabel
          Left = 21
          Top = 32
          Width = 68
          Height = 16
          Caption = 'Min. Score'
        end
        object m_dMarkScore1: TEdit
          Left = 96
          Top = 30
          Width = 81
          Height = 24
          TabOrder = 0
          Text = 'editPickSpacerPosY'
        end
      end
      object GroupBox13: TGroupBox
        Left = 16
        Top = 8
        Width = 257
        Height = 73
        Caption = #23450#20301'CCD '#21443#25976
        TabOrder = 4
        object Label3: TLabel
          Left = 21
          Top = 32
          Width = 68
          Height = 16
          Caption = 'Min. Score'
        end
        object m_dMarkScore2: TEdit
          Left = 96
          Top = 30
          Width = 81
          Height = 24
          TabOrder = 0
          Text = 'editPickSpacerPosY'
        end
      end
    end
  end
end
