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
		cout<<"��"<<fixed<<setw(2)<<i<<"��,İ���˵õ���ǮΪ��";
		cout<<fixed<<setw(12)<<setprecision(2)<<stranger<<" ";
		cout<<"��"<<fixed<<setw(2)<<i<<"��,���˵õ���ǮΪ��"; 
		cout<<fixed<<setw(12)<<setprecision(2)<<richer<<endl; 
		sumrich+=richer;
		sumstranger += stranger;
		stranger *=2;
	} 
	cout<<endl;
	cout<<"��30���İ���˵õ�����Ǯ��Ϊ��"<<fixed<<setprecision(2)<<sumstranger<<endl;
	cout<<"��30��󣬸��˵õ�����Ǯ��Ϊ��"<<fixed<<setprecision(2)<<sumrich<<endl;
	cout<<"��30��󣬸�����ʧ����Ǯ��Ϊ��"<<fixed<<setprecision(2)<<sumstranger-sumrich<<endl;
} 
