<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
    Me.MenuStrip1 = New System.Windows.Forms.MenuStrip
    Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.LoadBinaryToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.MachineToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.RunToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.StepToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.RestarToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
    Me.MenuStrip1.SuspendLayout()
    Me.SuspendLayout()
    '
    'MenuStrip1
    '
    Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem, Me.MachineToolStripMenuItem})
    Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
    Me.MenuStrip1.Name = "MenuStrip1"
    Me.MenuStrip1.Size = New System.Drawing.Size(560, 24)
    Me.MenuStrip1.TabIndex = 0
    Me.MenuStrip1.Text = "MenuStrip1"
    '
    'FileToolStripMenuItem
    '
    Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.LoadBinaryToolStripMenuItem, Me.ExitToolStripMenuItem})
    Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
    Me.FileToolStripMenuItem.Size = New System.Drawing.Size(35, 20)
    Me.FileToolStripMenuItem.Text = "&File"
    '
    'LoadBinaryToolStripMenuItem
    '
    Me.LoadBinaryToolStripMenuItem.Name = "LoadBinaryToolStripMenuItem"
    Me.LoadBinaryToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
    Me.LoadBinaryToolStripMenuItem.Text = "&Load Binary"
    '
    'ExitToolStripMenuItem
    '
    Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
    Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
    Me.ExitToolStripMenuItem.Text = "E&xit"
    '
    'MachineToolStripMenuItem
    '
    Me.MachineToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.RunToolStripMenuItem, Me.StepToolStripMenuItem, Me.RestarToolStripMenuItem})
    Me.MachineToolStripMenuItem.Name = "MachineToolStripMenuItem"
    Me.MachineToolStripMenuItem.Size = New System.Drawing.Size(58, 20)
    Me.MachineToolStripMenuItem.Text = "&Machine"
    '
    'RunToolStripMenuItem
    '
    Me.RunToolStripMenuItem.Name = "RunToolStripMenuItem"
    Me.RunToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
    Me.RunToolStripMenuItem.Text = "&Run"
    '
    'StepToolStripMenuItem
    '
    Me.StepToolStripMenuItem.Name = "StepToolStripMenuItem"
    Me.StepToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
    Me.StepToolStripMenuItem.Text = "&Step"
    '
    'RestarToolStripMenuItem
    '
    Me.RestarToolStripMenuItem.Name = "RestarToolStripMenuItem"
    Me.RestarToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
    Me.RestarToolStripMenuItem.Text = "Res&tart"
    '
    'Form1
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.ClientSize = New System.Drawing.Size(560, 434)
    Me.Controls.Add(Me.MenuStrip1)
    Me.MainMenuStrip = Me.MenuStrip1
    Me.Name = "Form1"
    Me.Text = "pmScript Debugger"
    Me.MenuStrip1.ResumeLayout(False)
    Me.MenuStrip1.PerformLayout()
    Me.ResumeLayout(False)
    Me.PerformLayout()

  End Sub
  Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip
  Friend WithEvents FileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents LoadBinaryToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents MachineToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents RunToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents StepToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
  Friend WithEvents RestarToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem

End Class
