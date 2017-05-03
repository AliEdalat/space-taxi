#include "user.h"

using namespace std;

User::User(string _user_name,string _password,string _type){
	user_name=_user_name;
	password=_password;
	type=_type;
	credit=0;
	is_login=true;
	is_accepted=false;
}