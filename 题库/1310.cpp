#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int c;
		cin>>c;
		double a[2000];
		for(int i=0;i<c;i++)
		{
			cin>>a[i];
		}
		double sum = 0;
		for(int i=0;i<c;i++)
		{
			sum+=a[i];
		}
		cout<<fixed<<setprecision(3)<<sum/c<<endl;
	}
} 
