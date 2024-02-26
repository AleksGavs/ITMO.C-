#include <string>
#include "Time.h"

#include <iomanip>


void Time::set_hours(int hours)
{
	Time::hours = hours;
}

void Time::set_minutes(int minutes)
{
	Time::minutes = minutes;
}

void Time::set_seconds(int seconds)
{
	Time::seconds = seconds;
}

int Time::get_hours()
{
	return Time::hours;
}

int Time::get_minutes()
{
	return Time::minutes;
}

int Time::get_seconds()
{
	return Time::seconds;
}

void Time::ShowTime()
{
	cout << setfill('0') << setw(2) << Time::get_hours() << ":" << setfill('0') << setw(2) << Time::get_minutes() << ":" << setfill('0') << setw(2) << Time::get_seconds() << endl;
}

Time Time::AddTime(Time t2)
{
	int h = Time::get_hours() + t2.get_hours();
	int m = Time::get_minutes() + t2.get_minutes();
	int s = Time::get_seconds() + t2.get_seconds();
	
	if (s >= 60)
	{
		m += s / 60;
		s %= 60;
	}

	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	if (h >= 24)
	{
		h %= 24;
	}

	return Time(h, m, s);
}

Time::Time(int hours, int minutes, int seconds)
{
	if (seconds >= 60)
	{
		minutes += seconds / 60;
		seconds %= 60;		
	}

	if (minutes >= 60)
	{		
		hours += minutes / 60;
		minutes %= 60;
	}
	if (hours >= 24)
	{
		hours %= 24;
	}
	Time::set_hours(hours);
	Time::set_minutes(minutes);
	Time::set_seconds(seconds);	
	
}

Time::Time()
{
	Time::set_hours(00);
	Time::set_minutes(00);
	Time::set_seconds(00);
}


