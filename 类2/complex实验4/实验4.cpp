#include <iostream>
using namespace std;
class complex
{
	public:
		complex(double r = 0,double i = 0)
		{
			real = r;
			image = i;
			cout<<"Call constructor;\n";
		}
		complex(complex const &t)
		{
			real = t.real;
			image = t.image;
			cout<<"Call copy constuctor;\n";
		}
		complex&operator = (const complex& t)
		{
			real = t.real;
			image = t.image;
			cout<<"Call constructor;\n";
		}
		void setx(double v,double u){real = v;image = v;}
		void display()
		{
			if(image == 0)
			cout<<real<<endl;
			else cout<<real<<"+"<<image<<"i"<<endl; 
		}
		~complex()
		{
			cout<<"call distructor;\n";
		} 
	private:
		double real;
		double image;
};
int main()
{
	complex c1(1.6,7.9),c2(c1),c3;
	cout<<"c1复数为："<<endl;
	c1.display();
	cout<<"c2复数为："<<endl;
	c2.display();
	cout<<"c3复数为："<<endl;
	c3.display();
}
