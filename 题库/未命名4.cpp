#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;
int main()
{
	string s; getline(cin, s);
	s = s + ' ';
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'A'&&s[i] <= 'Z')
			s[i] += 32;
	for (string s1; getline(cin, s1);)
	{
		for (int i = 0; i < s1.length(); i++)
			if (s1[i] >= 'A'&&s1[i] <= 'Z')
				s1[i] += 32;
		int count = 0;
		istringstream sin(s1);
		for (string t; sin >> t;)
		{
			if (t.length()>1&&s.find(t+' ')!=string::npos)
				count += 2;
			else
				count += t.length();
			count++;
			t.clear();
		}
		cout << count  << endl;
	}
}
