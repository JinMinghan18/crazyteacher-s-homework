#include<iostream>
#include "poolhead.h"
using namespace std;

int main()
{
	int i=0,n;
	double summ = 0.0;
	cout<<"请输入需要造的水池个数\n";
	cin>>n;
	while(n--)
	{
		i++;
		cout<<"请输入第"<<i<<"个水池的半径与走道宽\n"; 
		Pool apool;
		apool.set_cir();
		cout<<"该水池的造价为：\n"; 
		apool.show_cir(); 
		summ+=apool.sum; 
	}
	cout<<"总造价为："<<summ; 
	
	return 0;
} 
