#pragma once
#include <string>
#include <vector>
#include "Students.h"

using namespace std;
class Course
{
	private:
		long courseID;
		string courseName;
		float credit;

	public:
		struct CourseSelect
		{
			long stu_id;
			float score;
		};
		vector<CourseSelect*> courseSelect;

		Course();
		Course(long courseID, string courseName, float credit);
		~Course();
		long getCourseID();
		string getCourseName();
		float getCredit();
		void setCourseID(long courseID);
		void setCourseName(string courseName);
		void setCredit(float credit);
		void addCourseSelect(long stu_id, float score);
		CourseSelect* findCourseSelect(long stu_id);
		void deleteCourseSelect(long stu_id);
		void updateCourseSelect(CourseSelect* courselect);
};

