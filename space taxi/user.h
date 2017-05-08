#ifndef USER_H
#define USER_H

#include "address.h"
#include "date_time.h"
#include <string>

class User
{
public:
	User(std::string _user_name,std::string _password,std::string _type,Date_time* _birth_date);
	std::string get_username(){return user_name;}
	std::string get_password(){return password;}
	int get_credit(){return credit;}
	std::string get_type(){return type;}
	void set_credit(int _credit){credit=_credit;}
	bool get_is_login(){return is_login;}
	void login(){is_login=true;}
	void logout(){is_login=false;}
	bool get_is_accepted(){return is_accepted;}
	void set_is_accepted(bool _is_accepted){is_accepted=_is_accepted;}
	std::string get_status(){return status;}
	void set_status(std::string _status){status=_status;}
	std::string get_address_galaxy(){return address->get_galaxy();}
	std::string get_address_planet(){return address->get_planet();}
	void set_address(Address* _address){address=_address;}
	Address* get_address(){return address;}
	bool rate_all_trips(){};
	Date_time* get_birth_time(){return birth_date;}
	//check username in usernames
	//~User();
protected:
	std::string type;
	std::string status;
	std::string user_name;
	std::string password;
	int credit;
	bool is_login;
	bool is_accepted;
	Address* address;
	Date_time* birth_date;
};

#endif