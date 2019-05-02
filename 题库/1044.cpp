#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a,b,temp = 1;
		cin>>a>>b;
		while(b--)
		{
			temp = temp*a%10;
		}
		cout<<temp<<endl;
	}
} 
