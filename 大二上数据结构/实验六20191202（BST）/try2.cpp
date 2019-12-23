#include <iostream>
#include "try1.cpp"
using namespace std;
int main(){
	string a,b,c;
	cin>>a;
	cin >> b;
	cin >> c;
	NumList l1, l2, tmp, l3;
	l1.inputNum(a);
	l2.inputNum(b);
	l3.inputNum(c);
	tmp = l1 - l2;
	NumList l = tmp%l3;
	tmp.printNum();
	l.printNum();
	/*cin >> c;
	l3.inputNum(c);

	cout<<"tmp"<< endl;
	tmp.printNum();
	cout << endl;
	cout << "l3:";
	l3.printNum();
	cout << endl;
	tmp = tmp % l3;
	tmp.printNum();*/
	system("pause");
}

