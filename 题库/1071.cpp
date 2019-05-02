#include<iostream>
#include<cmath>
using namespace std;
int qpow(int a,int b)
{
	int temp=1;
	while(b--)
	{
		temp*=a;
	}
	return temp;
}
int main()
{   
	int m=0,n,i=100;
	while(i<=1000)
	{
		n=i;
		while(n>0)
		{
	     	m=m+qpow(n%10,3);
		    n=n/10;
	   	}
	   	if(i==m) cout<<m<<endl;
		i++;
		m=0;
	}	
	
	
}

