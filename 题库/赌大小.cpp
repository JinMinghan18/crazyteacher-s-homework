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
	int a,c;
	char b;
	int sum = 0;
	while(cin>>a)
	{
		cin>>b;
		cin>>c;
		if(b == 'b' && (c < 11 || c == 18))
		{
			sum-=a;
		}
		if(b == 'b' && (c>=11 && c < 18))
		{
			sum+=a;
		}
		if(b == 's' && c>3 && c<11)
		{
			sum+=a;
		}
		if(b == 's' && (c >= 11 || c == 3))
		{
			sum-=a;
		}
	}
	cout<<sum<<endl;
	
} 
