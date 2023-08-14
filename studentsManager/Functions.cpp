#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Students.h"
#include "Course.h"

using namespace std;

vector<Students*> studentsInfo;
vector<Course*> courseInfo;
bool is_Changed = false;
bool is_Saved = true;
bool is_Import = false;
string data_path = "data.bin";


void ExportData()
{
	fstream fs;
	fs.open(data_path, ios::out | ios::binary);
	if (fs.is_open())
	{
		for (auto it = studentsInfo.begin(); it != studentsInfo.end(); it++)
		{
			fs << (*it)->getName() << " " << (*it)->getId() << " " << (*it)->getGender() << " " << (*it)->getAge() << endl;
		}
		fs << "-------------------------------------------------------" << endl;

		for (auto it = courseInfo.begin(); it != courseInfo.end(); it++)
		{
			fs << (*it)->getCourseName() << " " << (*it)->getCourseID() << " " << (*it)->getCredit() << " " << endl;
			fs << "******************************************************************" << endl;
			for (auto it1 = ((*it)->courseSelect).begin(); it1 != ((*it)->courseSelect).end(); it1++)
				fs << (*it1)->stu_id << " " << (*it1)->score << endl;
			fs << "******************************************************************" << endl;
		}
		bool is_Changed = false;
		bool is_Saved = true;
	}

	else
	{
		cout << "文件打开失败，请检查文件是否存在或有无被占用" << endl;
		bool is_Saved = false;
	}
	fs.close();


}

void ImportData()
{
	fstream fs;
	fs.open(data_path, ios::in | ios::binary);
	if (fs.is_open())
	{
		string line;

		// Clear the existing container data
		studentsInfo.clear();
		courseInfo.clear();
		is_Changed = false;
		is_Saved = true;

		// Read the student data
		while (getline(fs, line))
		{
			if (line == "-------------------------------------------------------")
				break;

			string name;
			long id;
			string gender;
			int age;

			// Parse the student data from the file
			if (sscanf_s(line.c_str(), "%s %ld %s %d", name.c_str(), name.size(), &id, gender.c_str(), gender.size(), &age) == 4)
			{
				// Create a new student object and add it to the container
				Students* student = new Students(name, id, age, gender);
				studentsInfo.push_back(student);
			}
		}

		// Read the course data
		while (getline(fs, line))
		{
			if (line == "-------------------------------------------------------")
				break;

			string name;
			long courseID;
			float credit;

			// Parse the course data from the file
			if (sscanf_s(line.c_str(), "%s %ld %f", name.c_str(), name.size(), &courseID, &credit) == 3)
			{
				// Create a new course object and add it to the container
				Course* course = new Course(courseID, name, credit);
				courseInfo.push_back(course);

				getline(fs, line); // Skip the line of asterisks

				// Read the course selection data
				while (getline(fs, line))
				{
					if (line == "******************************************************************")
						break;

					long stu_id;
					float score;

					// Parse the course selection data from the file
					if (sscanf_s(line.c_str(), "%ld %f", &stu_id, &score) == 2)
					{
						// Find the student associated with this selection
						auto student = find_if(studentsInfo.begin(), studentsInfo.end(), [stu_id](Students* s) {
							return s->getId() == stu_id;
							});

						// If a student was found, create a new course selection object and add it to the course
						if (student != studentsInfo.end())
						{
							Course::CourseSelect* selection = new Course::CourseSelect();
							selection->stu_id = (*student)->getId();
							selection->score = score;
							(*course).courseSelect.push_back(selection);
						}
					}
				}
			}
		}
	}

	else
	{
		cout << "文件打开失败，请检查文件是否存在或有无被占用" << endl;
		is_Saved = false;
	}
	fs.close();
}