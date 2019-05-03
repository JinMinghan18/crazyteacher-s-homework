#include"vectorhead.h"
#include<iostream>
using namespace std;
int main()
{	
	Vec v1(4);  
	v1[0] = 1; 
	v1[1] = 2;
	v1[2] = 3;
	v1[3] = 4;
	Vec v2(v1);  
	Vec v3 = v1 + v2; 
	v2 = v2 - v1; 
	v1.print();
	v2.print();
	v3.print();
	return 0;
} 

