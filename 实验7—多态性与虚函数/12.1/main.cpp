#include <iostream>
#include "cylinder.h"

using namespace std;
int main() 
{
	cylinder cy1(3.5,6.4,5.2,10); 
	cout<<"\noriginal cylinder:\nx="<<cy1.getX()
		<<", y="<<cy1.getY()<<", r=" <<cy1.getradius()
		<<", h="<<cy1.getheight()<<"\narea="<<cy1.aera() 
		<<", volume="<<cy1.volume()<<endl; 
		cy1.setheight(15); 
		cy1.setradius(7.5); 
		cy1.setpoint(5,5); 
		cout<<"\nnew cylinder:\n"<<cy1; 
		point &pRef=cy1; 
		cout<<"\npRef as a point:"<<pRef; 
		circle &cRef=cy1; 
		cout<<"\ncRef as a Circle:"<<cRef; 
		return 0; 
}
