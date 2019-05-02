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
	int a[200];
	int n;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int flag = 0;
		int cnt = 0;
		while(!flag)
		{
			if(a[1] < 0)
			{
				a[n] = a[n] + a[1];
				a[2] = a[2] + a[1];
				a[1] = -a[1];
				cnt++;
			}
			for(int i=2;i<n;i++)
			{
				if(a[i] < 0)
				{
					a[i-1] += a[i];
					a[i+1] += a[i];
					a[i] = -a[i]; 
					cnt++;
				}
				
			} 
			if(a[n]<0)
			{
				a[n-1] += a[n];
				a[1] += a[n];
				a[n] = -a[n]; 
				cnt++;
			}
			flag = 1;
			for(int i=1;i<=n;i++)
			{	
				if(a[i]<0) flag = 0;
			}
		}
		cout<<cnt<<endl;
	}
}
