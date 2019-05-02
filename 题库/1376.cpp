#include <iostream>
#include<algorithm>
#include <string>//#include <cstring>
using namespace std;
int main()
{
	string b;
	int a[12000];
	while(getline(cin,b))
	{
		int len = b.length();
		int j = 0;
		int temp =0;
		for(int i=0;i<len;i++)
		{
			
			if(b[i] != ' ')	temp = temp*10+b[i]-48;
			if(b[i] == ' ')
			{
				a[j] = temp;
				temp = 0;
				j++;
			}
		
		}
		a[j] = temp; 
		j++;
		sort(a,a+j);
		int fir = a[0],sec = a[0];
		for(int i=0;i<j;i++)
		{
			if(a[i] > fir)
			{
				sec = fir;
				fir = a[i];
			}
		}
		cout<<sec<<endl;
		
	}
} 
