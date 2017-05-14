#include "code.h"

using namespace std;

Code::Code(string _code,Passenger* _owner){
	code=_code;
	owner=_owner;
}
void Code::use_code(){
	//cout<<owner->get_credit()+10<<endl;
	owner->set_credit(owner->get_credit()+10);
	counter--;
}