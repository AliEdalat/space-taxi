//#include "client_socket.h"
//#include "command.h"
//#include <cstdlib>
#include "passenger_client.h"
using namespace std;

/*void do_trip_commands(Command* command,bool& do_command){
  if (command->get_type() == "estimate_trip" && command->get_num_of_parameters() >=3){
    do_command=true;
  }if (command->get_type() == "request_trip" && command->get_num_of_parameters() >=3){
    do_command=true;
  }
  if(command->get_type() == "cancel_trip_request" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
    do_command=true;
  }if(command->get_type() == "trip_status" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
    do_command=true;
  }
}

void do_passenger_commands(Command* command,bool& do_command){
  if(command->get_type() == "get_discount_code" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
    do_command=true;
  }
  do_trip_commands(command,do_command);
  if(command->get_type() == "rate_driver" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
    do_command=true;
  }if(command->get_type() == "get_credit" && command->get_num_of_parameters() == 0 && command->get_num_of_spaces() == 1){
    do_command=true;
  }if(command->get_type() == "charge_account" && command->get_num_of_parameters() == 1 && command->get_num_of_spaces() == 2){
    do_command=true;
  }if(command->get_type() == "register_passenger" && (command->get_num_of_parameters() == 2 || command->get_num_of_parameters() == 3) && (command->get_num_of_spaces() == 3 || command->get_num_of_spaces() == 4)){
    do_command=true;
  }if (command->get_type() == "login" && command->get_num_of_parameters() == 1){
    do_command=true;
  }if(command->get_type() == "logout" && command->get_num_of_parameters() == 0){
    do_command=true;
  }

}
*/

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "valid operation: " << argv[0] << " [server address] [server port]\n";
    exit(-1);
  }
  
  /*ClientSocket socket(string(argv[1]), Tools::mystoi(argv[2]));
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
  }catch(invalid_command bad_command){
    cout<<bad_command.get_error()<<endl;
    continue;
  }
    cout<<"BEFORE_SEND :"<<line<<endl;
    socket.send(line);
    cout << socket.receive() << endl;
    socket.status();
    
  }*/
  passenger_client client(string(argv[1]), Tools::mystoi(argv[2]));
  client.handel_passenger_commands();
  
  return 0;
}
