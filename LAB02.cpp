#include "Header.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

void L02E01T01()
{	
	double x, y;
	cout << "������� ����� ������ ���������� �����: \n";
	cin >> x;
	cin >> y;
	if (x * x + y * y < 9 && y > 0)
		cout << "����� ��������� ������";
	else if (x * x + y * y > 9 || y < 0)
		cout << "����� ��������� �������";
	else
		cout << "����� ��������� �� �������";
}

void L02E01T02()
{
	char op;
	cout << "������ ���� �����, ������ ���� ���� �����: ";
	cin >> op;	
	switch (op)
	{
	case 'V':
		cout << "����������� ����\n";
		
	case 'S':
		cout << "����� ������ ������\n";
	default:
		cout << "������ �������\n";
		cout << "������ ���������\n";
	}

}

void L02E02T01()
{
	double x, x1, x2, y;
	cout << "x1 = "; 
	cin >> x1;
	cout << "x2 = "; 
	cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);
}

void L02E02T02()
{
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << "��� = " << a << endl;
}

void L02E02T03_1()
{
	double x, x1, x2, y;
	cout << "x1 = ";
	cin >> x1;
	cout << "x2 = ";
	cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	while (x <= x2)
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	}
}

void L02E02T03_2()
{
	double x, x1, x2, y;
	cout << "x1 = ";
	cin >> x1;
	cout << "x2 = ";
	cin >> x2;
	cout << "\tx\tsin(x)\n";
	x = x1;
	do
	{
		y = sin(x);
		cout << "\t" << x << "\t" << y << endl;
		x = x + 0.01;
	} while (x <= x2);
}
void L02E03()
{
	srand(time(NULL));
	int a, b, c;
	int k = 0, n = 10;
	for (int i = 1; i <= n; i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		if (a * b != c)
		{
			k++;
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
	}

	cout << "Count error: " << k << endl;
}

void L02E04()
{
	int k, m, s = 0;
	cout << "������� ������ ����� � ������� �����: ";
	cin >> k;
	cin >> m;
	for (int i = 1; i <= 100; i++)
	{
		if ((i >= k) && (i <= m))
			continue;
		s += i;
	}
	cout << s;
}

void L02K01()
{
	cout << 1 << "\n";
	for (int i = 1; i < 96; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i == j)
				cout << i << "\n";
			else if (i % j != 0)
				continue;
			else if (i % j == 0)
				break;
		}
	}
}

bool L02K02()
{
	string s = "";
	string temp;

	cout << "������� �����:\n";
	cin >> s;
	int strlength = s.length();
	temp += s[s.length() - 2];
	temp += s[s.length() - 1];
	int controlNum = stoi(temp);
	int controlSum = 0;
	temp = "";

	if (strlength != 11)
	{
		cout << "�������� ����� ������\n";
		return false;
	}

	for (int i = 0; i < strlength - 4; i++)
	{
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
		{
			cout << "�������� �����\n";
			return false;
		}
	}

	int k = 1;
	for (int i = strlength - 3; i >= 0; i--)
	{
		int num = stoi(temp += s[i]);
		num *= k;
		k++;
		temp = "";
		controlSum += num;
	}

	if (controlSum == 100 || controlSum == 101)
	{
		controlSum = 0;
	}
	else if (controlSum > 101)
	{
		controlSum %= 101;
		if (controlSum == 100)
		{
			controlSum = 0;
		}
	}

	if (controlSum != controlNum)
	{
		cout << "�������� ����������� �����\n";
		return false;
	}
	else
	{
		cout << "����� ����� ������!\n";
		return true;
	}
}

void L02K03()
{
	int rubAmount = 0;
	int kopAmount = 0;
	int tenRubles, fiveRubles, twoRubles, oneRuble = 0;
	int fiftyKops, tenkops, fiveKops, oneKop = 0;
	
	cout << "������� ���������� ������: ";
	cin >> rubAmount;
	tenRubles = rubAmount / 10; rubAmount %= 10;
	fiveRubles = rubAmount / 5; rubAmount %= 5;
	twoRubles = rubAmount / 2; rubAmount %= 2;
	oneRuble = oneRuble;

	cout << "������� ���������� ������: ";
	cin >> kopAmount;
	fiftyKops = kopAmount / 50; kopAmount %= 50;
	tenkops = kopAmount / 10; kopAmount %= 10;
	fiveKops = kopAmount / 5; kopAmount %= 5;
	oneKop = kopAmount;
	
	cout << "���������� 10-������� �����: " << tenRubles << " ��. ���������� 5-������� �����: " << fiveRubles << " ��. ���������� 2-������� �����: "
		<< twoRubles << " ��. ���������� 1-������� �����: " << oneRuble << " ��." << endl;
	cout << "���������� 50-��������� �����: " << fiftyKops << " ��. ���������� 10-��������� �����: " << tenkops << " ��. ���������� 5-��������� �����: "
		<< fiveKops << " ��. ���������� 1-��������� �����: " << oneKop << " ��." << endl;
}

void L02K04()
{
	float centerOfAimX = (float)(rand() % 8 + 4);
	float centerOfAimY = (float)(rand() % 8 + 4);
	float radius = 4.0f;


	int maxField = 16;
	int res = 0;



	cout << "� ���� " << maxField << " �� " << maxField << " ��.���������� ������ ��������� " << radius <<
		" c�.\n��� ����� ���������� ������� ��� ��������.\n��� ����� ������� ���������� �����, � ������� ����� ���������� �������.\n" <<
		"��� ��������� �� ���������� ������ (������� " << radius / 2 << " ��.), ������ ������������� 3 ����, \n��� ��������� �� ������� - 2 ����, ��� ������� 1 ����.\n" <<
		"����� ������� ��������, ����� ������� ���������, ����� ����� ��� ��������������� ���� ��������� �������.\n�����!";

	for (int i = 0; i < 3; i++)
	{
		bool inCenter = false;

		cout << "\n������� � ���������� �������� �� 0 �� " << maxField << endl;
		float xCoor = 0;
		cin >> xCoor;
		cout << "\n������� Y ���������� �������� �� 0 �� " << maxField << endl;
		float yCoor = 0;
		cin >> yCoor;

		if ((pow((xCoor - centerOfAimX), 2) + pow((yCoor - centerOfAimY), 2)) <= pow(radius / 2, 2))
		{
			inCenter = true;
			cout << "\n� �������! ��������� 3 ����!";
			res += 3;
		}
		else if ((pow((xCoor - centerOfAimX), 2) + pow((yCoor - centerOfAimY), 2)) <= pow(radius, 2) && !inCenter)
		{
			cout << "\n������ ��������! ��������� 2 ����!";
			res += 2;
		}
		else
		{
			cout << "\n���� :-( �� 1 ���� ���������!";
			res += 1;
		}
	}
	cout << "\n�����������! ��� ���������: " << res << "!" << endl;
}