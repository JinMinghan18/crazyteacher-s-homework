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
ull a[1000010]={1,1}; 
ull infinite(int n)
{

	
	if(n<=1000000) return a[n];
	return infinite((n-1)/2)+infinite((n+1)/2);
}
int main()
{
	int n;
	for(int i=2;i<=1000000;i++)
	{
		a[i] = a[(i-1)/2] + a[(i+1)/2];
	}
	while(cin>>n)
	{
		if(n<=1)
		{
			cout<<"1"<<endl;
			continue;
		}
		int temp = infinite(n);
		cout<<temp<<endl;
	}
}
