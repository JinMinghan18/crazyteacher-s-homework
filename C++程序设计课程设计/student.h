#ifndef student_H
#define student_H

#include<iostream>
#include<fstream> 
#include <cstring>
using namespace std;
class student 
{
	public:
		void get_name()
		{
			cin>>name;
		}
		void get_id()
		{
			cin>>id;
		}
		void get_time()
		{
			cin>>year>>month>>day;
		} 
		void get_order()
		{
			cin>>order;
		}
		void get_classname()
		{
			cin>>classname;
		} 
		void get_abstype()
		{
			cin>>abstype;
		}
		
	private:
		char name[20];//���� 
		string id;//ѧ�� 
		int year; //ȱ������ 
		int month;
		int day;
		int order; //�ڼ��ڿ� 
		char classname[20]; //�γ����� 
		char abstype[20];//ȱ�����ͣ��ٵ������ˡ���١����Σ� 
		
};
void get_info();
void modify();
#endif
