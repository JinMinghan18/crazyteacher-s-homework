#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;
void get_info()
{
	cout<<"请输入录入的学生数：";
	int num;
	cin>>num;
	cout<<"请输入"<<num<<"位同学的信息\n";
	student a[10000];
	for(int i = 0;i < num;i++ )
	{
		cout<<"姓名：" ;
		a[i].get_name();
		cout<<"\n学号："; 
		a[i].get_id(); 
		cout<<"\n缺课时间："; 
		a[i].get_time();
		cout<<"\n课时：" ;
		a[i].get_order();
		cout<<"\n课程名称："; 
		a[i].get_classname();
		cout<<"\n缺课类型：";
		a[i].get_abstype();	
	}
}
void modify()
{	
	
}


