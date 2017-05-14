#include "passenger_client.h"  

using namespace std;

void passenger_client::do_passenger_commands(Command* command,bool& do_command){
	if(command->get_type() == "get_discount_code" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
		do_command=true;
  	}
  	do_trip_commands(command,do_command);
  	if(command->get_type() == "rate_driver" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 1){
    	do_command=true;
  	}if(command->get_type() == "get_credit" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}if(command->get_type() == "charge_account" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 1){
    	do_command=true;
  	}if(command->get_type() == "register" && (command->get_num_of_parameters() == 3 || command->get_num_of_parameters() == 4) && (command->get_num_of_spaces() == 3 || command->get_num_of_spaces() == 4)){
  		if(find_username == false){ 
        	send_register_command=true;
        	username = command->get_parameter(0);
    		find_username=true;
      	}
    	do_command=true;
  	}if (command->get_type() == "login" && command->get_num_of_parameters() == 2){
    	if(find_username == false){ 
        	send_register_command=true;
        	username = command->get_parameter(0);
    		find_username=true;
      	}
    	do_command=true;
  	}if(command->get_type() == "logout" && command->get_num_of_parameters() == 0){
    	do_command=true;
  	}
}
void passenger_client::do_trip_commands(Command* command,bool& do_command){
	if (command->get_type() == "estimate_trip" && command->get_num_of_parameters() >=2){
    	do_command=true;
  	}if (command->get_type() == "request_trip" && command->get_num_of_parameters() >=2){
    	do_command=true;
  	}
  	if(command->get_type() == "cancel_trip_request" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}if(command->get_type() == "trip_status" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 0){
    	do_command=true;
  	}
}
string provide_command(string line , string username){
	string _user_name=username;
	if(line.find("register") != -1){
		int find=line.find(_user_name);
		if(find == -1){
			throw invalid_command("you can not use this command because you use register command before this time!");
		}
		string temp=line.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		return _user_name+" "+"register_passenger"+" "+temp;
  	}else if(line.find("login") != -1){
  		int find=line.find(_user_name);
  		if(find == -1){
			throw invalid_command("i can not find your username in command!");
		}
		string temp=line.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		return _user_name+" "+"login"+" "+temp;
  	}
  	return _user_name+" "+line;
}
void passenger_client::handel_passenger_commands(){
	ClientSocket socket(address , port);
  	cout << "# connection established\n";
	string line;
  	while (getline(cin, line)) {
    	if (line == ":q")
      		break;
  		try{
      		Command* command=new Command(line);
      		bool do_command= false;
      		do_passenger_commands(command,do_command);
      		if(do_command == false){
        		cout<<"\""<<line<<"\" is not a valid passenger command!"<<endl;
        		continue;
      		}
      		if(find_username == false){
  				cout<<"you must register yourself in space taxi system!"<<endl;
  				continue;
  			}else{
  				line=provide_command(line,username);
  			}
  		}catch(invalid_command bad_command){
    		cout<<bad_command.get_error()<<endl;
    		continue;
  		}
  		
    	cout<<"BEFORE_SEND :"<<line<<endl;
    	socket.send(line);
    	string temp=socket.receive();
    	if(send_register_command == true && temp != " "){
    		find_username=false;
    		send_register_command=false;
    	}else{
    		send_register_command=false;
    	}
    	cout << temp << endl;
    	socket.status();
  	}
}
passenger_client::passenger_client(string _address, int _port){
	find_username=false;
	send_register_command=false;
	port=_port;
	address=_address;
}