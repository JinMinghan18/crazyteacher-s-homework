#include<iostream>
#include"parking.h"
using namespace std;
int main()
{
	cout<<"1.����ϵͳ\t0.����ʹ��\n";
	int i;
	while(cin>>i&&i)
	{
		cout<<"��ӭʹ��ʮ��ͣ��վ�շѹ���ϵͳ\n�շѹ������£�\nһСʱ�ڣ�����һСʱ�������\nһСʱ���ϣ�\n0-15min���\n15-30min�ư�Сʱ\n30min���ϼ�һСʱ\ÿСʱ�շѱ�׼Ϊ4Ԫ\n���������շ�300\n"; 
		cout<<"�ó����볡ʱ��Ϊ��" ;
		clock arrivet,leavet;
		arrivet.set_time();
		cout<<"�ó��ĳ���ʱ��Ϊ��";
		leavet.set_time();
		cout<<"�볡ʱ��Ϊ��\n";
		arrivet.show_time();
		cout<<"�볡ʱ�䣺\n";
		leavet.show_time();
		double time = leavet.diff(arrivet);
		if(time <=0 ) cout<<"ͣ������һСʱ����ͣ����\n";
		else if (time>0 &&time<=71)	cout<<"�շ�Ϊ��"<<time*4<<"Ԫ"<<endl;
		else if (time>71) 	cout<<"���������շ�300Ԫ\n";
		cout<<"ף��һ·˳��\n";
		cout<<"1.����ʹ��\t0.����ʹ��\n";
	}
} 
