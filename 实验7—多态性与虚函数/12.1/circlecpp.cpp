#include <iostream>
#include "circle.h"
using namespace std;
circle::circle(float a,float b,float c):point(a,b),radius(c){}
void circle::setradius(float r)
{
	radius = r;
}
float circle::getradius()const
{
	return radius;
}
float circle::aera()const
{
	return 3.14159*radius*radius;
}
ostream &operator<<(ostream &out,const circle &p)
{
	out<<"Center=["<<p.x<<","<<p.y<<"],r="<<p.radius<<",aera="<<p.aera()<<endl;
	return out;
}

