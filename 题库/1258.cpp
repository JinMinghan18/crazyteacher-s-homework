#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<cstdio>
using namespace std;
#define maxn 1001
string a;
string b;
const int B = 100000007;
typedef unsigned long long ull;
ull _hash(int al, int bl)
{
    if (al < bl)return 0;
    ull t = 1, ah = 0, bh = 0, cnt = 0;

    for (int i = 0; i < bl; i++)t *= B;
    for (int i = 0; i < bl; i++)ah = ah*B + a[i];
    for (int i = 0; i < bl; i++)bh = bh*B + b[i];
    for (int i = 0; i + bl<=al; i++)
    {
        //cout << a << "\n" << b << endl;
        //cout << ah << "\t" << bh << endl;
        if (ah == bh)
        {
            cnt++;
            ah = ah - a[i + bl - 1] + '$';
            //���ǹؼ�һ����������ĸ֮��hashֵ�����仯�����Ա仯��Ϊ'$'-a[i+bl-1]
            a[i + bl-1] = '$';//������ƥ������һ����ĸ
        }
        if (i+bl<al)
            ah = ah*B - a[i] * t + a[i + bl];
    }
    return cnt;
}
int main()
{
    while (cin>>a&&a!="#")
    {   
        cin >> b;
        int al = a.length();
        int bl = b.length();
        ull res = _hash(al, bl);
        cout << res << endl;
    }
}
