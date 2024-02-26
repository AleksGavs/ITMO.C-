#include "Header.h"

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

int L06E01()
{
	double sum = 0;
	int const n = 100;
	double nums[n];

	for (int i = 0; i < n; i++)
	{
		nums[i] = (rand() % 100);
	}

	ofstream out("testFile", ios::out | ios::binary);
	if (!out) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}
	out.write((char*)nums, sizeof(nums));
	out.close();

	ifstream in("testFile", ios::in | ios::binary);
	if (!in) {
		cout << "Файл открыть невозможно";
		return 1;
	}
	in.read((char*)&nums, sizeof(nums));

	int k = sizeof(nums) / sizeof(double);
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
		cout << nums[i] << ' ';
	}
	cout << "\nsum = " << sum << endl;

	in.close();
}

void L06K01()
{

	fstream f;
	f.open("file.txt", ios::out);
	if (f)
	{
		string str;
		string stop = "ВСЁ!";
		cout << "Запишите стихотворение. Для окончания ввода, введите \"ВСЁ!\"" << endl;
		while (true)
		{
			getline(cin, str);
			if (str == stop)
			{
				break;
			}
			f << str << endl;
		}
		f.close();

		f.open("poem.txt", ios::in);
		if (f)
		{
			while (getline(f, str))
				cout << str << endl;

			f.close();
		}
		else
			cout << "Файл открыть невозможно" << endl;
	}
	else
		cout << "Файл открыть невозможно" << endl;

	cin.get();
}

void LAB06K02()
{
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями

	fstream f;
	f.open("array.txt", ios::out);
	if (f)
	{
		for (int i = 0; i < N; i++)
		{
			f << a[i] << " ";
		}
		f << endl;
	}
	else
		cout << "Файл открыть невозможно" << endl;

	for (int i = 0; i < N; i++)
	{
		min = i; // номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		// перестановка этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	for (int i : a)
		cout << i << '\t';

	//f.open("array.txt", ios::out);
	if (f)
	{
		for (int i = 0; i < N; i++)
		{
			f << a[i] << " ";
		}
		f << endl;
	}
	else
		cout << "Файл открыть невозможно" << endl;
	f.close();
}
