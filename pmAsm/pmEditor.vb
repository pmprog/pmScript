Public Class pmEditor

  Dim WithEvents pmAssembler As pmCompiler

  Private Sub NewToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NewToolStripMenuItem.Click
    rtfCode.Text = ""
    ofd.FileName = ""
  End Sub

  Private Sub SaveToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveToolStripMenuItem.Click
    If ofd.FileName = "" Then
      sfd.Filter = "pmScript Source|*.psc;*.asm|pmScript Include|*.inc"
      sfd.FileName = ofd.FileName
      If sfd.ShowDialog = Windows.Forms.DialogResult.OK Then
        rtfCode.SaveFile(sfd.FileName, RichTextBoxStreamType.PlainText)
        ofd.FileName = sfd.FileName
      End If
    Else
      rtfCode.SaveFile(ofd.FileName, RichTextBoxStreamType.PlainText)
    End If
  End Sub

  Private Sub OpenToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OpenToolStripMenuItem.Click
    If ofd.ShowDialog = Windows.Forms.DialogResult.OK Then
      rtfCode.LoadFile(ofd.FileName, RichTextBoxStreamType.PlainText)
    End If
  End Sub

  Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
    Application.Exit()
  End Sub

  Private Sub PortableBinaryToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PortableBinaryToolStripMenuItem.Click
    ' Force save first
    If ofd.FileName = "" Then SaveToolStripMenuItem.PerformClick()

    sfd.Filter = "pmScript Portable Binary|*.bin"
    If sfd.ShowDialog = Windows.Forms.DialogResult.OK Then
      pCompile.Visible = True
      pCompile.Height = Me.Height / 3
      tEvents.Text = ""
      pmAssembler = New pmCompiler
      pmAssembler.LoadScript(ofd.FileName)
      pmAssembler.Compile()
      pmAssembler.SaveBinary(sfd.FileName, True)
    End If
  End Sub

  Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
    pCompile.Visible = False
  End Sub

  Private Sub pmAssembler_Feedback(ByVal comment As String) Handles pmAssembler.Feedback
    tEvents.Text &= comment & vbCrLf
  End Sub

  Private Sub pmAssembler_UIAllowRefresh() Handles pmAssembler.UIAllowRefresh
    Application.DoEvents()
  End Sub
End Class
