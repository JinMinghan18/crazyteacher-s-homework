#include<iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int c = 0;
		for(int i=n*n-1;i>=0;i--)
		{
			if((c)%n == 0 && c != 0)	cout<<endl;
			if(i<10)
			{
				cout<<fixed<<setw(4)<<"0"<<i;
			}
			else cout<<fixed<<setw(5)<<i;
			c++;
		}
		cout<<endl<<endl;
		
	}
	
	
} 
