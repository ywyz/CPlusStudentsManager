#pragma once
#include <vector>
#include "data.h"
using namespace std;

class Manager
{
private:
	vector<Student> students;
	vector<Course> courses;
	vector<CourseSelect> courseSelects;
	bool is_changed = false;
	bool is_saved = true;
	bool is_import = false;
public:
	/*显示提示信息*/
	void show_Menu();
	void show_Information();
	void show_Add();
	void show_Delete();
	void show_Edit();
	void show_Export();
	void show_Import();
	void show_Query();
	void clear_Screen() noexcept;

	/*增删改查*/
	void add_Student();
	void add_Course();
	void add_CourseSelect();
	void delete_Student();
	void delete_Course();
	void delete_CourseSelect();
	Student query_Student();
	Course query_Course();
	CourseSelect query_CourseSelect();
	void edit_Student();
	void edit_Course();
	void edit_CourseSelect();
	void show_Student(&stu);
	void show_Course(&cour);
	void show_CourseSelect(&coursele);
	/*导入导出*/
	void exportfile();
	void importfile();
	/*排序*/
	void sort_students();
	void sort_Course();
	void sort_CourseSelect();
	/*去重*/
	void remove_repeat();
};
