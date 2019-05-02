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
	double n;
	while(cin>>n)
	{
		cout<<n<<":"<<endl;
		double temp = n/20;
		double a[19] = {0,0.05,0.1,0.2,0.4,0.8,1.6,3.2,6.4,12.8,25.6,51.2,102.4,204.8,409.6,819.2,1638.4,3276.8,6553.6};
		double flag[19] = {};
		for(int i = 18;i>0;i--)
		{
			if(temp >= a[i]-0.00000000001)
			{
				temp -= a[i];
				flag[i] = 1;
			}
			else 
				continue;
		}
		for(int i=0;i<19;i++)
		{
			if(flag[i] == 1)
			{
				cout<<"  "<<a[i]<<"kg"<<endl;
			}
		}
		 
	} 
}
