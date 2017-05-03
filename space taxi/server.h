#ifndef SERVER_H
#define SERVER_H

#include <iostream>

class Server
{
public:
	Server();
	void recive_command();
	std::string send_result();
	void listen_to_clients();

};

#endif