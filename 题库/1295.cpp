#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n; 
	while(cin>>n)
	{
		double a[200];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		double sum=0;
		for(int i=1;i<n-1;i++)
		{
			sum+=a[i];
		}
		cout<<fixed<<setprecision(2)<<sum/(n-2)<<endl;
	}
	
	
}
