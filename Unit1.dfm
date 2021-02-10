object Form1: TForm1
  Left = 192
  Top = 118
  Width = 730
  Height = 385
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Image1: TImage
    Left = 152
    Top = 64
    Width = 105
    Height = 105
    Visible = False
  end
  object Image2: TImage
    Left = 272
    Top = 64
    Width = 105
    Height = 105
    Visible = False
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 160
    Top = 208
  end
end
