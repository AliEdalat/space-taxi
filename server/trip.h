#ifndef TRIP_H
#define TRIP_H


#include "address.h"
#include "date_time.h"
#include <vector>
#include <iostream>

class Trip
{
public:
	Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,int _distance,Date_time* _date_time);
	bool get_is_accepted(){return accepted;}
	void set_is_accepted(bool status){accepted=status;}
	bool get_is_finished(){return finished;}
	void set_is_finished(bool status){finished=status;}
	std::string get_model(){return model;}
	bool is_rated(){return rated;}
	void set_is_rated(bool status){rated=status;}
	Address* get_address(){return source_address;}
	Address* get_destination(){return destinations[destinations.size()-1];}
	void set_driver_name(std::string username){driver_username=username;}
	std::string get_driver_name(){return driver_username;}
	std::string get_username(){return username;}
	void set_start_time(Date_time* start){
		delete start_date_time;
		start_date_time=start;
	}
	void set_end_time(Date_time* end){
		delete end_date_time;
		end_date_time=end;
	}
	std::string get_end_time(){return end_date_time->get_date_time();}
	std::string get_start_time(){return start_date_time->get_date_time();}
	int get_credit(){return cost;}
	int get_score(){return rate;}
	void set_rate(int _rate){rate=_rate;}
	virtual std::string show_trip_information();
	~Trip();
protected:
	Address* source_address;
	std::string username;
	Date_time* date_time;
	Date_time* start_date_time;
	Date_time* end_date_time;
	std::string driver_username;
	int cost;
	int distance;
	int rate;
	bool accepted;
	bool finished;
	bool rated;
	std::string model;
	std::vector<Address*> destinations;
};

#endif