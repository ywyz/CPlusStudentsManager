#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Manager.h"
using namespace std;

void Manager::show_Menu()							// ��ʾ���˵�
{
	std::cout << "***********��ӭʹ��ѧ���ɼ�����ϵͳ***********" << std::endl;
	std::cout << "1- �����ʼ����" << std::endl;
	std::cout << "2- ��ʾ��Ϣ" << std::endl;
	std::cout << "3- �����¼" << std::endl;
	std::cout << "4- ɾ����¼" << std::endl;
	std::cout << "5- ��ѯ��Ϣ" << std::endl;
	std::cout << "6- �༭��¼" << std::endl;
	std::cout << "7- ȥ��" << std::endl;
	std::cout << "8- ������������" << std::endl;
	std::cout << "0- �˳�" << std::endl;
}

void Manager::show_Information()						// ��ʾ��Ϣѡ��	
{
	std::cout << "1.��ʾѧ����Ϣ:" << std::endl;
	std::cout << "2.��ʾ�γ���Ϣ��" << std::endl;
	std::cout << "3.��ʾ�ɼ���Ϣ" << std::endl;
	std::cout << "0.������һ��" << std::endl;

}

void Manager::show_Add()								// ��ʾ���ѧ��ѡ��
{
	std::cout << "1.���ѧ����Ϣ:" << std::endl;
	std::cout << "2.��ӿγ���Ϣ��" << std::endl;
	std::cout << "3.��ӳɼ���Ϣ" << std::endl;
	std::cout << "0.������һ��" << std::endl;

}

void Manager::show_Delete()							// ��ʾɾ��ѧ��ѡ��
{
	std::cout << "1.ɾ��ѧ����Ϣ:" << std::endl;
	std::cout << "2.ɾ���γ���Ϣ��" << std::endl;
	std::cout << "3.ɾ���ɼ���Ϣ" << std::endl;
	std::cout << "0.������һ��" << std::endl;

}

void Manager::show_Edit()							// ��ʾ�༭ѧ��ѡ��
{
	std::cout << "1.�༭ѧ����Ϣ:" << std::endl;
	std::cout << "2.�༭�γ���Ϣ��" << std::endl;
	std::cout << "3.�༭�ɼ���Ϣ" << std::endl;
	std::cout << "0.������һ��" << std::endl;

}

void Manager::show_Export()								// ��ʾ������Ϣ
{
	std::cout << "������data.bin��......." << std::endl;
}

void Manager::show_Import()								// ��ʾ�����Ϣ
{
	std::cout << "��data.bin������......." << std::endl;
}


void Manager::show_Query()								// ��ʾ��ѯ��Ϣѡ��
{
	std::cout << "1.��ѯѧ����Ϣ:" << std::endl;
	std::cout << "2.��ѯ�γ���Ϣ��" << std::endl;
	std::cout << "3.��ѯ�ɼ���Ϣ" << std::endl;
	std::cout << "0.������һ��" << std::endl;

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
	cout << "������ѧ��������";
	cin >> stu_name;
	cout << "������8λѧ�ţ�";
	cin >> stu_id;
	for (int temp = 0; temp<=3&&cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_id;
	}
	if (&stu_id == NULL)
		return;

	cout << "������ѧ�����䣺";
	cin >> stu_age;
	for (int temp = 0; (temp <= 3 && cin.good() == false)&& (stu_age <= 0 || stu_age >= 100); temp++)
	{
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_age;
	}
	if (&stu_age == NULL)
		return;
	cout << "������ѧ���Ա���/Ů����";
	cin >> stu_gender;
	for (int temp = 0; (temp <= 3 && cin.good() == false) && (stu_gender != "��" || stu_gender != "Ů"); temp++)
	{
		cout << "����������������룡" << endl;
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
	cout << "������γ����ƣ�";
	cin >> course_name;
	cout << "������γ̱�ţ�";
	cin >> course_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> course_id;
	}
	if (&course_id == NULL)
		return;
	cout << "������γ�ѧ�֣�";
	cin >> course_credit;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
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
	cout << "������ѧ�ţ�";
	cin >> stu_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stu_id;
	}
	cout << "������γ̺ţ�";
	cin >> cour_id;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> cour_id;
	}
	if (&cour_id == NULL)
		return;
	cout << "������γ̷�����";
	cin >> credit;
	for (int temp = 0; temp <= 3 && cin.good() == false; temp++)
	{
		cout << "����������������룡" << endl;
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
	cout << "δ�ҵ���ѧ��" << endl;
	return;
}

Student Manager::query_Student(string name)
{
	for (auto it = students.begin(); it != students.end(); it++)
	{
		if (name == (*it).name)
			return (*it);
	}
	cout << "δ�ҵ���ѧ��" << endl;
	return;
}

void Manager::query_Student()
{
	cout << "��ѡ���ѯ��ʽ��" << endl;
	cout << "1.��ѧ�Ų�ѯ" << endl;
	cout << "2.��������ѯ" << endl;
	cout << "������ѡ��";
	int choice;
	cin >> choice;
	
	if (choice == 1)
	{
		cout << "������ѧ�ţ�";
		long stu_id;
		cin >> stu_id;
		Students temp = this->query_Student(stu_id);
		if(temp != NULL)

	}

	else
	{
		cout << "������ѧ��������";
		string stu_name;
		cin >> stu_name;
		for (auto it = students.begin(); it != students.end(); it++)
		{
			if (stu_name == (*it).name)
				return (*it);
		}

	cout << "δ�ҵ���ѧ��" << endl;
	}
	return;
}

void Manager::show_Student(&stu)
{
	cout << "ѧ�ţ�" << stu.id << endl;
	cout <<
}