#include<iostream>
#include "vehiclehead.h"
using namespace std;
vehicle::vehicle(float l_s,float w):limit_speed(l_s),weight(w){cout<<"A vehicle is running\n";}
void vehicle::show()
{
	cout<<"limit_speed£º "<<limit_speed<<endl
		<<"weight: "<<weight<<endl;
} 
bicycle::bicycle(float l_s,float w,float h):vehicle(l_s,w),high(h){}
void bicycle::show()
{
	vehicle::show();
	cout<<"high: "<< high<<endl;
} 
void bicycle::show_h()
{
	cout<<"high: "<<high<<endl;
}
motor_veh::motor_veh(float l_s,float w,int seat):vehicle(l_s,w),seat(seat){cout<<"A motor_veh is running\n";}
void motor_veh::show()
{
	vehicle::show();
	cout<<"seat: "<<seat<<endl;	
}
void motor_veh::show_s()
{
	cout<<"seat: "<<seat<<endl;	
}

motorcycle::motorcycle(float l_s,float w,float h,int seat):vehicle(l_s,w),bicycle(l_s,w,h),motor_veh(l_s,w,seat){cout<<"A motorcycle is running\n";}
void motorcycle::show()
{
	vehicle::show();
	motor_veh::show_s();
}

