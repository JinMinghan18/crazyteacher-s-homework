#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;
void get_info()
{
	cout<<"������¼���ѧ������";
	int num;
	cin>>num;
	cout<<"������"<<num<<"λͬѧ����Ϣ\n";
	student a[10000];
	for(int i = 0;i < num;i++ )
	{
		cout<<"������" ;
		a[i].get_name();
		cout<<"\nѧ�ţ�"; 
		a[i].get_id(); 
		cout<<"\nȱ��ʱ�䣺"; 
		a[i].get_time();
		cout<<"\n��ʱ��" ;
		a[i].get_order();
		cout<<"\n�γ����ƣ�"; 
		a[i].get_classname();
		cout<<"\nȱ�����ͣ�";
		a[i].get_abstype();	
	}
}
void modify()
{	
	
}


