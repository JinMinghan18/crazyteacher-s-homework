#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	int n = 0;
	int mon1[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int mon2[13] ={0,31,29,31,30,31,30,31,31,30,31,30,31}; 
	char a[12];
	ll b;
	while(cin>>a)
	{
		int flag = 1;
		int year = 1000*(a[0]-48) + 100*(a[1]-48) + 10*(a[2]-48) + (a[3]-48); 
		int month = 10*(a[4]-48) + (a[5] - 48);
		if(month>50)
		{
			month -=50;
		}
		int date = 10*(a[6]-48) + (a[7] - 48); 
		n++;
		b = 0;
		for(int i=0;i<12;i++)
		{
			int k = a[i]-48;
			b = 10*b+k;
		}
		if(b%11 != 0)
		{
			cout<<"Case "<<n<<": No\n";
			continue;
		}
		else
		{
			int runnian = 0;
			if((year%4==0&&year%100!=0)||(year%400==0)) runnian = 1;
			if(month == 0 || month >12)
			{
				cout<<"Case "<<n<<": No\n";
				continue;
			}
			else if(runnian == 1 && (date>mon2[month] || date == 0))
			{
				cout<<"Case "<<n<<": No\n";
				continue;
			} 
			else if(runnian == 0 && (date > mon1[month] || date == 0))
			{
				cout<<"Case "<<n<<": No\n";
				continue;
			}
			else if(runnian == 0 && (date<= mon1[month]&&date>0))
			{
				cout<<"Case "<<n<<": Yes\n";
				continue;
			}
			else if(runnian == 1 && (date<= mon2[month]&&date>0))
			{
				cout<<"Case "<<n<<": Yes\n";
				continue;
			}
		}
	}
}
