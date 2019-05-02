#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
return b?gcd(b,a%b):a;
}
int main()
{
	int n;
	scanf("%d",&n);
	char x[50];
	while(n--)
	{
		scanf("%s",x);
		int len=strlen(x);
		int m=0;
		for(int i=2;i<len;i++)
		m=(x[i]-'0')+m*10;
		len-=2;
		int y=1;
		for(int i=0;i<len;i++)
		y*=10;
		int res=gcd(m,y);
		printf("%d/%d\n",m/res,y/res);
	}
	return 0;
}
