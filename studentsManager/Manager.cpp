#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Manager.h"
using namespace std;

void Manager::show_Menu()							// 显示主菜单
{
	std::cout << "***********欢迎使用学生成绩管理系统***********" << std::endl;
	std::cout << "1- 导入初始数据" << std::endl;
	std::cout << "2- 显示信息" << std::endl;
	std::cout << "3- 输入记录" << std::endl;
	std::cout << "4- 删除记录" << std::endl;
	std::cout << "5- 查询信息" << std::endl;
	std::cout << "6- 编辑记录" << std::endl;
	std::cout << "7- 去重" << std::endl;
	std::cout << "8- 批量导入数据" << std::endl;
	std::cout << "0- 退出" << std::endl;
}

void Manager::show_Information()						// 显示信息选项	
{
	std::cout << "1.显示学生信息:" << std::endl;
	std::cout << "2.显示课程信息：" << std::endl;
	std::cout << "3.显示成绩信息" << std::endl;
	std::cout << "0.返回上一层" << std::endl;

}

void Manager::show_Add()								// 显示添加学生选项
{
	std::cout << "1.添加学生信息:" << std::endl;
	std::cout << "2.添加课程信息：" << std::endl;
	std::cout << "3.添加成绩信息" << std::endl;
	std::cout << "0.返回上一层" << std::endl;

}

void Manager::show_Delete()							// 显示删除学生选项
{
	std::cout << "1.删除学生信息:" << std::endl;
	std::cout << "2.删除课程信息：" << std::endl;
	std::cout << "3.删除成绩信息" << std::endl;
	std::cout << "0.返回上一层" << std::endl;

}

void Manager::show_Edit()							// 显示编辑学生选项
{
	std::cout << "1.编辑学生信息:" << std::endl;
	std::cout << "2.编辑课程信息：" << std::endl;
	std::cout << "3.编辑成绩信息" << std::endl;
	std::cout << "0.返回上一层" << std::endl;

}

void Manager::show_Export()								// 显示导出信息
{
	std::cout << "导出到data.bin中......." << std::endl;
}

void Manager::show_Import()								// 显示入出信息
{
	std::cout << "从data.bin导入中......." << std::endl;
}


void Manager::show_Query()								// 显示查询信息选项
{
	std::cout << "1.查询学生信息:" << std::endl;
	std::cout << "2.查询课程信息：" << std::endl;
	std::cout << "3.查询成绩信息" << std::endl;
	std::cout << "0.返回上一层" << std::endl;

}

void Manager::clear_Screen() noexcept
{
	system("cls");
}

void Manager::add_Student()
{
	string stu_name, stu_gender;
	long stu_id;
	int stu_age;
	cout << "请输入学生姓名：";
	cin >> stu_name;
	cout << "请输入8位学号：";
	cin >> stu_id;
	for (int temp = 0; temp<=3&&cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_id;
	}
	if (&stu_id == NULL)
		return;

	cout << "请输入学生年龄：";
	cin >> stu_age;
	for (int temp = 0; (temp <= 3 && cin.good() == false)&& (stu_age <= 0 || stu_age >= 100); temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_age;
	}
	if (&stu_age == NULL)
		return;
	cout << "请输入学生性别（男/女）：";
	cin >> stu_gender;
	for (int temp = 0; (temp <= 3 && cin.good() == false) && (stu_gender != "男" || stu_gender != "女"); temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_gender;
	}
	if (&stu_gender == NULL)
		return;
	Student stu = { stu_name, stu_age, stu_id, stu_gender };
	students.push_back(stu);
}

void Manager::add_Course()
{
	string course_name;
	int course_id;
	float course_credit;
	cout << "请输入课程名称：";
	cin >> course_name;
	cout << "请输入课程编号：";
	cin >> course_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> course_id;
	}
	if (&course_id == NULL)
		return;
	cout << "请输入课程学分：";
	cin >> course_credit;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> course_credit;
	}
	if (&course_credit == NULL)
		return;
	Course course = { course_name, course_id, course_credit};
	courses.push_back(course);
}

void Manager::add_CourseSelect()
{
	long stu_id, cour_id;
	float credit;
	cout << "请输入学号：";
	cin >> stu_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_id;
	}
	cout << "请输入课程号：";
	cin >> cour_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> cour_id;
	}
	if (&cour_id == NULL)
		return;
	cout << "请输入课程分数：";
	cin >> credit;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "输入错误，请重新输入！" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> credit;
	}
	if (credit == NULL)
		return;
	CourseSelect courseSelect = { stu_id, cour_id, credit };
	courseSelects.push_back(courseSelect);
}


Student Manager::query_Student(long id)
{
	for (auto it = students.begin(); it != students.end(); it++)
	{
		if (id == (*it).id)
			return (*it);
	}
	cout << "未找到该学生" << endl;
	return;
}

Student Manager::query_Student(string name)
{
	for (auto it = students.begin(); it != students.end(); it++)
	{
		if (name == (*it).name)
			return (*it);
	}
	cout << "未找到该学生" << endl;
	return;
}

void Manager::query_Student()
{
	cout << "请选择查询方式：" << endl;
	cout << "1.按学号查询" << endl;
	cout << "2.按姓名查询" << endl;
	cout << "请输入选择：";
	int choice;
	cin >> choice;
	
	if (choice == 1)
	{
		cout << "请输入学号：";
		long stu_id;
		cin >> stu_id;
		Students temp = this->query_Student(stu_id);
		if(temp != NULL)

	}

	else
	{
		cout << "请输入学生姓名：";
		string stu_name;
		cin >> stu_name;
		for (auto it = students.begin(); it != students.end(); it++)
		{
			if (stu_name == (*it).name)
				return (*it);
		}

	cout << "未找到该学生" << endl;
	}
	return;
}

void Manager::show_Student(&stu)
{
	cout << "学号：" << stu.id << endl;
	cout <<
}