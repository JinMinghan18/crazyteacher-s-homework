#include <iostream>
#include "salaryhead.h"
using namespace std;
int main()
{
	while(1)
	{
		employee * emp; 
		int t;
		cout << "请输入员工的类别信息,1:manager 2:technician 3:salesman 4:salesmanager 0:退出):"<< endl; 
		cin>>t;
		if(t == 0)	break;
		else if(t == 1)
		{
			emp = &manager(); 
			emp->setdate();
			emp->pay();
			emp->display(); 	 
		}	
		else if(t == 2)
		{
			emp = &technician();
			
			emp->setdate();
			emp->pay();
			emp->display(); 	 
		}
		else if(t == 3)
		{
			emp = &salesman();
			emp->setdate();
			emp->pay();
			emp->display(); 	 
		}
		else if(t == 4)
		{
			emp = &salesmanager(); 
			emp->setdate();
			emp->pay();
			emp->display(); 	 
		}
	} 
} 
