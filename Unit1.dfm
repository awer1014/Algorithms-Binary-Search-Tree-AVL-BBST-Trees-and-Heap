object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Binary Search Tree Made by W.R_Chen'
  ClientHeight = 607
  ClientWidth = 772
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 0
    Height = 607
    ExplicitLeft = 96
    ExplicitTop = 240
    ExplicitHeight = 100
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 105
    Height = 105
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 3
    Width = 201
    Height = 596
    ActivePage = TabSheet2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'BST'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 201
        Height = 568
        Align = alLeft
        TabOrder = 0
        object Label1: TLabel
          Left = 24
          Top = 16
          Width = 54
          Height = 13
          Caption = 'Target Add'
        end
        object Label2: TLabel
          Left = 24
          Top = 101
          Width = 68
          Height = 13
          Caption = 'Target Search'
        end
        object Label3: TLabel
          Left = 18
          Top = 178
          Width = 38
          Height = 13
          Caption = 'Element'
        end
        object Label4: TLabel
          Left = 18
          Top = 231
          Width = 31
          Height = 13
          Caption = 'Range'
        end
        object Label5: TLabel
          Left = 18
          Top = 359
          Width = 66
          Height = 13
          Caption = 'Target Delete'
        end
        object Edit1: TEdit
          Left = 76
          Top = 35
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Edit2: TEdit
          Left = 76
          Top = 120
          Width = 121
          Height = 21
          TabOrder = 1
          Text = '10'
        end
        object Button1: TButton
          Left = 18
          Top = 62
          Width = 75
          Height = 25
          Caption = 'Recursive'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 116
          Top = 62
          Width = 81
          Height = 25
          Caption = 'Non-Recursive'
          TabOrder = 3
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 18
          Top = 147
          Width = 75
          Height = 25
          Caption = 'Recursive'
          TabOrder = 4
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 116
          Top = 147
          Width = 81
          Height = 25
          Caption = 'Non-Recursive'
          TabOrder = 5
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 17
          Top = 328
          Width = 75
          Height = 25
          Caption = 'Random'
          TabOrder = 6
          OnClick = Button5Click
        end
        object Edit3: TEdit
          Left = 76
          Top = 197
          Width = 121
          Height = 21
          TabOrder = 7
          Text = '10'
        end
        object Edit4: TEdit
          Left = 76
          Top = 250
          Width = 121
          Height = 21
          TabOrder = 8
          Text = '0'
        end
        object Edit5: TEdit
          Left = 76
          Top = 277
          Width = 121
          Height = 21
          TabOrder = 9
          Text = '0'
        end
        object Button9: TButton
          Left = 116
          Top = 328
          Width = 81
          Height = 25
          Caption = 'Clear'
          TabOrder = 10
          OnClick = Button9Click
        end
        object TrackBar1: TTrackBar
          Left = 5
          Top = 197
          Width = 62
          Height = 33
          Max = 100
          TabOrder = 11
          OnChange = TrackBar1Change
        end
        object TrackBar2: TTrackBar
          Left = 5
          Top = 250
          Width = 62
          Height = 33
          Max = 100
          TabOrder = 12
          OnChange = TrackBar2Change
        end
        object TrackBar3: TTrackBar
          Left = 5
          Top = 277
          Width = 62
          Height = 45
          Max = 100
          TabOrder = 13
          OnChange = TrackBar3Change
        end
        object GroupBox1: TGroupBox
          Left = 6
          Top = 445
          Width = 97
          Height = 116
          Caption = 'Recursive'
          TabOrder = 14
          object Button6: TButton
            Left = 3
            Top = 49
            Width = 81
            Height = 25
            Caption = 'InOrder'
            TabOrder = 0
            OnClick = Button6Click
          end
          object Button8: TButton
            Left = 3
            Top = 18
            Width = 81
            Height = 25
            Caption = 'PreOrder'
            TabOrder = 1
            OnClick = Button8Click
          end
          object Button7: TButton
            Left = 3
            Top = 80
            Width = 81
            Height = 25
            Caption = 'PostOrder'
            TabOrder = 2
            OnClick = Button7Click
          end
        end
        object GroupBox2: TGroupBox
          Left = 96
          Top = 445
          Width = 89
          Height = 116
          Caption = 'Non-Recursive'
          TabOrder = 15
          object Button11: TButton
            Left = 3
            Top = 48
            Width = 75
            Height = 25
            Caption = 'InOrder'
            TabOrder = 0
            OnClick = Button11Click
          end
          object Button12: TButton
            Left = 3
            Top = 79
            Width = 75
            Height = 25
            Caption = 'PostOrder'
            TabOrder = 1
            OnClick = Button12Click
          end
          object Button15: TButton
            Left = 3
            Top = 17
            Width = 75
            Height = 25
            Caption = 'PreOrder'
            TabOrder = 2
            OnClick = Button15Click
          end
        end
        object RadioButton1: TRadioButton
          Left = 84
          Top = 0
          Width = 113
          Height = 17
          Caption = 'Draw Binary Tree'
          TabOrder = 16
        end
        object Edit6: TEdit
          Left = 76
          Top = 378
          Width = 121
          Height = 21
          TabOrder = 17
          Text = '0'
        end
        object Button13: TButton
          Left = 18
          Top = 405
          Width = 75
          Height = 25
          Caption = 'Recursive'
          TabOrder = 18
          OnClick = Button13Click
        end
        object Button14: TButton
          Left = 116
          Top = 414
          Width = 81
          Height = 25
          Caption = 'Non-Recursive'
          TabOrder = 19
          OnClick = Button14Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Find BST'
      ImageIndex = 1
      object Label6: TLabel
        Left = 16
        Top = 16
        Width = 26
        Height = 13
        Caption = 'Infix:'
      end
      object Label7: TLabel
        Left = 16
        Top = 69
        Width = 32
        Height = 13
        Caption = 'Prefix:'
      end
      object Label8: TLabel
        Left = 16
        Top = 128
        Width = 37
        Height = 13
        Caption = 'Postfix:'
      end
      object Edit7: TEdit
        Left = 48
        Top = 35
        Width = 121
        Height = 21
        TabOrder = 0
        Text = 'HBJAFDGCE'
      end
      object Edit8: TEdit
        Left = 48
        Top = 88
        Width = 121
        Height = 21
        TabOrder = 1
        Text = 'ABHJCDFGE'
      end
      object Button19: TButton
        Left = 19
        Top = 497
        Width = 147
        Height = 25
        Caption = 'Clear'
        TabOrder = 2
        OnClick = Button19Click
      end
      object GroupBox3: TGroupBox
        Left = 16
        Top = 224
        Width = 153
        Height = 81
        Caption = 'Infix + Prefix'
        TabOrder = 3
        object Button10: TButton
          Left = 3
          Top = 14
          Width = 147
          Height = 25
          Caption = 'Infix + Pretfix'
          TabOrder = 0
          OnClick = Button10Click
        end
        object Button17: TButton
          Left = 3
          Top = 45
          Width = 147
          Height = 25
          Caption = 'LevleOrder'
          TabOrder = 1
          OnClick = Button17Click
        end
      end
      object Edit9: TEdit
        Left = 48
        Top = 147
        Width = 121
        Height = 21
        TabOrder = 4
        Text = 'HJBFGDECA'
      end
      object GroupBox4: TGroupBox
        Left = 16
        Top = 311
        Width = 153
        Height = 82
        Caption = 'Infix + Postfix'
        TabOrder = 5
        object Button16: TButton
          Left = 3
          Top = 16
          Width = 147
          Height = 25
          Caption = 'Infix + Postfix'
          TabOrder = 0
          OnClick = Button16Click
        end
        object Button20: TButton
          Left = 3
          Top = 47
          Width = 147
          Height = 25
          Caption = 'LevleOrder'
          TabOrder = 1
          OnClick = Button20Click
        end
      end
      object CheckBox1: TCheckBox
        Left = 16
        Top = 190
        Width = 113
        Height = 17
        Caption = 'Show BST to Char'
        TabOrder = 6
      end
    end
  end
  object PageControl2: TPageControl
    Left = 207
    Top = 0
    Width = 562
    Height = 607
    ActivePage = TabSheet3
    TabOrder = 1
    object TabSheet3: TTabSheet
      Caption = 'Inorder Sequence of BST'
      object Memo1: TMemo
        Left = -4
        Top = 0
        Width = 570
        Height = 553
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Draw BST Tree'
      ImageIndex = 1
    end
  end
end
