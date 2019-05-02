#include<iostream>
#include<cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct str
{
    int len;
    int one;
    char a[276];
}p[201];
int cmp(str a,str b)
{
    if(a.len!=b.len)
        return a.len<b.len;
    else return a.one<b.one;
}

int main()
{
        int i=0,j;
    while(scanf("%s",p[i].a)!=EOF)
    {
        p[i].len=strlen(p[i].a);
        p[i].one=0;
        for(j=0;p[i].a[j]!='\0';j++)
            if(p[i].a[j]=='1')
            p[i].one++;
        i++;
    };
    sort(p,p+i,cmp);
    for(j=0;j<i;j++)
        puts(p[j].a);
    return 0;
}

