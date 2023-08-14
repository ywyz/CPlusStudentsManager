#include "Course.h"

Course::Course(){}

Course::Course(long courseID, string courseName, float credit) :courseID(courseID), courseName(courseName), credit(credit) {};

Course::~Course(){}

long Course::getCourseID()
{
	return this->courseID;
}

string Course::getCourseName()
{
	return this->courseName;
}

float Course::getCredit()
{
	return this->credit;
}

void Course::setCourseID(long courseID)
{
	this->courseID = courseID;
}

void Course::setCourseName(string courseName)
{
	this->courseName = courseName;
}

void Course::setCredit(float credit)
{
	this->credit = credit;
}

void Course::addCourseSelect(long stu_id, float score)
{
	CourseSelect * select = new CourseSelect();
	select->stu_id = stu_id;
	select->score = score;
	courseSelect.push_back(select);
}

Course::CourseSelect* Course::findCourseSelect(long stu_id)
{
	auto it = courseSelect.begin();
	for (; it != courseSelect.end(); it++)
	{
		if ((*it)->stu_id == stu_id)
		{
			return *it;
		}
	}
	return NULL;
}

void Course::deleteCourseSelect(long stu_id)
{
	auto it = courseSelect.begin();
	for (; it != courseSelect.end(); it++)
	{
		if ((*it)->stu_id == stu_id)
		{
			courseSelect.erase(it);
			break;
		}
	}
}

void Course::updateCourseSelect(CourseSelect* courselect)
{
	auto it = courseSelect.begin();
	for (; it != courseSelect.end(); it++)
	{
		if ((*it)->stu_id == courselect->stu_id)
		{
			(*it)->score = courselect->score;
			break;
		}
	}
}