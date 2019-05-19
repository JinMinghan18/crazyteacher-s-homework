#include<iostream>
#include"salaryhead.h" 
using namespace std;

void employee::display()
{
	cout<<"id: "<<id<<endl
		<<"name: "<<name<<endl
		<<"salary: "<<salary<<endl;
} 

void manager::pay()
{ 
	salary = 5000; 
}

void manager::setdate()
{
	cout<<"please cin the id and the name of this manager\n";
	cin>>id>>name;
}

void manager::display()
{
	cout<<"type: manager\n";
	employee::display();
	cout<<endl;
}

void technician::setdate()
{
	cout<<"please cin the id ,name and worktime of this technician\n";
	cin>>id>>name>>time;
}

void technician::pay()
{
	salary = time*100; 
}

void technician::display()
{
	cout<<"type: technician\n";
	employee::display();
	cout<<"worktime: "<<time<<endl<<endl;
}

void salesman::setdate()
{
	cout<<"please cin the id ,name and sales of this salesman\n";
	cin>>id>>name>>sales;
} 

void salesman::pay()
{
	salary = 0.07*sales;
}

void salesman::display()
{
	cout<<"type: salesman\n";
	employee::display();
	cout<<"sales: "<<sales<<endl
		<<"salary: "<<salary<<endl; 
}

void salesmanager::pay()
{
	salary = 0.07*sales+0.002*sumsales+8000;
}

void salesmanager::setdate()
{
	cout<<"please cin id, name, sales and sumsales of this salesmanager: \n";
	cin>>id>>name>>sales>>sumsales;
}

void salesmanager::display()
{
	cout<<"type: salesmanager\n"
		<<"sales: "<<sales<<endl
		<<"sumsales: "<<sumsales<<endl;
	employee::display();
}

 



