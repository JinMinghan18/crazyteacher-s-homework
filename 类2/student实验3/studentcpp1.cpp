#include<iostream>
#include "studenthead.h" 
using namespace std;
void student::get_stu_num()
{
	cin>>num;
}
//�õ�ѧ�� 
void student::set_stu_inf() 
{
	cout<<"������ѧ��Ϊ"<<num<<"��ѧ��������\n" ;
	cin>>name;
	cout<<"������ѧ��Ϊ"<<num<<"��ѧ����Ӣ���ɢ��C++�ɼ�\n" ;
	cin>>escore>>mscore>>cscore; 
	sum = escore+mscore+cscore;
}//�õ�ȫ����Ϣ 
void student::show_name()
{
	cout<<"��ѧ����ѧ�š�����Ϊ��\n" ;
	cout<<num<<" "<<name<<endl; 
}//�õ�ѧ������ 
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
	cout<<"��ѧ����ѧ�š�����Ϊ��\n" ;
	cout<<num<<" "<<name<<endl; 
	cout<<"��ѧ����Ӣ���ɢ��C++�ɼ��ֱ�Ϊ:\n" ;
	cout<<escore<<" "<<mscore<<" "<<cscore<<endl; 
}//���ȫ����Ϣ 
void student::show_aver()
{
	aver = (escore+ cscore+ mscore)/3;
	cout<<"��ѧ��Ϊ"<<num<<"ͬѧ��ƽ���ɼ�Ϊ"<<aver<<endl; 
}//���ƽ���ɼ� 
void student::show_sum()
{
	sum = escore+ cscore+ mscore;
	cout<<"��ѧ��Ϊ"<<num<<"ͬѧ���ܳɼ�Ϊ"<<sum<<endl; 
}//����ܳɼ� 
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
}//�ҵ�Ӣ����߷ֵ�λ�� 
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
}//�ҵ���ɢ��߷ֵ�λ�� 
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
}//�ҵ�C++��߷ֵ�λ�� 
void student::show_escore()
{
	cout<<num<<"��"<<"��"<<name<<"ͬѧ"<<"�ɼ�Ϊ"<<escore<<endl; 
} 
void student::show_mscore()
{
	cout<<num<<"��"<<"��"<<name<<"ͬѧ"<<"�ɼ�Ϊ"<<mscore<<endl; 
} 
void student::show_cscore()
{
	cout<<num<<"��"<<"��"<<name<<"ͬѧ"<<"�ɼ�Ϊ"<<cscore<<endl; 
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
}//�ҵ��ܷ���߷ֵ�λ�� 
void student::show_classaver(student *s)
{
	int sum = 0;
	for(int i=0;i<5;i++)
	{
		sum+=s[i].escore+ s[i].mscore+s[i].cscore;
	}
	cout<<"�ð��ƽ����Ϊ�� "; 
	int temp = sum/5;
	cout<<sum/5<<endl;
	cout<<"����ͬѧ�ɼ�δ��ƽ����\n";
	for(int i=0;i<5;i++)
	{
		if(s[i].sum<temp)
		{
			cout<<s[i].num<<" "<<s[i].name<<endl;
		} 
	} 
}
