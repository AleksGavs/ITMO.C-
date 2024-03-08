#include "Templates.cpp"
#include <iostream>
#include <vector>

using namespace std;

void L14E01()
{
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, world";
	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
	sorting(arr, k1);
	printing(arr, k1);
	sorting(arrd, k2);
	printing(arrd, k2);
	sorting(arrc, k3);
	printing(arrc, k3);
}

void L14E02()
{
	using Tuple = tuple<string, int, double>;
	using TupleV2 = tuple<int, char, double>;

	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	auto t1 = make_tuple(v1[1], v2[1], v3[1]);
	auto t2 = make_tuple(v1[2], v2[2], v3[2]);
	auto t4 = make_tuple(25, 'a', 2.1);
	printTupleOfThree(t0);
	printTupleOfThree(t1);
	printTupleOfThree(t2);
	printTupleOfThree(t4);
}

void L14E03()
{
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
	auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);
	printTuple(t1);
	printTuple(t2);
}

void L14K01()
{
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, world";
	long arrl[] = { 123545, 165165161, 9818161161, 184168166168 };

	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
	int k4 = sizeof(arrl) / sizeof(arrl[0]);
	averageOfArray(arr, k1);
	averageOfArray(arrd, k2);
	averageOfArray(arrc, k3);
	averageOfArray(arrl, k4);
}

void L14K02()
{
	std::vector<int> data = { 1, 2, 3 }; 
	Print(data, ", ");
}