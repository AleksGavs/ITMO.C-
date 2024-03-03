#include <string>
#include "Time.h"

#include <iomanip>


class WrongTimeName
{
public:
	WrongTimeName() : message("Неверное название времени") { }
	void printMessage() const { cout << message << endl; }
private:
	string message;
};

bool TimeNameExists(string timeName)
{
	if (timeName != "Полночь" && timeName != "Полдень")
	{
		throw WrongTimeName();
	}
	return true;
}

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

Time::Time(string time)
{
	try
	{
		bool exists = TimeNameExists(time);
		if (time == "Полдень")
		{
			Time::set_hours(12);
			Time::set_minutes(0);
			Time::set_seconds(0);
		}
		else 
		{
			Time::set_hours(0);
			Time::set_minutes(0);
			Time::set_seconds(0);
		}
	}
	catch (WrongTimeName& error)

	{
		cout << "ОШИБКА: ";
		error.printMessage();
	}
}

Time::Time()
{
	Time::set_hours(00);
	Time::set_minutes(00);
	Time::set_seconds(00);
}

Time Time::operator+ (const Time& t2) const
{
	int h = hours + t2.hours;
	int m = minutes + t2.minutes;
	int s = seconds + t2.seconds;
	
	return Time(h, m, s);
}

Time Time::operator- (const Time& t2) const
{
	int h = hours - t2.hours;
	int m = minutes - t2.minutes;
	int s = seconds - t2.seconds;

	if (s < 0)
	{
		s += 60; m--;
	}
	if (m < 0)
	{
		m += 60;
		h--;
	}
	if (h < 0)
	{
		h += 24;
	}
	return Time(h, m, s);
}

	Time Time::operator+ (int val) const
	{
		Time d;
		d.hours = val /60 / 60;
		d.minutes = (val / 60) % 60;
		d.seconds = val % 60;
		return *this + d;
	}

	Time operator+(int val, const Time& d)
	{
		Time t;
		t.set_hours(val / 60 / 60);
		t.set_minutes((val / 60) % 60);
		t.set_seconds(val % 60);
		return d + t;
	}


	Time Time::operator- (int val) const
	{
		Time d; 
		d.hours = val / 60 / 60;
		d.minutes = (val / 60) % 60;
		d.seconds = val % 60;
		d.ShowTime();
		return *this - d;
	}

	Time operator-(int val, const Time& d)
	{
		Time t;
		t.set_hours(val / 60 / 60);
		t.set_minutes((val / 60) % 60);
		t.set_seconds(val % 60);
				
		return t - d;
	}

	bool Time::operator< (const Time& t2) const
	{
		if (hours != t2.hours)
			return hours < t2.hours;
		if (minutes != t2.minutes)
			return minutes < t2.minutes;
		return seconds < t2.seconds;
	}

	bool Time::operator> (const Time& t2) const
	{
		return t2 < *this;
	}

	bool Time::operator<= (const Time& t2) const
	{
		return !(t2 < *this);
	}

	bool Time::operator>= (const Time& t2) const
	{
		return !(*this < t2);
	}

	bool Time::operator== (const Time& t2) const
	{
		return hours == t2.hours && minutes == t2.minutes && seconds == t2.seconds;
	}

	bool Time::operator!= (const Time& t2) const
	{
		return !(*this == t2);
	}
	


