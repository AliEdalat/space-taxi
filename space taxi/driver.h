#ifndef DRIVER_H
#define DRIVER_H

#include "user.h"
#include "spaceship.h"
#include "trip.h"
#include <iostream>

class Driver:public User
{
public:
	Driver(std::string _user_name,std::string _password,std::string _spaceship_number,
	std::string _spaceship_model,
	std::string _production_year,
	std::string _color):User(_user_name,_password,"driver"){
		score=0;
		status="unavailable";
		is_accepted=false;
		model="driver";
		//server:
		//check username in usernames
		//check spaceship number in numbers
		//check validation of spaceship model (from vehicles.cfg)
		spaceship=new Spaceship(_spaceship_number,_spaceship_model,_production_year,_color);
	};
	std::string get_spaceship_number(){return spaceship->get_number();}
	void add_trip(Trip* new_trip){trips.push_back(new_trip);}
	void show_requests();
	std::string get_model(){return model;}
	int get_score(){return score;}
	void erase_request(Trip* _trip);
	bool find_trip(Trip* _trip); 
	virtual void show_information();
	//std::string get_status(){return status;}
	//void set_status(std::string _status){status=_status;}
	//~Driver();
	//show trip requests
	//accept trip requst
	//show arrived signal
	//show end trip signal
protected:
	//std::string status;
	std::string model;
	std::vector<Trip*> trips;
	int score;
	Spaceship* spaceship;
};

#endif