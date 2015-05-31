#include "stdafx.h"
#include "ClientWebSocketAdapter.h"
#include <cpprest/ws_client.h> 

using namespace web;
using namespace web::websockets::client;

ClientWebSocketAdapter::ClientWebSocketAdapter()
{
	_ws = new websocket_client();
}

ClientWebSocketAdapter::~ClientWebSocketAdapter()
{
	_ws->close().wait();
	delete _ws;
}

void ClientWebSocketAdapter::Connect(std::wstring url)
{
	_ws->connect(uri{ url }).wait();
}

void ClientWebSocketAdapter::SendString(std::string utf8s)
{
	websocket_outgoing_message message;
	message.set_utf8_message(utf8s);
	_ws->send(message).wait();
}

std::string ClientWebSocketAdapter::ReceiveString()
{
	auto res = _ws->receive().get();
	return res.extract_string().get();
}

void ClientWebSocketAdapter::Close()
{
	_ws->close().wait();
}
