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
	int n=0,m=0;
	while(cin>>n>>m)
	{
		ull temp = 1;
		for(int i=1,j=n;i<=m,j>n-m;i++,j--)
		{
			temp = temp*j/i;
		} 
		cout<<temp<<endl;
	}
}
