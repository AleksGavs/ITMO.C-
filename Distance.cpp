#include <iostream>
#include "Distance.h"
using namespace std;

Distance::Distance()
{
	feet = 0; inches = 0; 
}
Distance::Distance(int ft, float in)
{
	feet = ft; inches = in; 
}

void Distance::getdist()
{
	cout << "\n¬ведите число футов : ";
	cin >> Distance::feet;
	cout << "\n¬ведите число дюймов : ";
	cin >> Distance::inches;
}
void Distance::showdist()
{
		cout << feet << "\' - " << inches << "\"\n";
}Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}Distance Distance::operator- (const Distance& d2) const
{
	if ((feet > d2.feet) || (feet == d2.feet && inches >= d2.inches))
	{
		int f = feet - d2.feet;
		float i = inches - d2.inches;
		if (i < 0)
		{
			i += 12.0;
			f--;
		}
		return Distance(f, i);
	}
	else return Distance();
}Distance::Distance(float meters) : MTF(3.280833F)
{
	float fltfeet = MTF * meters; // перевод в футы
	feet = int(fltfeet); // число полных футов
	inches = 12 * (fltfeet - feet); // остаток - это дюймы
}

Distance::Distance::operator float() const
{
	float fracfeet = inches / 12;
	fracfeet += static_cast<float>(feet);
	return fracfeet / MTF;
}Distance Distance::operator+ (float val) const
{
	Distance d = val;	
	return *this + d;
}

Distance operator+(float val, const Distance& d)
{
	return d + val;
}


Distance Distance::operator- (float val) const
{
	Distance d = val;
	if ((feet > d.feet) || (feet == d.feet && inches >= d.inches))
	{
		return *this - d;
	}
	else return Distance();
}

Distance operator-(float val, const Distance& d)
{
	return Distance(val) - d;
}std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\'' - " << dist.inches << "\"\n";
	return out;
}