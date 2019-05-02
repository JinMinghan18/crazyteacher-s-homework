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
	int y,m,d;
	while(cin>>y>>m>>d)
	{
		int sum = 0;
		int month1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int month2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
		if(y>1999)
		{
			for(int i=1999;i<y;i++)
			{
				if((i%4==0 && i%100!=0 || i%400==0))
				sum += 366;
				else sum += 365;
			}
			if((y%4==0 && y%100!=0 || y%400==0))
			{
				for(int i = 1;i < m;i++)
				{
					sum+=month2[i];
				}
				sum += d-1;
			}
			else
			{
				for(int i = 1;i < m;i++)
				{
					sum+=month1[i];
				}
				sum += d-1;
			}
		}
		else if(y == 1999)
		{
			for(int i=1;i < m;i++)
			{
				sum +=month1[i];
			}
			sum+=d-1;
		}
		else if(y<1999)
		{
			for(int i=y+1;i<1999;i++)
			{
				if((i%4==0 && i%100!=0 || i%400==0))
				sum += 366;
				else sum += 365;
			}
			if((y%4==0 && y%100!=0 || y%400==0))
			{
				for(int i = m;i <= 12;i++)
				{
					sum+=month2[i];
				}
				sum -= d-1;
			}
			else
			{
				for(int i = m;i <= 12;i++)
				{
					sum+=month1[i];
				}
				sum -= d-1;
			}	
		}
		
		if(sum == 0)
		cout<<0<<endl;
		else if(sum%7 == 0)
		{
			cout<<sum/7<<endl;
		}
		else cout<<sum/7+1<<endl; 
	}
} 
