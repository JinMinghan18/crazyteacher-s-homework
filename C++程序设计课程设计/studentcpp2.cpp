#include <iostream>
#include <fstream>
#include<algorithm> 
#include <iomanip>
#include <map>
#include "student.h"
student a[1000000];
int count1,count2;
struct students
{
	string classnames;
	string namee;
	int countname;
	int countclass;
} stu[10000];
bool cmp(students a,students b)
{
	return a.countname<b.countname;
}
int main()
{
	int cnt=0;
	int i;
	
	cout<<"\t\t\t★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
	cout<<"\t\t\t\t☆☆欢迎进入学生考勤系统☆☆"<<endl;
	cout<<"\t\t\t★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  1、录入学生的缺课记录；        ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  2、修改某个学生的缺课记录；    ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  3、查询某个学生的缺课情况      ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  4、旷课学生姓名及旷课次数      ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  5、有学生旷课人次              ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★         ※  0. 退出                        ★"<<endl;
	cout<<"\t\t\t★                                            ★"<<endl;
	cout<<"\t\t\t★★★★★★★★★★★★★★★★★★★★★★★★" <<endl <<endl <<"\t\t";
	cout<<"\t      ※ ******请选择您所需要的信息******※"<<endl;
   	while(1)
	{
		cout<<"请输入数字选择功能\n"; 
		cin>>i;
		switch(i)
		{
			case 0:return 0; 
			case 1:
			{
				cout<<"请输入此次录入的学生人数\n"; 
				cin>>cnt;
				for(int i=0;i<cnt;i++)
				{
					a[i].get_info();
				}
				break;
			}
			case 2:
			{
				int id,date,order;
				cout<<"请输入想要修改的学生学号、缺课时间和课时\n";
				cin>>id;
				cin>>date;
				cin>>order;
				for(int i=0;i<cnt;i++)
				{
					if(a[i].check(id,date,order))
					{
						a[i].modify();
						break;
					}	
				}
				break;  
			}
			case 3:
			{
				int id;
				cout<<"请输入想要查询的学生的学号:\n";
				cin>>id;
				for(int i=0;i<cnt;i++)
				{
					a[i].search(id); 
				}
				break;
			}
			case 4:
			{	
				int cnt2=0;
				int ftime1,ltime1;
				cout<<"请输入起始时间（例如20000101）\n";
				cin>>ftime1;
				cout<<"请输入结束时间（例如20000101）\n";
				cin>>ltime1;
				for(int i = 0;i<cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime1 && time <= ltime1)
					{
						if(i == 0)
						{
							stu[cnt2].namee = a[i].check_name();
							stu[cnt2].countname = 1;
						}
						else 
						{
							int flag = 0;
							for(int j=0;j<=cnt2;j++)
							{
								if(stu[j].namee == a[i].check_name())
								{
									flag = 1;
									stu[j].countname++;
									break; 
								}
							}
							if(!flag)
							{
								cnt2++;
								stu[cnt2].namee = a[i].check_name();
								stu[cnt2].countname = 1;
							}
							count1 = cnt2; 
						} 
					}
					else continue;
				}
				sort(stu,stu+count1,cmp);
				for(int i=0;i<=count1;i++)
				{
					cout<<"姓名： "<<stu[i].namee<<" "<<"旷课次数： "<<stu[i].countname<<endl; 
				}
				break;
			} 
			case 5:
			{
				int cnt3 = 0;
				int ftime2,ltime2;
				cout<<"请输入起始时间（例如20000101）\n";
				cin>>ftime2;
				cout<<"请输入结束时间（例如20000101）\n";
				cin>>ltime2;
				for(int i=0;i<cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime2 && time <= ltime2)
					{
						if(i == 0)
						{
							stu[cnt3].classnames = a[i].check_classname();
							stu[cnt3].countclass = 1;
						}
						else 
						{
							int flag1 = 0;
							for(int j = 0;j<=cnt3;j++)
							{
								if(stu[j].classnames == a[i].check_classname())
								{
									flag1 = 1;
									stu[j].countclass++;
									break;
								}
							}
							if(!flag1)
							{
								cnt3++;
								stu[cnt3].classnames = a[i].check_classname();
								stu[cnt3].countclass = 1;
							}
							count2 = cnt3;
						}
					}
					else continue;
				}
				break;
			}
			
		}
	}
	return 0;
} 
