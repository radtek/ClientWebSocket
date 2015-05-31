#pragma once

namespace web
{
	namespace websockets
	{
		namespace client
		{
			class websocket_client;
		}
	}
}
 
class ClientWebSocketAdapter
{
public:
	ClientWebSocketAdapter();
	virtual ~ClientWebSocketAdapter();
	void Connect(std::wstring url);
	void SendString(std::string utf8s);
	std::string ReceiveString();
	void Close();

private:
	web::websockets::client::websocket_client* _ws;
};

