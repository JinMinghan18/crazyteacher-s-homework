#include<iostream>
#include <cmath>
using namespace std;
class  triangle
{
	public:
		double a;
		double b;
		double c;
		//三角形三边长 
		void s();//面积 
		void cc();//周长 
		void set_l();
};
void triangle::set_l()
{
	cout<<"请依次输入三角形三边长（用空格间隔）：";
	cin>>a>>b>>c;
} 
void triangle::s()
{
	cout<<"三角形的面积为："<<sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/4<<endl;
} 
void triangle::cc()
{
	cout<<"三角形的周长为："<<a+b+c<<endl;
}
int main()
{
	triangle aa;
	aa.set_l();
	aa.s();
	aa.cc();
}
