#include<iostream> 
#include<cmath>
#include <cstring>
#include <cassert>
#include <cctype>
#include <stack>
using namespace std;
double posfix(string exp)
{
	stack<double>opstack;
	double a = 0;
	char token,topToken;
	string posfixExp;
	int flag = 1;
	int cnt = 0;
	for(int i = 0;i<exp.length();i++)
	{
		token = exp[i];
		if(isalnum(token) && flag == 1)
		{
			a = a*10 + token-'0';
			continue;	
		} 
		else if(isalnum(token) && flag == 0)
		{
			a = a*10 + token-'0';
			cnt++;
		}
		else if(exp[i] == '.')
		{
			flag = 0;
		}
		else if(exp[i] == ' ')
		{
			
			a=a*pow(0.1,cnt);
			if(a!=0) {
				opstack.push(a);
			}
			else continue;
			cout<<"a "<<a<<endl;
			a = 0;
			flag = 1;
			cnt = 0; 
		} 
		else if(exp[i] == '+')
		{
			double s1,s2,res;
			s1 = opstack.top();
			opstack.pop();
			s2 = opstack.top();
			opstack.pop();
			res = s1+s2;
			opstack.push(res);
		}
		else if(exp[i] == '-')
		{
			double s1,s2,res;
			s1 = opstack.top();
			opstack.pop();
			s2 = opstack.top();
			opstack.pop();
			res = s1-s2;
			opstack.push(res);
		}
		else if(exp[i] == '*')
		{
			double s1,s2,res;
			s1 = opstack.top();
			opstack.pop();
			s2 = opstack.top();
			opstack.pop();
			res = s1*s2;
			opstack.push(res);
		}
		else if(exp[i] == '/')
		{
			double s1,s2,res;
			s1 = opstack.top();
			opstack.pop();
			s2 = opstack.top();
			opstack.pop();
			res = s2/s1;
			opstack.push(res);
		}
	}
	return opstack.top();
	
}
int main()
{
	string a;
	while(getline(cin,a) && a != "#")
		cout<<posfix(a);
}
