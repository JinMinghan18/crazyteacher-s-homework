#include<iostream>
using namespace std;
class cclock
{
	public:
		cclock(){}
		cclock(int a,int b,int c):hour(a),min(b),sec(c){}
		cclock operator++();
		cclock operator++(int);
		friend ostream&operator<<(ostream&out,cclock a);
		int  equal(cclock c2);
	private:
		int hour;
		int min;
		int sec;
}; 
