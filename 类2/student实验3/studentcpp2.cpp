#include<iostream>
#include "studenthead.h" 
using namespace std;
int main()
{
	student a[5],stu;	
	int i;
	cout<<"请输入数字执行你想要的功能：1、输入学生的学号\n" ;
	cout<<"2、输入学生的各科成绩\n" ;
	cout<<"3、输出学生的平均成绩\n" ;
	cout<<"4、输出学生的总成绩\n";
	cout<<"5、输出特定学生的所有信息\n";
	cout<<"6、输出班级离散数学最高分\n"; 
	cout<<"7、输出班级学术英语最高分\n";
	cout<<"8、输出班级C++最高分\n";
	cout<<"9、全班的总最高分\n"; 
	cout<<"10、全班均分以及未达均分同学信息\n";
	cout<<"0、退出系统\n";	 
	while(cin>>i && i)
	{
		switch(i)
		{
			case 1:
				{
					for(int i = 0;i<5;i++)
					{	
						cout<<"请输入第"<<i+1<<"位同学的学号"; 
						a[i].get_stu_num();
					}
					break;
				}
			case 2:
				{
					for(int i = 0;i<5;i++)
					{
						a[i].set_stu_inf();
					}				
					break;
				}	
			case 3:
				{
					for(int i=0;i<5;i++)
					{
						a[i].show_aver();
					} 
					break;
				} 
			case 4:
				{
					for(int i=0;i<5;i++)
					{
						a[i].show_sum();
					}
					break;
				}
			case 5:
				{
					student b;
					int j;
					cout<<"请输入想查询的学生学号："; 
					cin>>j;	
					int point = b.search(a,j);
					a[point].print_stu();	
					break; 
				}
			case 6:
				{
					student b;
					b.index = stu.maxscoree(a);
					cout<<"班级中英语最高分为：";
					a[b.index].show_escore();
					break;
				}
			case 7:
				{
					student b;
					b.index = stu.maxscorem(a);
					cout<<"班级中离散数学最高分为：";
					a[b.index].show_mscore();
					break;
				} 
			case 8:
				{
					student b;
					b.index = stu.maxscorec(a);
					cout<<"班级中C++最高分为：";
					a[b.index].show_cscore();
					break;
				}
			case 9:
				{
					student b;
					b.index = stu.maxscoresum(a);
					cout<<"全班总分最高分为：";
					a[b.index].show_sum(); 
					break; 
				}
			case 10:
				{
					student stu;
					stu.show_classaver(a);
					break;
				}
			 
		}
	}
	 
	
} 
