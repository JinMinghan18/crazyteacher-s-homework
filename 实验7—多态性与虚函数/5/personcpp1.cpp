#include <iostream>
#include "person.h"
#include <string.h>
using namespace std;

void person::display()
{
	cout<<"������"<<name<<endl<<endl
		<<"id: "<<id<<endl<<endl; 
}

int person::time()
{
	return worktime;
}
void student::display()
{
	person::display();
	cout<<"ѧϰʱ�䣺"<<person::time()<<endl<<endl; 
	cout<<"רҵ:"<<major<<endl<<endl
		<<"�༶ְ��"<<classpost<<endl<<endl; 
}
void teacher::display()
{
	person::display();
	cout<<"��ѧʱ����"<<person::time()<<endl<<endl;
	cout<<"����ѧԺ��"<<college<<endl<<endl
		<<"ְ�ƣ�"<<title<<endl<<endl
		<<"���ʣ�"<<salary<<endl<<endl; 
}
void employee::display()
{
	person::display();
	cout<<"����ʱ��:"<<person::time()<<endl;
	cout<<"���ţ�"<<department<<endl;
	cout<<"����:"<<salary<<endl; 
}
