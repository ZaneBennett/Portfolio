Public Class Form1
    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged

        Dim info(3, 3) As String

        info(0, 0) = "Stan Lee"
        info(0, 1) = "12/28/1922"
        info(0, 2) = "7065884"
        info(1, 0) = "Jack Kirby"
        info(1, 1) = "08/28/1917"
        info(1, 2) = "6758045"
        info(2, 0) = "Steve Ditko"
        info(2, 1) = "11/02/1927"
        info(2, 2) = "8307368"

        MsgBox("Name: " & info(ListBox1.SelectedIndex, 0) & vbCrLf & "Date of Birth: " & info(ListBox1.SelectedIndex, 1) & vbCrLf & "ID: " & info(ListBox1.SelectedIndex, 2))

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Me.Close()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs)

    End Sub
End Class
