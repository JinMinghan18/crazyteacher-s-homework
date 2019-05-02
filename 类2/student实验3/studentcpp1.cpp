#include<iostream>
#include "studenthead.h" 
using namespace std;
void student::get_stu_num()
{
	cin>>num;
}
//得到学号 
void student::set_stu_inf() 
{
	cout<<"请输入学号为"<<num<<"的学生的姓名\n" ;
	cin>>name;
	cout<<"请输入学号为"<<num<<"的学生的英语、离散、C++成绩\n" ;
	cin>>escore>>mscore>>cscore; 
	sum = escore+mscore+cscore;
}//得到全部信息 
void student::show_name()
{
	cout<<"该学生的学号、姓名为：\n" ;
	cout<<num<<" "<<name<<endl; 
}//得到学号姓名 
int student::search(student *s,int j)
{
	int point;
	for(int i=0;i<5;i++)
	{
		if(s[i].num == j)
		point = i;
	}
	return point;
}

void student::print_stu()
{
	cout<<"该学生的学号、姓名为：\n" ;
	cout<<num<<" "<<name<<endl; 
	cout<<"该学生的英语、离散、C++成绩分别为:\n" ;
	cout<<escore<<" "<<mscore<<" "<<cscore<<endl; 
}//输出全部信息 
void student::show_aver()
{
	aver = (escore+ cscore+ mscore)/3;
	cout<<"该学号为"<<num<<"同学的平均成绩为"<<aver<<endl; 
}//输出平均成绩 
void student::show_sum()
{
	sum = escore+ cscore+ mscore;
	cout<<"该学号为"<<num<<"同学的总成绩为"<<sum<<endl; 
}//输出总成绩 
int student::maxscoree(student *s)
{
	int maxn;
	student index;
	maxn = s[0].escore;
	for(int i = 0;i<5;i++)
	{
		if(s[i].escore > maxn)
		{
			maxn = s[i].escore;
			index.index = i;
		}
	}
	return index.index;
}//找到英语最高分的位置 
int student::maxscorem(student *s)
{
	int maxn,index = 0;
	maxn = s[0].mscore;
	for(int i = 0;i<5;i++)
	{
		if(s[i].mscore > maxn)
		{
			maxn = s[i].mscore;
			index = i;
		}
	}
	return index;
}//找到离散最高分的位置 
int student::maxscorec(student *s)
{
	int maxn,index = 0;
	maxn = s[0].cscore;
	for(int i = 0;i<5;i++)
	{
		if(s[i].cscore > maxn)
		{
			maxn = s[i].cscore;
			index = i;
		}
	}
	return index;
}//找到C++最高分的位置 
void student::show_escore()
{
	cout<<num<<"号"<<"的"<<name<<"同学"<<"成绩为"<<escore<<endl; 
} 
void student::show_mscore()
{
	cout<<num<<"号"<<"的"<<name<<"同学"<<"成绩为"<<mscore<<endl; 
} 
void student::show_cscore()
{
	cout<<num<<"号"<<"的"<<name<<"同学"<<"成绩为"<<cscore<<endl; 
}
int student::maxscoresum(student *s)
{
	int maxn,index = 0;
	maxn = s[0].sum;
	for(int i = 0;i<5;i++)
	{
		if(s[i].sum > maxn)
		{
			maxn = s[i].sum;
			index = i;
		}
	}
	return index;
}//找到总分最高分的位置 
void student::show_classaver(student *s)
{
	int sum = 0;
	for(int i=0;i<5;i++)
	{
		sum+=s[i].escore+ s[i].mscore+s[i].cscore;
	}
	cout<<"该班的平均分为： "; 
	int temp = sum/5;
	cout<<sum/5<<endl;
	cout<<"以下同学成绩未达平均：\n";
	for(int i=0;i<5;i++)
	{
		if(s[i].sum<temp)
		{
			cout<<s[i].num<<" "<<s[i].name<<endl;
		} 
	} 
}
