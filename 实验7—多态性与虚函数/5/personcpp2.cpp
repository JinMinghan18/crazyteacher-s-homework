#include <iostream>
#include "person.h"
#include <string.h>
using namespace std;
int main()
{
	while(1)
	{
		cout<<"�㽭��ҵ��ѧ         ��Ϣ����ƽ̨"<<endl;
		cout<<"*********************************"<<endl;
		cout<<"1\ѧ����Ϣ����\n";
		cout<<"2\��ʦ��Ϣ����\n";
		cout<<"3\ְ����Ϣ����\n";
		cout<<"4\�˳�ϵͳ\n";
		cout<<"*********************************"<<endl;
		int i;
		cin>>i;
		person *p; 
		if(i == 4)	break;
		else if(i == 1)
		{
			cout<<"ѧ������ϵͳ\n";
			string name;
			string id;
			double time;
			string college;
			string classpos;
			cout<<"������ѧ������:";
			cin>>name;
			cout<<"\n������ѧ��id:";
			cin>>id;
			cout<<"\n������ѧ��ѧϰʱ��:";
			cin>>time;
			cout<<"\n������ѧ��ѧԺ:";
			cin>>college;
			cout<<"\n������ѧ��ְ��:";
			cin>>classpos;
			student stu(id,name,time,college,classpos);
			p = &stu;
			p->display(); 
		}
		else if(i == 2)
		{
			cout<<"��ʦ����ϵͳ\n";
			string name;
			string id;
			double time;
			double s;
			string college;
			string pos;
			string tit;
			cout<<"�������ʦ����:";
			cin>>name;
			cout<<"\n �������ʦid:";
			cin>>id;
			cout<<"\n �������ʦ�ڿ�ʱ��:";
			cin>>time;
			cout<<"\n �������ʦѧԺ:";
			cin>>college;
			cout<<"\n �������ʦְ��:"; 
			cin>>tit;
			cout<<"\n �������ʦ����:";
			cin>>s; 
			teacher tea(id,name,time,college,tit,s);
			p = &tea;
			p->display(); 
		}
		else if(i == 3)
		{
			cout<<"ְ������ϵͳ\n";
			string name;
			string id;
			double time;
			string dep;
			double s;
			cout<<"������ְ������:";
			cin>>name;
			cout<<"\n������ְ��id:";
			cin>>id;
			cout<<"\n������ְ������ʱ��";
			cin>>time;
			cout<<"\n������ְ����������";
			cin>>dep;
			cout<<"\n������ְ������"; 
			cin>>s;
			employee emp(id,name,time,dep,s);
			p = &emp;
			p->display(); 
		}
	}
	
} 
