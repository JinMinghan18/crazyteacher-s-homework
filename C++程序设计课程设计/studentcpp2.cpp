#include <iostream>
#include <windows.h>
#include <fstream>
#include<algorithm> 
#include <iomanip>
#include "student.h"
using namespace std;
student a[1000000];
int count1,count2,counttea;//count1�ǿ���ѧ����count2�Ǳ����γ�����counttea����ʦע���� 
const int admin =  6666;
struct safesystem
{
	string zhanghao;
	string mima;
}tea[2000];
struct students
{
	string classnames;//�����Ŀγ� 
	string namee;//����ѧ��name 
	int countname;//���δ���ͳ�� 
	int countclass;//�ÿγ̱�������ͳ�� 
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
	//����ϵͳ	
	cout<<"�������������: ";
	int ad;
	cin>>ad;
	if(ad == admin)	
	{
		cout<<"��ӭ����ϵͳ\n";
		cout<<"1��ע��	2����¼\n";
		int choice;
		cin>>choice;
		if(choice == 1)
		{
			
			cout<<"������ע���˺ţ��Ƽ�ʹ�ý�ʦid): ";
			cin>>tea[counttea].zhanghao;
			cout<<"�������½����: ";
			cin>>tea[counttea].mima;
			cout<<"\nע��ɹ�������\n";
			cout<<"�Զ���¼\n"; 
			ofstream out("��ʦ�˺�.txt",ios::app|ios::out);
			out<<tea[counttea].zhanghao<<" "<<tea[counttea].mima<<" "<<endl;
			out.close();
		}
		else if(choice == 2)
		{ 
			ifstream in("��ʦ�˺�.txt");
			int i=0;
			while(in>>tea[i].zhanghao>>tea[i].mima)
			{
				i++;
			}
			string zh,mm;
			cout<<"�������˺ţ�"; 
			cin>>zh;
			cout<<endl;
			cout<<"���������룺"; 
			cin>>mm;
			int flag = 0;//ȷ���Ƿ�����˺� 
			int spot;//��¼����˺�λ�� 
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
					cout<<"��ӭ����ϵͳ";
					cout<<endl<<endl;
					system("pause");
					system("cls");
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
				}
				
				else 
				{
					cerr<<"�������\n";
					return 0;
				}
			}
			else
			{
				cerr<<"�˺Ŵ���\n";
				return 0; 
			}
		}
	}
	else 
	{
		cerr<<"����Ա�������\n";
		return 0;
	}
	
	
	//������� 
	int cnt=0;
	int i;
	
   	while(1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		cout<<"\t\t\t�������������������������"<<endl;
		cout<<"\t\t\t\t��ӭ����ѧ������ϵͳ���"<<endl;
		cout<<"\t\t\t�������������������������"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  1��¼��ѧ����ȱ�μ�¼��        ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  2���޸�ĳ��ѧ����ȱ�μ�¼��    ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  3����ѯĳ��ѧ����ȱ�����      ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  4������ѧ�����������δ���      ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  5����ѧ�����ογ̺��˴�        ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t��         ��  0. �˳�                        ��"<<endl;
		cout<<"\t\t\t��                                            ��"<<endl;
		cout<<"\t\t\t�������������������������" <<endl <<endl <<"\t\t";
		cout<<"\t      �� ******��ѡ��������Ҫ����Ϣ******��"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout<<"����������ѡ����\n"; 
		cin>>i;
		switch(i)
		{
			case 0:return 0; 
			
			case 1://¼�빦�� 
			{
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				cout<<"��ѡ��\n1������¼��\n2����¼\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				int c;
				cin>>c;
				if(c == 1)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"������˴�¼���ѧ������\n";
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
							cerr<<"���������������������\n";
							int n,y,r;
							cout<<"����\n";
							cin>>n>>y>>r;
							a[i].chuanru_date(n,y,r); 
						} 
						cout<<endl;
					}
					cout<<"�Ƿ񵼳��ı�1��yes 0��no\n";
					int i;
					cin>>i;
					if(i)
					{
						cout<<"����ɹ���:)"<<endl;
						system("pause"); 
						ofstream outfile("���δ���.txt",ios::out|ios::app);
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
					cout<<"������˴�¼���ѧ������\n";
					int b;//��¼��ѧ������
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
					cout<<"�Ƿ񵼳��ı�1��yes 0��no\n";
					int i;
					cin>>i;
					if(i)
					{
						cout<<"����ɹ���:)"<<endl; 
						system("pause"); 
						ofstream outfile("���δ���.txt",ios::out|ios::app);
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
			case 2://�޸�ĳ��ѧ����ȱ�μ�¼�� 
			{
				string name,classname,abstype;
				int y,m,d,orderr;
				long long idd;
				int i = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
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
				cout<<"1/�޸�	2/ɾ��\n"; 
				int pan;
				cin>>pan;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				if(pan == 1)
				{
					cout<<"/---------------------------------------------------------------------------------------/\n" ;	
					cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�š�ȱ��ʱ��Ϳ�ʱ\n";
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
						cout<<"ȱ�μ�¼������,��ȷ�Ϻ������޸�\n";
					}
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					cout<<"�Ƿ񱣴�1/yes 0/no"<<endl;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					int check;//ѡ���Ƿ񱣴� 
					cin>>check;
					if(check)
					{
						cout<<"����ɹ���:)"<<endl;
						system("pause");
						ofstream out("���δ���.txt",ios::out);
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
					cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�š�ȱ��ʱ��Ϳ�ʱ\n";
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
					cout<<"�Ƿ񱣴�1/yes 0/no"<<endl;
					cout<<"/---------------------------------------------------------------------------------------/\n" ;
					int check;//ѡ���Ƿ񱣴� 
					cin>>check;
					if(check)
					{
						cout<<"����ɹ���:)"<<endl;
						system("pause");
						ofstream out("���δ���.txt",ios::out);
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
			case 3://ѯĳ��ѧ����ȱ����� 
			{
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int i = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
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
				//������� 
				long long id;
				string n; 
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��ѡ���ѯ��ʽ\n 1/ѧ��		2/����:\n";
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				int aa;
				cin>>aa;
				if(aa == 1)
				{
					cout<<"���棺�����������ᵼ�³����������������\n"; 
					cout<<"���棺�����������ᵼ�³����������������\n";
					cout<<"���棺�����������ᵼ�³����������������\n";
					cin>>id; 
					for(int j=0;j<=i;j++)
					{
						a[j].search(id); 
					}
					cout<<"�Ƿ񵼳���ѧ���ļ�¼1/yes	\n 0/no\n";
					int c;
					cin>>c;
					if(c)
					{
						cout<<"����ɹ���:)"<<endl;
						system("pause");
						ofstream out("����ͳ��.txt",ios::out);
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
					cout<<"��������Ҫ������ѧ������\n\n";
					cout<<"���棺�����������ᵼ�³����������������\n"; 
					cout<<"���棺�����������ᵼ�³����������������\n";
					cout<<"���棺�����������ᵼ�³����������������\n";
					cin>>n; //�������� 
					for(int j=0;j<=i;j++)
					{
						if(n == a[j].check_name())
						{
							cout<<"����: "<<a[j].check_name()<<" "
							<<"ѧ��: "<<a[j].check_id()<<" "
							<<"ȱ��ʱ��: "<<a[j].check_year()<<" "<<a[j].check_month()<<" "<<a[j].check_day()<<" "
							<<"��ʱ: "<<a[j].check_order()<<" "
							<<"ȱ������: "<<a[j].check_abstype()<<endl;
						}
					}
					cout<<"�Ƿ񵼳���ѧ���ļ�¼1/yes	0/no\n";
					int c;
					cin>>c;
					if(c)
					{
						cout<<"����ɹ���:)"<<endl;
						ofstream out("����ͳ��.txt",ios::out);
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
			
			case 4://����ѧ�����������δ��� 
			{	
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
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
				//�������
				int cnt2=-1;
				int ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d;
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������ʼʱ�䣨����2000 01 01��\n";
				cin>>ftime_y>>ftime_m>>ftime_d;
				if(!checkdate(ftime_y,ftime_m,ftime_d))
				{
					cerr<<"��ʼʱ����������������:\n";
					cin>>ftime_y>>ftime_m>>ftime_d;
				}
				cout<<"���������ʱ�䣨����2000 01 01��\n";
				cin>>ltime_y>>ltime_m>>ltime_d;
				if(!checkdate(ltime_y,ltime_m,ltime_d))
				{
					cerr<<"��ʼʱ����������������:\n";
					cin>>ltime_y>>ltime_m>>ltime_d;
				}
				cout<<"/---------------------------------------------------------------------------------------/\n" ;
				for(int i = 0;i<cnt;i++)
				{
					if(a[i].check_id() == 0) continue; 
					int year = a[i].check_year();
					int month = a[i].check_month();
					int day = a[i].check_day();
					if(check_time(ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d,year,month,day))//ȷ��ʱ�䷶Χ 
					{
						int flag = 0;
						for(int j=0;j<=cnt2;j++)
						{
							if(stu[j].namee == a[i].check_name())
							{
								flag = 1;
								stu[j].countname++;//��ѧ�����δ���+1 
								break;
							}
						}
						if(!flag)//���û���������������ҵ��ÿ���ѧ�� 
						{
							cnt2++;//����ѧ����++�� 
							stu[cnt2].namee = a[i].check_name();
							stu[cnt2].countname = 1;
						}
						count1 = cnt2;//�����ܿ���ѧ���� 
					}
				}
				sort(stu,stu+count1+1,cmp1);
				cout<<"����                     ���δ���\n";
				for(int i=0;i<=count1;i++)
				{
					cout<<stu[i].namee<<"                            "<<stu[i].countname<<endl; 
				}
				cout<<"�Ƿ񱣴浽�ı�1/yes	0/no\n";
				int c;
				cin>>c;
				if(c == 1)
				{
					cout<<"����ɹ���:)"<<endl;
					system("pause");
					ofstream out("������������.txt",ios::out|ios::app);
					out<<"����                     ���δ���\n";
					for(int i=0;i<=count1;i++)
					{
						out<<stu[i].namee<<"                            "<<stu[i].countname<<endl; 
					}
					out.close();
				}				 
				break;
			} 
			case 5:// ��ѧ�����ογ̺��˴�  
			{
				string name,classname,abstype;
				int yea,mon,da,orderr;
				long long idd;
				int cnt = 0;
				ifstream in("���δ���.txt",ios::in);
				//���ú����������ݣ���ʱû�и��õİ취 
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
				//�������
				int cnt3 = 0;
				int ftime_y,ftime_m,ftime_d,ltime_y,ltime_m,ltime_d;
				cout<<endl;
				cout<<"/---------------------------------------------------------------------------------------/\n" ;	
				cout<<"��������ʼʱ�䣨����2000 01 01��\n";
				cin>>ftime_y>>ftime_m>>ftime_d;
				if(!checkdate(ftime_y,ftime_m,ftime_d))
				{
					cerr<<"��ʼʱ����������������:\n";
					cin>>ftime_y>>ftime_m>>ftime_d;
				}
				cout<<"���������ʱ�䣨����2000 01 01��\n";
				cin>>ltime_y>>ltime_m>>ltime_d;
				if(!checkdate(ltime_y,ltime_m,ltime_d))
				{
					cerr<<"��ʼʱ����������������:\n";
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
						for(int j = 0;j<=cnt3;j++)//cnt3�ǵ����ܼ�¼�µ����������ڱȽϺ���������Ƿ����ظ� 
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
				cout<<"�����γ�                  ��������\n";
				for(int i=0;i<count2;i++)
				{
					cout<<stu[i].classnames<<"                            "<<stu[i].countclass<<endl;
				} 
				cout<<"�Ƿ񵼳��ļ�1/yes	0/no\n";
				int check;
				cin>>check; 
				if(check == 1)
				{
					cout<<"����ɹ���:)"<<endl;
					system("pause");
					ofstream out("�γ����ͳ��.txt",ios::out|ios::app);
					out<<"�����γ�                      ��������\n";
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
