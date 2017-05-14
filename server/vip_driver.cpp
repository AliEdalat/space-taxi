#include "vip_driver.h"

using namespace std;

string Vip_driver::show_information(){
	string temp=user_name+' '+spaceship->get_number()+' '+spaceship->get_model()+' '+spaceship->get_production_year()+' '+spaceship->get_color()+" VIP";
	cout<<temp<<endl;
	return user_name+' '+spaceship->get_number()+' '+spaceship->get_model()+' '+spaceship->get_production_year()+' '+spaceship->get_color()+" VIP";
}