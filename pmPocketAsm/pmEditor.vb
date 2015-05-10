Public Class pmEditor

  Dim WithEvents pmAssembler As pmCompiler

  Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem7.Click
    tCode.Text = ""
    ofd.FileName = ""
  End Sub

  Private Sub MenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem2.Click
    Dim sFile As IO.FileStream
    Dim bContents() As Byte

    If ofd.ShowDialog = Windows.Forms.DialogResult.OK Then
      sFile = IO.File.Open(ofd.FileName, IO.FileMode.Open)
      ReDim bContents(sFile.Length - 1)
      sFile.Read(bContents, 0, sFile.Length)
      tCode.Text = System.Text.ASCIIEncoding.ASCII.GetString(bContents, 0, bContents.Length)
      sFile.Close()
    End If
  End Sub

  Private Sub MenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem4.Click
    Application.Exit()
  End Sub

  Private Sub MenuItem6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem6.Click
    ' Force save first
    If ofd.FileName = "" Then MenuItem3_Click(Nothing, Nothing)

    sfd.Filter = "pmScript Portable Binary|*.bin"
    If sfd.ShowDialog = Windows.Forms.DialogResult.OK Then
      panelFeedback.Height = Me.Height / 2
      tEvents.Text = ""
      pmAssembler = New pmCompiler
      pmAssembler.LoadScript(ofd.FileName)
      pmAssembler.Compile()
      pmAssembler.SaveBinary(sfd.FileName, True)
    End If
  End Sub

  Private Sub MenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem3.Click
    Dim sFile As IO.FileStream
    Dim bDocument() As Byte

    If ofd.FileName = "" Then
      sfd.Filter = "pmScript|*.psc;*.asm;*.inc|All Files|*.*"
      If sfd.ShowDialog <> Windows.Forms.DialogResult.OK Then Exit Sub
      sFile = IO.File.Open(sfd.FileName, IO.FileMode.Create)
    Else
      sFile = IO.File.Open(ofd.FileName, IO.FileMode.Create)
    End If
    bDocument = System.Text.ASCIIEncoding.ASCII.GetBytes(tCode.Text)
    sFile.Write(bDocument, 0, UBound(bDocument) + 1)
    sFile.Close()
  End Sub

  Private Sub pmAssembler_Feedback(ByVal comment As String) Handles pmAssembler.Feedback
    tEvents.Text &= comment & vbCrLf
  End Sub

  Private Sub pmAssembler_UIAllowRefresh() Handles pmAssembler.UIAllowRefresh
    Application.DoEvents()
  End Sub

  Private Sub bHideFB_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles bHideFB.Click
    panelFeedback.Height = 0
  End Sub

  Private Sub pmEditor_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles MyBase.Load
    bHideFB_Click(sender, e)
  End Sub
End Class
