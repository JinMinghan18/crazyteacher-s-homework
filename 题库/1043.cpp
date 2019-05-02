#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int dp[1001][1001];
int a[1001];
 
int fun(int left, int right)
{
  if(left > right)
    return 0;
  if(left == right)
    return dp[left][right];
  if(dp[left][right] != -1)
    return dp[left][right];
  
  //ѡ����ˣ����ʣ�µ���˴���ѡ����ˣ�����ѡ���Ҷˣ�Ȼ��ʣ�µĶ��ٵݹ� 
  int leftSum = a[left] + (a[left+1] >= a[right]? fun(left+2, right) : fun(left+1, right-1) );
  //ѡ���Ҷ� 
  int rightSum = a[right] +(a[left] >= a[right-1]? fun(left+1, right-1): fun(left, right-2));    
  dp[left][right] = max(leftSum, rightSum);
  return dp[left][right];
}
 
int main()
{
    int n = 0;
    int turn = 0;
    
    while(1)
    {
      cin >> n;
      if (n == 0)
      break;     
      memset(dp,-1,sizeof(dp));
      int Sum =0;
      for(int i=0; i < n; i++)
      {
         cin >> a[i];
         Sum += a[i];
       }
       int firstSum = fun(0,n-1);
        
       turn++;
       cout << "In game " << turn << ", the greedy strategy might lose by as many as "<<2*firstSum-Sum<<" points."<< endl;  
       
    }
    
 
    return 0;   
}                                 
