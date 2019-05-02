#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	
	char str[10000];
	while(scanf("%s",str)!=EOF)
	{
		int cnt = 0;
		int len = strlen(str);
		for(int i=0;i<len;i++)
		{
			if(str[i] == 'a') cnt++;
		}
		int cnt2 = len-cnt;
		cout<<cnt<<" "<<cnt2<<endl;
	}
	
} 
