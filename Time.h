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

	Time operator+ (const Time&) const;
	Time operator- (const Time&) const;
	Time operator+ (int val) const;
	Time operator- (int val) const;	
	friend Time operator- (int val, const Time& d);
	friend Time operator+ (int val, const Time& d);
	bool operator< (const Time& t2) const;
	bool operator> (const Time& t2) const;
	bool operator<= (const Time& t2) const;
	bool operator>= (const Time& t2) const;
	bool operator== (const Time& t2) const;
	bool operator!= (const Time& t2) const;

	void ShowTime();
	Time AddTime(Time);
	
	
private:	
	int hours;
	int minutes;	
	int seconds;	
};
