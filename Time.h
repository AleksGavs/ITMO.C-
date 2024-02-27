#pragma once
#include <string>
#include <iostream>

using namespace std;
class Time
{
public:
	
	void set_hours(int);
	void set_minutes(int);
	void set_seconds(int);
	int get_hours();
	int get_minutes();
	int get_seconds();

	Time(int, int, int);
	Time();
	Time(string);

	void ShowTime();
	Time AddTime(Time);
	
	
private:	
	int hours;
	int minutes;	
	int seconds;	
};
