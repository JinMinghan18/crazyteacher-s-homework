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
	int n,h,z;
	while(cin>>n>>h>>z)
	{
		int yetu = (z-2*h)/2;
		int nafter = n-2;
		int yetuafter = yetu -3;
		if(yetuafter > 2*nafter)
		cout<<"no"<<endl;
		else if(yetuafter < nafter)
		cout<<"no"<<endl;
		else 
		cout<<"yes"	<<endl;
	}
}
