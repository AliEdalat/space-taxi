#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"
#include "trip.h"
#include <string>
#include <vector>

class Passenger:public User
{
public:
	Passenger(std::string _user_name,std::string _password,std::string _phone):User(_user_name,_password,"passenger"){
		//server:
		//check phone_number in numbers
		phone_number=_phone;
		status="available";
	};
	std::string get_phone(){return phone_number;}
	//std::string get_status();
	void add_trip(Trip* new_trip){trips.push_back(new_trip);}
	~Passenger();
	//get discount code
	//calculate trip cost
	//trip request
	//cancel request trip
	//get trip status
	//rate driver in trip
	//charge account
	//get_credit
private:
	std::string phone_number;
	//std::string status;
	std::vector<Trip*> trips;
};

#endif