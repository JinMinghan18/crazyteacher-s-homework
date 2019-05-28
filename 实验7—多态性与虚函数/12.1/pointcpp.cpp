#include <iostream>
#include "point.h"
using namespace std;
point::point(float a,float b)
{
	x = a;
	y = b;
}
void point::setpoint(float a,float b)
{
	x = a;
	y = b;
}
ostream &operator<<(ostream &out,const point &p)
{
	out<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return out;
}
