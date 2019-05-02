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
	int N;
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
	{
		string a,b;
		cin>>a>>b;
		int t = a[a.length()-1] - 48;
		int x = b[b.length()-1] - 48;
		if(t == 1||t == 5||t == 6||t == 0)
		{
			printf("%d\n",t);
		}
		else if(t == 4)
		{
			if(x%2==0)
			{
				printf("6\n");
			}
			else printf("4\n");
		}
		else if(t == 9)
		{
			if(x%2==0)
			{
				printf("1\n");
			}
			else printf("9\n");
		}
		else
		{
			int num = 0;
			int cnt = 0;
			for(int j = 0;j < b.length();j++)
			{
				int k = b[j]-48;
				num+=k;
				if(num<4)
				{
					cnt = num;
					num = cnt*10;
				}
				else
				{
					cnt = num%4;
					num = cnt * 10;
				}
			}
			if(t==2)
			{
				if(cnt==0)
				{
					printf("6\n");
				}
				else if(cnt == 1)
				{
					printf("2\n");
				}
				else if(cnt == 2)
				{
					printf("4\n");
				}
				else if(cnt == 3)
				{
					printf("8\n");
				}
			}
			else if(t == 3)
			{
				if(cnt==0)
				{
					printf("1\n");
				}
				else if(cnt == 1)
				{
					printf("3\n");
				}
				else if(cnt == 2)
				{
					printf("9\n");
				}
				else if(cnt == 3)
				{
					printf("7\n");
				}
			}
			else if(t == 8)
			{
				if(cnt==0)
				{
					printf("6\n");
				}
				else if(cnt == 1)
				{
					printf("8\n");
				}
				else if(cnt == 2)
				{
					printf("4\n");
				}
				else if(cnt == 3)
				{
					printf("2\n");
				}
			}
			else if(t == 7)
			{
				if(cnt==0)
				{
					printf("1\n");
				}
				else if(cnt == 1)
				{
					printf("7\n");
				}
				else if(cnt == 2)
				{
					printf("9\n");
				}
				else if(cnt == 3)
				{
					printf("3\n");
				}
			}
		} 
	}
	return 0;
}
