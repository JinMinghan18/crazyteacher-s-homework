#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int N,M,a,b;
	while(cin>>N>>M && N+M) 
	{
		int t = M;
		for(int i=1;i<=M;i++)
		{
			cin>>a>>b;
		}
		int b = N-1-t;
		if(b<=0)
		cout<<0<<endl;
		else 
		cout<<b<<endl;
	}
	return 0;
} 
