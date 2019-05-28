#ifndef VEHICLE_H_H
#define  VEHICLE_H_H
#include <iostream>
using namespace std;
class Vehicle
{
	public:
		Vehicle() { cout<<"Vehicle constructor."<<endl; }
		~Vehicle() { cout<<"Vehicle destructor."<<endl; }
		virtual void display() =0;
};
class Car:public Vehicle
{
	public:
		virtual void display();
		Car(int s):seat(s){ cout<<"Car constructor."<<endl; }
		~Car() { cout<<"Car destructor."<<endl; }
	protected:
		int seat;//座位数 
};
class Truck:public Vehicle
{
	public:
		virtual void display();
		Truck(double l):load(l) { cout<<"Truck constructor."<<endl; }
		~Truck() { cout<<"Truck destructor."<<endl; }
	protected:
		double load;//载重 
};
class Boat:public Vehicle
{
	public:
		virtual void display();
		Boat(double t):tonnes(t) { cout<<"Boat constructor."<<endl; }
		~Boat() { cout<<"Boat destructor."<<endl; }	
	protected:
		double tonnes;//排水量 
};
#endif
