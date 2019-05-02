#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
	int a,n;
	int c;
	while(cin>>a>>n)
	{
		int c = 0;
		for(int i = 0,j = n,k=1;i< n && j>0 ;i++,j--,k*=10)
		{
			c += a*j*k;
		}
		cout<<c<<endl;
	}
	
} 
