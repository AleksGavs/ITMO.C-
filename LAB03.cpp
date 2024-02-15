#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 

using namespace std;

void privet(string name);
void privet(string name, int num);
string privet2(string name);
long double firBinSearch(double a, int n);
int addNumdersRecursion(int n);
int addNumdersRecursion(int n, int k);
int gcd(int m, int n);
double triangleSqr(double a);
double triangleSqr(double a, double b, double c);
double cubeSqrt(double a);
int multipleFiveSum(int n);
string binaryCodeReversed(int a, string res);

void L03E01T01()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);
}

void L03E01T02()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	string nameOut = privet2(name);
	cout << nameOut;
}

void L03E02()
{
	string name;
	int k;
	cout << "What is your name?" << endl;
	cin >> name;
	cout << "Enter number: " << endl;
	cin >> k;
	privet(name, k);
}

void L03E03()
{
	double num;
	int sqr;
	cout << "������� ����� ������ ����� �� 1 �� 1000 � ��������� �� 6 ������: ";
	cin >> num;
	cout << "������� ����� ������ ����� �� 1 �� 10 - ��� ������� ����� ��� ���������� �����: ";
	cin >> sqr;
	cout << "���������: " << firBinSearch(num, sqr);
}

void L03E04T01()
{
	int num = 0;
	int num2 = 0;
	cout << "������� ������ �������: ";
	cin >> num;
	cout << "������� ������� �������: ";
	cin >> num2;
	cout << addNumdersRecursion(num, num2);
}

void L03E04T02()
{
	int num = 0;
	int num2 = 0;
	cout << "������� 1� �����: ";
	cin >> num;
	cout << "������� 2� �����: ";
	cin >> num2;
	cout << gcd(num, num2);
}

bool L03K01()
{
	string s = "";
	string temp;

	cout << "������� �����:\n";
	getline(cin, s);
	s.erase(remove(s.begin(), s.end(), '-'), s.end());	
	int strlength = s.length();
	temp += s[s.length() - 2];
	temp += s[s.length() - 1];
	int controlNum = stoi(temp);
	int controlSum = 0;
	temp = "";

	for (int i = 0; i < strlength; i++)
	{
		if (!isdigit(s[i]))
		{
			cout << "����� �� ����� ��������� ����!";
			return false;
		}
	}

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

void L03K02()
{
	double a;
	cout << "������� �����, ������ �� �������� ���������� �������:\n";
	cin >> a;
	cout << "��������� ������� ��������: " << pow(a, 1.0 / 3) << endl;
	cout << "��������� ������� ��������: " << cubeSqrt(a) << endl;
}

void L03K03()
{
	cout << "�������� ��� ������������:\n�������������� - ������� 1, �������������� - ������� 2\n";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		double a;
		cout << "������� ������� ������������:\n" << endl;
		cin >> a;
		cout << "������� ������������� ����� " << triangleSqr(a);
	}
	else if (choice == 2)
	{
		double a, b, c;
		cout << "������� ������� ������������ ����� ������:\n" << endl;
		cin >> a >> b >> c;
		cout << "������� ������������� ����� " << triangleSqr(a, b, c);
	}
	else
	{
		cout << "����� ����� �� ���������";
	}
}

void L03K04()
{
	cout << "������� �����: " << endl;
	int a;
	cin >> a;
	cout << "���������: " << multipleFiveSum(a);
}

void L03K05()
{
	cout << "������� �����:\n";
	int a;
	cin >> a;
	string res = "";
	res = binaryCodeReversed(a, res);
	reverse(res.begin(), res.end());
	cout << "���������: " << res;
}

void privet(string name)
{
	cout << name << ", " << "hello!" << endl;
}

void privet(string name, int k)
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}

string privet2(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}

long double firBinSearch(double a, int n)
{
	double L = 0;
	double R = a;
	while (R - L > 1e-10)
	{
		double M = (L + R) / 2;
		if (pow(M, n) < a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	return R;
}

int addNumdersRecursion(int n)
{
	if (n == 1) return 1; // ����� �� ��������
	else return (n + addNumdersRecursion(n - 1));
}

int addNumdersRecursion(int n, int k)
{
	if (n == k) return n; // ����� �� ��������
	else return (k + addNumdersRecursion(n, k-1));
}

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m % n);
}

double triangleSqr(double a)
{
	return (pow(a, 2) * sqrt(3)) / 4;
}

double triangleSqr(double a, double b, double c)
{
	double halfPerimeter = (a + b + c) / 2;
	return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b)* (halfPerimeter - c));
}

double cubeSqrt(double a)
{
	double res = 1;
	double temp = 0;
	double z = 1;

	while (z > 0.00001)
	{
		temp = 1.0 / 3 * (a / (res * res) + 2 * res);
		z = abs (temp - res);
		res = temp;
	}
	return res;
}

int multipleFiveSum(int n)
{
	if (n == 1) return 0; 
	else return (5*n + multipleFiveSum(n - 1));
}

string binaryCodeReversed(int a, string res)
{	
	
	if (a == 0) return res;
	else
	{
		int temp = a % 2;
		res += to_string(temp);
		return binaryCodeReversed(a / 2, res);
	}
}