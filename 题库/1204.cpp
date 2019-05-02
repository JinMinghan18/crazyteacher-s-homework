#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct str
{
    int len;
    int one;
    char a[276];
}p[2000];

bool cmp(str x,str y)
{
	if(x.len!=y.len)
        return x.len<y.len;
    else if(x.one != y.one)
		return x.one<y.one;
	else if (strcmp(x.a,y.a) < 0) return true;
	else return false;
}

int main()
{
    int i=0,j;
    while(scanf("%s",&p[i].a)!=EOF)
    {
        p[i].len=strlen(p[i].a);
        p[i].one=0;
        for(j=0;p[i].a[j]!='\0';j++)
            if(p[i].a[j]=='1')
            p[i].one++;
        i++;
    };
    //i--;
    sort(p,p+i,cmp);
    for(j=0;j<i;j++)
       printf("%s\n",p[j].a);
    return 0;
}
