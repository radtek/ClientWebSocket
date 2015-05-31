// ClientWebSocket.h

#pragma once

#include "../ClientWebSocketAdapter/ClientWebSocketAdapter.h"

using namespace System;
using namespace msclr::interop;

namespace Ysq {
	namespace ClientWebSocket {

		public ref class ClientWebSocket
		{
		public:
			ClientWebSocket()
			{
				_ws = new ClientWebSocketAdapter();
			};

			virtual ~ClientWebSocket(){ delete _ws; };
			
			void Connect(String^ url)
			{
				try
				{
					auto s = marshal_as<std::wstring>(url);
					_ws->Connect(s);
				}
				catch (std::exception ex)
				{
					auto s = marshal_as<String^>(ex.what());
					throw gcnew InvalidOperationException(s);
				}
			};

			void Close()
			{
				try
				{
					_ws->Close();
				}
				catch (std::exception ex)
				{
					auto s = marshal_as<String^>(ex.what());
					throw gcnew InvalidOperationException(s);
				}
			};

			void Send(String^ message)
			{
				if (message == nullptr)
				{
					throw gcnew ArgumentNullException("message");
				}

				if (message->Length == 0)
				{
					throw gcnew ArgumentException("Message length is zero.");
				}

				try
				{
					auto s = marshal_as<std::string>(message);
					_ws->SendString(s);
				}
				catch (std::exception ex)
				{
					auto s = marshal_as<String^>(ex.what());
					throw gcnew InvalidOperationException(s);
				}
			};

			String^ Receive()
			{
				try
				{
					auto s = _ws->ReceiveString();
					return marshal_as<String^>(s);
				}
				catch (std::exception ex)
				{
					auto s = marshal_as<String^>(ex.what());
					throw gcnew InvalidOperationException(s);
				}
			};

		private:
			ClientWebSocketAdapter* _ws;
		};
	}
}
