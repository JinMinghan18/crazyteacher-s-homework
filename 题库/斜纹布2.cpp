#include<iostream>
#include<string.h>
using namespace std;
int main ()
{
	int len,n; 
	string a;
	while(cin>>a)
	{
		len=a.length();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<a[(i+j)%len]; 
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
