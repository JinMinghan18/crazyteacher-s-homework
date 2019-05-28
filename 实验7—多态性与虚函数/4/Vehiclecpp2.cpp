#include <iostream>
#include "Vehicle.h"
using namespace std;
int main()
{
	Car car(4);
	Truck truck(13286.2);
	Boat boat(100000);
	Vehicle *p[3]= {&car,&truck,&boat};
	for(int i=0;i<3;i++)
	{
		p[i]->display();
	}
	delete []p; 
} 
