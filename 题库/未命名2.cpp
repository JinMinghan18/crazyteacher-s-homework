#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,top,t,flag;
	char a[260],left[260];
	while(scanf("%s",a)!=EOF)
	{
		t=strlen(a); 
		i=0;  top=0; flag=1;
		while(i<t&&a[i]&&flag)
		{
			if(a[i]=='['||a[i]=='(')
				left[++top]=a[i];
			if(a[i]==']')
				if(left[top]=='[') top--;
				else flag=0;
			if(a[i]==')')
				if(left[top]=='(') top--;
				else flag=0;
		   i++;
		}
	   if(flag&&top==0)  printf("YES\n");
	   else printf("NO\n");
	}
 return 0;
 
}
