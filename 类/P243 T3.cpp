#include<iostream>
using namespace std;
class Time 
{
	public:
		void set_time();
		void show_time();
	private:
		int hour;
		int minute;
		int sec;
};
Time t;
inline void Time::set_time()
{ 
	cin>>t.hour>>t.minute>>t.sec;
}
inline void Time::show_time()
{
	cout<<t.hour<<":"<<t.minute<<":"<<t.sec;
}
int main()
{
	t.set_time();
	t.show_time();
}
