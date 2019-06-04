#include <iostream>
#include <fstream>
#include "worker.h" 
using namespace std;
int main()
{
	worker a[100];
	a[0] = worker(1,"11111111111","zhangsan",18,10000); 
	a[1] = worker(2,"22222222222","lisi",19,10000);
	a[2] = worker(3,"33333333333","wangwu",20,10000);
	a[3] = worker(4,"44444444444","66",33,10000); 
	a[4] = worker(5,"5","77",23,10300); 
	ofstream out("职工信息.txt",ios::out);
	for(int i=0;i<4;i++)
	{
		out<<a[i].id<<" "<<a[i].name<<" "<<a[i].tel<<" "<<a[i].age<<" "<<a[i].salary<<endl;
	}
	out.close();
	string name,tel;
	int age;
	long long id; 
	double salary;
	cout<<"请输入新增的两位职工信息\n";
	for(int i=0;i<2;i++)
	{
		cin>>id>>name>>tel>>age>>salary;
		a[5+i] = worker(id,name,tel,age,salary);
	} 
	out.open("职工信息.txt",ios::out|ios::app);
	for(int i=0;i<2;i++)
	{
		out<<a[5+i].id<<" "<<a[5+i].name<<" "<<a[5+i].tel<<" "<<a[5+i].age<<" "<<a[5+i].salary<<endl;
	}
	out.close();
	ifstream in("职工信息.txt",ios::in); 
	while(in>>id>>name>>tel>>age>>salary)
	{
		cout<<"id:"<<id<<" name："<<name<<" tel:"<<tel<<" age:"<<age<<" salary:"<<salary<<endl;
	} 
	cout<<"请输入id\n";
	int i;
	while(cin>>i&&i)
	{
		for(int i=0;i<7;i++)
		{
			in>>a[i].id>>a[i].name>>a[i].tel>>a[i].age>>a[i].salary;
		}
		int flag = 0;
		int spot;
		for(int j=0;j<7;j++)
		{
			if(a[j].id == i)
			{
				spot = j;
				flag = 1;
				break;
			} 
		}
		if(flag)
		{
			cout<<"id:"<<a[spot].id<<" name:"<<a[spot].name<<" tel:"<<a[spot].tel<<" age:"<<a[spot].age<<" salary:"<<a[spot].salary<<endl;
		}
		else if(!flag)
		{
			cerr<<"无此人\n";
		}
		cout<<"请输入id\n";
	} 
} 
