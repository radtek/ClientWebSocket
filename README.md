# ClientWebSocket For .NET Framework 4.x
This library is a .NET implementation of websocket client. It is a C++/CLI wrapper of Microsoft C++ Rest SDK.
http://microsoft.github.io/cpprestsdk/namespaceweb_1_1websockets_1_1client.html

# Background
Although Windows 8 and newer natively support websocket protocol, older versions of Windows are not able to use the official implementation. Microsoft has an open source websocket library for older versions of Windows, but it's available only for C++. ClientWebSocket for .NET Framework 4.x bridges the gap.

# Interface
ClientWebSocket class has four public methods. All methods are blocking operations.
```C#
public void Connect(string url)
public void Close()
public void Send(string message)
public string Receive()
```

# Example 
This example connects to a public echo websocket server.
```C#
var url = "ws://echo.websocket.org";
using (var ws = new ClientWebSocket())
{
    ws.Connect(url);
    ws.Send("TEST");
    var res = ws.Receive();
    Debug.Assert(res == "TEST");
}
```
