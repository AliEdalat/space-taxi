#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
#include <iostream>
#include <vector>

class Date_time
{
public:
	Date_time(std::string _date_time);
	std::string get_date_time(){return date_time;}
	std::string different_of_times(Date_time* time2);
	std::string add_time(Date_time* time2);
	int convert_to_seconds();
	//~Date_time();
private:
	std::string date_time;
	
};

#endif