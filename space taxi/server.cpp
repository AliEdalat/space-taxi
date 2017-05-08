#include "server.h"

using namespace std;
Server::Server(){
	t=new taxi_system();
	t->read_spaceship_models();
	t->read_topology();
}
Server::~Server(){
	delete t;
}
std::vector<Address*> create_vector_of_destinations(Command* command,int start){
	std::vector<Address*> destinations;
	for (int i = start; i < command->get_num_of_parameters(); ++i)
	{
		string temp=command->get_parameter(i);
		int find=temp.find(',');
		string galaxy=temp.substr(0,find);
		string planet=temp.substr(find+1);
		destinations.push_back(new Address(galaxy,planet));
	}
	return destinations;
}
void Server::listen_to_clients(){
	string line;
	while(getline(cin,line)){
		//cout<<line<<endl;
		try{
			Command* command=new Command(line);
			if(command->get_type() == "register_passenger" && command->get_num_of_parameters() >= 2){
				if(command->get_num_of_parameters() == 2){
					t->register_passenger(command->get_username(),command->get_parameter(0),command->get_parameter(1),"0");
				}else{
					t->register_passenger(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2));
				}
			}
			if (command->get_type() == "register_driver" && (command->get_num_of_parameters() == 6 || command->get_num_of_parameters() == 5)){
				if(command->get_num_of_parameters() == 6 && command->get_parameter(5) == "VIP"){
					t->register_driver(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2),command->get_parameter(3),command->get_parameter(4),true);
				}else{
					cout<<"NOT VIP!"<<endl;
					t->register_driver(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2),command->get_parameter(3),command->get_parameter(4),false);
				}
			}
			if(command->get_type() == "show_registration_requests" && command->get_username() == "admin" && command->get_num_of_parameters() == 0){
				t->show_registeration_requests();
			}
			if(command->get_type() == "get_discount_code" && command->get_num_of_parameters() == 0 ){
				t->genarate_discount_code(command->get_username());
			}
			if(command->get_type() == "accept_registeration" && command->get_username() == "admin" && command->get_num_of_parameters() == 1){
				t->accept_registeration(command->get_parameter(0));
			}
			if(command->get_type() == "reject_registraion" && command->get_username() == "admin" && command->get_num_of_parameters() == 1){
				t->reject_registeration(command->get_parameter(0));
			}
			if (command->get_type() == "login" && command->get_num_of_parameters() == 1){
				t->login_user(command->get_username() , command->get_parameter(0));
			}if(command->get_type() == "logout" && command->get_num_of_parameters() == 0){
				t->logout_user(command->get_username());
			}
			if(command->get_type() == "set_status" && command->get_num_of_parameters() == 2 && command->get_parameter(0) == "available"){
				string temp=command->get_parameter(1);
				int find=temp.find(',');
				string galaxy=temp.substr(0,find);
				string planet=temp.substr(find+1);
				Address* address=new Address(galaxy,planet);
				t->set_status_available(command->get_username(),address);
			}
			if(command->get_type() == "set_status" && command->get_num_of_parameters() == 1 && command->get_parameter(0) == "unavailable"){
				t->set_status_unavailable(command->get_username());
			}
			if (command->get_type() == "estimate_trip" && command->get_num_of_parameters() >=3){
				if(command->get_parameter(0) == "VIP"){
					string temp=command->get_parameter(1);
					int find=temp.find(',');
					string galaxy=temp.substr(0,find);
					string planet=temp.substr(find+1);
					Address* address=new Address(galaxy,planet);
					std::vector<Address*> destinations=create_vector_of_destinations(command,2);
					t->estimate_trip(command->get_username(),true,address,destinations);
				}else{
					string temp=command->get_parameter(0);
					int find=temp.find(',');
					string galaxy=temp.substr(0,find);
					string planet=temp.substr(find+1);
					Address* address=new Address(galaxy,planet);
					std::vector<Address*> destinations=create_vector_of_destinations(command,1);
					t->estimate_trip(command->get_username(),false,address,destinations);
				}
			}if (command->get_type() == "request_trip" && command->get_num_of_parameters() >=3){
				if(command->get_parameter(0) == "VIP"){
					string temp=command->get_parameter(1);
					int find=temp.find(',');
					string galaxy=temp.substr(0,find);
					string planet=temp.substr(find+1);
					Address* address=new Address(galaxy,planet);
					std::vector<Address*> destinations=create_vector_of_destinations(command,2);
					t->request_trip(command->get_username(),true,address,destinations);
				}else{
					string temp=command->get_parameter(0);
					int find=temp.find(',');
					string galaxy=temp.substr(0,find);
					string planet=temp.substr(find+1);
					Address* address=new Address(galaxy,planet);
					std::vector<Address*> destinations=create_vector_of_destinations(command,1);
					t->request_trip(command->get_username(),false,address,destinations);
				}
			}
			if(command->get_type() == "cancel_trip_request" && command->get_num_of_parameters() == 0){
				t->cancel_trip_request(command->get_username());
			}if(command->get_type() == "show_trip_requests" && command->get_num_of_parameters() == 0){
				t->show_trip_requests(command->get_username());
			}
			if (command->get_type() == "accept_trip_request" && command->get_num_of_parameters() == 1)
			{
				t->accept_trip_request(command->get_username(),command->get_parameter(0));
			}
			if(command->get_type() == "trip_status" && command->get_num_of_parameters() == 0){
				t->trip_status(command->get_username());
			}
			if (command->get_type() == "arrived" && command->get_num_of_parameters() == 0)
			{
				t->arrived(command->get_username());
			}if(command->get_type() == "end_trip" && command->get_num_of_parameters() == 0){
				t->end_trip(command->get_username());
			}if(command->get_type() == "rate_driver" && command->get_num_of_parameters() == 1){
				int rate=stoi(command->get_parameter(0));
				t->rate_driver(command->get_username() , rate);
			}if(command->get_type() == "get_credit" && command->get_num_of_parameters() == 0){
				t->get_credit(command->get_username());
			}if(command->get_type() == "set_time" && command->get_num_of_parameters() == 1){
				t->set_time(command->get_parameter(0));
			}if(command->get_type() == "charge_account" && command->get_num_of_parameters() == 1){
				int credit=stoi(command->get_parameter(0));
				t->charge_account(command->get_username() , credit);
			}if(command->get_type() == "passenger_report" && command->get_num_of_parameters() == 1){
				t->passenger_report(command->get_parameter(0));
			}if (command->get_type() == "driver_report" && command->get_num_of_parameters() == 3 && command->get_username() == "admin"){
				t->driver_report(command->get_parameter(0) , command->get_parameter(1) , command->get_parameter(2));
			}if(command->get_type() == "system_report" && command->get_username() == "admin" && command->get_num_of_parameters() == 0){
				t->system_report();
			}if(command->get_type() == "system_report" && command->get_username() == "admin" && command->get_num_of_parameters() == 2){
				t->system_report_with_date(command->get_parameter(0) , command->get_parameter(1));
			}
			delete command;
		}catch(invalid_command bad_command){
			cout<<bad_command.get_error()<<endl;
		}
	}
}
void readfiles(vector<string>& models){
	ifstream file("vehicles.cfg");
	string line;
	while(getline(file,line)){
		models.push_back(line);
	}
	file.close();
}