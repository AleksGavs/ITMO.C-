#include <iostream>

using namespace std;


void fum_value(double k, double x, double y) //параметры
{
	x = x + k;
	y = y + k;
}
void fum_ptr(double k, double* x, double* y) //указатели
{
	*x = *x + k;
	*y = *y + k;
}
void fum_ref(double k, double& x, double& y) //ссылки
{
	x = x + k;
	y = y + k;
}

void print(double x, double y)
{
	cout << "x = " << x << "; y = " << y << endl;
}

void L04E01()
{
	double k = 2.5;
	double xv = 10;
	double yv = 10;
	print(xv, yv);
	fum_value(k, xv, yv); // Передача в функцию обычного параметра 
	print(xv, yv);
	fum_ptr(k, &xv, &yv); // Передача в функцию параметра указателя 
	print(xv, yv);
	fum_ref(k, xv, yv); // Передача в функцию параметра ссылки 
	print(xv, yv);
}

//--------------------------------------------------------------------

void swap(int*, int*);
void swap(int&, int&);

void L04E02()
{
	int x = 5, y = 10;
	cout << "x = " << x << ", y = " << y << endl;
	swap(&x, &y);
	cout << "x = " << x << ", y = " << y << endl;
	swap(x, y);
	cout << "x = " << x << ", y = " << y << endl;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
//-------------------------------------
int Myroot(double a, double b, double c, double& res1, double& res2)
{
	double d = pow(b, 2) - 4 * a * c;
	if (d > 0)
	{
		res1 = (-b + sqrt(d)) / (2 * a);
		res2 = (-b - sqrt(d)) / (2 * a);
		return 1;
	}
	else if (d == 0)
	{
		res1 = (-b) / (2 * a);
		return 0;
	}
	else
	{
		return -1;
	}
}

void LAB04K1()
{
	double a, b, c, res1, res2;
	cin >> a >> b >> c;
	if (Myroot(a, b, c, res1, res2) == 1)
	{
		cout << "Корни уравнения найдены. Первый корень равен " << res1 << ", второй корень равен " << res2 << "." << endl;
	}
	else if (Myroot(a, b, c, res1, res2) == 0)
	{
		cout << "Уравнение имеет единственный корень равный " << res1 << "." << endl;
	}
	else
	{
		cout << "Уравнение не имеет корней." << endl;
	}
}

//-----------------------------------------------
bool Input(int& a, int& b)
{
	cin >> a >> b;
	if ((a >= -100 && a <= 100) && a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LAB04K2()
{
	int a, b;
	if (Input(a, b) == false) // if(!Input(a,b))
	{
		cerr << "error";		
	}
	int s = a + b;
}