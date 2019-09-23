#include <iostream>
#include <windows.h>
#include <fstream>
#include<algorithm> 
#include <iomanip>
#include "student.h"
using namespace std;
student a[1000000];
int count1,count2,counttea;//count1是旷课学生数count2是被旷课程数，counttea是老师注册数 
const int admin =  6666;
struct safesystem
{
	string zhanghao;
	string mima;
}tea[2000];
struct students
{
	string classnames;//被旷的课程 
	string namee;//旷课学生name 
	int countname;//旷课次数统计 
	int countclass;//该课程被旷次数统计 
}stu[10000];
int a1[13] = {0,31,30,31,28,31,30,31,31,30,31,30,31};
int a2[13] = {0,31,30,31,29,31,30,31,31,30,31,30,31}; 
bool cmp1(students &a,students &b)
{
	return a.countname>b.countname;
}
bool cmp2(students a,students b)
{
	return a.countclass>b.countclass;
}
int check_time(int fy,int fm,int fd,int ly,int lm,int ld,int y,int m,int d)
{
	int ftime,ltime,time;
	ftime = fy*10000+fm*100+fd;
	ltime = ly*10000+lm*100+ld;
	time = y*10000+m*100+d;
	if(time<=ltime && time>=ftime)
	{
		return 1;
	}
	return 0;
}

int checkdate(int year,int month ,int day)
{
	int flag = 1;
	if((year % 4 == 0 && year % 100 != 0)||(year%400==0)) 
	{
		if(month>0&&month<=12)
		{
			if(day<0 || day>a2[month])
			{
				flag = 0;
			} 
		}
		else
		{
			flag = 0;
		}
	}
	else 
	{
		if(month>0&&month<=12)
		{
			if(day<0 || day>a1[month])
			{
				flag = 0;
			}
		}
		else
		{
			flag = 0;
		}
	}
	return flag;
}

int main()
{
	//密码系统	
	cout<<"请输入管理密码: ";
	int ad;
	cin>>ad;
	if(ad == admin)	
	{
		cout<<"欢迎进入系统\n";
		cout<<"1、注册	2、登录\n";
		int choice;
		cin>>choice;
		if(choice == 1)
		{
			
			cout<<"请输入注册账号（推荐使用教师id): ";
			cin>>tea[counttea].zhanghao;
			cout<<"请输入登陆密码: ";
			cin>>tea[counttea].mima;
			cout<<"\n注册成功。。。\n";
			cout<<"自动登录\n"; 
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
					cout<<"欢迎进入系统";
					cout<<endl<<endl;
					system("pause");
					system("cls");
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
				}
				
				else 
				{
					cerr<<"密码错误\n";
					return 0;
				}
			}
			else
			{
				cerr<<"账号错误\n";
				return 0; 
			}
		}
	}
	else 
	{
		cerr<<"管理员密码错误！\n";
		return 0;
	}
	
	
	//管理界面 
	int cnt=0;
	int i;
	
   	while(1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout<<"请输入数字选择功能\n"; 
		cin>>i;
		switch(i)
		{
			case 0:return 0; 
			
			case 1://录入功能 
			{
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cout<<"请选择\n1、初次录入\n2、补录\n";
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
						int year = a[i].check_year();
						int month = a[i].check_month();
						int day = a[i].check_day();
						int flag = 1;
						if((year % 4 == 0 && year % 100 != 0)||(year%400==0)) 
						{
							if(month>0&&month<=12)
							{
								if(day<0 || day>a2[month])
								{
									flag = 0;
								} 
							}
							else
							{
								flag = 0;
							}
						}
						else 
						{
							if(month>0&&month<=12)
							{
								if(day<0 || day>a1[month])
								{
									flag = 0;
								}
							}
							else
							{
								flag = 0;
							}
						}
						if(!flag)
						{
							cerr<<"日期输入有误，请检查后重输\n";
							int n,y,r;
							cout<<"日期\n";
							cin>>n>>y>>r;
							a[i].chuanru_date(n,y,r); 
						} 
						cout<<endl;
					}
					cout<<"是否导出文本1、yes 0、no\n";
					int i;
					cin>>i;
					if(i)
					{
						cout<<"保存成功！:)"<<endl;
						system("pause"); 
						ofstream outfile("旷课大佬.txt",ios::out|ios::app);
						for(int j=0;j<cnt;j++)
						{
							if(a[j].check_id() == 0) continue;
							outfile<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()
								<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
						}
						outfile.close();				
					}
				}
				else if(c == 2)
				{
					cout<<"请输入此次录入的学生人数\n";
					int b;//补录的学生人数
					cin>>b;
					int temp = cnt;
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
					cout<<"是否导出文本1、yes 0、no\n";
					int i;
					cin>>i;
					if(i)
					{
						cout<<"保存成功！:)"<<endl; 
						system("pause"); 
						ofstream outfile("旷课大佬.txt",ios::out|ios::app);
						for(int j=temp;j<cnt;j++)
						{
							if(a[j].check_id() == 0) continue;
							outfile<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()
								<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
						}
						outfile.close();				
					}
					
				}
				
				break;
			}
			case 2://修改某个学生的缺课记录； 
			{
				string name,classname,abstype;
				int y,m,d,orderr;
				long long idd;
				int i = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>y>>m>>d>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(y,m,d);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				in.close(); 
				long long id;
				int yea,mon,da,order;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"1/修改	2/删除\n"; 
				int pan;
				cin>>pan;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				if(pan == 1)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"请输入想要修改的学生学号、缺课时间和课时\n";
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					cin>>id;
					cin>>yea>>mon>>da;
					cin>>order;
					int flag = 0;
					for(int j=0;j<i;j++)
					{
						if(a[j].check(id,yea,mon,da,order))
						{
							flag = 1;
							a[j].modify();
							break;
						}	
					}
					if(!flag)
					{
						cout<<"缺课记录不存在,请确认后重新修改\n";
					}
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					cout<<"是否保存1/yes 0/no"<<endl;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					int check;//选择是否保存 
					cin>>check;
					if(check)
					{
						cout<<"保存成功！:)"<<endl;
						system("pause");
						ofstream out("旷课大佬.txt",ios::out);
						for(int j=0;j<=i;j++)
						{
							if(a[j].check_id() == 0) continue;
							out<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()
								<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
						}
					}
				}
				else if(pan == 2)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"请输入想要修改的学生学号、缺课时间和课时\n";
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					cin>>id;
					cin>>yea>>mon>>da;
					cin>>order;
					for(int j=0;j<=i;j++)
					{
						if(a[j].check(id,yea,mon,da,order))
						{
							a[j].chuanru_name("0");
							a[j].chuanru_id(0);
							a[j].chuanru_date(0,0,0);
							a[j].chuanru_order(0);
							a[j].chuanru_classname("0");
							a[j].chuanru_abstype("0");
							break;
						}	
					}
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					cout<<"是否保存1/yes 0/no"<<endl;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					int check;//选择是否保存 
					cin>>check;
					if(check)
					{
						cout<<"保存成功！:)"<<endl;
						system("pause");
						ofstream out("旷课大佬.txt",ios::out);
						for(int j=0;j<=i;j++)
						{
							if(a[j].check_id() == 0) continue;
							out<<a[j].check_name()<<" "<<a[j].check_id()<<" "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()
								<<" "<<a[j].check_order()<<" "<<a[j].check_classname()<<" "<<a[j].check_abstype()<<endl;
						}
					}
				} 
				break;  
			}
			case 3://询某个学生的缺课情况 
			{
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int i = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>yea>>mon>>da>>orderr>>classname>>abstype)
				{
					a[i].chuanru_name(name);
					a[i].chuanru_id(idd);
					a[i].chuanru_date(yea,mon,da);
					a[i].chuanru_order(orderr);
					a[i].chuanru_classname(classname);
					a[i].chuanru_abstype(abstype);
					i++;
				}
				in.close();
				//传入结束 
				long long id;
				string n; 
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请选择查询方式\n 1/学号		2/姓名:\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				int aa;
				cin>>aa;
				if(aa == 1)
				{
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n"; 
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n";
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n";
					cin>>id; 
					for(int j=0;j<=i;j++)
					{
						a[j].search(id); 
					}
					cout<<"是否导出该学生的记录1/yes	\n 0/no\n";
					int c;
					cin>>c;
					if(c)
					{
						cout<<"保存成功！:)"<<endl;
						system("pause");
						ofstream out("个人统计.txt",ios::out);
						for(int j=0;j<=i;j++)
						{
							if(id == a[j].check_id())
							{
								out<<a[j].check_name()<<" "
								<<a[j].check_id()<<" "
								<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()<<" "
								<<a[j].check_order()<<" "
								<<a[j].check_abstype()<<endl;
							} 
						}
						out.close();
					}
				}
				else if(aa == 2)
				{
					cout<<"请输入想要搜索的学生姓名\n\n";
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n"; 
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n";
					cout<<"警告：请勿恶意输入会导致程序崩溃！！！！！\n";
					cin>>n; //姓名搜索 
					for(int j=0;j<=i;j++)
					{
						if(n == a[j].check_name())
						{
							cout<<"姓名: "<<a[j].check_name()<<" "
							<<"学号: "<<a[j].check_id()<<" "
							<<"缺课时间: "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()<<" "
							<<"课时: "<<a[j].check_order()<<" "
							<<"缺课类型: "<<a[j].check_abstype()<<endl;
						}
					}
					cout<<"是否导出该学生的记录1/yes	0/no\n";
					int c;
					cin>>c;
					if(c)
					{
						cout<<"保存成功！:)"<<endl;
						ofstream out("个人统计.txt",ios::out);
						for(int j=0;j<=i;j++)
						{
							if(n == a[j].check_name())
							{
								out<<a[j].check_name()<<" "
								<<a[j].check_id()<<" "
								<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()<<" "
								<<a[j].check_order()<<" "
								<<a[j].check_abstype()<<endl;
							} 
						}
						system("pause");
						out.close();
					} 
				}
				break;
			}
			
			case 4://旷课学生姓名及旷课次数 
			{	
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>yea>>mon>>da>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(yea,mon,da);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//传入结束
				int cnt2=-1;
				int ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d;
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入起始时间（例如2000 01 01）\n";
				cin>>ftime_y>>ftime_m>>ftime_d;
				if(!checkdate(ftime_y,ftime_m,ftime_d))
				{
					cerr<<"起始时间有误，请重新输入:\n";
					cin>>ftime_y>>ftime_m>>ftime_d;
				}
				cout<<"请输入结束时间（例如2000 01 01）\n";
				cin>>ltime_y>>ltime_m>>ltime_d;
				if(!checkdate(ltime_y,ltime_m,ltime_d))
				{
					cerr<<"起始时间有误，请重新输入:\n";
					cin>>ltime_y>>ltime_m>>ltime_d;
				}
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i = 0;i<cnt;i++)
				{
					if(a[i].check_id() == 0) continue; 
					int year = a[i].check_year();
					int month = a[i].check_month();
					int day = a[i].check_day();
					if(check_time(ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d,year,month,day))//确定时间范围 
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
				sort(stu,stu+count1+1,cmp1);
				cout<<"姓名                     旷课次数\n";
				for(int i=0;i<=count1;i++)
				{
					cout<<stu[i].namee<<"                            "<<stu[i].countname<<endl; 
				}
				cout<<"是否保存到文本1/yes	0/no\n";
				int c;
				cin>>c;
				if(c == 1)
				{
					cout<<"保存成功！:)"<<endl;
					system("pause");
					ofstream out("六月死刑名单.txt",ios::out|ios::app);
					out<<"姓名                     旷课次数\n";
					for(int i=0;i<=count1;i++)
					{
						out<<stu[i].namee<<"                            "<<stu[i].countname<<endl; 
					}
					out.close();
				}				 
				break;
			} 
			case 5:// 有学生旷课课程和人次  
			{
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("旷课大佬.txt",ios::in);
				//利用函数传入数据，暂时没有更好的办法 
				while(in>>name>>idd>>yea>>mon>>da>>orderr>>classname>>abstype)
				{
					a[cnt].chuanru_name(name);
					a[cnt].chuanru_id(idd);
					a[cnt].chuanru_date(yea,mon,da);
					a[cnt].chuanru_order(orderr);
					a[cnt].chuanru_classname(classname);
					a[cnt].chuanru_abstype(abstype);
					cnt++;
				}
				in.close(); 
				//传入结束
				int cnt3 = 0;
				int ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d;
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"请输入起始时间（例如2000 01 01）\n";
				cin>>ftime_y>>ftime_m>>ftime_d;
				if(!checkdate(ftime_y,ftime_m,ftime_d))
				{
					cerr<<"起始时间有误，请重新输入:\n";
					cin>>ftime_y>>ftime_m>>ftime_d;
				}
				cout<<"请输入结束时间（例如2000 01 01）\n";
				cin>>ltime_y>>ltime_m>>ltime_d;
				if(!checkdate(ltime_y,ltime_m,ltime_d))
				{
					cerr<<"起始时间有误，请重新输入:\n";
					cin>>ltime_y>>ltime_m>>ltime_d;
				}
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i=0;i<=cnt;i++)
				{
					if(a[i].check_id() == 0) continue;
					int year = a[i].check_year();
					int month = a[i].check_month();
					int day = a[i].check_day();
					if(check_time(ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d,year,month,day))
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
				sort(stu,stu+count2+1,cmp2);
				cout<<"被旷课程                  被旷次数\n";
				for(int i=0;i<count2;i++)
				{
					cout<<stu[i].classnames<<"                            "<<stu[i].countclass<<endl;
				} 
				cout<<"是否导出文件1/yes	0/no\n";
				int check;
				cin>>check; 
				if(check == 1)
				{
					cout<<"保存成功！:)"<<endl;
					system("pause");
					ofstream out("课程情况统计.txt",ios::out|ios::app);
					out<<"被旷课程                      被旷次数\n";
					for(int i=0;i<count2;i++)
					{
						out<<stu[i].classnames<<"                            "<<stu[i].countclass<<endl;
					}
					out.close();
				}
				
				break;
			}	
		}
		system("cls");	
	}
	return 0;
} 
