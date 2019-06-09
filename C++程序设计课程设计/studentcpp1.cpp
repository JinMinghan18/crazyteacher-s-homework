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
	cout<<"请重新输入想要更改信息\n";
	get_name();
	get_id(); 
	get_time();
	get_order();
	get_classname();
	get_abstype();
}
int student::check(long long i,int y,int m,int d,int o)
{
	if(id == i && y == year&&m == month &&d == day && o == order)
	return 1;
	else return 0;
}
void student::search(long long n)
{
	if(id == n)
	{
		cout<<"姓名: "<<name<<" "
			<<"学号: "<<id<<" "
			<<"缺课时间: "<<year<<" "<<month<<" "<<day<<" "
			<<"课时: "<<order<<" "
			<<"缺课类型: "<<abstype<<endl;
	}
}




