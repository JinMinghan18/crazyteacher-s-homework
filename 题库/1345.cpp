#include <iostream>
#include <cstring>
#include<algorithm> 
using namespace std;
struct node
{
	int A;
	int B;
}a[11];
bool cmp(node a,node b)
{
	return a.B>b.B;
}
int main()
{
	char b[1010];
	while(cin>>b)
	{
		for(int i =0 ;i<10;i++)
		{
			a[i].A = i;
			a[i].B = 0;
		}
		int len = strlen(b);
		for(int i=0;i<len;i++)
		{
			int temp = b[i]-48;
			a[temp].B+=1;
		}
		for(int i=0;i<10;i++)
		{
			if(a[i].B != 0)
			cout<<a[i].A<<" "<<a[i].B<<endl;
		}
		cout<<endl;	
	} 
}
