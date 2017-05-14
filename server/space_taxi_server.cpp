#include "space_taxi_server.h"
#include "bad_command_exception.h"

using namespace std;
space_taxi_server::space_taxi_server(){
	t=new taxi_system();
	t->read_spaceship_models();
	t->read_topology();
}
space_taxi_server::~space_taxi_server(){
	delete t;
}
Address* create_source_address(Command* command ,int start){
	string temp=command->get_parameter(start);
	int find=temp.find(',');
	if (find == -1)
	{
		throw bad_command_exception(temp+" is not a valid address in space taxi system!");
	}
	string galaxy=temp.substr(0,find);
	string planet=temp.substr(find+1);
	Address* address=new Address(galaxy,planet);
	return address;
}
std::vector<Address*> create_vector_of_destinations(Command* command,int start){
	std::vector<Address*> destinations;
	for (int i = start; i < command->get_num_of_parameters(); ++i)
	{
		string temp=command->get_parameter(i);
		int find=temp.find(',');
		if (find == -1)
		{
			throw bad_command_exception(temp+" is not a valid address in space taxi system!");
		}
		string galaxy=temp.substr(0,find);
		string planet=temp.substr(find+1);
		destinations.push_back(new Address(galaxy,planet));
	}
	return destinations;
}
void space_taxi_server::do_register_commands(Command* command,bool& do_command){
	if(command->get_type() == "register_passenger" && (command->get_num_of_parameters() == 2 || command->get_num_of_parameters() == 3) && (command->get_num_of_spaces() == 3 || command->get_num_of_spaces() == 4)){
		if(command->get_num_of_parameters() == 2){
			t->register_passenger(command->get_username(),command->get_parameter(0),command->get_parameter(1),"0");
		}else{
			t->register_passenger(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2));
		}
		do_command=true;
	}
	if (command->get_type() == "register_driver" && (command->get_num_of_parameters() == 6 || command->get_num_of_parameters() == 5) && (command->get_num_of_spaces() == 6 || command->get_num_of_spaces() == 7)){
		if(command->get_num_of_parameters() == 6 && command->get_parameter(5) == "VIP"){
			t->register_driver(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2),command->get_parameter(3),command->get_parameter(4),true);
		}else{
			//cout<<"NOT VIP!"<<endl;
			t->register_driver(command->get_username(),command->get_parameter(0),command->get_parameter(1),command->get_parameter(2),command->get_parameter(3),command->get_parameter(4),false);
		}
		do_command=true;
	}
}
void space_taxi_server::do_registration_command(Command* command ,bool& do_command){
	if(command->get_type() == "show_registration_requests" && command->get_username() == "admin" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->show_registeration_requests();
		do_command=true;
	}if(command->get_type() == "accept_registration" && command->get_username() == "admin" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		t->accept_registeration(command->get_parameter(0));
		do_command=true;
	}
	if(command->get_type() == "reject_registration" && command->get_username() == "admin" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		t->reject_registeration(command->get_parameter(0));
		do_command=true;
	}
}
void space_taxi_server::do_trip_commands(Command* command,bool& do_command){
	if (command->get_type() == "estimate_trip" && command->get_num_of_parameters() >=2){
		if(command->get_parameter(0) == "VIP"){
			Address* address=create_source_address(command,1);
			std::vector<Address*> destinations=create_vector_of_destinations(command,2);
			t->estimate_trip(command->get_username(),true,address,destinations);
		}else{
			Address* address=create_source_address(command,0);
			std::vector<Address*> destinations=create_vector_of_destinations(command,1);
			t->estimate_trip(command->get_username(),false,address,destinations);
		}
		do_command=true;
	}if (command->get_type() == "request_trip" && command->get_num_of_parameters() >=2){
		if(command->get_parameter(0) == "VIP"){
			Address* address=create_source_address(command,1);
			std::vector<Address*> destinations=create_vector_of_destinations(command,2);
			t->request_trip(command->get_username(),true,address,destinations);
		}else{
			Address* address=create_source_address(command,0);
			std::vector<Address*> destinations=create_vector_of_destinations(command,1);
			t->request_trip(command->get_username(),false,address,destinations);
		}
		do_command=true;
	}
	if(command->get_type() == "cancel_trip_request" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->cancel_trip_request(command->get_username());
		do_command=true;
	}if(command->get_type() == "trip_status" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->trip_status(command->get_username());
		do_command=true;
	}
}
void space_taxi_server::do_passenger_commands(Command* command,bool& do_command){
	if(command->get_type() == "get_discount_code" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->genarate_discount_code(command->get_username());
		do_command=true;
	}
	do_trip_commands(command,do_command);
	if(command->get_type() == "rate_driver" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		int rate=stoi(command->get_parameter(0));
		t->rate_driver(command->get_username() , rate);
		do_command=true;
	}if(command->get_type() == "get_credit" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->get_credit(command->get_username());
		do_command=true;
	}if(command->get_type() == "charge_account" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		int credit=stoi(command->get_parameter(0));
		t->charge_account(command->get_username() , credit);
		do_command=true;
	}
}
void space_taxi_server::do_driver_commands(Command* command,bool& do_command){
	if(command->get_type() == "set_status" && command->get_num_of_parameters() == 2 && command->get_parameter(0) == "available" && command->get_num_of_spaces() == 3){
		Address* address=create_source_address(command,1);
		t->set_status_available(command->get_username(),address);
		do_command=true;
	}if(command->get_type() == "set_status" && command->get_num_of_parameters() == 1 && command->get_parameter(0) == "unavailable" && command->get_num_of_spaces() == 2){
		t->set_status_unavailable(command->get_username());
		do_command=true;
	}if(command->get_type() == "show_trip_requests" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->show_trip_requests(command->get_username());
		do_command=true;
	}if (command->get_type() == "accept_trip_request" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		t->accept_trip_request(command->get_username(),command->get_parameter(0));
		do_command=true;
	}if (command->get_type() == "arrived" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->arrived(command->get_username());
		do_command=true;
	}if(command->get_type() == "end_trip" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		t->end_trip(command->get_username());
		do_command=true;
	}
}
bool check_date_time(string time){
	int find=time.find('-');
	string temp=time.substr(0,find);
	if(stoi(temp) > 31 || stoi(temp) < 1){
		throw bad_command_exception(time+" time_date is not valid in space taxi system!");
	}
	for (int i = 0; i < 2; ++i)
	{
		int found=time.find(':');
		string temp2=time.substr(find+1,found);
		if(i==0 && (stoi(temp2) < 0 || stoi(temp2) >23)){
			throw bad_command_exception(time+" time_date is not valid in space taxi system!");		
		}if(i == 1 && (stoi(temp2) < 0 || stoi(temp2) >59))
		{
			throw bad_command_exception(time+" time_date is not valid in space taxi system!");
		}
		find=found;
	}
	temp=time.substr(find+1);
	if(stoi(temp) < 0 || stoi(temp) >59)
	{
		throw bad_command_exception(time+" time_date is not valid in space taxi system!");
	}
	return true;
}
void space_taxi_server::do_admin_commands(Command* command,bool& do_command){
	if(command->get_type() == "set_time" && command->get_username() == "admin" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		do_command=true;
		check_date_time(command->get_parameter(0));
		t->set_time(command->get_parameter(0));
	}if(command->get_type() == "passenger_report" && command->get_username() == "admin" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
		do_command=true;
		t->passenger_report(command->get_parameter(0));
	}if (command->get_type() == "driver_report" && command->get_num_of_parameters() == 3 && command->get_username() == "admin" && command->get_num_of_spaces() == 4){
		do_command=true;
		check_date_time(command->get_parameter(1));
		check_date_time(command->get_parameter(2));
		t->driver_report(command->get_parameter(0) , command->get_parameter(1) , command->get_parameter(2));
	}if(command->get_type() == "system_report" && command->get_username() == "admin" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
		do_command=true;
		t->system_report();
	}if(command->get_type() == "system_report" && command->get_username() == "admin" && command->get_num_of_parameters() == 2 && command->get_num_of_spaces() == 3){
		do_command=true;
		check_date_time(command->get_parameter(0));
		check_date_time(command->get_parameter(1));
		t->system_report_with_date(command->get_parameter(0) , command->get_parameter(1));
	}
}
void space_taxi_server::do_user_commands(Command* command,bool& do_command){
	if (command->get_type() == "login" && command->get_num_of_parameters() == 1){
		t->login_user(command->get_username() , command->get_parameter(0));
		do_command=true;
	}if(command->get_type() == "logout" && command->get_num_of_parameters() == 0){
		t->logout_user(command->get_username());
		do_command=true;
	}
}
void space_taxi_server::listen_to_clients(){
	string line;
	while(getline(cin,line)){
		string temp=line;
		try{
			Command* command=new Command(line);
			bool do_command=false;
			do_register_commands(command,do_command);
			do_registration_command(command,do_command);
			do_passenger_commands(command,do_command);
			do_driver_commands(command,do_command);
			do_admin_commands(command,do_command);
			do_user_commands(command,do_command);
			if (do_command == false)
			{
				cout<<temp<<" is not a valid command in space taxi system!"<<endl;
			}
			delete command;
		}catch(invalid_command bad_command){
			cout<<bad_command.get_error()<<endl;
		}catch(bad_command_exception command_ex){
			cout<<command_ex.get_exception()<<endl;
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