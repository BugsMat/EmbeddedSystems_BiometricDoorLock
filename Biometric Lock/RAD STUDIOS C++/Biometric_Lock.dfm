object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 523
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object lblStdNo: TLabel
    Left = 40
    Top = 64
    Width = 88
    Height = 15
    Caption = 'Student Number'
  end
  object lblStdDetails: TLabel
    Left = 40
    Top = 112
    Width = 87
    Height = 15
    Caption = 'Surname & Initials'
  end
  object lblFingerID: TLabel
    Left = 232
    Top = 156
    Width = 54
    Height = 15
    Caption = 'xxxxxxxxx'
  end
  object lblIn: TLabel
    Left = 152
    Top = 219
    Width = 61
    Height = 15
    Caption = 'Students IN'
  end
  object lblOut: TLabel
    Left = 472
    Top = 219
    Width = 72
    Height = 15
    Caption = 'Students OUT'
  end
  object lblAll: TLabel
    Left = 472
    Top = 40
    Width = 115
    Height = 15
    Caption = 'ENROLLED STUDENTS'
  end
  object lblScanned: TLabel
    Left = 376
    Top = 16
    Width = 60
    Height = 15
    Caption = 'LAST SCAN'
  end
  object lblDelete: TLabel
    Left = 726
    Top = 40
    Width = 26
    Height = 15
    Caption = 'KEEP'
  end
  object btnEnroll: TButton
    Left = 40
    Top = 152
    Width = 75
    Height = 25
    Caption = 'ENROLL'
    TabOrder = 0
    OnClick = btnEnrollClick
  end
  object edtStdNum: TEdit
    Left = 192
    Top = 61
    Width = 161
    Height = 23
    NumbersOnly = True
    TabOrder = 1
  end
  object edtStdDetails: TEdit
    Left = 192
    Top = 109
    Width = 161
    Height = 23
    TabOrder = 2
  end
  object lstAll: TListBox
    Left = 441
    Top = 61
    Width = 337
    Height = 140
    ItemHeight = 15
    TabOrder = 3
    TabWidth = 40
  end
  object lstOUT: TListBox
    Left = 441
    Top = 240
    Width = 337
    Height = 257
    ItemHeight = 15
    TabOrder = 4
    TabWidth = 40
  end
  object lstIN: TListBox
    Left = 8
    Top = 240
    Width = 345
    Height = 257
    ItemHeight = 15
    TabOrder = 5
    TabWidth = 40
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 384
    Top = 240
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 384
    Top = 304
  end
  object Timer3: TTimer
    Interval = 300
    Left = 384
    Top = 376
  end
end
