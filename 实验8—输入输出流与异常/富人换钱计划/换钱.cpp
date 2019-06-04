#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
int main()
{
	double richer = 100000,stranger = 0.01;
	double sumrich=0,sumstranger=0;
	for(int i=1;i<=30;i++)
	{
		cout<<"第"<<fixed<<setw(2)<<i<<"天,陌生人得到的钱为：";
		cout<<fixed<<setw(12)<<setprecision(2)<<stranger<<" ";
		cout<<"第"<<fixed<<setw(2)<<i<<"天,富人得到的钱为："; 
		cout<<fixed<<setw(12)<<setprecision(2)<<richer<<endl; 
		sumrich+=richer;
		sumstranger += stranger;
		stranger *=2;
	} 
	cout<<endl;
	cout<<"第30天后，陌生人得到的总钱数为："<<fixed<<setprecision(2)<<sumstranger<<endl;
	cout<<"第30天后，富人得到的总钱数为："<<fixed<<setprecision(2)<<sumrich<<endl;
	cout<<"第30天后，富人损失的总钱数为："<<fixed<<setprecision(2)<<sumstranger-sumrich<<endl;
} 
