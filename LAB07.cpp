#include "Header.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct Distance
{
	int feet;
	double inches;

	void ShowDist()
	{
		cout << feet << "\'-" << inches << "\"\n";
	}

};


//Distance AddDist(Distance d1, Distance d2)
//{
//	Distance d;
//	d.feet = d1.feet + d2.feet;
//	d.inches = d1.inches + d2.inches;
//	if (d.inches >= 12.0)
//	{
//		d.inches -= 12.0;
//		d.feet++;
//	}
//	return d;
//}

Distance AddDist(const Distance& d1, const Distance& d2)
{
	Distance d;
	d.feet = d1.feet + d2.feet;
	d.inches = d1.inches + d2.inches;
	if (d.inches >= 12.0)
	{
		d.inches -= 12.0;
		d.feet++;
	}
	return d;
}

Distance InputDist()
{
	Distance d;
	cout << "\nВведите число футов: ";
	cin >> d.feet;
	cout << "Введите число дюймов: ";
	cin >> d.inches;
	return d;
}

//void ShowDist(Distance d)
//{
//	cout << d.feet << "\'-" << d.inches << "\"\n";
//}


void L07E01()
{
	Distance d1 = InputDist();
	Distance d2 = { 1, 6.25 };
	Distance d3 = AddDist(d1, d2);

	/*ShowDist(d1);
	ShowDist(d2);
	ShowDist(d3);*/
	d1.ShowDist();
}


void L07E02()
{
	int n;
	cout << "Введите размер массива расстояний ";
	cin >> n;

	Distance* masDist = new Distance[n];

	for (int i = 0; i < n; i++)
	{
		masDist[i] = InputDist();
	}

	for (int i = 0; i < n; i++)
	{
		masDist[i].ShowDist();
	}

	double sumInches = 0;
	double sumFeet = 0;

	for (int i = 0; i < n; i++)
	{
		sumInches += masDist[i].inches;
		sumFeet += masDist[i].feet;
	}

	sumFeet += (int)(sumInches / 12);
	sumInches -= (int)(sumInches / 12) * 12;

	Distance sum = { sumFeet, sumInches };
	sum.ShowDist();

	delete[] masDist;
}
//-------------------------------------------
using Tuple = tuple<string, int, double>;
using TupleV2 = tuple<int, char>;


void printTupleOfThree(Tuple t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
}

void printTupleOfTwo(TupleV2 t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ")" << endl;
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

Tuple customed(string s, int a, double d)
{
	s.append("!");
	a += 299;
	return make_tuple(s, a, d - 3);
}

TupleV2 changeTuple(string s, int a, double d)
{
	d = (int)d * 12;
	char ch = s[0];
	return make_tuple(d, ch);
}

void L07E05()
{
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	auto t1 = funtup(v1[1], v2[1], v3[1]);
	auto t2 = customed(v1[2], v2[2], v3[2]);
	auto t3 = changeTuple(v1[3], v2[3], v3[3]);
	printTupleOfThree(t0);
	printTupleOfThree(t1);
	printTupleOfThree(t2);
	printTupleOfTwo(t3);
}

//------------------------

struct Time
{
	int hours;
	int minutes;
	int seconds;

	void TimePrintOut()
	{
		cout << "Время: " << hours << ":" << minutes << ":" << seconds;
	}
};

void TimeSum(Time timeStart, Time timeEnd)
{
	Time res;
	res.hours = timeStart.hours + timeEnd.hours;
	res.minutes = timeStart.minutes + timeEnd.minutes;
	if (res.minutes > 59)
	{
		res.hours++;
		res.minutes %= 60;
	}
	res.seconds = timeStart.seconds + timeEnd.seconds;
	if (res.seconds > 59)
	{
		res.minutes++;
		res.seconds %= 60;
	}
	if (res.hours > 23)
	{
		res.hours -= 24;
	}
	cout << "Результат сложения промежутков: " << res.hours << ":" << res.minutes << ":" << res.seconds << endl;
}

void TimeDeduction(Time timeStart, Time timeEnd)
{
	Time res;
	if (timeEnd.seconds < timeStart.seconds)
	{
		timeEnd.seconds += 60;
		timeEnd.minutes--;
	}
	res.seconds = timeEnd.seconds - timeStart.seconds;

	if (timeEnd.minutes < timeStart.minutes)
	{
		timeEnd.minutes += 60;
		timeEnd.hours--;
	}
	res.minutes = timeEnd.minutes - timeStart.minutes;

	if (timeEnd.hours < timeStart.hours)
	{
		timeEnd.hours += 24;
	}
	res.hours = timeEnd.hours - timeStart.hours;

	cout << "Результат вычитания промежутков: " << res.hours << ":" << res.minutes << ":" << res.seconds << endl;
}

Time InputTime()
{
	Time time;
	cout << "\nВведите через пробел время (часы, минуты, секунды): ";
	cin >> time.hours >> time.minutes >> time.seconds;
	return time;
}

void L07K01()
{
	Time firstTime = InputTime();
	Time secondTime = InputTime();
	TimeSum(firstTime, secondTime);
	TimeDeduction(firstTime, secondTime);
}

struct QuadEq
{
	double firstSolution;
	double secondSolytion;

	void returnRoots(double a, double b, double c)
	{
		double d = pow(b, 2) - 4 * a * c;
		if (d > 0)
		{
			firstSolution = (-b + sqrt(d)) / (2 * a);
			secondSolytion = (-b - sqrt(d)) / (2 * a);
		}
		else if (d == 0)
		{
			firstSolution = (-b) / (2 * a);
		}
		else
		{
			cout << "Решение не имеет корней";
		}
	}
};

QuadEq Solution(double a, double b, double c)
{
	QuadEq s;
	s.returnRoots(a, b, c);
	return s;
}

void L07K02()
{
	double a, b, c;
	cout << "Введите a,b,c для решения квадратного уравнения\n";
	cin >> a >> b >> c;
	QuadEq s = Solution(a, b, c);
	cout << "Результат: x1 = " << s.firstSolution << " x2 = " << s.secondSolytion;
}

//---------------------
using QuadEqSol = tuple<double, double, bool>;

QuadEqSol returnRoots(double a, double b, double c)
{
	double d = pow(b, 2) - 4 * a * c;
	if (d > 0)
	{
		return make_tuple((-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a), true);		
	}
	else if (d == 0)
	{
		return make_tuple((-b) / (2 * a), NULL, true);		
	}
	else
	{
		return make_tuple(NULL, NULL, false);
	}
}

void printQuadEqSol(QuadEqSol t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
}

void L07K03()
{
	double a, b, c;
	cout << "Введите a,b,c для решения квадратного уравнения\n";
	cin >> a >> b >> c;
	QuadEqSol s = returnRoots(a, b, c);
	printQuadEqSol(s);
}