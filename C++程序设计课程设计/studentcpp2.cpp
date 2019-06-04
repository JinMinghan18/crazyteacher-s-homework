#include <iostream>
#include <fstream>
#include<algorithm> 
#include <iomanip>
#include <map>
#include "student.h"
student a[1000000];
int count1,count2,counttea;//count1是旷课学生数count2是被旷课程数，counttea是老师注册数 
const int admin =  6666;
struct safesystem
{
	string zhanghao;
	string mima;
}tea[1000];
struct students
{
	string classnames;//被旷的课程 
	string namee;//旷课学生name 
	int countname;//旷课次数统计 
	int countclass;//该课程被旷次数统计 
}stu[10000];
bool cmp(students a,students b)
{
	return a.countname>b.countname;
}
bool cmp1(students a,students b)
{
	return a.countclass>b.countclass;
}
int main()
{
	//密码系统	
	cout<<"请输入管理密码: ";
	int ad;
	cin>>ad;
	if(ad == admin)	
	{
		cout<<"welcome to the system teacher\n";
		cout<<"1、register in 2、log on\n";
		int choice;
		cin>>choice;
		if(choice == 1)
		{
			cout<<"请输入注册账号（推荐使用教师id): ";
			cin>>tea[counttea].zhanghao;
			cout<<"请输入登陆密码: ";
			cin>>tea[counttea].mima;
			cout<<"\nregister successfully\n";
			ofstream out("教师账号.txt",ios::app|ios::out);
			out<<tea[counttea].zhanghao<<" "<<tea[counttea].mima<<" "<<endl;
			out.close();
		}
		else if(choice == 2)
		{ 
			ifstream in("教师账号.txt");
			int i=0;
			while(in>>tea[i].zhanghao>>tea[i].mima)
			{
				i++;
			}
			string zh,mm;
			cout<<"请输入账号："; 
			cin>>zh;
			cout<<endl;
			cout<<"请输入密码："; 
			cin>>mm;
			int flag = 0;//确认是否存在账号 
			int spot;//记录相符账号位置 
			for(int j = 0;j<=1000;j++)
			{
				if(tea[j].zhanghao == zh )
				{
					flag = 1;
					spot = j;
				}
			}
			if(flag)
			{
				if(tea[spot].mima == mm)
				{
					cout<<"welcome sir\n";
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
				}
				
				else 
				{
					cerr<<"wrong key\n";
					return 0;
				}
			}
			else
			{
				cerr<<"wrong cipher\n";
				return 0; 
			}
		}
	}
	else 
	{
		cout<<"big key wrong\n";
		return 0;
	}
	
	//管理界面 
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
	cout<<"\t\t\t★         ※  5、有学生旷课课程和人次        ★"<<endl;
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
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cout<<"请选择是1、初次录入2、补录\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				int c;
				cin>>c;
				if(c == 1)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"请输入此次录入的学生人数\n";
					cin>>cnt;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					for(int i=0;i<cnt;i++)
					{
						a[i].get_info();
						cout<<endl;
					}
				}
				else if(c == 2)
				{
					cout<<"请输入此次录入的学生人数\n";
					int b;//补录的学生人数
					cin>>b;
					for(int i=0;i<cnt;i++)
					{
						if(a[i].check_id() == 0)
						{
							a[i].get_info();
							b--;
						}
					} 
					for(int i = cnt;i<cnt+b;i++)
					{
						a[i].get_info();
					} 
					cnt+=b;
				}
				cout<<"是否导出文本1、yes 0、no\n";
				int i;
				cin>>i;
				if(i == 1)
				{
					ofstream outfile("旷课大佬.txt",ios::out|ios::app);
					for(int j=0;j<cnt;j++)
					{
						outfile<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_time()
							<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
					}				
				}
				else if(i == 0)
				break;
				break;
			}
			case 2://修改某个学生的缺课记录； 
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int i = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(datee);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				int id,date,order;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入想要修改的学生学号、缺课时间和课时\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cin>>id;
				cin>>date;
				cin>>order;
				for(int j=0;j<=i;j++)
				{
					if(a[j].check(id,date,order))
					{
						a[j].modify();
						break;
					}	
				}
				break;  
			}
			case 3://询某个学生的缺课情况 
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int i = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(datee);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				in.close();
				//传入结束 
				long long id;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入想要查询的学生的学号:\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cin>>id;
				for(int j=0;j<=i;j++)
				{
					a[j].search(id); 
				}
				break;
			}
			
			case 4://旷课学生姓名及旷课次数 
			{	
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(datee);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//传入结束
				int cnt2=0;
				int ftime1,ltime1;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入起始时间（例如20000101）\n";
				cin>>ftime1;
				cout<<"请输入结束时间（例如20000101）\n";
				cin>>ltime1;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i = 0;i<cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime1 && time <= ltime1)
					{
						if(i == 0)//第一次确认
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
									stu[j].countname++;//该学生旷课次数+1 
									break; 
								}
							}
							if(!flag)//如果没有在已有名单中找到该旷课学生 
							{
								cnt2++;//旷课学生数++； 
								stu[cnt2].namee = a[i].check_name();
								stu[cnt2].countname = 1;
							}
							count1 = cnt2;//传递总旷课学生数 
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
			case 5:// 有学生旷课课程和人次  
			{
				string name,classname,abstype;
				int datee,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>datee>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(datee);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//传入结束
				int cnt3 = 0;
				int ftime2,ltime2;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入起始时间（例如20000101）\n";
				cin>>ftime2;
				cout<<"请输入结束时间（例如20000101）\n";
				cin>>ltime2;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i=0;i<=cnt;i++)
				{
					int time = a[i].check_time();
					if(time>=ftime2 && time <= ltime2)
					{
						if(i == 0)//第一次搜索 
						{
							stu[cnt3].classnames = a[i].check_classname();
							stu[cnt3].countclass = 1;
						}
						else 
						{
							int flag1 = 0;
							for(int j = 0;j<=cnt3;j++)//cnt3是当下总记录下的人数，用于比较后输入的人是否有重复 
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
				sort(stu,stu+count2,cmp1);
				cout<<"被旷课程                  被旷次数\n";
				for(int i=0;i<count2;i++)
				{
					cout<<stu[i].classnames<<"                            "<<stu[i].countclass<<endl;
				} 
				break;
			}
			
		}
	}
	return 0;
} 
