#include<iostream>
using namespace std;
int main()
{
    unsigned long long int a,temp=0;
	int i=0;
	while(cin>>a)
	{
		int flag=1,len=0;
		temp=a;
		if(a>=1000 || a<100)
		{
			cout<<"No\n";
			continue;
		} 
		i=2;
		while(i<temp/2)
		{
			if(temp%i==0) 
			{
			    flag=0;
			    break;
			}
            i++;
		}
	
		if(flag== 1 && temp % 10 == temp / 100) 
		{
				cout<<"Yes\n";
		}
		else cout<<"No\n";
	}
} 
