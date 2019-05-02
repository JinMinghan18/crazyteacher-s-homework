#include<iostream>
#include"storehead.h"
using namespace std;
int main()
{
	sale sal[3] = {sale(101,5,23.5),sale(102,12,24.56),sale(103,100,21.5)};
	for(int i = 0;i<3;i++)
	{
		sal[i].total();
	} 
	sale::display();
	return 0;
} 
