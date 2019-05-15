#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;
string delete1(string s)
{	
	for (int i=0; i<=s.length(); i++)
	{
		if (s[i] == '('&&s[i+1] == ')')
		{
			s.erase(i,2);
			return delete1(s);
		}
	    else if (s[i] == '['&&s[i + 1] == ']')
		{
			s.erase(i, 2);
			return delete1(s);
		}
	    else if (s[i] == '{'&&s[i + 1] == '}')
		{
			s.erase(i, 2);
			return delete1(s);
		}
	}
	return s;
}
int main()
{
	string s;
	while(cin>>s)
	{
		string a =  delete1(s); 
		if (a.length() == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

