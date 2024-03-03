#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct StudentGrade
{
	string name;
	char grade;
};

class GradeMap
{
private:
	vector<StudentGrade> m_map;
public:
	GradeMap()
	{ }
	char& operator[](const string& name);
};
