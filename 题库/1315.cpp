#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2){
		bool flag = 0;
		int len = s1.length();
		if(s1==s2){
			printf("Yes\n");
			continue;
		}
		for(int i = 1;i <= len;i++){
			s1.insert(s1.begin(),s1[len-1]);
			s1.erase(s1.end()-1);
			if(s1==s2){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Yes\n");
			continue;
		}
		reverse(s1.begin(),s1.end());
		for(int i = 1;i <= len;i++){
			s1.insert(s1.begin(),s1[len-1]);
			s1.erase(s1.end()-1);
			if(s1==s2){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}

