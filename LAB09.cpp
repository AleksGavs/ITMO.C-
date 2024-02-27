#include <String>
#include <iostream>
#include "Triangle.h"
#include "Time.h"

using namespace std;

class DivideByZeroError
{
public:
	DivideByZeroError() : message("������� �� ����") { }
	void printMessage() const { cout << message << endl; }
private:
	string message;
};

float quotient(int numl, int num2)
{
	if (num2 == 0)
		throw DivideByZeroError();
	return (float)numl / num2;
}

int L09E01()
{
	cout << "������� ��� ����� ����� ��� ������� �� ��������:\n";
	int number1, number2;
	cin >> number1;
	cin >> number2;
	try
	{
		float result = quotient(number1, number2);
		cout << "������� ����� " << result << endl;
	}
	catch (DivideByZeroError& error)

	{
		cout << "������: ";
		error.printMessage();
		return 1; // ���������� ��������� ��� ������
	}
}

int L09E02()
{
	cout << "������� �������:\n";
	int number1;
	cin >> number1;
	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "������� ����� " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "������: ";
			error.printMessage();
		}
	}
	return 1; // ���������� ��������� ��� ������
}

void L09K01()
{
	int a, b, c;

	cin >> a >> b >> c;

	Triangle tr = Triangle(a, b, c);

	cout << "������� ������������ �����: " << tr.CalculateSquare();
}

void L09K02()
{
	string noon = "�������";

	Time check = Time(noon);
	check.ShowTime();

	Time check2 = Time("�������� �������");
	check2.ShowTime();
}

