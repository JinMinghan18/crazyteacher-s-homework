#include<iostream>
using namespace std;
class capacity
{
	private:
		double l,w,h;
	public:
		void set_rec();
		void show_rec();
};
capacity arec;
void capacity::set_rec()
{
	cin>>l>>w>>h;
}
void capacity::show_rec()
{
	cout<<l*w*h<<endl;
} 
int main()
{
	cout<<"1.��������0.��������\n";
	int i;
	cin>>i; 
	while(i)
	{
		cout<<"�����볤�����ĳ������ֵ��"; 
		arec.set_rec();
		cout<<"�����������Ϊ��"; 
		arec.show_rec();
		cout<<"1.��������0.��������\n";
		cin>>i;
	}
	
} 
