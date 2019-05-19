#ifndef VEHICLEHEAD_H_H
#define VEHICLEHEAD_H_H
#include<iostream>
#include<cstring> 
#include<string> 
using namespace std;
class vehicle
{
	public:
		vehicle(float l_s,float w);
		void show();
	private:
		float limit_speed;
		float weight;
};

class bicycle:virtual public vehicle
{
	public:
		bicycle(float l_s,float w,float h);
		void show();
		void show_h();
	private:
		float high;
};
class motor_veh:virtual public vehicle
{
	public:
		void show();
		void show_s();
		motor_veh(float l_s,float w,int seat);
	private:
		int seat;
};
class motorcycle:public motor_veh,public bicycle
{
	public:
		motorcycle(float l_s,float w,float high,int seat);
		void show(); 
};
#endif
