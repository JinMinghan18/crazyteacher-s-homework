#ifndef student_H_H
#define student_H_H

#include <map>
#include<iostream>
#include<fstream> 
#include <cstring>
using namespace std;
class student 
{
	public:
		void get_name()
		{
			cout<<"������" ;
			cin>>name;
		}
		void get_id()
		{
			cout<<"\nѧ�ţ����㹤������רҵѧ�ţ�"; 
			cin>>id;
		}
		void get_time()
		{
			cout<<"\nȱ��ʱ�䣺(����1999 11 11)"; 
			cin>>year>>month>>day; 
		} 
		void get_order()
		{
			cout<<"\n��ʱ��" ;
			cin>>order;
		}
		void get_classname()
		{
			cout<<"\n�γ����ƣ�"; 
			cin>>classname;
		} 
		void get_abstype()
		{
			cout<<"\nȱ�����ͣ�";
			cin>>abstype;
		}
		string check_name()
		{
			return name;
		} 
		long long check_id()
		{
			return id;
		} 
		int check_year()
		{
			return year;
		} 
		int check_month()
		{
			return month;
		}
		int check_day()
		{
			return day;
		}
		int check_order()
		{
			return order;
		} 
		string check_classname()
		{
			return classname;
		} 
		string check_abstype()
		{
			return abstype;
		} 		
		void chuanru_name(string n)
		{
			name = n;
		}
		void chuanru_id(long long i)
		{
			id = i;
		}
		void chuanru_date(int y,int m,int d)
		{
			year = y;
			month = m;
			day = d;
		}
		void chuanru_order(int orde)
		{
			order = orde;
		}
		void chuanru_classname(string cla)
		{
			classname = cla;
		}
		void chuanru_abstype(string abs)
		{
			abstype = abs;
		}
		void get_info();
		void modify();
		void search(long long n);
		int check(long long id,int year,int month,int day,int order);
	private:
		string name;//���� 
		long long id;//ѧ�� 
		int year,month,day; //ȱ������ 
		int order; //�ڼ��ڿ� 
		string classname; //�γ����� 
		string abstype;//ȱ�����ͣ��ٵ������ˡ���١����Σ� 
		
};

#endif
