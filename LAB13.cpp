#include "Item.h"
#include "PaperBook.h"
#include "AudioBook.h"
#include "Student1.h"
#include "Teacher.h"
#include <iostream>

using namespace std;

void L13E01()
{

	Item* pubarr[100];
	int n = 0;
	char choice;
	do
	{
		cout << "\nВводить данные для книги или звукового файла(b / a) ? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new Paperbook;
		else
			pubarr[n] = new AudioBook;
		pubarr[n++]->getdata();
		cout << "Продолжать((у / n) ? ";
		cin >> choice;
	} while (choice == 'y');
	for (int j = 0; j < n; j++) //цикл по всем объектам
		pubarr[j]->putdata(); //вывести данные о публикации
	cout << endl;
}

void L13K01()
{
	
		student1* stud = new student1("Петров", "Иван", "Алексеевич", { 5,4,3,5,4 });
		stud->print_name();

		Teacher* tch = new Teacher("Сергеев", "Дмитрий", "Сергеевич",
			40);
		tch->print_name();
	
}