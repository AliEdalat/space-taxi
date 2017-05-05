#include "space_taxi_system.h"

using namespace std;

taxi_system::~taxi_system(){
	for (int i = 0; i < passengers.size(); ++i)
	{
		delete passengers[i];
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		delete drivers[i];
	}
	delete admin;
	delete date_time;
	for (int i = 0; i < codes.size(); ++i)
	{
		delete codes[i];
	}
	for (int i = 0; i < trips.size(); ++i)
	{
		delete trips[i];
	}
	for (int i = 0; i < galaxies.size(); ++i)
	{
		delete galaxies[i];
	}
}

Planet* find_planet(std::vector<Planet*> planets,string planet_name){
	for (int i = 0; i < planets.size(); ++i)
	{
		if(planets[i]->get_name() == planet_name){
			return planets[i];
		}
	}
	return NULL;
}
void print_tree(Planet* root,int i){
	cout<<i<<root->get_name()<<endl;
	std::vector<Planet*> children=root->get_planets();
	for (int i = 0; i < children.size(); ++i)
	{
		print_tree(children[i],i+1);
	}
}
void taxi_system::read_spaceship_models(){
	ifstream file("vehicles.cfg");
	string line;
	while(getline(file,line)){
		int index=line.size()-1;
		line.erase(line.begin()+index);
		models.push_back(line);
	}
	file.close();
}
void taxi_system::read_topology(){
	ifstream file("topology.cfg");
	string line;
	int line_counter=0;
	int number_of_planets=0;
	std::vector<Planet*> planets;
	while(getline(file,line)){
		//cout<<line<<endl;
		if (line_counter == 0)
		{
			line_counter++;
			continue;
		}
		if (line_counter == 1)
		{
			int find=line.find(' ');
			string galaxy_name=line.substr(0,find);
			number_of_planets=stoi(line.substr(find+1));
			galaxies.push_back(new Galaxy(galaxy_name));
			line_counter++;
			continue;
		}
		if (line_counter == 2)
		{
			number_of_planets--;
			Planet* root;
			int find=line.find(' ');
			string planet_name=line.substr(0,find);
			int planets_count=stoi(line.substr(find+1));
			root=find_planet(planets,planet_name);
			if(root == NULL){
				root=new Planet(planet_name);
				planets.push_back(root);
			}
			for (int i = 0; i < planets_count; ++i)
			{
				string temp;
				getline(file,temp);
				//cout<<temp<<endl;
				if (find_planet(planets,temp) == NULL)
				{
					Planet* Planet_pointer=new Planet(temp);
					planets.push_back(Planet_pointer);
					root->add_adjacent_planet(Planet_pointer);
				}

			}
			cout<<"PRINT TREE: "<<endl;
			print_tree(planets[0],0);

			if(number_of_planets == 0){
				
				galaxies[galaxies.size()-1]->add_root(planets[0]);
				print_tree(planets[0],0);

				planets.clear();
				line_counter=1;
			}
		}
	}
	file.close();
	cout<<galaxies[0]->calculate_distance_to("planet2")<<endl;
}
int taxi_system::calculate_distance(Address* from,Address* to){
	if(from->get_galaxy() == to->get_galaxy()){

	}
	else{

	}
}
bool taxi_system::find_username(string username){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if(passengers[i]->get_username() == username){
			return true;
		}
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		if (drivers[i]->get_username() == username)
		{
			return true;
		}
	}
	return false;
}
bool taxi_system::find_spaceship_number(string number){
	for (int i = 0; i < drivers.size(); ++i)
	{
		if (drivers[i]->get_spaceship_number() == number)
		{
			return true;
		}
	}
	return false;
}
bool taxi_system::find_phone_number(string phone){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if (passengers[i]->get_phone() == phone)
		{
			return true;
		}
	}
	return false;
}
bool is_phone_number(string phone){
	for (int i = 0; i < phone.size(); ++i)
	{
		if(phone[i] < ZERO_ASCII || phone[i]>NINE_ASCII){
			return false;
		}
	}
	return true;
}
bool taxi_system::find_code(string code){
	//int int_code=stoi(code);
	int index=-1;
	for (int i = 0; i < codes.size(); ++i)
	{
		if(codes[i]->get_code() == code){
			codes[i]->use_code();
		}
		if(codes[i]->get_counter() == 0){
			index=i;
		}
	}
	if(index != -1){
		delete codes[index];
		codes.erase(codes.begin()+index);
	}
}
void taxi_system::register_passenger(string username,string password,string phone_number,string code){
	if(find_username(username) == true){
		cout<<username<<" is not a new username , i have this username in my database!"<<endl;
		return;
	}
	if(find_phone_number(phone_number) == true){
		cout<<phone_number<<" is not new , i have this in my database!"<<endl;
		return;
	}
	if(is_phone_number(phone_number) == false){
		cout<<phone_number<<" is not a valid phone number."<<endl;
		return;
	}
	passengers.push_back(new Passenger(username,password,phone_number));
	if(find_code(code)){
		passengers[passengers.size()-1]->set_credit(10);
	}

}
bool taxi_system::find_model(string _spaceship_model){
	for (int i = 0; i < models.size(); ++i)
	{
		cout<<models[i].size()<<(int)models[i][models[i].size()-1]<<models[i]<<endl;
		if(models[i] == _spaceship_model){
			return true;
		}
	}
	return false;
}
void taxi_system::register_driver(string _user_name,string _password,string _spaceship_number,string _spaceship_model,string _production_year,string _color,bool is_vip){
	if(find_username(_user_name) == true){
		cout<<_user_name<<" is not a new username , i have this username in my database!"<<endl;
		return;
	}
	if(find_spaceship_number(_spaceship_number) == true){
		cout<<_spaceship_number<<" is not a new spaceship number , i have this spaceship number in my database!"<<endl;
		return;
	}
	if(find_model(_spaceship_model) == false){
		cout<<_spaceship_model<<" is not a valid spaceship model!"<<endl;
		return;
	}
	if(is_vip == true){
		drivers.push_back(new Vip_driver(_user_name, _password,_spaceship_number,_spaceship_model,_production_year,_color));
	}else{
		drivers.push_back(new Driver(_user_name, _password,_spaceship_number,_spaceship_model,_production_year,_color));
	}
}
int number_of_digits(int number){
	int counter=0;
	while(number > 0){
		counter++;
		number/=10;
	}
	return counter;
}
User* taxi_system::find_user(string username){
	for (int i = 0; i < passengers.size(); ++i)
	{
		if(passengers[i]->get_username() == username){
			return passengers[i];
		}
	}
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->get_username() == username){
			return drivers[i];
		}
	}
	return NULL;
}
void taxi_system::genarate_discount_code(std::string username){
	string string_code;
	if(find_username(username) && (find_user(username))->get_is_login() && find_user(username)->get_type() == "passenger"){
		for (int i = 0; i < username.size(); ++i)
		{
			int temp=(int)username[i];
			if(i == 0){
				string_code=to_string(temp);
			}else{
				string_code=string_code+to_string(temp);
			}
			/*int num_of_digits=number_of_digits(temp);
			number*=pow(10,num_of_digits);
			number+=temp;
			*/
		}
		cout<<string_code<<' '<<"5"<<endl;
		Code* code=new Code(string_code,(Passenger*)find_user(username));
		codes.push_back(code);
	}else{
		cout<<"you can not use this command because you are not login!"<<endl;
	}
}
void taxi_system::login_user(std::string username){
	if (find_username(username) && !find_user(username)->get_is_login())
	{
		find_user(username)->login();
	}else if(find_username(username) == false){
		cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else{
		cout<<"you are login , you can not use login command!"<<endl;
	}
}
void taxi_system::logout_user(std::string username){
	if (find_username(username) && find_user(username)->get_is_login())
	{
		find_user(username)->logout();
	}else if(find_username(username) == false){
		cout<<"you do not have account \"in space taxi system\"!"<<endl;
	}else{
		cout<<"you are logout , you can not use logout command!"<<endl;
	}	
}
void taxi_system::accept_registeration(string username){
	if(admin->get_is_login()){
		find_user(username)->set_is_accepted(true);
	}else{
		cout<<"you can not use \"accept_registeration\" command please login first!"<<endl;
	}
}
void taxi_system::delete_driver_registeration(string username){
	int index=-1;
	for (int i = 0; i < drivers.size(); ++i)
	{
		if(drivers[i]->get_username() == username){
			index=i;
			break;
		}
	}
	delete drivers[index];
	drivers.erase(drivers.begin()+index);
	cout<<"DELETE"<<endl;
}
void taxi_system::reject_registeration(string username){
	if(admin->get_is_login()){
		find_user(username)->set_is_accepted(false);
		delete_driver_registeration(username);
	}else{
		cout<<"you can not use \"reject_registeration\" command please login first!"<<endl;
	}
}
void taxi_system::show_registeration_requests(){
	if (admin->get_is_login())
	{
		for (int i = 0; i < drivers.size(); ++i)
		{
			if (!drivers[i]->get_is_accepted())
			{
				drivers[i]->show_information();
			}
		}
	}
}
bool taxi_system::find_address(Address* address){
	for (int i = 0; i < galaxies.size(); ++i)
	{
		if(galaxies[i]->get_name() == address->get_galaxy() && galaxies[i]->find_planet(address->get_planet())){
			return true;
		}
	}
	return false;
}
void taxi_system::set_status_available(std::string username,Address* address){
	if(find_username(username) && find_user(username)->get_is_login() && find_address(address)){
		Driver* driver=(Driver*)(find_user(username));
		if(driver->get_status() != "traveling"){
			driver->set_status("available");
		}else{
			cout<<"you can not change your status to available"<<endl;
		}
	}else if(!find_username(username)){
		cout<<"you can not use \"set_status\" command please login first!"<<endl;
	}else{
		cout<<"address is not valid!"<<endl;
	}
}
void taxi_system::set_status_unavailable(std::string username){
	if(find_username(username) && find_user(username)->get_is_login()){
		Driver* driver=(Driver*)(find_user(username));
		if(driver->get_status() != "traveling"){
			driver->set_status("unavailable");
		}else{
			cout<<"you can not change your status to unavailable"<<endl;
		}
	}else{
		cout<<"you can not use \"set_status\" command please login first!"<<endl;
	}
}
int taxi_system::calculate_cost_of_trip(bool& is_vip,Address* source_address,std::vector<Address*> destinations){
	int sum=0;
	sum+=calculate_distance(source_address,destinations[0]);
	for (int i = 0; i < destinations.size()-1; ++i)
	{
		sum+=calculate_distance(destinations[i],destinations[i+1]);
	}
	if(is_vip){
		return 2*sum;
	}else{
		return sum;
	}
}
void taxi_system::estimate_trip(std::string username,bool& is_vip,Address* source_address,std::vector<Address*> destinations){
	int cost;
	if (find_username(username) && find_user(username)->get_is_login() && find_address(source_address))
	{
		for (int i = 0; i < destinations.size(); ++i)
		{
			if(!find_address(destinations[i])){
				cout<<'\"'<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<'\"'<<" is not a valid address!"<<endl;
				return;
			}
		}
		cost=calculate_cost_of_trip(is_vip,source_address,destinations);
		if(is_vip){
			cout<<cost<<' '<<cost/2<<endl;
		}else{
			cout<<cost<<' '<<cost<<endl;
		}		
	}else if(!find_username(username)){
		cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		cout<<"you can not use \"estimate_trip\" command please login first!"<<endl;	
	}else{
		cout<<'\"'<<source_address->get_galaxy()<<','<<source_address->get_planet()<<'\"'<<" is not a valid address!"<<endl;
	}
}
void taxi_system::request_trip(std::string username, bool is_vip,Address* source_address,std::vector<Address*> destinations){
	if(find_username(username) && find_user(username)->get_is_login() && find_user(username)->get_status()=="available" && find_address(source_address)){
		for (int i = 0; i < destinations.size(); ++i)
		{
			if(!find_address(destinations[i])){
				cout<<'\"'<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<'\"'<<" is not a valid address!"<<endl;
				return;
			}
		}
		int cost=calculate_cost_of_trip(is_vip,source_address,destinations);
		if(is_vip){
			trips.push_back(new Vip_trip(username,source_address,destinations,cost,date_time));
			cout<<cost<<' '<<cost/2<<endl;
		}else{
			trips.push_back(new Trip(username,source_address,destinations,cost,date_time));
			cout<<cost<<' '<<cost<<endl;
		}

	}else if(!find_username(username)){
		cout<<"you do not have account in space taxi system!"<<endl;
	}else if(!find_user(username)->get_is_login()){
		cout<<"you can not use \"request_trip\" command please login first!"<<endl;	
	}else{
		cout<<'\"'<<source_address->get_galaxy()<<','<<source_address->get_planet()<<'\"'<<" is not a valid address!"<<endl;
	}
}