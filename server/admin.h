#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "date_time.h"

class Admin:public User
{
public:
	Admin(std::string _user_name,std::string _password,Date_time* birth_date):User(_user_name,_password,"admin",birth_date){};
	void set_date_time(Date_time* new_date_time);
	
};

#endif