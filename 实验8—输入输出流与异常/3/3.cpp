#include<iostream>
#include <fstream>
using namespace std;
class student
{
	private:
		string id;
		string name;
		double score;
	public:
		student(){}
		student(string i,string n,double s):id(i),name(n),score(s){}
		string get_id()
		{
			return id;
		}
		string get_name()
		{
			return name;
		}
		double get_score()
		{
			return score; 
		}
		void chuan_id(string i)
		{
			id = i;
		} 
		void chuan_name(string n)
		{
			name = n;
		}
		void chuan_score(double s)
		{
			score = s;
		}
};
int main()
{
	student a[100];
	a[0] = student("1","jmh",85);
	a[1] = student("2","mhj",80);
	a[2] = student("3","hjm",75);
	ofstream out("学生信息.txt",ios::out);
	for(int i=0;i<3;i++)
	{
		out<<a[i].get_id()<<' '<<a[i].get_name()<<' '<<a[i].get_score()<<endl;
	}
	out.close();
	ifstream in("学生信息.txt",ios::in);
	for(int i=0;i<3;i++)
	{
		string id,name;
		double s;
		in>>id>>name>>s;
		a[i].chuan_id(id);
		a[i].chuan_name(name);
		a[i].chuan_score(s);
	}
	for(int i=0;i<3;i++)
	{
		cout<<"id:"<<a[i].get_id()<<"    name:"<<a[i].get_name()<<"    score:"<<a[i].get_score()<<endl;
	}
} 
