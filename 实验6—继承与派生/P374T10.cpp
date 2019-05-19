#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class teacher
{
	public:
		teacher(int num,string name,char sex);
		void display();
	private:
		int num;
		string name;
		char sex;
};
teacher::teacher(int num,string name,char sex):
num(num),name(name),sex(sex){}
void teacher::display()
{
	cout<<"num: "<<num<<endl
		<<"name: "<<name<<endl
		<<"sex: "<<sex<<endl; 
}
class birthdate
{
	public:
		birthdate(int year,int month,int day);
		void display();
		void reset(int y,int m,int d);
	private:
		int year;
		int month;
		int day;
};
birthdate::birthdate(int year,int month,int day):
year(year),month(month),day(day){}
void birthdate::display()
{
	cout<<"生日是：\n"; 
	cout<<year<<' '<<month<<' '<<day;
}
void birthdate::reset(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}
class professor:public teacher
{
	public: 
		professor(int num,string name,char sex,int year,int month,int day);
		void display();
		void resetbirthdate(int y,int m,int d);
	private:
		birthdate birthday;
};
professor::professor(int num,string name,char sex,int year,int month,int day):teacher(num,name,sex),birthday(year,month,day){}
void professor::display()
{
	teacher::display();
	cout<<endl;
	birthday.display();
	cout<<endl<<endl;
}
void professor::resetbirthdate(int y,int m,int d)
{
	birthday.reset(y,m,d);
}
int main()
{
	cout<<"原始数据为：\n";
	professor prof1(1,"lilei",'m',1999,12,7);
	prof1.display();
	cout<<"请输入修改的生日数据\n";
	int y,m,d;
	cin>>y>>m>>d;
	cout<<"修改后的数据为：\n";
	prof1.resetbirthdate(y,m,d);
	prof1.display();
} 

