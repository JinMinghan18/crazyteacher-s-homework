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
	cout<<"\t\t\t��         ��  5����ѧ�������˴�              ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t��         ��  0. �˳�                        ��"<<endl;
	cout<<"\t\t\t��                                            ��"<<endl;
	cout<<"\t\t\t�������������������������" <<endl <<endl <<"\t\t";
	cout<<"\t      �� ******��ѡ��������Ҫ����Ϣ******��"<<endl;
   	while(1)
	{
		cout<<"����������ѡ����\n"; 
		cin>>i;
		switch(i)
		{
			case 0:return 0; 
			case 1:
			{
				cout<<"������˴�¼���ѧ������\n"; 
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
				cout<<"��������Ҫ�޸ĵ�ѧ��ѧ�š�ȱ��ʱ��Ϳ�ʱ\n";
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
				cout<<"��������Ҫ��ѯ��ѧ����ѧ��:\n";
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
				cout<<"��������ʼʱ�䣨����20000101��\n";
				cin>>ftime1;
				cout<<"���������ʱ�䣨����20000101��\n";
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
					cout<<"������ "<<stu[i].namee<<" "<<"���δ����� "<<stu[i].countname<<endl; 
				}
				break;
			} 
			case 5:
			{
				int cnt3 = 0;
				int ftime2,ltime2;
				cout<<"��������ʼʱ�䣨����20000101��\n";
				cin>>ftime2;
				cout<<"���������ʱ�䣨����20000101��\n";
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
