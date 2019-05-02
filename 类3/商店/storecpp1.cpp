#include<iostream>
#include<iomanip>
#include"storehead.h"
using namespace std;
void sale::display()
{
	cout<<fixed<<setprecision(2)<<"the average price is:"<<average()<<"yuan"<<endl;
	cout<<"the sum sale money is:"<<sum<<"yuan"<<endl;
}
void sale::total()
{
	float dis = 1.0;
	if(quantity>10) dis = 0.98*dis;
	sum += sum +quantity*price*dis*discount;
	n += quantity;
}
float sale::average()
{
	return sum/n;
}
float sale::discount=0.95;
float sale::sum=0;
int sale::n=0;
