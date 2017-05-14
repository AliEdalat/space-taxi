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
		
		phone_number=_phone;
		status="available";
		is_excellent_passenger=false;
	};
	std::string get_phone(){return phone_number;}
	void cancel_trip();
	void add_trip(Trip* new_trip){trips.push_back(new_trip);}
	Trip* get_trip();
	bool rate_all_trips();
	void reduce_credit(int delta){credit-=delta;}
	bool get_is_excellent_passenger(){return is_excellent_passenger;}
	void set_is_excellent_passenger(bool status){is_excellent_passenger=status;}
	int get_num_of_trips();
	void set_trip_accepted();
	std::string get_gap_between_last_trips();
	std::string get_last_trip_gap_with(std::string time);
	
private:
	std::string phone_number;
	bool is_excellent_passenger;
	std::vector<Trip*> trips;
};

#endif