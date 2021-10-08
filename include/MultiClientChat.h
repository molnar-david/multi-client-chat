#pragma once

#include "TcpListener.h"

class MultiClientChat : public TcpListener
{
protected:
	// Handler for client connections
	void onClientConnected(int clientSocket) override;

	// Handler for client disconnections
	void onClientDisconnected(int clientSocket) override;

	// Handler for when a message is received from the client
	void onMessageReceived(int clientSocket, const char* msg, int length) override;

public:
	MultiClientChat(const char* ipAddress, int port);
};
