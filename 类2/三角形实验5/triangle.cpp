#include<iostream>
#include <cmath>
using namespace std;
class  triangle
{
	public:
		double a;
		double b;
		double c;
		//���������߳� 
		void s();//��� 
		void cc();//�ܳ� 
		void set_l();
};
void triangle::set_l()
{
	cout<<"�������������������߳����ÿո�������";
	cin>>a>>b>>c;
} 
void triangle::s()
{
	cout<<"�����ε����Ϊ��"<<sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/4<<endl;
} 
void triangle::cc()
{
	cout<<"�����ε��ܳ�Ϊ��"<<a+b+c<<endl;
}
int main()
{
	triangle aa;
	aa.set_l();
	aa.s();
	aa.cc();
}
