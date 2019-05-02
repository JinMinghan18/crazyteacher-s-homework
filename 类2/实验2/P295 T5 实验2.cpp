#include<iostream>
using namespace std;
class Student
{
	public:
		Student(int ,double ); 
		int num;
		double score;
};
Student::Student(int n,double s)
{
	num = n;
	score = s;
} 
int maxscore(Student *s)
{
	int maxn,index = 0;
	maxn = s[0].score;
	for(int i = 0;i<5;i++)
	{
		if(s[i].score > maxn)
		{
			maxn = s[i].score;
			index = i;
		}
	}
	return index;
}
int main()
{
	Student a[5]={Student(1,50),Student(2,70),Student(3,88),Student(4,100),Student(5,47)};
	int maxscorenum = maxscore(a);
	cout<<"成绩最好的学生学号为："<<a[maxscorenum].num<<"号"<<endl;
	cout<<"他的成绩为："<<a[maxscorenum].score<<"分"<<endl;
	return 0; 
} 
