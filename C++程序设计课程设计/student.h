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
			cout<<"\nѧ�ţ�"; 
			cin>>id;
		}
		void get_time()
		{
			cout<<"\nȱ��ʱ�䣺"; 
			cin>>date; 
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
		int check_id()
		{
			return id;
		} 
		int check_time()
		{
			return date;
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
		void get_info();
		void modify();
		void search(int n);
		int check(int id,int date,int order);
	private:
		string name;//���� 
		int id;//ѧ�� 
		int date; //ȱ������ 
		int order; //�ڼ��ڿ� 
		string classname; //�γ����� 
		string abstype;//ȱ�����ͣ��ٵ������ˡ���١����Σ� 
		
};

#endif
