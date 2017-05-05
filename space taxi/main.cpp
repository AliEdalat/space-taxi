#include <iostream>

using namespace std;

#include "server.h"
#include "space_taxi_system.h"

int main(int argc, char const *argv[])
{
	
	Server s;
	s.listen_to_clients();
	//Server server;
	//taxi_system* t=server.get_taxi_system();
	//t.read_topology();
	//t->register_passenger("aliooo","1377","09171305495","0");
	//t->genarate_discount_code("aliooo");
	//t->register_driver("sd","1","123456","U_wing","1234","red",false);
	//Address* addre=new Address("ali","ert");
	//t->set_status_available("sd",addre);
	//t->logout_user("aliooo");
	//t->logout_user("aliooo");
	//t.accept_registeration("sd");
	//t->show_registeration_requests();
	//t.read_spaceship_models();
	return 0;
}