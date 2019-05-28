#include <iostream>
#include <iomanip>
#include "shape.h"
using namespace std;
int main()
{
	circle cir(6.6);
	rectangle rec(6.6,5.5);
	square squ(6.6);
	trapezoid tra(6.6,4.4,5);
	triangle tri(6.6,6);
	shape *p[5]={&cir,&rec,&squ,&tra,&tri};
	double areas = 0.0;
	cout<<"面积分别为：\n"; 
	for(int i=0;i<5;i++)
	{
		areas += p[i]->area();
		cout<<fixed<<setprecision(2)<<p[i]->area()<<endl;
	} 
	cout<<"总面积为：\n";
	cout<<areas; 
}
