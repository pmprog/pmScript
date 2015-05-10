<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class pmEditor
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

  'NOTE: The following procedure is required by the Windows Form Designer
  'It can be modified using the Windows Form Designer.  
  'Do not modify it using the code editor.
  <System.Diagnostics.DebuggerStepThrough()> _
  Private Sub InitializeComponent()
    Me.rtfCode = New System.Windows.Forms.RichTextBox
    Me.MenuStrip1 = New System.Windows.Forms.MenuStrip
    Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.NewToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.OpenToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.SaveToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.ToolStripMenuItem1 = New System.Windows.Forms.ToolStripSeparator
    Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.CompileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.PortableBinaryToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.ofd = New System.Windows.Forms.OpenFileDialog
    Me.sfd = New System.Windows.Forms.SaveFileDialog
    Me.pCompile = New System.Windows.Forms.Panel
    Me.tEvents = New System.Windows.Forms.TextBox
    Me.Button1 = New System.Windows.Forms.Button
    Me.MenuStrip1.SuspendLayout()
    Me.pCompile.SuspendLayout()
    Me.SuspendLayout()
    '
    'rtfCode
    '
    Me.rtfCode.AcceptsTab = True
    Me.rtfCode.Dock = System.Windows.Forms.DockStyle.Fill
    Me.rtfCode.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
    Me.rtfCode.Location = New System.Drawing.Point(0, 24)
    Me.rtfCode.Name = "rtfCode"
    Me.rtfCode.Size = New System.Drawing.Size(292, 169)
    Me.rtfCode.TabIndex = 0
    Me.rtfCode.Text = ""
    '
    'MenuStrip1
    '
    Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem, Me.CompileToolStripMenuItem})
    Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
    Me.MenuStrip1.Name = "MenuStrip1"
    Me.MenuStrip1.Size = New System.Drawing.Size(292, 24)
    Me.MenuStrip1.TabIndex = 1
    Me.MenuStrip1.Text = "MenuStrip1"
    '
    'FileToolStripMenuItem
    '
    Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.NewToolStripMenuItem, Me.OpenToolStripMenuItem, Me.SaveToolStripMenuItem, Me.ToolStripMenuItem1, Me.ExitToolStripMenuItem})
    Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
    Me.FileToolStripMenuItem.Size = New System.Drawing.Size(35, 20)
    Me.FileToolStripMenuItem.Text = "&File"
    '
    'NewToolStripMenuItem
    '
    Me.NewToolStripMenuItem.Name = "NewToolStripMenuItem"
    Me.NewToolStripMenuItem.Size = New System.Drawing.Size(103, 22)
    Me.NewToolStripMenuItem.Text = "&New"
    '
    'OpenToolStripMenuItem
    '
    Me.OpenToolStripMenuItem.Name = "OpenToolStripMenuItem"
    Me.OpenToolStripMenuItem.Size = New System.Drawing.Size(103, 22)
    Me.OpenToolStripMenuItem.Text = "&Open"
    '
    'SaveToolStripMenuItem
    '
    Me.SaveToolStripMenuItem.Name = "SaveToolStripMenuItem"
    Me.SaveToolStripMenuItem.Size = New System.Drawing.Size(103, 22)
    Me.SaveToolStripMenuItem.Text = "&Save"
    '
    'ToolStripMenuItem1
    '
    Me.ToolStripMenuItem1.Name = "ToolStripMenuItem1"
    Me.ToolStripMenuItem1.Size = New System.Drawing.Size(100, 6)
    '
    'ExitToolStripMenuItem
    '
    Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
    Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(103, 22)
    Me.ExitToolStripMenuItem.Text = "E&xit"
    '
    'CompileToolStripMenuItem
    '
    Me.CompileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.PortableBinaryToolStripMenuItem})
    Me.CompileToolStripMenuItem.Name = "CompileToolStripMenuItem"
    Me.CompileToolStripMenuItem.Size = New System.Drawing.Size(56, 20)
    Me.CompileToolStripMenuItem.Text = "&Compile"
    '
    'PortableBinaryToolStripMenuItem
    '
    Me.PortableBinaryToolStripMenuItem.Name = "PortableBinaryToolStripMenuItem"
    Me.PortableBinaryToolStripMenuItem.Size = New System.Drawing.Size(148, 22)
    Me.PortableBinaryToolStripMenuItem.Text = "Portable Binary"
    '
    'ofd
    '
    Me.ofd.Filter = "pmScript|*.psc;*.asm;*.inc|All Files|*.*"
    '
    'pCompile
    '
    Me.pCompile.Controls.Add(Me.tEvents)
    Me.pCompile.Controls.Add(Me.Button1)
    Me.pCompile.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.pCompile.Location = New System.Drawing.Point(0, 193)
    Me.pCompile.Name = "pCompile"
    Me.pCompile.Size = New System.Drawing.Size(292, 80)
    Me.pCompile.TabIndex = 2
    Me.pCompile.Visible = False
    '
    'tEvents
    '
    Me.tEvents.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                Or System.Windows.Forms.AnchorStyles.Left) _
                Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.tEvents.Location = New System.Drawing.Point(0, 12)
    Me.tEvents.Multiline = True
    Me.tEvents.Name = "tEvents"
    Me.tEvents.Size = New System.Drawing.Size(292, 68)
    Me.tEvents.TabIndex = 1
    '
    'Button1
    '
    Me.Button1.Anchor = CType((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
    Me.Button1.Location = New System.Drawing.Point(280, 0)
    Me.Button1.Name = "Button1"
    Me.Button1.Size = New System.Drawing.Size(12, 12)
    Me.Button1.TabIndex = 0
    Me.Button1.UseVisualStyleBackColor = True
    '
    'pmEditor
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.ClientSize = New System.Drawing.Size(292, 273)
    Me.Controls.Add(Me.rtfCode)
    Me.Controls.Add(Me.pCompile)
    Me.Controls.Add(Me.MenuStrip1)
    Me.MainMenuStrip = Me.MenuStrip1
    Me.Name = "pmEditor"
    Me.Text = "pmScript Editor/Assembler"
    Me.MenuStrip1.ResumeLayout(False)
    Me.MenuStrip1.PerformLayout()
    Me.pCompile.ResumeLayout(False)
    Me.pCompile.PerformLayout()
    Me.ResumeLayout(False)
    Me.PerformLayout()

  End Sub
  Friend WithEvents rtfCode As System.Windows.Forms.RichTextBox
  Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip
  Friend WithEvents FileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents NewToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents OpenToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents SaveToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ToolStripMenuItem1 As System.Windows.Forms.ToolStripSeparator
  Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents CompileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents PortableBinaryToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ofd As System.Windows.Forms.OpenFileDialog
  Friend WithEvents sfd As System.Windows.Forms.SaveFileDialog
  Friend WithEvents pCompile As System.Windows.Forms.Panel
  Friend WithEvents Button1 As System.Windows.Forms.Button
  Friend WithEvents tEvents As System.Windows.Forms.TextBox

End Class
