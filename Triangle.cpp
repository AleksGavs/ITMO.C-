#include <string>
#include "Triangle.h"

#include <iomanip>

class WrongTriangle
{
public:
	WrongTriangle() : message("Такого треугольника не существует") { }
	void printMessage() const { cout << message << endl; }
private:
	string message;
};

bool TriangleExists(int a, int b, int c)
{
	if ((a + b < c) || (a + c < b) || (b + c < a))
	{		
		throw WrongTriangle();
	}		
	return true;
}

void Triangle::set_firstSide(int firstSide)
{
	Triangle::firstSide = firstSide;
}

void Triangle::set_secondSide(int secondSideide)
{
	Triangle::secondSide = secondSideide;
}

void Triangle::set_thirdSide(int thirdSide)
{
	Triangle::thirdSide = thirdSide;
}

int Triangle::get_firstSide()
{
	return Triangle::firstSide;
}

int Triangle::get_secondSide()
{
	return Triangle::secondSide;
}

int Triangle::get_thirdSide()
{
	return Triangle::thirdSide;
}

Triangle::Triangle(int firstSide, int secondSide, int thirdSide)
{
	try
	{
		bool exists = TriangleExists(firstSide, secondSide, thirdSide);
		Triangle::set_firstSide(firstSide);
		Triangle::set_secondSide(secondSide);
		Triangle::set_thirdSide(thirdSide);
	}
	catch (WrongTriangle& error)

	{
		cout << "ОШИБКА: ";
		error.printMessage();		
	}	
}

double Triangle::CalculateSquare()
{
	double halfPer = (Triangle::firstSide + Triangle::secondSide + Triangle::thirdSide) / 2;
	return sqrt(halfPer * (halfPer - Triangle::firstSide) * (halfPer - Triangle::secondSide)* (halfPer - Triangle::thirdSide));
}

