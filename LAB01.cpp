#include "Header.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void L01E01()
{
	string name;
	cout << "What is your name? ";
	//cin >> name;
	getline(cin, name);
	cout << "Hello, " << name << "!\n";
}

void L01E02()
{	
	cout.precision(3);
	double a, b;
	string name;
	cout << "������� ���� ���:\n";
	cout << "������� a � b:\n";
	cin >> a;
	cin >> name;
	cin >> b;
	double x = a / b;
	cout << "\nx = " << x << endl;
	cout << "������, " << name << "!\n";
	cout << "Size of a/b = " << sizeof(a / b) << ends << " Size of x = " << sizeof(x) << endl;	
}

void L01E03()
{		
	double perimenter;
	cout << "������� �������� ������������: \n";
	cin >> perimenter;
	double side = perimenter / 3;
	double halfPerimeter = perimenter / 2;
	double square = sqrt(halfPerimeter * pow(halfPerimeter - side, 3));
	cout << left << setw(15) << "�������: " << left << setw(15) << "�������: " << endl;
	cout << left << setw(15) << perimenter / 3 << left << setw(15) << setprecision(2) << square << endl;	
}

void L01K01()
{
	double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
	cout << "������� ����� ������ ���������� ������ ����� �������������: \n";
	cin >> x1;
	cin >> y1;
	cout << "������� ����� ������ ���������� ������ ����� �������������: \n";
	cin >> x2;
	cin >> y2;
	cout << "������� ����� ������ ���������� ������� ����� �������������: \n";
	cin >> x3;
	cin >> y3;
	cout << "������� ����� ������ ���������� �������� ����� �������������: \n";
	cin >> x4;
	cin >> y4;
	cout << "������� ����� ������ ���������� ����� ����� �������������: \n";
	cin >> x5;
	cin >> y5;
	double square = 0.5 * (x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5);
	cout << "������� ������������� �����: " << square << endl;
}