#include "line.cpp"
#include <iostream>
int main()
{
	node a, b, c,d;
//    a = new node(1,1);
    a.initial();
    cout << "a= " << a << endl;
	a.display();
//    b.initial();
//    cout << "b=" << b << endl;
    c = a + b;
//    cout << "c=" << c << endl;
    d=a*b;
    cout<<"d="<<d<<endl;
    a.myfree();
    b.myfree();
    c.myfree();
    d.myfree();
    return 0;
}
