#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		char a[10000];
		gets(a);
		int len = strlen(a);
		for(int i=len-1;i>=0;i--)
		cout<<a[i];
		cout<<endl;		
	}
	
}
