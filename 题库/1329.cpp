#include <stdio.h>
#include <cmath>
#include<iomanip>
double a[400010];
using namespace std;
int fun()
{
	double temp=0;
	for(int j=1;j<=400000;j++)
	{
		temp +=pow(-1.0,j+1)*(1.0/(2*j-1));
		a[j-1] = temp;
	}
	return 0;
}
int main()
{
	fun();
	int n;
	int max = 0;
	while(scanf("%d",&n)!=EOF  && n)
	{
			printf("%.8f\n",4*a[n]);
	}
} 
