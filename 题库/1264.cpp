#include <iostream>
#include <stdio.h> 
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	while(m--)
	{
		switch(n)
		{
			case 1:
				{
					printf("A\n");
					break;
				}
			case 2:
				{
					printf(" A\nBCD\n");
					break;
				}
			case 3:
				{
					printf("  A\n BCD\nEFGHI\n");
					break;
				}
			case 4:
				{
					printf("   A\n  BCD\n EFGHI\nJKLMNOP\n");
					break;
				}
			case 5:
				{
					printf("    A\n   BCD\n  EFGHI\n JKLMNOP\nQRSTUVWXY\n");
					break;
				}	
		}		
	}
}

