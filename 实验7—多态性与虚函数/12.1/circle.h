#ifndef CIRCLE_H_H
#define CIRCLE_H_H 
#include <iostream>
#include "point.h" 
using namespace std;
class circle:public point
{
	public:
		circle(float = 0,float = 0,float = 0);
		void setradius(float);
		float getradius() const;
		float aera() const;
		friend ostream&operator<<(ostream &,const circle&);
	protected:
		float radius;
};
#endif
