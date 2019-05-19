#include<iostream>
#include<string>
using namespace std;
class teacher
{
	public:
		teacher(string nam,int a,string se,
				string addr,string t,string tit);
		void display();
	protected:
		int age;
		string name;
		string sex;
		string address;
		string tel; 
		string title;
};
teacher::teacher(string nam,int a,string se,
				string addr,string t,string tit):
				name(nam),age(a),sex(se),address(addr),
				tel(t),title(tit){}
void teacher::display()
{
	cout<<"name:  "<<name<<endl;
	cout<<"age:  "<<age<<endl;
	cout<<"sex:  "<<sex<<endl;
	cout<<"address:  "<<address<<endl;
	cout<<"tel:  "<<tel<<endl;
	cout<<"title:  "<<title<<endl;
}
class cadre
{
	public:
		cadre(int a,string nam,string pos,string se,string addr,string t);
		void display();
	protected:
		int age;
		string post;
		string name;
		string sex;
		string address;
		string tel;	
};
cadre::cadre(int a,string nam,string pos,string se,string addr,string t):
age(a),name(nam),post(pos),sex(se),address(addr),tel(t){}
void cadre::display()
{
	cout<<"name:   "<<name<<endl;
	cout<<"age:   "<<age<<endl;
	cout<<"post:   "<<post<<endl;
	cout<<"sex:   "<<sex<<endl;
	cout<<"address:   "<<address<<endl;
	cout<<"tel:   "<<tel<<endl;
}
class teacher_cadre:public teacher,public cadre
{
	public:
		teacher_cadre(int age,string name,string post,string sex,
		string address,string tel,string title,int wages);
		void show();		
	private:
		int wages;
};
teacher_cadre::teacher_cadre(int age,string name,string post,
string sex,string address,string tel,string title,int wage):
teacher(name,age,sex,address,tel,title),
cadre(age,name,post,sex,address,tel),wages(wage){}
void teacher_cadre::show()
{
	teacher::display(); 
	cout<<"post:   "<<cadre::post<<endl;
	cout<<"wages:   "<<wages;
}
int main()
{
	teacher_cadre c(30,"·å¸ç","teacher","famale","hangzhou","2333333","prof.",10000000);
	c.show();
	return 0;
} 
