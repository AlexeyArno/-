object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1080
  ClientHeight = 537
  ClientWidth = 927
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 187
    Top = 72
    Width = 44
    Height = 13
    Caption = #1042#1099#1073#1086#1088#1086#1084
  end
  object Label2: TLabel
    Left = 297
    Top = 72
    Width = 56
    Height = 13
    Caption = #1055#1091#1079#1099#1088#1100#1082#1086#1084
  end
  object Label3: TLabel
    Left = 401
    Top = 72
    Width = 53
    Height = 13
    Caption = #1042#1089#1090#1072#1074#1082#1072#1084#1080
  end
  object Label4: TLabel
    Left = 505
    Top = 72
    Width = 34
    Height = 13
    Caption = #1064#1077#1083#1083#1072
  end
  object Label5: TLabel
    Left = 609
    Top = 72
    Width = 80
    Height = 13
    Caption = #1055#1080#1088#1072#1084#1080#1076#1072#1083#1100#1085#1072#1103
  end
  object Label6: TLabel
    Left = 729
    Top = 72
    Width = 43
    Height = 13
    Caption = #1041#1099#1089#1090#1088#1072#1103
  end
  object Label7: TLabel
    Left = 833
    Top = 72
    Width = 67
    Height = 13
    Caption = #1055#1086#1088#1072#1079#1088#1103#1076#1085#1072#1103
  end
  object Label8: TLabel
    Left = 27
    Top = 72
    Width = 88
    Height = 13
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1084#1072#1089#1089#1080#1074
  end
  object Label9: TLabel
    Left = 184
    Top = 384
    Width = 47
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label10: TLabel
    Left = 297
    Top = 384
    Width = 56
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label11: TLabel
    Left = 401
    Top = 384
    Width = 49
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label12: TLabel
    Left = 508
    Top = 384
    Width = 46
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label13: TLabel
    Left = 609
    Top = 384
    Width = 49
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label14: TLabel
    Left = 729
    Top = 384
    Width = 56
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Label15: TLabel
    Left = 832
    Top = 384
    Width = 50
    Height = 13
    Alignment = taCenter
    AutoSize = False
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 113
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 688
    Top = 8
    Width = 111
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100' '#1089#1086#1088#1090#1080#1088#1086#1074#1082#1091
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 832
    Top = 8
    Width = 75
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 2
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    Left = 184
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 3
  end
  object ListBox2: TListBox
    Left = 297
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 4
  end
  object ListBox3: TListBox
    Left = 401
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 5
  end
  object ListBox4: TListBox
    Left = 505
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 6
  end
  object ListBox5: TListBox
    Left = 609
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 7
  end
  object ListBox6: TListBox
    Left = 729
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 8
  end
  object ListBox7: TListBox
    Left = 833
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 9
  end
  object ListBox8: TListBox
    Left = 24
    Top = 103
    Width = 49
    Height = 265
    ItemHeight = 13
    TabOrder = 10
  end
  object ComboBox1: TComboBox
    Left = 160
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 11
    Text = '10'
    Items.Strings = (
      '10'
      '100'
      '1000'
      '10000'
      '30000'
      '50000'
      '100000')
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 192
    Top = 424
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer2Timer
    Left = 312
    Top = 432
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer3Timer
    Left = 416
    Top = 432
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer4Timer
    Left = 520
    Top = 432
  end
  object Timer5: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer5Timer
    Left = 624
    Top = 432
  end
  object Timer6: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer6Timer
    Left = 744
    Top = 424
  end
  object Timer7: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer7Timer
    Left = 840
    Top = 432
  end
end
