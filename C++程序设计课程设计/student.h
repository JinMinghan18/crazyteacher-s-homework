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
			cout<<"\n学号："; 
			cin>>id;
		}
		void get_time()
		{
			cout<<"\n缺课时间："; 
			cin>>date; 
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
		int check_id()
		{
			return id;
		} 
		int check_time()
		{
			return date;
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
		void get_info();
		void modify();
		void search(int n);
		int check(int id,int date,int order);
	private:
		string name;//姓名 
		int id;//学号 
		int date; //缺课日期 
		int order; //第几节课 
		string classname; //课程名称 
		string abstype;//缺课类型（迟到、早退、请假、旷课） 
		
};

#endif
