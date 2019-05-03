#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
	public:
		Matrix(){}
		friend istream&operator>>(istream&,Matrix&);
		friend ostream&operator<<(ostream&,Matrix&);
		Matrix operator + (Matrix a);
		Matrix operator - (Matrix a);
	private:
		int _matrix[6] = {0};
};
