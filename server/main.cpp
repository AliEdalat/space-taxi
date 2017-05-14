#include "server.h"
#include "space_taxi_server.h"
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct client_info client_info;
struct client_info
{
	string username;
	int identifier;
	
};

// 'Server' is an abstract class, so define your own server class inheriting from the 'Server'
class MyServer : public Server {
public:
  MyServer(int port) : Server(port) {
  	server=new space_taxi_server();	
  }
  void on_standard_input(string line);
  void on_new_connection(int identifier);
  void on_new_message(int identifier, string message);
  void on_terminated_connection(int identifier);
 private:
 	string get_identifier_username(int identifier);
 	bool find_client_username(string username);
 	space_taxi_server* server;
 	std::vector<client_info*> clients_information;
};

string MyServer::get_identifier_username(int identifier){
	for (int i = 0; i < clients_information.size(); ++i)
	{
		if(clients_information[i]->identifier == identifier){
			return clients_information[i]->username;
		}
	}
	return " ";
}

bool MyServer::find_client_username(string username){
	for (int i = 0; i < clients_information.size(); ++i)
	{
		if(clients_information[i]->username == username){
			return true;
		}
	}
	return false;
}

string provide_command(string line , string username){
	string _user_name=username;
	if(line.find("login") != -1){
  		int find=line.find(_user_name);
		string temp=line.substr(find);
		find=temp.find(' ');
		temp=temp.substr(find+1);
		return _user_name+" "+"login"+" "+temp;
  	}
  	return _user_name+" "+line;
}

void MyServer::on_standard_input(string line)
{
	cout << "STDIN: " << line << endl;
	if (line == ":q")
		stop();
	string result="ali";
	try{
		string temp=line;
		temp=provide_command(line,"admin");
		cout<<temp<<endl;
		Command* command=new Command(temp);
		bool do_command=false;
		server->do_registration_command(command,do_command);
		server->do_admin_commands(command,do_command);
		server->do_user_commands(command,do_command);
		if(server->get_result() != " "){
			cout<<server->get_result()<<endl;
		}
		if (do_command == false)
		{
			cout<<line<<" is not a valid command in space taxi system!"<<endl;
		}
	}catch(invalid_command bad_command){
		cout<<bad_command.get_error()<<endl;
	}catch(bad_command_exception command_ex){
		cout<<command_ex.get_exception()<<endl;
	}
}

void MyServer::on_new_connection(int identifier) {
  cout << "NEW CONNECTION: " << identifier << endl;
}

void MyServer::on_new_message(int identifier, string message) {
  	cout << "NEW MESSAGE FROM " << identifier <<": " << message << endl;
  	string result="ali";
  	try{
  		string temp=message;
  		cout<<"SERVER_MESSAGE :"<<message<<endl;
		Command* command=new Command(temp);
		bool do_command=false;
		if(get_identifier_username(identifier) == command->get_username() || get_identifier_username(identifier) == " "){
			cout<<command->get_username()<<endl;
			cout<<"A:"<<endl;
	    	server->do_register_commands(command,do_command);
			cout<<"B:"<<endl;
	 	   	server->do_registration_command(command,do_command);
			cout<<"C:"<<endl;
	    	server->do_passenger_commands(command,do_command);
			cout<<"D:"<<endl;
	    	server->do_driver_commands(command,do_command);
			cout<<"E:"<<endl;
	    	server->do_admin_commands(command,do_command);
			cout<<"F:"<<endl;
	    	server->do_user_commands(command,do_command);
    	}
    	result = server->get_result();
		if (do_command == false)
		{
			result=message+" is not a valid command in space taxi system!";
			cout<<message<<" is not a valid command in space taxi system!"<<endl;
		}else if(message.find("register") != -1 && result == " " && !find_client_username(command->get_username())){
			client_info* new_client_info = new client_info();
			new_client_info->username=command->get_username();
			new_client_info->identifier=identifier;
			clients_information.push_back(new_client_info);
		}
		//delete command;
	}catch(invalid_command bad_command){
		result=bad_command.get_error();
		cout<<bad_command.get_error()<<endl;
	}catch(bad_command_exception command_ex){
		result=command_ex.get_exception();
		cout<<command_ex.get_exception()<<endl;
	}
  	send(identifier, result);
}

void MyServer::on_terminated_connection(int identifier) {
	cout << "TERMINATED CONNECTION: " << identifier << endl;
	string line;
	for (int i = 0; i < clients_information.size(); ++i)
	{
  		if(clients_information[i]->identifier == identifier){
  			line = clients_information[i]->username;
  		}
  	}
  	line=line+" logout";
  	cout<<line<<endl;
  	try{
  		Command* command=new Command(line);
  		bool do_command=false;
  		server->do_user_commands(command,do_command);
  	
  	}catch(invalid_command bad_command){
		cout<<bad_command.get_error()<<endl;
	}catch(bad_command_exception command_ex){
		cout<<command_ex.get_exception()<<endl;
	}

}


int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "valid operation: " << argv[0] << " [port number]\n";
    exit(-1);
  }
  //space_taxi_server e;
  //e.listen_to_clients();
  MyServer server(Tools::mystoi(argv[1]));
  server.run();
  
  return 0;
}
