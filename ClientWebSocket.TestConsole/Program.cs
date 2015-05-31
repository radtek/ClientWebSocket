using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ysq.ClientWebSocket.TestConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            var url = "ws://echo.websocket.org";
            using (var ws = new ClientWebSocket())
            {
                Console.WriteLine("Connecting {0}...", url);
                ws.Connect(url);
                Console.WriteLine("Sending TEST...");
                ws.Send("TEST");
                Console.WriteLine("Receiving...");
                var test1 = ws.Receive();
                Console.WriteLine("Received {0}.", test1);
                Debug.Assert(test1 == "TEST");

                Console.WriteLine("Sending TEST1...");
                ws.Send("TEST1");
                Console.WriteLine("Sending TEST2...");
                ws.Send("TEST2");
                Console.WriteLine("Received: {0}", ws.Receive());
                Console.WriteLine("Received: {0}", ws.Receive());

                Console.WriteLine("Closing...");
                ws.Close();
                Console.WriteLine("Closing again... safely able to call multiple close.");
                ws.Close();
            }
                        
            using (var ws = new ClientWebSocket())
            {
                Console.WriteLine("Connecting {0}...", url);
                ws.Connect(url);
                while (true)
                {
                    Console.Write("Please input string: ");
                    var input = Console.ReadLine();
                    Console.WriteLine("Sending input {0}...", input);
                    ws.Send(input);
                    Console.WriteLine("Receiving...");
                    Console.WriteLine("Received: {0}", ws.Receive());
                }
            }
        }
    }
}
