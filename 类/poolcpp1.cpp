#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include "poolhead.h"
#define pi 3.1415926
using namespace std;
void Pool::set_cir()
{
	cin>>r>>c;
	wlc = 2*pi*c;
	dzs = pi*(pow((r+c),2)-pow(r,2));
	sum = cost1*dzs+cost2*wlc; 
}
void Pool::show_cir()
{
	cout<<fixed<<setprecision(2)<<sum<<endl; 
}

