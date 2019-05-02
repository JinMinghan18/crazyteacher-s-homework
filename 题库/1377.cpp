#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n;
	while(cin>>n && n)
	{
		int a[10000];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		cout<<"A:";
		for(int i=0;i<n;i++)
		{
			if(a[i]>=90) cout<<" "<<a[i];
		}
		cout<<endl;
		cout<<"B:";
		for(int i=0;i<n;i++)
		{
			if(a[i]<90 && a[i]>=80) cout<<" "<<a[i];
		}
		cout<<endl;
		cout<<"C:";
		for(int i=0;i<n;i++)
		{
			if(a[i]<80 && a[i]>=70) cout<<" "<<a[i];
		}
		cout<<endl;
		cout<<"D:";
		for(int i=0;i<n;i++)
		{
			if(a[i]<70 && a[i]>=60) cout<<" "<<a[i];
		}
		cout<<endl;
		cout<<"E:";
		for(int i=0;i<n;i++)
		{
			if(a[i]<60) cout<<" "<<a[i];
		}
		cout<<endl<<endl;
	}
	getchar();
}
