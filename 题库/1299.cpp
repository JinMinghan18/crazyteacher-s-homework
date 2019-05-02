#include<iostream>
using namespace std;
struct s{
	int x,y;
}a[10000] ;
int main(){
	for(int k=1;k<=9999;k++)
	{
		a[k].x=0;
		a[k].y=0;
	}
	for(int i=2; i<100; i++)
	{
		int t=i*i;
		for(int j=2; t<10000; j++,t*=i)
			a[t].x=i, a[t].y=j;
	}
	int n;
	while(cin>>n && n)
		cout<<a[n].x<<" "<<a[n].y<<"\n";
}
