#include "Student.h"
#include "Time.h"
#include "Header.h"
#include <String>
#include <iostream>


using namespace std;

//��� ������, ���������� ������ ����������� �� Student.cpp � Student.h 
//void L08E02()
//{
//	
//	// �������� ������� ������ Student
//	Student student01;
//	string name;
//	string last_name;
//	// ���� ����� � ����������
//	cout << "Name: ";
//	getline(cin, name);
//	// ���� �������
//	cout << "Last name: ";
//	getline(cin, last_name);
//	// ���������� ����� � ������� � ������ ������ Student
//	student01.set_name(name);
//	student01.set_last_name(last_name);
//	// ������
//	int scores[5];
//	// ����� ���� ������
//	int sum = 0;
//	// ���� ������������� ������
//	for (int i = 0; i < 5; ++i) {
//		cout << "Score " << i + 1 << ": ";
//		cin >> scores[i];
//		// ������������
//		sum += scores[i];
//	}
//	// ��������� ������������� ������ � ������ ������ Student
//	student01.set_scores(scores);
//
//	// ������� ������� ����
//double average_score = sum / 5.0;
//// ��������� ������� ���� � ������ ������ Student
//student01.set_average_score(average_score);
//// ������� ������ �� ��������
//cout << "Average ball for " << student01.get_name() << " "
//	<< student01.get_last_name() << " is "
//	<< student01.get_average_score() << endl;
//
//}


//��� ������, ���������� ������ ����������� �� Student.cpp � Student.h 
//void L08E03()
//{
//	// ��������� ������ ��� ������� Student
//	Student* student02 = new Student;
//	string name;
//	string last_name;
//	// ���� ����� � ����������
//	cout << "Name: ";
//	getline(std::cin, name);
//	// ���� �������
//	cout << "Last name: ";
//	getline(std::cin, last_name);
//	// ������
//	int scores[5];
//	// ����� ���� ������
//	int sum = 0;
//
//	// ���� ������������� ������
//	for (int i = 0; i < 5; ++i) {
//		cout << "Score " << i + 1 << ": ";
//		cin >> scores[i];
//		// ������������
//		sum += scores[i];
//	}
//
//	// ���������� ����� � ������� � ������ ������ Students
//	student02->set_name(name);
//	student02->set_last_name(last_name);
//	// ��������� ������������� ������ � ������ ������ Student
//	student02->set_scores(scores);
//	// ������� ������� ����
//	float average_score = sum / 5.0;
//	// ��������� ������� ���� � ������ ������ Student
//	student02->set_average_score(average_score);
//	// ������� ������ �� ��������
//	cout << "Average ball for " << student02->get_name() << " "
//		<< student02->get_last_name() << " is "
//		<< student02->get_average_score() << endl;
//	delete student02;
//}

void L08E04()
{
	string name;
	string last_name;
	// ���� ����� � ����������
	cout << "Name: ";
	getline(cin, name);
	// ���� �������
	cout << "Last name: ";
	getline(cin, last_name);
	// �������� ���������� ������������
	Student* student02 = new Student(name, last_name);
	// ������
	int scores[5];
	// ����� ���� ������
	int sum = 0;
	// ���� ������������� ������
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// ������������
		sum += scores[i];
	}
	// ��������� ������������� ������ � ������ ������ Student
	student02->set_scores(scores);
	// ������� ������� ����
	double average_score = sum / 5.0;
	// ��������� ������� ���� � ������ ������ Student
	student02->set_average_score(average_score);
	// ������� ������ �� ��������
	cout << "Average ball for " << student02->get_name() << " "
		<< student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;
	// �������� ������� student �� ������
	delete student02;
}

void L08K01()
{
	int h, m, s;
	cin >> h >> m >> s;
	Time time1 = Time(h, m, s);
	Time time2 = Time(14, 22, 58);
	time1.ShowTime();
	Time timeRes = time1.AddTime(time2);
	timeRes.ShowTime();
}