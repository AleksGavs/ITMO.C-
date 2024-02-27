#pragma once
#include <string>
#include <iostream>

using namespace std;
class Triangle
{
public:

	void set_firstSide(int);
	void set_secondSide(int);
	void set_thirdSide(int);
	int get_firstSide();
	int get_secondSide();
	int get_thirdSide();

	Triangle(int, int, int);
	

	double CalculateSquare();
	


private:
	int firstSide;
	int secondSide;
	int thirdSide;
};

