#include<iostream>
using namespace std;
class A
{
	public:
		A(){a=0;b=0;cout<<"�����޲���A  ";}
		A(int i){a=i;b=0;cout<<"���쵥������A  ";}
		A(int i,int j){a=i;b=j;cout<<"����˫������A  ";}
		void display(){cout<<"a="<<a<<" b="<<b;}
	private:
		int a;
		int b;
};
class B : public A
{
	public:
		B(){c=0;cout<<"�����޲���B\n";}
		B(int i):A(i){c=0;cout<<"���쵥������B\n";}
		B(int i,int j):A(i,j){c=0;cout<<"����˫����B\n";}
		B(int i,int j,int k):A(i,j){c=k;cout<<"����������B\n";}
		void display1()
		{
			display();
			cout<<" c="<<c<<endl;
		}
	private:
		int c;
};
int main()
{
	B b1;
	B b2(1);
	B b3(1,3);
	B b4(1,3,5);
	b1.display1();
	b2.display1();
	b3.display1();
	b4.display1();
	return 0;
} 
