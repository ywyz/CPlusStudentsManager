#include <iostream>
#include <string>
#include "Students.h"
using namespace std;

Students::Students(){};
Students::Students(string name, long id, int age, string gender):name(name), age(age), id(id),  gender(gender){}
Students::~Students(){};

void Students::setName(string name) {
	this->name = name;
}

void Students::setAge(int age) {
	this->age = age;
}

void Students::setId(long id) {
	this->id = id;
}

void Students::setGender(string gender){
	this->gender = gender;
}

int Students::getAge()
{
	return this->age;
}

string Students::getName()
{
	return this->name;
}

string Students::getGender()
{
	return this->gender;
}

long Students::getId()
{
	return this->id;
}
