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
	cout<<"1.继续计算0.结束计算\n";
	int i;
	cin>>i; 
	while(i)
	{
		cout<<"请输入长方柱的长宽高数值："; 
		arec.set_rec();
		cout<<"长方柱的体积为："; 
		arec.show_rec();
		cout<<"1.继续计算0.结束计算\n";
		cin>>i;
	}
	
} 
