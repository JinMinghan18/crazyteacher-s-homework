#ifndef student_H_H
#define student_H_H

#include <map>
#include<iostream>
#include<fstream> 
#include <cstring>
using namespace std;
class student 
{
	public:
		void get_name()
		{
			cout<<"姓名：" ;
			cin>>name;
		}
		void get_id()
		{
			cout<<"\n学号：（浙工大计算机专业学号）"; 
			cin>>id;
		}
		void get_time()
		{
			cout<<"\n缺课时间：(例如1999 11 11)"; 
			cin>>year>>month>>day; 
		} 
		void get_order()
		{
			cout<<"\n课时：" ;
			cin>>order;
		}
		void get_classname()
		{
			cout<<"\n课程名称："; 
			cin>>classname;
		} 
		void get_abstype()
		{
			cout<<"\n缺课类型：";
			cin>>abstype;
		}
		string check_name()
		{
			return name;
		} 
		long long check_id()
		{
			return id;
		} 
		int check_year()
		{
			return year;
		} 
		int check_month()
		{
			return month;
		}
		int check_day()
		{
			return day;
		}
		int check_order()
		{
			return order;
		} 
		string check_classname()
		{
			return classname;
		} 
		string check_abstype()
		{
			return abstype;
		} 		
		void chuanru_name(string n)
		{
			name = n;
		}
		void chuanru_id(long long i)
		{
			id = i;
		}
		void chuanru_date(int y,int m,int d)
		{
			year = y;
			month = m;
			day = d;
		}
		void chuanru_order(int orde)
		{
			order = orde;
		}
		void chuanru_classname(string cla)
		{
			classname = cla;
		}
		void chuanru_abstype(string abs)
		{
			abstype = abs;
		}
		void get_info();
		void modify();
		void search(long long n);
		int check(long long id,int year,int month,int day,int order);
	private:
		string name;//姓名 
		long long id;//学号 
		int year,month,day; //缺课日期 
		int order; //第几节课 
		string classname; //课程名称 
		string abstype;//缺课类型（迟到、早退、请假、旷课） 
		
};

#endif
