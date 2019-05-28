#include <iostream>
#include "cylinder.h"
using namespace std;
cylinder::cylinder(float a,float b,float r,float h):circle(a,b,r),height(h){}
void cylinder::setheight(float h)
{
	height = h;
}
float cylinder::getheight()const
{
	return height;
}
float cylinder::aera()const
{
	return 2*circle::aera() + 2*3.14159*radius*height;
} 
float cylinder::volume()const
{
	return circle::aera()*height;	
}
ostream &operator<<(ostream &out,const cylinder&c)
{
	out<<"Center=["<<c.x<<","<<c.y<<"], r="
	   <<c.radius<<", h="<<c.height <<"\narea="
	   <<c.aera()<<", volume="<<c.volume()<<endl; 
	return out;
}
