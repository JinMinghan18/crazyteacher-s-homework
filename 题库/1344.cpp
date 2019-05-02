#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int a = 0;
		double maxn = (3*n-m-1)/2;
		for(double z = 0;z<=131;z++)
		{
			double leftsum = m - z;
			double left = n - z;
			double x;
			double y;
			x = m-2*n+z;
			y = m-n-2*x;
			if(y-(int)y == 0 && x-(int)x == 0 && y>=1 && z>=1 && x>=1) a++;
		}
		cout<<a<<endl;
		
	}
 } 
