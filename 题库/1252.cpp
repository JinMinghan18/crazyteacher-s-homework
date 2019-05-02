#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		double a;
		int b;
		scanf("%lf",&a);
		if(a-(int)a == 0)
		{
			b = a;
		}
		else b = (int)a+1;
		printf("%d\n",b);
	}
}
