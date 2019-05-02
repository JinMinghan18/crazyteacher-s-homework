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
	ll n; 
	while(cin>>n)
	{
		char a;
		ll b;
		while(n--)
		{
			ll temp = 0;
			for(int i=0;i<5;i++)
			{
				cin>>b;
				temp = temp + b%26;
	 		}
	 		temp = temp%26 + 97;
	 		a = temp;
			cout<<a<<endl; 
		}
	}
	 
} 
