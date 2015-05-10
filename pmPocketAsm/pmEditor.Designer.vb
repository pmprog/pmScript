<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Public Class pmEditor
  Inherits System.Windows.Forms.Form

  'Form overrides dispose to clean up the component list.
  <System.Diagnostics.DebuggerNonUserCode()> _
  Protected Overrides Sub Dispose(ByVal disposing As Boolean)
    If disposing AndAlso components IsNot Nothing Then
      components.Dispose()
    End If
    MyBase.Dispose(disposing)
  End Sub

  'Required by the Windows Form Designer
  Private components As System.ComponentModel.IContainer
  Private mainMenu1 As System.Windows.Forms.MainMenu

  'NOTE: The following procedure is required by the Windows Form Designer
  'It can be modified using the Windows Form Designer.  
  'Do not modify it using the code editor.
  <System.Diagnostics.DebuggerStepThrough()> _
  Private Sub InitializeComponent()
    Me.mainMenu1 = New System.Windows.Forms.MainMenu
    Me.MenuItem1 = New System.Windows.Forms.MenuItem
    Me.MenuItem7 = New System.Windows.Forms.MenuItem
    Me.MenuItem2 = New System.Windows.Forms.MenuItem
    Me.MenuItem3 = New System.Windows.Forms.MenuItem
    Me.MenuItem4 = New System.Windows.Forms.MenuItem
    Me.MenuItem5 = New System.Windows.Forms.MenuItem
    Me.MenuItem6 = New System.Windows.Forms.MenuItem
    Me.ofd = New System.Windows.Forms.OpenFileDialog
    Me.sfd = New System.Windows.Forms.SaveFileDialog
    Me.tCode = New System.Windows.Forms.TextBox
    Me.panelFeedback = New System.Windows.Forms.Panel
    Me.Splitter1 = New System.Windows.Forms.Splitter
    Me.Label1 = New System.Windows.Forms.Label
    Me.tEvents = New System.Windows.Forms.TextBox
    Me.bHideFB = New System.Windows.Forms.Button
    Me.panelFeedback.SuspendLayout()
    Me.SuspendLayout()
    '
    'mainMenu1
    '
    Me.mainMenu1.MenuItems.Add(Me.MenuItem1)
    Me.mainMenu1.MenuItems.Add(Me.MenuItem5)
    '
    'MenuItem1
    '
    Me.MenuItem1.MenuItems.Add(Me.MenuItem7)
    Me.MenuItem1.MenuItems.Add(Me.MenuItem2)
    Me.MenuItem1.MenuItems.Add(Me.MenuItem3)
    Me.MenuItem1.MenuItems.Add(Me.MenuItem4)
    Me.MenuItem1.Text = "&File"
    '
    'MenuItem7
    '
    Me.MenuItem7.Text = "&New"
    '
    'MenuItem2
    '
    Me.MenuItem2.Text = "&Open"
    '
    'MenuItem3
    '
    Me.MenuItem3.Text = "&Save"
    '
    'MenuItem4
    '
    Me.MenuItem4.Text = "E&xit"
    '
    'MenuItem5
    '
    Me.MenuItem5.MenuItems.Add(Me.MenuItem6)
    Me.MenuItem5.Text = "&Compile"
    '
    'MenuItem6
    '
    Me.MenuItem6.Text = "Portable Binary"
    '
    'ofd
    '
    Me.ofd.Filter = "pmScript|*.psc;*.asm;*.inc|All Files|*.*"
    '
    'tCode
    '
    Me.tCode.AcceptsReturn = True
    Me.tCode.AcceptsTab = True
    Me.tCode.Dock = System.Windows.Forms.DockStyle.Fill
    Me.tCode.Location = New System.Drawing.Point(0, 0)
    Me.tCode.Multiline = True
    Me.tCode.Name = "tCode"
    Me.tCode.ScrollBars = System.Windows.Forms.ScrollBars.Both
    Me.tCode.Size = New System.Drawing.Size(240, 180)
    Me.tCode.TabIndex = 0
    Me.tCode.WordWrap = False
    '
    'panelFeedback
    '
    Me.panelFeedback.Controls.Add(Me.bHideFB)
    Me.panelFeedback.Controls.Add(Me.tEvents)
    Me.panelFeedback.Controls.Add(Me.Label1)
    Me.panelFeedback.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.panelFeedback.Location = New System.Drawing.Point(0, 184)
    Me.panelFeedback.Name = "panelFeedback"
    Me.panelFeedback.Size = New System.Drawing.Size(240, 84)
    '
    'Splitter1
    '
    Me.Splitter1.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.Splitter1.Location = New System.Drawing.Point(0, 180)
    Me.Splitter1.Name = "Splitter1"
    Me.Splitter1.Size = New System.Drawing.Size(240, 4)
    '
    'Label1
    '
    Me.Label1.BackColor = System.Drawing.SystemColors.ActiveCaption
    Me.Label1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText
    Me.Label1.Location = New System.Drawing.Point(4, 4)
    Me.Label1.Name = "Label1"
    Me.Label1.Size = New System.Drawing.Size(232, 16)
    Me.Label1.Text = "Compiler Feedback"
    '
    'tEvents
    '
    Me.tEvents.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.tEvents.Location = New System.Drawing.Point(4, 24)
    Me.tEvents.Multiline = True
    Me.tEvents.Name = "tEvents"
    Me.tEvents.ReadOnly = True
    Me.tEvents.Size = New System.Drawing.Size(232, 56)
    Me.tEvents.TabIndex = 1
    '
    'bHideFB
    '
    Me.bHideFB.Font = New System.Drawing.Font("Tahoma", 8.0!, System.Drawing.FontStyle.Regular)
    Me.bHideFB.Location = New System.Drawing.Point(216, 4)
    Me.bHideFB.Name = "bHideFB"
    Me.bHideFB.Size = New System.Drawing.Size(16, 16)
    Me.bHideFB.TabIndex = 2
    Me.bHideFB.Text = "_"
    '
    'pmEditor
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(96.0!, 96.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi
    Me.AutoScroll = True
    Me.ClientSize = New System.Drawing.Size(240, 268)
    Me.Controls.Add(Me.tCode)
    Me.Controls.Add(Me.Splitter1)
    Me.Controls.Add(Me.panelFeedback)
    Me.Menu = Me.mainMenu1
    Me.Name = "pmEditor"
    Me.Text = "pmScript Editor/Assembler"
    Me.panelFeedback.ResumeLayout(False)
    Me.ResumeLayout(False)

  End Sub
  Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
  Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
  Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
  Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
  Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
  Friend WithEvents MenuItem6 As System.Windows.Forms.MenuItem
  Friend WithEvents ofd As System.Windows.Forms.OpenFileDialog
  Friend WithEvents sfd As System.Windows.Forms.SaveFileDialog
  Friend WithEvents MenuItem7 As System.Windows.Forms.MenuItem
  Friend WithEvents tCode As System.Windows.Forms.TextBox
  Friend WithEvents panelFeedback As System.Windows.Forms.Panel
  Friend WithEvents bHideFB As System.Windows.Forms.Button
  Friend WithEvents tEvents As System.Windows.Forms.TextBox
  Friend WithEvents Label1 As System.Windows.Forms.Label
  Friend WithEvents Splitter1 As System.Windows.Forms.Splitter

End Class
