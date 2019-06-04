#include<iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	ofstream out("f1.txt",ios::out);
	int a[11],b[11];
	cout<<"ÇëÊäÈë20¸öÊý\n";
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
		out<<a[i]<<" ";
	}
	out.close();
	out.open("f2.txt",ios::out);
	for(int i=0;i<10;i++)
	{
		cin>>b[i];
		out<<b[i]<<" ";
	}
	out.close();
	ifstream in("f1.txt",ios::in);
	int c[11];
	for(int i=0;i<10;i++)
	{
		in>>c[i];
	}
	in.close();
	out.open("f2.txt",ios::out|ios::app);
	for(int i=0;i<10;i++)
	{
		out<<c[i]<<' ';
	}
	out.close();
	in.open("f2.txt",ios::in);
	int d[22];
	for(int i=0;i<20;i++)
	{
		in>>d[i];
	}
	in.close();
	out.open("f2.txt",ios::out);
	sort(d,d+20);
	for(int i=0;i<20;i++)
	{
		out<<d[i]<<" ";
	}
} 
