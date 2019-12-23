#include <iostream>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
    char ch;
    double num;
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]>='0' && s[i]<='9' ||s[i] == '.' || s[i] !=' ') cin.putback(s[i]);
    	
	}
//    cout<<ch;
    cin>>num;
    cout<<num;
}
