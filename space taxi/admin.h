#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin:public User
{
public:
	Admin(std::string _user_name,std::string _password):User(_user_name,_password,"admin"){};
	//~Admin();
	//set time
	
};

#endif