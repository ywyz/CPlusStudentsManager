#pragma once
#include <string>
using namespace std;

struct Student
{
	string name;
	int age;
	long id;
	string gender;
};

struct Course
{
	string name;
	long id;
	float credit;
};

struct CourseSelect
{
	long stu_id;
	long course_id;
	float stu_grade;
};