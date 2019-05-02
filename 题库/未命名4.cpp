#include<iostream>
using namespace std;
int main()
{
	int n;
	int i;
	int* p=new int [20];
	p[0]=1;
	for(i=1;i<20;i++)
	p[i]=p[i-1]*2;
	for(;cin>>n;)
	{
		int* q=new int [20];
		int j=19;
		int m=n;
		i=19;
		int k;
		for(;m>0;j--)
		{
			for(;i>=0;i--)
			if(m/p[i]==1){m=m-p[i];q[j]=p[i];k=i;break;}
		}
		double a=20;
		cout<<n<<':'<<endl;
		for(i=j+1;i<20;i++)
		cout<<"  "<<q[i]/a<<"kg"<<endl;
		delete [] q;
	}
	delete [] p;
	return 0;
}
