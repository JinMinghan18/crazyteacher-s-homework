#include<iostream> 
#include <cstring>
#include <cassert>
#include <cctype>
#include <stack>
using namespace std;
string posfix(string exp)
{
	char token,topToken;
	stack<char>opstack;
	string posfixExp;
	const string Blank = " ";
	for(int i = 0;i<exp.length();i++)
	{
		token = exp[i];
		switch(token)
		{
			case ' ':break;
			case '(':opstack.push(token);break;
			case ')':
			for(;;)
			{
				assert(!opstack.empty());
				topToken = opstack.top();
				opstack.pop();
				if(topToken == '(') break;
				posfixExp.append(Blank + topToken);				
			}
			break;
			case '+': case '-': case '*': case '/': case '%':
				for(;;)
				{
					if(opstack.empty() || opstack.top() == '(' || 
					(token == '*' || token == '%' ||token == '/' ) &&
					(opstack.top() =='+'||opstack.top() =='-'))
					{
						opstack.push(token);
						break;
					}
					else 
					{
						topToken = opstack.top();
						opstack.pop();
						posfixExp.append(Blank + topToken);
					}	
				}
				break;
			default:
				posfixExp.append(Blank+token);

				for(;;)
				{
					if(!isalnum(exp[i+1]) && exp[i+1] != '.') break;
					i++;
					token  = exp[i];

					posfixExp.append(1,token);
				}
		}
	}
	for(;;)
	{
		if(opstack.empty()) break;
		topToken = opstack.top();
		opstack.pop();
		if(topToken != '(')
		{
			posfixExp.append(Blank+topToken);
		}
		else 
		{
			cout<<"error in indix expression"<<endl;
			break;
		} 
	}
	return posfixExp;	
}

int main()
{
	string infixExp;
	cout<<"note:enter #for infix expression to stop"<<endl;
	for(;;)
	{
		cout<<"\nInfixexpression?\n";
		getline(cin,infixExp);
		if(infixExp == "#") break;
		cout<<"posfix expression is"<<posfix(infixExp)<<endl;
	}
}
