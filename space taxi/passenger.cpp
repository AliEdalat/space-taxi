#include "passenger.h"

using namespace std;

//string Passenger::get_status(){return status;}
Passenger::~Passenger(){
	for (int i = 0; i < trips.size(); ++i)
	{
		delete trips[i];
	}
}