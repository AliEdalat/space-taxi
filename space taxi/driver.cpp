#include "driver.h"

using namespace std;

void Driver::show_information(){
	string temp=user_name+' '+spaceship->get_number()+' '+spaceship->get_model()+' '+spaceship->get_production_year()+' '+spaceship->get_color();
	cout<<temp<<endl;
}
void Driver::show_requests(){
	for (int i = 0; i < trips.size(); ++i)
	{
		if(!trips[i]->get_is_finished()){
			trips[i]->show_trip_information();
		}
	}
}
void Driver::erase_request(Trip* _trip){
	int index=-1;
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i] == _trip){
			index=i;
		}
	}
	trips.erase(trips.begin()+index);
}
bool Driver::find_trip(Trip* _trip){
	for (int i = 0; i < trips.size(); ++i)
	{
		if (trips[i] == _trip)
		{
			return true;
		}
	}
	return false;
}
void Driver::set_trip_rate(int rate){
	for (int i = trips.size()-1; i >= 0; i--)
	{
		if (trips[i]->get_is_finished())
		{
			trips[i]->set_rate(rate);
		}
	}
}
void Driver::show_report(std::string from , std::string to){
	int incom=0;
	int rate=0;
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i]->get_start_time() >= from && trips[i]->get_end_time() <= to && trips[i]->get_is_finished()){
			incom+=(trips[i]->get_credit()*8)/10;
			rate+=trips[i]->get_score();
		}
	}
	cout<<trips.size()<<' '<<incom<<' '<<rate<<endl;
}
bool Driver::find_trip_for_accept(){
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i]->get_is_accepted() == false){
			return true;
		}
	}
	return false;
}
Driver::~Driver(){
	delete spaceship;
} 