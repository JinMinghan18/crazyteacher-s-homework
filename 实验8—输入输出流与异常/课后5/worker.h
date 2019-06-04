#include<iostream>
#include <fstream>
using namespace std;
class worker
{
	public:
		worker(){}
		worker(long long i,string t,string n,int a,double s):id(i),tel(t),name(n),age(a),salary(s){}
		string tel;
		long long id;
		string name;
		int age;
		double salary; 
}; 
