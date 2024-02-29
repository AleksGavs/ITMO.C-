#include <string>
#include "TriangleComp.h"
#include "Dot.h"
#include <iomanip>

TriangleComp::TriangleComp(Dot d1, Dot d2, Dot d3)
{
	set_dot1(d1);
	set_dot2(d2);
	set_dot3(d3);
}
void TriangleComp::set_dot1(Dot d)
{
	TriangleComp::dot1 = d;
}
void TriangleComp::set_dot2(Dot d)
{
	TriangleComp::dot2 = d;
}
void TriangleComp::set_dot3(Dot d)
{
	TriangleComp::dot3 = d;
}

double TriangleComp::Perimeter()
{
	double side1 = dot1.distanceTo(dot2);
	double side2 = dot2.distanceTo(dot3);
	double side3 = dot3.distanceTo(dot1);
	return side1 + side2 + side3;
}
double TriangleComp::Square()
{
	double side1 = dot1.distanceTo(dot2);
	double side2 = dot2.distanceTo(dot3);
	double side3 = dot3.distanceTo(dot1);
	
	double s = (side1 + side2 + side3) / 2;
	
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
void TriangleComp::printSides()
{
	cout << dot1.distanceTo(dot2) << "---" << dot2.distanceTo(dot3) << "---" << dot3.distanceTo(dot1);
}
