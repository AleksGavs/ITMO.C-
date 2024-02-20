#include "Header.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <vector>


using namespace std;

int main(int argc, char* argv[])
{
	system("chcp 1251");

	if (argc < 4) {
		std::cout << "Недостаточно аргументов. Пример использования: ITMO.C++ -a 12 45\n";		
	}

	int num1 = atoi(argv[2]);
	int num2 = atoi(argv[3]);

	if (string(argv[1]) == "-a") {
		cout << "Сумма: " << num1 + num2 << std::endl;
	}
	else if (std::string(argv[1]) == "-m") {
		cout << "Произведение: " << num1 * num2 << std::endl;
	}
	else {
		std::cout << "Неверный формат параметра. Используйте -a для суммы или -m для произведения.\n";		
	}

	return 0;
}
