#include <iostream>
#include "Matrix.h"
using namespace std;
istream&operator>>(istream& in,Matrix& a)
{
	for(int i=0;i<6;i++)
	{
		in>>a._matrix[i];
	}
	return in;
}
ostream&operator<<(ostream& out,Matrix &b)
{
	for(int i=0;i<6;i++)
	{
		if(i == 3) cout<<endl;
		out<<setw(5)<<b._matrix[i];
	}	
	return out;
}
Matrix Matrix::operator + (Matrix a)
{
	Matrix c;
	for(int i=0;i<6;i++)
	{
		c._matrix[i] = _matrix[i]+a._matrix[i];
	}
	return c;
}
Matrix Matrix::operator -(Matrix a)
{
	Matrix c;
	for(int i=0;i<6;i++)
	{
		c._matrix[i] = _matrix[i]-a._matrix[i];
	}
	return c;
} 
