#include <iostream>
#include <fstream>
#include <map>
#include "student.h"
using namespace std;
void student::get_info()
{
		
		get_name();
		
		get_id(); 
		
		get_time();
		
		get_order();
		
		get_classname();
		
		get_abstype();	
}
void student::modify()
{	
	cout<<"������������Ҫ������Ϣ\n����ɾ����ȫ������0\n";
	get_name();
	get_id(); 
	get_time();
	get_order();
	get_classname();
	get_abstype();
}
int student::check(long long i,int d,int o)
{
	if(id == i && d == date && o == order)
	return 1;
	else return 0;
}
void student::search(long long n)
{
	if(id == n)
	{
		cout<<"����: "<<name<<" "
			<<"ѧ��: "<<id<<" "
			<<"ȱ��ʱ��: "<<date<<" "
			<<"��ʱ: "<<order<<" "
			<<"ȱ������: "<<abstype<<endl;
	}
}




