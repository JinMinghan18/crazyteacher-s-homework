#include <iostream>
#include "CClockhead.h"
using namespace std;
int main() 
{
	cclock t1(11,59,59), t2(12, 0, 1);
	cout<<t1<<endl;
	cout<<t2<<endl;
	cclock t3;
	t3 = ++t1;
	cout<<t3<<endl;
	t3 = t1++;
	cout<<t3<<endl;
	if(t1.equal(t2))
	cout<<"Equal\n";
	
}
