#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{	
	Matrix a,b,c;
	cout<<"Please input the matrix a:\n";
	cin>>a;
	cout<<"Please input the matrix b:\n";
	cin>>b;
	cout<<endl<<"Matrix a:\n"<<a<<endl;
	cout<<endl<<"Matrix b:\n"<<b<<endl;
	c=a+b;
	cout<<endl<<"Matrix c = Matrix a + Matrix b:\n"<<c<<endl;
	return 0;
}

