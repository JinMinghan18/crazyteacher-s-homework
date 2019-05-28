#ifndef POINT_H_H
#define POINT_H_H
#include <iostream>
using namespace std;
class point
{
	public:
		point(float x,float y); 
		void setpoint(float,float); 
		float getX() const {return x;} 
		float getY() const {return y;} 
		friend ostream & operator<<(ostream &,const point &); 
	protected: 
			float x,y; 
};
#endif
