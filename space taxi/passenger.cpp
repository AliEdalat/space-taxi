#include "passenger.h"

using namespace std;

//string Passenger::get_status(){return status;}
/*Passenger::~Passenger(){
	for (int i = 0; i < trips.size(); ++i)
	{
		delete trips[i];
	}
}*/
void Passenger::cancel_trip(){
	if (!trips[trips.size()-1]->get_is_accepted())
	{
		int index=trips.size()-1;
		trips.erase(trips.begin()+index);
	}
}
bool Passenger::rate_all_trips(){
	for (int i = 0; i < trips.size(); ++i)
	{
		if(trips[i]->is_rated() == false){
			return false;
		}
	}
	return true;
}