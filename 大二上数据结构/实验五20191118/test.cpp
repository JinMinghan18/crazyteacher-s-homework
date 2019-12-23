#include<iostream>
#include "Polynomial.cpp"

using namespace std;
int main()
{
    Polynomial P1,P2;
    int n;
    int c = 1 + 2;
    cin>>n;
    for (int i = 1,a,b;i<=n;i++)
    {
        cin>>a>>b;
        P1.add(a,b);
    }
    cin>>n;
    for (int i = 1,a,b;i<=n;i++)
    {
		cin>>a>>b;
		P2.add(a,b);
    }

	cout<<P1;
//    P1.write();
	
	cout<<P2;
//    P2.write();
    
	Polynomial P3 = P1 + P2;
//    P3.write();
	
	cout<<P3;
	
	Polynomial P4 = P1 * P2;
    cout<<P4;
    
	Polynomial P5 = P4.differentiate();//对P4求导 
    
	cout<<"求导后结果为：\n";
	cout<<P5;
    return 0;
}
