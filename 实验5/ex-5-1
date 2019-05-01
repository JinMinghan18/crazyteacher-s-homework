#include <iostream>
using namespace std;

class Complex
{
	public:
		Complex():real(0),image(0){}
		Complex(double a):real(a),image(0){}
		Complex(double a,double b):real(a),image(b){}
		Complex(double &r){real = r,image = 0;}
		friend Complex operator+(Complex c1,Complex c2);
		Complex operator-();
		friend Complex operator-(Complex&c1,Complex&c2);
		friend ostream&operator<<(ostream& ,Complex &); 
	private:
		double real;
		double image;
};


Complex operator-(Complex &c1,Complex&c2)
{
	return Complex(c1.real-c2.real,c1.image-c2.image);
}

Complex Complex::operator-()
{
	return Complex(-this->real,-this->image);
}
Complex operator+(Complex c1,Complex c2)
{
	return Complex(c1.real+c2.real,c1.image+c2.image);
}

ostream &operator<<(ostream &output,Complex &d)
{
	if(d.image>0 && d.image != 1)
	{
		output<<d.real<<"+"<<d.image<<"i"<<endl; 
	}
	else if(d.image<0 && d.image != -1)
	{
		output<<d.real<<d.image<<"i"<<endl;
	} 
	else if(d.image == 1 )
	{
		output<<d.real<<"+i"<<endl;
	}
	else if(d.image == -1)
	{
		output<<d.real<<"-i"<<endl;
	}
	else 
	{
		output<<d.real<<endl;
	}
}

int main()
{
	Complex c1(1,2),c2(2),c3(c1),c4(1,3),c5(4,1);     
	c1=c1+c2+c3;  
	cout<<c1<<endl;
	c2=-c3;  	
	cout<<c2<<endl;
	c3=c2-c1;  
	cout<<c3<<endl;
	c4=c4-c1;
	cout<<c4<<endl;
	c5=c5+(c4+4);
	cout<<c5<<endl;
	return 0;
}
