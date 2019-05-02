#include<iostream>
#include"parking.h"
using namespace std;
int main()
{
	cout<<"1.启用系统\t0.结束使用\n";
	int i;
	while(cin>>i&&i)
	{
		cout<<"欢迎使用十八停车站收费管理系统\n收费规则如下：\n一小时内（包括一小时）：免费\n一小时以上：\n0-15min免费\n15-30min计半小时\n30min以上计一小时\每小时收费标准为4元\n超过三天收费300\n"; 
		cout<<"该车的入场时间为：" ;
		clock arrivet,leavet;
		arrivet.set_time();
		cout<<"该车的出场时间为：";
		leavet.set_time();
		cout<<"入场时间为：\n";
		arrivet.show_time();
		cout<<"离场时间：\n";
		leavet.show_time();
		double time = leavet.diff(arrivet);
		if(time <=0 ) cout<<"停车不满一小时，免停车费\n";
		else if (time>0 &&time<=71)	cout<<"收费为："<<time*4<<"元"<<endl;
		else if (time>71) 	cout<<"超过三天收费300元\n";
		cout<<"祝您一路顺风\n";
		cout<<"1.继续使用\t0.结束使用\n";
	}
} 
