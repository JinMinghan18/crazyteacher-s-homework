#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define ll long long 
int main()
{
	long long n=1;
	int cnt = 0;
	while(1)
	{
		scanf("%lld",&n);
		if(n == 0)
		{
			break;
		}
		else if(n<0)
		{
			continue;
		}
		double m = pow(n,1.0/3.0);
		ll k = (int)m;
//		cout<<m<<" "<<k<<'\n'; 
		if(k*k*k == n ||(k+2)*(k+2)*(k+2) == n || (k+1)*(k+1)*(k+1) == n) cnt++;
	}
	printf("%d\n",cnt);
}
