#include "Dot.h"
#include "Student.h"
#include "TriangleAggr.h"
#include "TriangleComp.h"
#include "Header.h"
#include <String>
#include <iostream>

void L10E1()
{

	IdCard idc(123, "Базовый");
	string name;
	string last_name;
	cout << "Name: ";
	getline(std::cin, name);
	cout << "Last name: ";
	getline(std::cin, last_name);

	int scores[5];

	int sum = 0;;

	Student* student02 = new Student(name, last_name, &idc);

	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}
}

void L10K01()
{
	Dot d1(-1, -1);
	Dot d2(1, 1);
	Dot d3(-1, 1);

	TriangleComp tr(d1, d2, d3);
	TriangleAggr trAg(&d1, &d2, &d3);

	cout << tr.Perimeter() << endl;
	cout << tr.Square() << endl;
	tr.printSides();

	cout << trAg.Perimeter() << endl;
	cout << trAg.Square() << endl;
	trAg.printSides();
}