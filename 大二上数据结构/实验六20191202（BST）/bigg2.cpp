#include <iostream>
#include "bigg1.cpp"
using namespace std;
int main(){
	string a,b;
	cin>>a;
	cin>>b;
	NumList l1,l2,l3;
	l1.inputNum(a);
	l2.inputNum(b);
	
	l3 = l1/l2;
//	l3.checkNum();
	l3.printNum(); 
	system("pause");
}

