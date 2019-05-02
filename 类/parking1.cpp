#include <iostream>
#include "parking.h"
using namespace std;
void clock::set_time()
{
	cin>>year>>month>>day>>hour>>minute>>sec;
}
void clock::show_time()
{
	cout<<year<<"Äê"<<month<<"ÔÂ"<<day<<"ºÅ"<<hour<<":"<<minute<<":"<<sec<<endl;
}
long long clock::normalize()
{
	int month1[13] = {0,31,28,31,30,31,30,31,31,30,31,30};
	int month2[13] = {0,31,29,31,30,31,30,31,31,30,31,30};
	if(year%4==0 && year%100!=0 || year%400==0)
	{
		int temp=0;
		for(int i=0;i<month;i++)
		{
			temp += month2[i];
		}
		temp+=day;
		temp = temp*24*60+hour*60+minute;
		return temp;
	}
	else 
	{
		int temp=0;
		for(int i=0;i<month;i++)
		{
			temp += month1[i];
		}
		temp+=day;
		temp = temp*24*60+hour*60+minute;
		return temp;
	}
} 
double clock::diff(clock t)
{
	long long d =normalize()-t.normalize();
	if(d<0)	return 0;
	int h = d/60,m = d%60;
	if(m<15)	return h;
	if(m>=15&&m<30 ) return h+0.5;
	if(m>=30&&m<60) return h+1;
}

