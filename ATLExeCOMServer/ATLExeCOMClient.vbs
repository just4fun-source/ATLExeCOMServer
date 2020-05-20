On Error Resume Next
SET ComSrv = CreateObject("ATLExeCOMServer.SimpleObject")

If ComSrv Then
	StrMsg = ComSrv.SayHello
	StrPID = ComSrv.GetProcessID
	StrTID = ComSrv.GetThreadID
	MsgBox _
	"ATLExeCOMServer.exe" &vbNewLine &_
	"" &vbNewLine &_
	"method GetProcessID" &vbTab &StrPID &vbNewLine &_
	"method GetThreadID"  &vbTab &StrTID &vbNewLine &_
	"method SayHello"     &vbTab &vbTab  &StrMsg _
	,vbOKOnly ,"ATLExeCOMClient"
Else
	MsgBox _
	"ATLExeCOMServer.exe" &vbNewLine &_
	"" &vbNewLine &_
	"Server not registered or unreachable!" _
	,vbOKOnly ,"ATLExeCOMClient"
End If

SET ComSrv = Nothing