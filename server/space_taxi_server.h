#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "space_taxi_system.h"
#include "invalid_command.h"
#include "command.h"

class space_taxi_server
{
public:
	space_taxi_server();
	~space_taxi_server();
	void recive_command();
	std::string send_result();
	void listen_to_clients();
	void do_register_commands(Command* command,bool& do_command);
	void do_registration_command(Command* command,bool& do_command);
	void do_passenger_commands(Command* command,bool& do_command);
	void do_driver_commands(Command* command,bool& do_command);
	void do_admin_commands(Command* command,bool& do_command);
	void do_user_commands(Command* command,bool& do_command);
	void do_trip_commands(Command* command,bool& do_command);
	taxi_system* get_taxi_system(){return t;}
	std::string get_result(){return t->get_result();}
private:
	std::vector<std::string> models;
	taxi_system* t;

};
void readfiles(std::vector<std::string>& models);
#endif