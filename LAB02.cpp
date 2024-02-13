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
	cout << "Введите через пробел координаты точки: \n";
	cin >> x;
	cin >> y;
	if (x * x + y * y < 9 && y > 0)
		cout << "Точка находится внутри";
	else if (x * x + y * y > 9 || y < 0)
		cout << "Точка находится снаружи";
	else
		cout << "Точка находится на границе";
}

void L02E01T02()
{
	char op;
	cout << "Сделай свой выбор, собери авто свой мечты: ";
	cin >> op;	
	switch (op)
	{
	case 'V':
		cout << "Кондиционер хочу\n";
		
	case 'S':
		cout << "Радио играть должно\n";
	default:
		cout << "Колеса круглые\n";
		cout << "Мощный двигатель\n";
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
	cout << "НОД = " << a << endl;
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
	cout << "Введите нижнее число и верхнее число: ";
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

	cout << "Введите СНИЛС:\n";
	cin >> s;
	int strlength = s.length();
	temp += s[s.length() - 2];
	temp += s[s.length() - 1];
	int controlNum = stoi(temp);
	int controlSum = 0;
	temp = "";

	if (strlength != 11)
	{
		cout << "Неверная длина номера\n";
		return false;
	}

	for (int i = 0; i < strlength - 4; i++)
	{
		if (s[i] == s[i + 1] && s[i] == s[i + 2])
		{
			cout << "Неверный номер\n";
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
		cout << "Неверное контрольное число\n";
		return false;
	}
	else
	{
		cout << "Номер СНИЛС верный!\n";
		return true;
	}
}

void L02K03()
{
	int rubAmount = 0;
	int kopAmount = 0;
	int tenRubles, fiveRubles, twoRubles, oneRuble = 0;
	int fiftyKops, tenkops, fiveKops, oneKop = 0;
	
	cout << "Введите количество рублей: ";
	cin >> rubAmount;
	tenRubles = rubAmount / 10; rubAmount %= 10;
	fiveRubles = rubAmount / 5; rubAmount %= 5;
	twoRubles = rubAmount / 2; rubAmount %= 2;
	oneRuble = oneRuble;

	cout << "Введите количество копеек: ";
	cin >> kopAmount;
	fiftyKops = kopAmount / 50; kopAmount %= 50;
	tenkops = kopAmount / 10; kopAmount %= 10;
	fiveKops = kopAmount / 5; kopAmount %= 5;
	oneKop = kopAmount;
	
	cout << "Количество 10-рублёвых монет: " << tenRubles << " шт. Количество 5-рублёвых монет: " << fiveRubles << " шт. Количество 2-рублёвых монет: "
		<< twoRubles << " шт. Количество 1-рублёвых монет: " << oneRuble << " шт." << endl;
	cout << "Количество 50-копеечных монет: " << fiftyKops << " шт. Количество 10-копеечных монет: " << tenkops << " шт. Количество 5-копеечных монет: "
		<< fiveKops << " шт. Количество 1-копеечных монет: " << oneKop << " шт." << endl;
}

void L02K04()
{
	float centerOfAimX = (float)(rand() % 8 + 4);
	float centerOfAimY = (float)(rand() % 8 + 4);
	float radius = 4.0f;


	int maxField = 16;
	int res = 0;



	cout << "В поле " << maxField << " на " << maxField << " см.выставлена мишень диаметром " << radius <<
		" cм.\nВам будет необходимо сделать три выстрела.\nДля этого введите координаты точки, в которую будет осуществлён выстрел.\n" <<
		"При попадании во внутреннее кольцо (диаметр " << radius / 2 << " см.), игроку засчитывается 3 очка, \nпри попадании во внешнее - 2 очка, при промахе 1 очко.\n" <<
		"После каждого выстрела, будет показан результат, чтобы игрок мог скорректировать свой следующий выстрел.\nУдачи!";

	for (int i = 0; i < 3; i++)
	{
		bool inCenter = false;

		cout << "\nВведите Х координату выстрела от 0 до " << maxField << endl;
		float xCoor = 0;
		cin >> xCoor;
		cout << "\nВведите Y координату выстрела от 0 до " << maxField << endl;
		float yCoor = 0;
		cin >> yCoor;

		if ((pow((xCoor - centerOfAimX), 2) + pow((yCoor - centerOfAimY), 2)) <= pow(radius / 2, 2))
		{
			inCenter = true;
			cout << "\nВ яблочко! Засчитано 3 очка!";
			res += 3;
		}
		else if ((pow((xCoor - centerOfAimX), 2) + pow((yCoor - centerOfAimY), 2)) <= pow(radius, 2) && !inCenter)
		{
			cout << "\nМишень поражена! Добавляем 2 очка!";
			res += 2;
		}
		else
		{
			cout << "\nМимо :-( Но 1 очко заслужили!";
			res += 1;
		}
	}
	cout << "\nПоздравляем! Ваш результат: " << res << "!" << endl;
}