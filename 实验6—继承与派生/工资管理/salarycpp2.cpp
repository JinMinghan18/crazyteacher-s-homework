#include <iostream>
#include "salaryhead.h"
using namespace std;
int main()
{
	while(1)
	{
		int t;
		cout << "请输入员工的类别信息,1:manager 2:technician 3:salesman 4:salesmanager 0:退出):"<< endl; 
		cin>>t;
		if(t == 0)	break;
		else if(t == 1)
		{
			manager Manager; 
			Manager.setdate();
			Manager.pay();
			Manager.display(); 	 
		}	
		else if(t == 2)
		{
			technician tech;
			tech.setdate();
			tech.pay();
			tech.display(); 	 
		}
		else if(t == 3)
		{
			salesman sale;
			sale.setdate();
			sale.pay();
			sale.display(); 	 
		}
		else if(t == 4)
		{
			salesmanager mana;
			mana.setdate();
			mana.pay();
			mana.display(); 	 
		}
	} 
} 
