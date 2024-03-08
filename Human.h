#pragma once
#include <string>
#include <sstream>
#include <iostream>
#pragma once 
class human {
public:
	// Конструктор класса human
	human(std::string last_name, std::string name, std::string
		second_name)
	{
		this->last_name = last_name;
		this->name = name;
		this->second_name = second_name;
	}
	// Получение ФИО человека
	std::string get_full_name()
	{
		std::ostringstream full_name;
		full_name << this->last_name << " "
			<< this->name << " "
			<< this->second_name;
		return full_name.str();
	}
	std::string get_name()
	{
		return name;
	}
	std::string get_last_name()
	{
		return last_name;
	}
	std::string get_second_name()
	{
		return second_name;
	}

	virtual void print_name()
	{
		std::cout << get_full_name();
	}

private:
	std::string name; // имя
	std::string last_name; // фамилия
	std::string second_name; // отчество
};