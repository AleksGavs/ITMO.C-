#include "Distance.h"
#include "Header.h"
#include "GradeMap.h"
#include "Time.h"
#include "Point.h"
#include <String>
#include <iostream>
#include <algorithm>

using namespace std;

void L11E01()
{
	Distance dist1, dist2;

	dist1.getdist();
	dist2.getdist();
	Distance dist3 = dist1 + dist2;
	Distance dist4 = dist3 + dist1 + dist2;


	dist1.showdist();
	dist2.showdist();
	dist3.showdist();
	dist4.showdist();

	Distance dist5 = dist4 - dist3;
	cout << dist5;
}

void L11E02()
{
	Distance distInMeters = 10.0F;
	distInMeters.showdist();
}

void L11E03()
{
	Distance dist1(50, 5);
	Distance res1 = 10.0f + dist1;
	res1.showdist();
	Distance res2 = dist1 - 10.0f;
	res2.showdist();
	Distance res3 = dist1 + 10.0f;
	res3.showdist();
	Distance res4 = 100 - dist1;
	res4.showdist();
}

void L11E04()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	cout << "John has a grade of " << grades["John"] << endl;
	cout << "Martin has a grade of " << grades["Martin"] << endl;
	cout << "New name and grade?" << endl;
	string name;
	char grade;
	cin >> name >> grade;
	grades[name] = grade;
	std::cout << name << " has a grade of " << grades[name] << endl;
}

void L11K01()
{
	Time t1(17, 25, 46);
	Time t2(10, 38, 51);
	Time t3(23, 55, 11);
	int timeInSecs1 = 11233;

	Time t4 = t1 + t2;
	t4.ShowTime();
	Time t5 = t3 + t2;
	t5.ShowTime();
	Time t6 = t1 - t2;
	t6.ShowTime();
	Time t7 = t2 - t3;
	t7.ShowTime();
	Time t8 = t1 - timeInSecs1;
	t8.ShowTime();
	Time t9 = t1 + timeInSecs1;
	t9.ShowTime();
	Time t10 = timeInSecs1 - t3;
	t10.ShowTime();
	Time t11 = timeInSecs1 + t2;
	t11.ShowTime();
	bool nTrue = t1 < t2;
	bool yTrue = t1 > t2;
	bool nTrue2 = t1 == t2;
	Time checkEq(17, 25, 46);
	bool yTrue2 = checkEq >= t1;
	cout << nTrue << "   " << yTrue << "   " << nTrue2 << "   " << yTrue2;
}

void L11K02()
{
	std::vector<Point> v;
	v.push_back(Point(1.0, 2.0));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для
	// класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для 
	// класса Point
}