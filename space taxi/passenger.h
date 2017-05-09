#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"
#include "trip.h"
#include "date_time.h"
#include <string>
#include <vector>

class Passenger:public User
{
public:
	Passenger(std::string _user_name,std::string _password,std::string _phone,Date_time* birth_date):User(_user_name,_password,"passenger",birth_date){
		//server:
		//check phone_number in numbers
		phone_number=_phone;
		status="available";
		is_excellent_passenger=false;
	};
	std::string get_phone(){return phone_number;}
	//std::string get_status();
	void cancel_trip();
	void add_trip(Trip* new_trip){trips.push_back(new_trip);}
	Trip* get_trip();
	bool rate_all_trips();
	void reduce_credit(int delta){credit-=delta;}
	bool get_is_excellent_passenger(){return is_excellent_passenger;}
	void set_is_excellent_passenger(bool status){is_excellent_passenger=status;}
	int get_num_of_trips();
	std::string get_gap_between_last_trips();
	std::string get_last_trip_gap_with(std::string time);
	//~Passenger();
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
	bool is_excellent_passenger;
	std::vector<Trip*> trips;
};

#endif