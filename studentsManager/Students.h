#pragma once
#include <iostream>
#include <string>
using namespace std;

class Students 
{
private:
	string name;
	int age;
	long id;
	string gender;

public:
	Students();
	Students(string name,long id, int age, string gender);
	~Students();
	void setName(string na);
	void setAge(int ag);
	void setId(long id);
	void setGender(string gen);
	string getName();
	int getAge();
	long getId();
	string getGender();
}