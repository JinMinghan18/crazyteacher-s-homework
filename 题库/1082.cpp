#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
int main()
{	
	string a;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>a;
		int len = a.length();
		if(a[0] == '-')
		{
			cout<<'-';
			for(int i=len-1;i>=1;i--)
			{
				cout<<a[i];
			} 
			cout<<endl;
		} 
		else 
		{
			for(int i=len-1;i>=0;i--)
			{
				cout<<a[i];
			}
			cout<<endl;
		}
	}
}
