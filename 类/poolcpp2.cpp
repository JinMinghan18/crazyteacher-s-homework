#include<iostream>
#include "poolhead.h"
using namespace std;

int main()
{
	int i=0,n;
	double summ = 0.0;
	cout<<"��������Ҫ���ˮ�ظ���\n";
	cin>>n;
	while(n--)
	{
		i++;
		cout<<"�������"<<i<<"��ˮ�صİ뾶���ߵ���\n"; 
		Pool apool;
		apool.set_cir();
		cout<<"��ˮ�ص����Ϊ��\n"; 
		apool.show_cir(); 
		summ+=apool.sum; 
	}
	cout<<"�����Ϊ��"<<summ; 
	
	return 0;
} 
