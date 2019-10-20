#include <iostream>
#include <math.h>
#include "time24.h"
using namespace std;
time24::time24(int h,int m){
	Hour = h;
	Minute = m;
} 
void time24::addTime(int m){
	int i = 0;
	i = (m+Minute)/60;
	if(i >0) Hour = i;
	Minute = (m+Minute)%60;
}
time24 time24::duration(const time24& t){
	time24 Time;
	int probit = abs(t.Hour*60+t.Minute-Hour*60-Minute);
	Time.Hour = probit/60;
	Time.Minute = probit%60;
	return Time;
}
void time24::readTime(){
	int a,b;//a为小时，b为分钟 
	scanf("%d:%d",&a,&b);
	Hour = a;
	Minute = b;
}
void time24::writeTime() const{
	cout<<Hour<<":"<<Minute<<endl;
}
int time24::getHour() const{
	return Hour;
}
int time24::getMinute() const{
	return Minute;
}
void time24::normalizeTime(){
	while(Hour>24) Hour -= 24;
	while(Hour<0) Hour += 24;
	while(Minute>60) Minute -= 60;
	while(Minute<0) Minute +=60;	
}

