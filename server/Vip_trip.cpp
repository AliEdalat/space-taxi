#include "Vip_trip.h"

using namespace std;

string Vip_trip::show_trip_information(){
	string temp=username+' '+source_address->get_galaxy()+','+source_address->get_planet()+' ';
	cout<<username<<' '<<source_address->get_galaxy()<<','<<source_address->get_planet()<<' ';
	for (int i = 0; i < destinations.size(); ++i)
	{
		temp=temp+destinations[i]->get_galaxy()+','+destinations[i]->get_planet()+' ';
		cout<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<' ';
	}
	temp=temp+to_string(cost)+' '+to_string(distance);
	cout<<cost<<' '<<distance<<endl;
	return temp;
}