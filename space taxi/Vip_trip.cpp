#include "Vip_trip.h"

using namespace std;

void Vip_trip::show_trip_information(){
	cout<<username<<' '<<source_address->get_galaxy()<<','<<source_address->get_planet()<<' ';
	for (int i = 0; i < destinations.size(); ++i)
	{
		cout<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<' ';
	}
	cout<<cost<<' '<<cost/2<<endl;
}