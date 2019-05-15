#ifndef student_H
#define student_H

#include<iostream>
#include<fstream> 
#include <cstring>
using namespace std;
class student 
{
	public:
		void get_name()
		{
			cin>>name;
		}
		void get_id()
		{
			cin>>id;
		}
		void get_time()
		{
			cin>>year>>month>>day;
		} 
		void get_order()
		{
			cin>>order;
		}
		void get_classname()
		{
			cin>>classname;
		} 
		void get_abstype()
		{
			cin>>abstype;
		}
		
	private:
		char name[20];//姓名 
		string id;//学号 
		int year; //缺课日期 
		int month;
		int day;
		int order; //第几节课 
		char classname[20]; //课程名称 
		char abstype[20];//缺课类型（迟到、早退、请假、旷课） 
		
};
void get_info();
void modify();
#endif
