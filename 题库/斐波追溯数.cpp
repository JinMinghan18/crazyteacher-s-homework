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
	int n;
	while(cin>>n)
	{
		int a[100000];
		a[0] = 1;
		a[1] = 1;
		a[2] = 2;
		for(int i = 3;i<1000;i++)
		{
			a[i] = a[i-1] + a[i-2]; 
			a[i] %= 100;
		}
		for(int i = 0;i<=10000;i++)
		{
			if(a[i] == n)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
