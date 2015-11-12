object frmBusy: TfrmBusy
  Left = 0
  Top = 265
  BorderStyle = bsNone
  BorderWidth = 1
  Caption = 'System Busy'
  ClientHeight = 85
  ClientWidth = 310
  Color = 13430215
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 20
  object textMessage: TStaticText
    Left = 0
    Top = 25
    Width = 310
    Height = 29
    Align = alClient
    BevelKind = bkFlat
    Caption = #31995#32113#24537#37636#20013'.................'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -16
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object panelExit: TPanel
    Left = 0
    Top = 54
    Width = 310
    Height = 31
    Align = alBottom
    Caption = '[Close]'
    Color = clRed
    TabOrder = 1
    OnClick = panelExitClick
  end
  object panelTime: TPanel
    Left = 0
    Top = 0
    Width = 310
    Height = 25
    Align = alTop
    Alignment = taRightJustify
    Caption = 'Time'
    Color = 4227072
    TabOrder = 2
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 296
    Top = 16
  end
  object Timer2: TTimer
    Interval = 30
    OnTimer = Timer2Timer
    Left = 240
    Top = 16
  end
end
