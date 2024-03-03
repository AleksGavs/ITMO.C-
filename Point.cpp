#include <iostream>
#include "Point.h"
using namespace std;

Point::Point()
{
	x = 0.0, 
	y = 0.0;
}

Point::Point(double x, double y)
{
	x = 0.0,
	y = 0.0;
}

double Point::distanceToOrigin() const
{
    return sqrt(x * x + y * y);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

bool Point::operator<(const Point& other) const
{
    return this->distanceToOrigin() < other.distanceToOrigin();
}