#include<iostream>
using namespace std;
class ex2 
{
	public:
		ex2(int v = 0)
		{
			x =new int(v);
			cout<<"构造对象"<<x<<endl; 
		}
		ex2&operator = (const ex2& r)
		{
			x =new int; *x = *(r.x);
		}
		void setx(int v){*x = v;}
		int  getx(){return *x;} 
		~ex2()
		{
			cout<<"析构对象"<<x<<endl;
			delete x;
		}
	private:
		int *x;
};
int main()
{
	ex2 objA(3),objB(4),objC;
	cout<<"objA:"<<objA.getx()<<endl; 
	cout<<"objB:"<<objB.getx()<<endl; 
	cout<<"objC:"<<objC.getx()<<endl; 
	objC = objA;
	cout<<"objA:"<<objA.getx()<<endl; 
	cout<<"objB:"<<objB.getx()<<endl; 
	cout<<"objC:"<<objC.getx()<<endl; 
	objA.setx(5);
	objB.setx(6);
	objC.setx(7);
	cout<<"objA:"<<objA.getx()<<endl; 
	cout<<"objB:"<<objB.getx()<<endl; 
	cout<<"objC:"<<objC.getx()<<endl; 
	return 0;
} 
