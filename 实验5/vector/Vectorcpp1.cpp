#include<iostream>
#include "vectorhead.h"
using namespace std;
Vec::Vec(int n)
{
	a = new int [n];
	size = n;
}
Vec::Vec(const Vec &x)
{
	size = x.size;
	a = new int[x.size];
	for(int i = 0;i<x.size;i++)
	{
		a[i] = x.a[i];
	}
}
Vec::~Vec()
{
	delete[] a;
}
Vec Vec::operator+(const Vec & x)
{
	const Vec *miner,*maxer;
	if(size<=x.size)
	{
		miner = this;
		maxer = &x; 
	}
	else
	{
		miner = &x;
		maxer = this;
	}
	Vec v1(miner->size);
	for(int i=0;i<=miner->size;i++)
	{
		v1.a[i] = miner->a[i] + maxer->a[i]; 
	}
	return v1;
}
Vec Vec::operator-(const Vec& x)
{
	const Vec *miner,*maxer;
	if(size<=x.size)
	{
		miner = this;
		maxer = &x; 
	}
	else
	{
		miner = &x;
		maxer = this;
	}
	Vec v1(miner->size);
	for(int i=0;i<=miner->size;i++)
	{
		v1.a[i] = miner->a[i] - maxer->a[i]; 
	}
	return v1;
}
Vec &Vec::operator=(const Vec& x)
{
	size = x.size;
	delete[] a;
	this->a = new int[x.size];
	for(int i=0;i<size;i++)
	{
		a[i] = x.a[i];
	}
}
int  &Vec::operator[](int idx)
{
	return a[idx];
}
void Vec::print()
{
	cout<<"(";
	for(int i=0;i<size;i++)
	{
		cout<<a[i];
		if(i<size-1)
			cout<<",";
		
	}
	cout<<")"<<endl;
}
