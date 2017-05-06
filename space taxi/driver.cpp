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