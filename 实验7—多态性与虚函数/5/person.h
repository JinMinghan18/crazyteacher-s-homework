#ifndef PERSON_H_H
#define PERSON_H_H
#include<iostream>
#include <string.h>
using namespace std;
class person
{
	public:
		person(string i,string n,double t):id(i),name(n),worktime(t){}
		virtual void display();
		int time();
	private:
		string id;
		string name;
		double worktime;
};
class student:public person
{
	public:
		student(string i,string n,double t,string m,string c):person(i,n,t),major(m),classpost(c){}		
		virtual void display();
	private:
		string major;
		string classpost;
};
class teacher:public person
{
	public:
		teacher(string i,string n,double t,string co,string tit,double s):person(i,n,t),college(co),title(tit),salary(s){}		
		virtual void display();
	private:
		string college;
		string title;
		double salary;
};
class employee:public person
{
	public:
		employee(string i,string n,double t,string dep,double s):person(i,n,t),department(dep),salary(s){} 
		virtual void display();
	private:
		string department;
		double salary;
};
#endif
