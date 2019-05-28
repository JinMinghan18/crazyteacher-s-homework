#ifndef CYLINDER_H_H
#define CYLINDER_H_H 
#include <iostream>
#include "circle.h"
using namespace std;
class cylinder:public circle
{
	public: 
		cylinder(float =0,float = 0,float =0,float =0);
		void setheight(float); 
		float getheight() const; 
		float aera() const; 
		float volume() const; 
		friend ostream& operator<<(ostream&,const cylinder&); 
	protected: 
		float height; 
};
#endif 
