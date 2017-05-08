#include "passenger.h"

using namespace std;

//string Passenger::get_status(){return status;}
/*Passenger::~Passenger(){
	for (int i = 0; i < trips.size(); ++i)
	{
		delete trips[i];
	}
}*/
Trip* Passenger::get_trip(){
	if(trips.size() >= 1){
		return trips[trips.size()-1];
	}
	return NULL;
}
void Passenger::cancel_trip(){
	if (!trips[trips.size()-1]->get_is_accepted())
	{
		int index=trips.size()-1;
		trips.erase(trips.begin()+index);
	}
}
std::string Passenger::get_gap_between_last_trips(){
	Date_time* end_three=new Date_time(trips[trips.size()-3]->get_end_time());
	Date_time* start_two=new Date_time(trips[trips.size()-2]->get_start_time());
	Date_time* end_two=new Date_time(trips[trips.size()-2]->get_end_time());
	Date_time* start_last=new Date_time(trips[trips.size()-1]->get_start_time());
	string first_gap=end_three->different_of_times(start_two);
	string second_gap=end_two->different_of_times(start_last);
	delete end_three;delete start_two;delete end_two;delete start_last;
	Date_time* gap1=new Date_time(first_gap);
	Date_time* gap2=new Date_time(second_gap);
	string result = gap1->add_time(gap2);
	delete gap1;delete gap2;
	cout<<result<<endl;
	return result;
}
std::string Passenger::get_last_trip_gap_with(std::string time){
	Date_time* end_time=new Date_time(trips[trips.size()-1]->get_end_time());
	Date_time* current=new Date_time(time);
	string result= end_time->different_of_times(current);
	delete end_time;delete current;
	return result;
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