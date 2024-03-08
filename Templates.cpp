#include <iostream>
#include <tuple>

using namespace std;

template<class T>
void sorting(T arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		T x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}

template<class T>
void averageOfArray(T arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		j += arr[i];
	}
	cout << j / size << endl;
}

template<class T>
void printing(T arr[], int size) {
	for (int i = 0; i < size; i++) cout << arr[i] << "; ";
	cout << endl;
}

template<class Tuple>
void printTupleOfThree(Tuple t)
{
	cout << "("
		<< get<0>(t) << ", "
		<< get<1>(t) << ", "
		<< get<2>(t) << ")" << endl;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);
		cout << ", " << get<N - 1>(t);
	}
};
template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t)
	{
		cout << get<0>(t);

	}
};

template<class... Args>
void printTuple(const tuple<Args...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << ")" << endl;
}

template <typename T>
void Print(const T& container, const std::string& separator) {
	bool first = true;
	for (const auto& element : container) {
		if (!first) {
			std::cout << separator;
		}
		std::cout << element;
		first = false;
	}
	std::cout << std::endl;
}
