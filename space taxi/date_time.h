#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>

class Date_time
{
public:
	Date_time(std::string _date_time);
	~Date_time();
private:
	std::string date_time;
	
};

#endif