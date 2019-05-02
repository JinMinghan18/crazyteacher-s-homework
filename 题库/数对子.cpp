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
	int N;
	while(cin>>N && N)
	{
		int cnt = 0;
		for(int i=0;i<N;i++)
		{
			int flag[4]={0,0,0,0};
			char a[4];
			cin>>a;
			for(int i=0;i<4;i++)
			{
				if(flag[i] == 1)
				continue;
				for(int j=i+1;j<4;j++)
				{
					if(flag[i] == 1 ||flag[j] == 1)
					continue;
					else if(a[i] == a[j])
					{
						cnt++;
						flag[i] = flag[j] = 1;
					}
				}
			} 
		}
		cout<<cnt<<endl;
	} 
} 
