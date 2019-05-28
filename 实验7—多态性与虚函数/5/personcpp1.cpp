#include <iostream>
#include "person.h"
#include <string.h>
using namespace std;

void person::display()
{
	cout<<"姓名："<<name<<endl<<endl
		<<"id: "<<id<<endl<<endl; 
}

int person::time()
{
	return worktime;
}
void student::display()
{
	person::display();
	cout<<"学习时间："<<person::time()<<endl<<endl; 
	cout<<"专业:"<<major<<endl<<endl
		<<"班级职务："<<classpost<<endl<<endl; 
}
void teacher::display()
{
	person::display();
	cout<<"教学时长："<<person::time()<<endl<<endl;
	cout<<"所属学院："<<college<<endl<<endl
		<<"职称："<<title<<endl<<endl
		<<"工资："<<salary<<endl<<endl; 
}
void employee::display()
{
	person::display();
	cout<<"工作时长:"<<person::time()<<endl;
	cout<<"部门："<<department<<endl;
	cout<<"工资:"<<salary<<endl; 
}
