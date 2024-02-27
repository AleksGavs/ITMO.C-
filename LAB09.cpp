#include <String>
#include <iostream>
#include "Triangle.h"
#include "Time.h"

using namespace std;

class DivideByZeroError
{
public:
	DivideByZeroError() : message("Деление на нуль") { }
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
	cout << "Введите два целых числа для расчета их частного:\n";
	int number1, number2;
	cin >> number1;
	cin >> number2;
	try
	{
		float result = quotient(number1, number2);
		cout << "Частное равно " << result << endl;
	}
	catch (DivideByZeroError& error)

	{
		cout << "ОШИБКА: ";
		error.printMessage();
		return 1; // завершение программы при ошибке
	}
}

int L09E02()
{
	cout << "Введите делимое:\n";
	int number1;
	cin >> number1;
	for (int i = -10; i < 10; i++)
	{
		try
		{
			float result = quotient(number1, i);
			cout << "Частное равно " << result << endl;
		}
		catch (DivideByZeroError& error)
		{
			cout << "ОШИБКА: ";
			error.printMessage();
		}
	}
	return 1; // завершение программы при ошибке
}

void L09K01()
{
	int a, b, c;

	cin >> a >> b >> c;

	Triangle tr = Triangle(a, b, c);

	cout << "Площадь треугольника равна: " << tr.CalculateSquare();
}

void L09K02()
{
	string noon = "Полдень";

	Time check = Time(noon);
	check.ShowTime();

	Time check2 = Time("Половина первого");
	check2.ShowTime();
}

