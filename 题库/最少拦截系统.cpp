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
	int a[100000];
	int b[10000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int temp = a[0];
	int cnt = 1;
	b[cnt] = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<temp)
		{
			temp = a[i];
			continue;
		} 
		else if(a[i]>=temp)
		{
			cnt++;
			temp = a[i];
		}
		
	}
	cout<<cnt<<endl;
} 
