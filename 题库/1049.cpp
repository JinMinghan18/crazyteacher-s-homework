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
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	int x,y,a,b,minx,miny;
	cin>>x>>y;
	int minn = INF;
	while(cin>>a>>b)
	{
		int temp = abs(sqrt((x-a)*(x-a)+(y-b)*(y-b)));
		if(temp < minn)
		{
			minn = temp;
			minx = a;
			miny = b;
		}
	}
	cout<<minx<<' '<<miny<<endl;
} 
