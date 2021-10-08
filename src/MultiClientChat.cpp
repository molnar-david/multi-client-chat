#include "MultiClientChat.h"

#include <sstream>
#include <string>

#define MAX_BUFFER_SIZE 4096

MultiClientChat::MultiClientChat(const char* ipAddress, int port)
	: TcpListener(ipAddress, port)
{
}

// Handler for client connections
void MultiClientChat::onClientConnected(int clientSocket)
{
	// Send a welcome message to the client
	std::string welcomeMsg{ "Welcome to the Awesome Chat Server!\r\n" };
	sendToClient(clientSocket, welcomeMsg.c_str(), welcomeMsg.size());

	// Broadcast we have a new connection
	std::ostringstream ss;
	ss << "SOCKET #" << clientSocket << " has joined the server!\r\n";
	std::string strOut{ ss.str() };

	broadcastToClients(clientSocket, strOut.c_str(), strOut.size());

}

// Handler for client disconnections
void MultiClientChat::onClientDisconnected(int clientSocket)
{
	// Broadcast a client has disconnected
	std::ostringstream ss;
	ss << "SOCKET #" << clientSocket << " has disconnected\r\n";
	std::string strOut{ ss.str() };

	broadcastToClients(clientSocket, strOut.c_str(), strOut.size());
}

// Handler for when a message is received from the client
void MultiClientChat::onMessageReceived(int clientSocket, const char* msg, int length)
{
	// Is the message a command?
	if (msg[0] == '\\')
	{
		std::string cmd{ std::string(msg, length) };

		// Quit the server
		if (cmd == "\\quit")
		{
			setRunning(false);
			return;
		}

		// Unknown command - continue
	}

	// For clients that send control characters after every command (like PuTTY)
	if (!std::strcmp(msg, "\n") || !std::strcmp(msg, "\r\n"))
	{
		return;
	}

	// Send message to the other clients
	std::ostringstream ss;
	ss << "SOCKET #" << clientSocket << ": " << msg << "\r\n";
	std::string strOut{ ss.str() };

	broadcastToClients(clientSocket, strOut.c_str(), strOut.size());
}
