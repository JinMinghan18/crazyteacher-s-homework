#include<iostream>
#include "studenthead.h" 
using namespace std;
int main()
{
	student a[5],stu;	
	int i;
	cout<<"����������ִ������Ҫ�Ĺ��ܣ�1������ѧ����ѧ��\n" ;
	cout<<"2������ѧ���ĸ��Ƴɼ�\n" ;
	cout<<"3�����ѧ����ƽ���ɼ�\n" ;
	cout<<"4�����ѧ�����ܳɼ�\n";
	cout<<"5������ض�ѧ����������Ϣ\n";
	cout<<"6������༶��ɢ��ѧ��߷�\n"; 
	cout<<"7������༶ѧ��Ӣ����߷�\n";
	cout<<"8������༶C++��߷�\n";
	cout<<"9��ȫ�������߷�\n"; 
	cout<<"10��ȫ������Լ�δ�����ͬѧ��Ϣ\n";
	cout<<"0���˳�ϵͳ\n";	 
	while(cin>>i && i)
	{
		switch(i)
		{
			case 1:
				{
					for(int i = 0;i<5;i++)
					{	
						cout<<"�������"<<i+1<<"λͬѧ��ѧ��"; 
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
					cout<<"���������ѯ��ѧ��ѧ�ţ�"; 
					cin>>j;	
					int point = b.search(a,j);
					a[point].print_stu();	
					break; 
				}
			case 6:
				{
					student b;
					b.index = stu.maxscoree(a);
					cout<<"�༶��Ӣ����߷�Ϊ��";
					a[b.index].show_escore();
					break;
				}
			case 7:
				{
					student b;
					b.index = stu.maxscorem(a);
					cout<<"�༶����ɢ��ѧ��߷�Ϊ��";
					a[b.index].show_mscore();
					break;
				} 
			case 8:
				{
					student b;
					b.index = stu.maxscorec(a);
					cout<<"�༶��C++��߷�Ϊ��";
					a[b.index].show_cscore();
					break;
				}
			case 9:
				{
					student b;
					b.index = stu.maxscoresum(a);
					cout<<"ȫ���ܷ���߷�Ϊ��";
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
