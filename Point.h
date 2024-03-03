#pragma once
#include <iostream>
#include <cmath>

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);
    double distanceToOrigin() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    bool operator<(const Point& other) const;

};

