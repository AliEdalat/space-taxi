#ifndef PASSENGER_CLIENT_H
#define PASSENGER_CLIENT_H

#include "client_socket.h"
#include "command.h"
#include <cstdlib>

class passenger_client
{
public:
	passenger_client(std::string address, int port);
  	void handel_passenger_commands();
private:
	std::string address;
	int port;
 	std::string username;
 	bool find_username;
 	bool send_register_command;
 	void do_passenger_commands(Command* command,bool& do_command);
 	void do_trip_commands(Command* command,bool& do_command);
};

#endif