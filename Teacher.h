#pragma once

#include "human.h"
#include <string>
class Teacher : public human {
	// Конструктор класса teacher
public:
	Teacher(
		std::string last_name,
		std::string name,
		std::string second_name,
		// Количество учебных часов за семестр у преподавателя
		unsigned int work_time
	) : human(
		last_name,
		name,
		second_name
	) {
		this->work_time = work_time;
	}
	// Получение количества учебных часов
	unsigned int get_work_time()
	{
		return this->work_time;		
	}
	void print_name()
	{
		human::print_name();
	}
private:
	// Учебные часы
	unsigned int work_time;
};
