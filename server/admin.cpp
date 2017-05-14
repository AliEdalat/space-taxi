#include "admin.h"
#include "date_time.h"

using namespace std;

void Admin::set_date_time(Date_time* new_date_time){
	birth_date=new_date_time;
}