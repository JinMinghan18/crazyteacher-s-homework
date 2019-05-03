#include <iostream>
#include "CClockhead.h"
using namespace std;
cclock cclock::operator++()
{
	sec++;
	if(sec == 60)
	{
		sec = 0;
		min++;
		if(min == 60)
		{
			min = 0;
			hour++;
			if(hour == 24)
			hour = 0;	
		} 
	}
	return *this;
}
cclock cclock::operator++(int)
{
	cclock temp(*this);
	++sec;
	if(sec == 60)
	{
		sec = 0;
		++min;
		if(min == 60)
		{
			min = 0;
			++ hour;
			if(hour == 24)
			hour = 0;
		}
	}
	return temp; 
}
ostream&operator<<(ostream&out,cclock a)
{
	out<<a.hour<<":"<<a.min<<":"<<a.sec;
}
int cclock::equal(cclock c1)
{
	if(c1.hour == hour && c1.min == min && c1.sec == sec)
	{
		return 1;
	}
	return 0;
}

