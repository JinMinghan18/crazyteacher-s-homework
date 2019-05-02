#include<iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		int a[100010];
		for(int i=0;i<k;i++)
		{
			cin>>a[i];
		}
		sort(a,a+k,cmp);
		int sum = 0;
		for(int i=0;i<10;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
}
