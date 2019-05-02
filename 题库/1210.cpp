#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int m = n*(n-1)+1;
		cout<<n<<"^3="<<m; 
		m+=2;
		for(int i=1;i<n;i++)
		{
			cout<<"+"<<m;
			m+=2;
		}
		cout<<endl;
	}
}
