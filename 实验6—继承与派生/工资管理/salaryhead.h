#ifndef SALARYHEAD_H_H
#define SALARYHEAD_H_H
#include<iostream>
using namespace std;
class employee{
	public:
		employee():id(""),name(""),salary(0){}
		employee(string id,string name):id(id),name(name),salary(0){}
		virtual void pay()=0 ;
		virtual void display();
		virtual void setdate()=0 ;
	protected:
		string id;
		string name;
		double salary;
};
class manager:virtual public employee //行政管理人员 
{
	public:
		manager():employee(){}
		manager(string id,string name):employee(id,name){}
		virtual void setdate();
		virtual void display();
		virtual void pay();
};
class technician:virtual public employee
{
	public:
		technician():employee(),time(0){}
		technician(string id,string name,int time):employee(id,name),time(time){}
		virtual void display();
		virtual void pay();
		virtual void setdate(); 
	protected:
		int time;
};
class salesman:virtual public employee
{
	public:
		salesman():employee(),sales(0){}
		salesman(string id,string name,double sales):employee(id,name),sales(sales){}
		virtual void display();
		virtual void pay();
		virtual void setdate();
	protected:
		double sales;
};
class salesmanager:virtual public employee
{
	public:
		salesmanager():employee(),sales(0),sumsales(0){}
		salesmanager(string id,string name,double sales,double sumsales):employee(id,name),sales(sales),sumsales(sumsales){}
		virtual void display();
		virtual void pay();
		virtual void setdate(); 
	protected:
		double sales;
		double sumsales; 
};
#endif 
