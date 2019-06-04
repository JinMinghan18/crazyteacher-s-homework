#include <iostream>
#include "person.h"
#include <string.h>
using namespace std;
int main()
{
	while(1)
	{
		cout<<"浙江工业大学         信息管理平台"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"1\学生信息管理\n";
		cout<<"2\教师信息管理\n";
		cout<<"3\职工信息管理\n";
		cout<<"4\退出系统\n";
		cout<<"*********************************"<<endl;
		int i;
		cin>>i;
		person *p; 
		if(i == 4)	break;
		else if(i == 1)
		{
			cout<<"学生管理系统\n";
			string name;
			string id;
			double time;
			string college;
			string classpos;
			cout<<"请输入学生姓名:";
			cin>>name;
			cout<<"\n请输入学生id:";
			cin>>id;
			cout<<"\n请输入学生学习时间:";
			cin>>time;
			cout<<"\n请输入学生学院:";
			cin>>college;
			cout<<"\n请输入学生职务:";
			cin>>classpos;
			student stu(id,name,time,college,classpos);
			p = &stu;
			p->display(); 
		}
		else if(i == 2)
		{
			cout<<"老师管理系统\n";
			string name;
			string id;
			double time;
			double s;
			string college;
			string pos;
			string tit;
			cout<<"请输入教师姓名:";
			cin>>name;
			cout<<"\n 请输入教师id:";
			cin>>id;
			cout<<"\n 请输入教师授课时间:";
			cin>>time;
			cout<<"\n 请输入教师学院:";
			cin>>college;
			cout<<"\n 请输入教师职称:"; 
			cin>>tit;
			cout<<"\n 请输入教师工资:";
			cin>>s; 
			teacher tea(id,name,time,college,tit,s);
			p = &tea;
			p->display(); 
		}
		else if(i == 3)
		{
			cout<<"职工管理系统\n";
			string name;
			string id;
			double time;
			string dep;
			double s;
			cout<<"请输入职工姓名:";
			cin>>name;
			cout<<"\n请输入职工id:";
			cin>>id;
			cout<<"\n请输入职工工作时间";
			cin>>time;
			cout<<"\n请输入职工所属部门";
			cin>>dep;
			cout<<"\n请输入职工工资"; 
			cin>>s;
			employee emp(id,name,time,dep,s);
			p = &emp;
			p->display(); 
		}
	}
	
} 
