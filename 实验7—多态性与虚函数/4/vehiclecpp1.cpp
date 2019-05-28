#include <iostream>
#include  "Vehicle.h"
using namespace std;
void Car::display()
{
	cout<<"座位数为:"<<seat<<endl;
}
void Truck::display()
{
	cout<<"载重为："<<load<<endl;
}
void Boat::display()
{
	cout<<"排水量为:"<<tonnes<<endl;
} 
