#ifndef SHAPE_H_H
#define SHAPE_H_H
#include <iostream>
using namespace std;
class shape
{
	public:
		virtual double area() const =0;
};
class circle:public shape		//Բ�� 
{
	public:
		circle(double r):radius(r){} 
		virtual double area()const{return 3.14159*radius*radius;};
	protected:
		double radius;
};
class rectangle:public shape		//���� 
{
	public:
		rectangle(double l,double r):c(l),k(r){}
		virtual double area() const {return c*k;};
	protected:
		double c,k;
};
class square:public shape		//������ 
{
	protected:
		double s;
	public:
		square(double s):s(s){}
		virtual double area() const  {return s*s;};
};
class trapezoid:public shape	//���� 
{
	protected:
		double shang,xia,h;
	public:
		trapezoid(double s,double x,double h):shang(s),xia(x),h(h){}
		virtual double area()const {return (shang+xia)*h/2.0;};
};
class triangle:public shape		//������ 
{
	protected:
		double di,h;
	public:
		triangle(double d,double h):di(d),h(h){}
		virtual double area()const {return 0.5*di*h;};
};
#endif
