object fmShowNow: TfmShowNow
  Left = 619
  Top = 404
  BorderStyle = bsDialog
  Caption = 'fmShowNow'
  ClientHeight = 385
  ClientWidth = 895
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Shape3: TShape
    Left = 104
    Top = 192
    Width = 657
    Height = 25
    Brush.Color = cl3DDkShadow
  end
  object Shape4: TShape
    Left = 104
    Top = 256
    Width = 657
    Height = 25
    Brush.Color = cl3DDkShadow
  end
  object Shape5: TShape
    Left = 40
    Top = 48
    Width = 273
    Height = 25
    Brush.Color = cl3DDkShadow
  end
  object Shape6: TShape
    Left = 584
    Top = 48
    Width = 273
    Height = 25
    Brush.Color = cl3DDkShadow
  end
  object Shape1: TShape
    Left = 216
    Top = 16
    Width = 25
    Height = 361
    Brush.Color = cl3DDkShadow
  end
  object Shape2: TShape
    Left = 624
    Top = 16
    Width = 25
    Height = 353
    Brush.Color = cl3DDkShadow
  end
  object Shape00: TShape
    Left = 48
    Top = 32
    Width = 57
    Height = 57
  end
  object Shape01: TShape
    Left = 208
    Top = 32
    Width = 57
    Height = 57
  end
  object Shape02: TShape
    Left = 200
    Top = 24
    Width = 57
    Height = 57
  end
  object Shape04: TShape
    Left = 208
    Top = 176
    Width = 57
    Height = 57
  end
  object Shape03: TShape
    Left = 200
    Top = 168
    Width = 57
    Height = 57
  end
  object Shape14: TShape
    Left = 208
    Top = 240
    Width = 57
    Height = 57
  end
  object Shape13: TShape
    Left = 200
    Top = 232
    Width = 57
    Height = 57
  end
  object Shape05: TShape
    Left = 280
    Top = 176
    Width = 57
    Height = 57
  end
  object Shape15: TShape
    Left = 280
    Top = 240
    Width = 57
    Height = 57
  end
  object Shape06: TShape
    Left = 344
    Top = 176
    Width = 57
    Height = 57
  end
  object Shape16: TShape
    Left = 344
    Top = 240
    Width = 57
    Height = 57
  end
  object Shape07: TShape
    Left = 416
    Top = 176
    Width = 57
    Height = 57
  end
  object Shape17: TShape
    Left = 416
    Top = 240
    Width = 57
    Height = 57
  end
  object Shape08: TShape
    Left = 616
    Top = 176
    Width = 57
    Height = 57
  end
  object Shape09: TShape
    Left = 608
    Top = 168
    Width = 57
    Height = 57
  end
  object Shape18: TShape
    Left = 616
    Top = 240
    Width = 57
    Height = 57
  end
  object Shape19: TShape
    Left = 608
    Top = 232
    Width = 57
    Height = 57
  end
  object Shape11: TShape
    Left = 616
    Top = 32
    Width = 57
    Height = 57
  end
  object Shape10: TShape
    Left = 608
    Top = 24
    Width = 57
    Height = 57
  end
  object Shape12: TShape
    Left = 792
    Top = 32
    Width = 57
    Height = 57
  end
  object Shape20: TShape
    Left = 208
    Top = 312
    Width = 57
    Height = 57
  end
  object Shape21: TShape
    Left = 200
    Top = 304
    Width = 57
    Height = 57
  end
  object Shape22: TShape
    Left = 616
    Top = 304
    Width = 57
    Height = 57
  end
  object Shape24: TShape
    Left = 616
    Top = 104
    Width = 57
    Height = 57
  end
  object Shape23: TShape
    Left = 608
    Top = 96
    Width = 57
    Height = 57
  end
  object Image1: TImage
    Left = 24
    Top = 16
    Width = 169
    Height = 89
    Hint = #25353#19968#19979' '#37325#32622#20837#26009#27969#36947#20043#31995#32113#27493#39519
    ParentShowHint = False
    ShowHint = True
    Transparent = True
    OnClick = Image1Click
  end
  object Image5: TImage
    Tag = 4
    Left = 680
    Top = 16
    Width = 193
    Height = 97
    Hint = #25353#19968#19979' '#37325#32622#20986#26009#27969#36947#20043#31995#32113#27493#39519
    ParentShowHint = False
    ShowHint = True
    OnClick = Image1Click
  end
  object Image3: TImage
    Tag = 2
    Left = 72
    Top = 168
    Width = 721
    Height = 137
    Hint = #25353#19968#19979' '#37325#32622#38617#36556#24179#21488#20043#31995#32113#27493#39519
    ParentShowHint = False
    ShowHint = True
    OnClick = Image1Click
  end
  object Image2: TImage
    Tag = 1
    Left = 168
    Top = 8
    Width = 121
    Height = 369
    Hint = #25353#19968#19979' '#37325#32622#20837#26009#21560#30436#20043#31995#32113#27493#39519
    ParentShowHint = False
    ShowHint = True
    OnClick = Image1Click
  end
  object Image4: TImage
    Tag = 3
    Left = 568
    Top = 8
    Width = 129
    Height = 369
    Hint = #25353#19968#19979' '#37325#32622#20986#26009#21560#30436#20043#31995#32113#27493#39519
    ParentShowHint = False
    ShowHint = True
    OnClick = Image1Click
  end
  object timerShow: TTimer
    Interval = 50
    OnTimer = timerShowTimer
    Left = 32
    Top = 280
  end
end
