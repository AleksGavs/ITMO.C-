#include <iostream>
#include <vector>

using namespace std;

void LAB05E01()
{
	const int n = 10;
	int mas[n];

	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	int s = 0;
	int negSum = 0;
	int posSum = 0;
	int evenSum = 0;
	int oddSum = 0;
	for (int i = 0; i < n; i++)
	{
		s += mas[i];
		if (i % 2 == 0)
		{
			evenSum += mas[i];
		}
		else
		{
			oddSum += mas[i];
		}
		if (mas[i] > 0)
		{
			posSum += mas[i];
		}
		else
		{
			negSum += mas[i];
		}
	}
	int avg = s / n;

	cout << "Сумма равна : " << s << endl;
	cout << "Среднее равно : " << avg << endl;
	cout << "Сумма положительных чисел равна : " << posSum << endl;
	cout << "Сумма отрицательных чисел равна : " << negSum << endl;
	cout << "Сумма чисел с чётными индексами равна : " << evenSum << endl;
	cout << "Сумма чисел с нечётными индексами равна : " << oddSum << endl;


	int minIndex, maxIndex;
	int multBetweenMinAndMax = 1;
	int minTemp = mas[0];
	int maxTemp = mas[0];
	for (int i = 1; i < n; i++)
	{
		if (mas[i] > maxTemp)
		{
			maxTemp = mas[i];
			maxIndex = i;
		}
		else if (mas[i] < minTemp)
		{
			minTemp = mas[i];
			minIndex = i;
		}
	}
	cout << "Индекс максимального числа равен : " << maxIndex << endl;
	cout << "Индекс минимального числа равен : " << minIndex << endl;

	for (int i = minIndex + 1; i < maxIndex; i++)
	{
		multBetweenMinAndMax *= mas[i];
	}
	cout << "Произведение чисел между минимальным и максимальным знавением равно : " << multBetweenMinAndMax << endl;
}

void LAB05E02()
{
	const int N = 10;
	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями
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
}
//--------------------------------------------------

void show_array(const int Arr[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
};

bool from_min(const int a, const int b)
{
	return a > b;
}
bool from_max(const int a, const int b)
{
	return a < b;
}
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
		}
	}
}

void LAB05E03()
{
	const int size = 10;
	int choice = 0;
	int arr[size];

	bool (*from_f[2])(int, int) = { from_min, from_max };//ПОЧЕМУ ДВА ИНТА?!

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200;
	}

	cout << "1. Сортировать по возрастанию\n";
	cout << "2. Сортировать по убыванию\n";
	cin >> choice;
	cout << "Исходные данные: ";
	show_array(arr, size);
	/*switch (choice)
	{
	case 1: bubble_sort(arr, size, from_min); break;
	case 2: bubble_sort(arr, size, from_max); break;
	default: cout << "\rНеизвестная операция ";
	}*/
	bubble_sort(arr, size, (*from_f[choice - 1])); //ТУТ ЖЕ ПЕРЕДАЕМ ОДИН

	show_array(arr, size);
}

void LAB05E04()
{
	int size = 0;
	cout << "Введите количество элементов массива: ";
	cin >> size;
	int choice = 0;
	int* arr = new int[size];

	bool (*from_f[2])(int, int) = { from_min, from_max };//ПОЧЕМУ ДВА ИНТА?!

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200;
	}

	cout << "1. Сортировать по возрастанию\n";
	cout << "2. Сортировать по убыванию\n";
	cin >> choice;
	cout << "Исходные данные: ";
	show_array(arr, size);
	/*switch (choice)
	{
	case 1: bubble_sort(arr, size, from_min); break;
	case 2: bubble_sort(arr, size, from_max); break;
	default: cout << "\rНеизвестная операция ";
	}*/
	bubble_sort(arr, size, (*from_f[choice - 1])); //ТУТ ЖЕ ПЕРЕДАЕМ ОДИН

	show_array(arr, size);
}
//-------------------------------------------

void LAB05E05T01()
{
	srand(time(NULL));
	int a, b, c;
	int k = 0;
	const int n = 10;
	int mas[n];
	for (int i = 0; i < n; i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;
		mas[i] = c;
		if (a * b != c)
		{
			k++;
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
	}

	cout << "\nAll: ";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " " << ends;
	}
}

void LAB05E05T02()
{
	srand(time(NULL));
	int a, b, c;
	int k = 0;
	const int n = 10;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		cout << a << " * " << b << " = ";
		cin >> c;		
		if (a * b != c)
		{
			v2.push_back(c);
			k++;
			cout << "Error! ";
			cout << a << " * " << b << " = " << a * b << endl;
		}
		else
		{
			v1.push_back(c);
		}
	}

	cout << "\nGood: ";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " " << ends;
	}
	cout << "\nBad: ";
	for (int i = 0; i < v2.size(); i++)		
	{
		cout << v2[i] << " " << ends;
	}
	delete[] & v1;
	delete[] & v2;

}

int* LAB05K01(const int arr[], const int size)
{
	int* res = new int[size];
	for (int i = 0; i < size; i++)
	{
		res[i] = arr[i];
	}
	
	int min = 0; 
	int buf = 0; 
	for (int i = 0; i < size; i++)
	{
		min = i; 
		for (int j = i + 1; j < size; j++)
			min = (res[j] < res[min]) ? j : min;
		
		if (i != min)
		{
			buf = res[i];
			res[i] = res[min];
			res[min] = buf;
		}
	}
	/*for (int i : res)
	{		
		cout << i << '\t';
	}*/
	for (int i = 0; i < size; i++)
	{
		cout << res[i] << endl;
	}
	return res;
}

//---------------------------------------
int* max_vect(int size, int arr1[], int arr2[])
{
	int* res = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] > arr2[i])
		{
			res[i] = arr1[i];
		}
		else
		{
			res[i] = arr2[i];
		}
	}
	return res;
}

void LAB05K02()
{
	int a[] = { 1,2,3,4,5,6,7,2 };
	int b[] = { 7,6,5,4,3,2,1,3 };
	int kc = sizeof(a) / sizeof(a[0]);
	int* c;
	c = max_vect(kc, a, b);
	for (int i = 0; i < kc; i++)
		cout << c[i] << " ";
	cout << endl;
	delete[]c;
}

//---------------------------------------------
void arrToSearch(int* arr, int num, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num && i != 0)
		{
			cout << "На момент запроса, индекс элемента = " << i;
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			break;
		}
		else if (arr[i] != num && i == size - 1)
		{
			cout << "Нет такого элемента";
		}
	}
}

void LAB05K03()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usersNum;
	cout << "Введите искомое число: ";
	cin >> usersNum;
	arrToSearch(arr, usersNum, size);
}

//------------------------------------------------------
//int main(int argc, char* argv[])
//{
//	system("chcp 1251");
//
//	if (argc < 4) {
//		std::cout << "Недостаточно аргументов. Пример использования: ITMO.C++ -a 12 45\n";
//		return 1;
//	}
//
//	int num1 = atoi(argv[2]);
//	int num2 = atoi(argv[3]);
//
//	if (string(argv[1]) == "-a") {
//		cout << "Сумма: " << num1 + num2 << std::endl;
//	}
//	else if (string(argv[1]) == "-m") {
//		cout << "Произведение: " << num1 * num2 << std::endl;
//	}
//	else {
//		cout << "Неверный формат параметра. Используйте -a для суммы или -m для произведения.\n";
//		return 1;
//	}
//
//	return 0;
//}



