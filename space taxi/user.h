#ifndef USER_H
#define USER_H

#include "address.h"
#include <string>

class User
{
public:
	User(std::string _user_name,std::string _password,std::string _type);
	std::string get_username(){return user_name;}
	int get_credit(){return credit;}
	std::string get_type(){return type;}
	void set_credit(int _credit){credit=_credit;}
	bool get_is_login(){return is_login;}
	void login(){is_login=true;}
	void logout(){is_login=false;}
	bool get_is_accepted(){return is_accepted;}
	void set_is_accepted(bool _is_accepted){is_accepted=_is_accepted;}
	//check username in usernames
	//~User();
protected:
	std::string type;
	std::string user_name;
	std::string password;
	int credit;
	bool is_login;
	bool is_accepted;
	Address* address;
};

#endif