#include "user.h"

using namespace std;

User::User(string _user_name,string _password,string _type,Date_time* _birth_date){
	user_name=_user_name;
	password=_password;
	type=_type;
	birth_date=_birth_date;
	credit=0;
	is_login=true;
	is_accepted=false;
	address=new Address("1","1");
}
User::~User(){
	delete birth_date;
	delete address;
}