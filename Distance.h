#pragma once
#include <iostream>


class Distance
{
private:
	int feet;
	float inches;
	const float MTF = 3.280833F;
public:
	
	Distance(); 
	Distance(int ft, float in);
	void getdist();
	void showdist();
	Distance operator+ (const Distance&) const;
	Distance operator- (const Distance&) const;
	Distance operator+ (float val) const;
	Distance operator- (float val) const;
	friend std::ostream& operator<< (std::ostream& out, const Distance& dist);
	

	Distance(float meters);
	operator float() const;
};


