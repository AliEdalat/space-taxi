#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "space_taxi_system.h"
#include "invalid_command.h"
#include "command.h"

class Server
{
public:
	Server();
	~Server();
	void recive_command();
	std::string send_result();
	void listen_to_clients();
	taxi_system* get_taxi_system(){return t;}
private:
	std::vector<std::string> models;
	taxi_system* t;

};
void readfiles(std::vector<std::string>& models);
#endif