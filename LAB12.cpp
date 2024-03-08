#include "Student1.h"
#include "Teacher.h"
#include <iostream>

using namespace std;

void L12E01()
{
	string name = "Ivanov";
	string surname = "Mikhail";
	string secondName = "Petrovish";
	student1 IMP(name, surname, secondName, { 5,4,3,3,4,4 });

	cout << IMP.get_full_name() << endl;
	cout << IMP.get_average_score();
}

void L12E02()
{
	// Оценкистудента
	std::vector<int> scores;
	// Добавление оценок студента в вектор
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	student1* stud = new student1("Петров", "Иван", "Алексеевич", scores);
	std::cout << stud->get_full_name() << std::endl;

	std::cout << "Средний балл : " << stud->get_average_score() << std::endl;
}

void L12E03()
{
	unsigned int teacher_work_time = 40;
	Teacher* tch = new Teacher("Сергеев", "Дмитрий", "Сергеевич",
		teacher_work_time);
	std::cout << tch->get_full_name() << std::endl;
	std::cout << "Количество часов: " << tch->get_work_time() <<
		std::endl;
}

