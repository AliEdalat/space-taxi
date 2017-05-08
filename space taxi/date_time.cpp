#include "date_time.h"

using namespace std;

Date_time::Date_time(string _date_time){
	date_time=_date_time;
}
int Date_time::convert_to_seconds(){
	string temp = date_time;
	std::vector<string> parameters;
	int find_dash=temp.find('-');
	parameters.push_back(temp.substr(0,find_dash));
	temp=temp.substr(find_dash+1);
	while(temp.find(':') != -1){
		parameters.push_back(temp.substr(0,temp.find(':')));
		temp=temp.substr(temp.find(':')+1);
	}
	parameters.push_back(temp);
	int result=(stoi(parameters[0])*24*360)+(stoi(parameters[1])*360)+(stoi(parameters[2])*60)+stoi(parameters[3]);
	return result;
}
string convert_to_string_seconds(int gap){
	int mod_day=gap%(360*24);
	int day=gap/(360*24);
	int mod_hour=mod_day%360;
	int hour=mod_day/360;
	int second=mod_hour%60;
	int minute=mod_hour/60;
	string result=to_string(day)+"-"+to_string(hour)+":"+to_string(minute)+":"+to_string(second);
	cout<<result<<endl;
	return result;
}
string Date_time::different_of_times(Date_time* time2){
	int seconds_of_time1=this->convert_to_seconds();
	int seconds_of_time2=time2->convert_to_seconds();
	int gap=seconds_of_time2 - seconds_of_time1;
	return convert_to_string_seconds(gap);
}
string Date_time::add_time(Date_time* time2){
	int seconds_of_time1=this->convert_to_seconds();
	int seconds_of_time2=time2->convert_to_seconds();
	int gap=seconds_of_time2 + seconds_of_time1;
	return convert_to_string_seconds(gap);	
}