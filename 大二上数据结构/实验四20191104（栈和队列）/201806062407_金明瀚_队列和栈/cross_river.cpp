#include<string>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
queue<string>que;
string a="0000";
string b,c;
int route[16],temp,l,r;
//依次为农夫、狼、羊、菜 
bool safeorn(char a1 ,char b1,char c1,char d1)//定义函数来检测合法状态
{
    if((a1=='1'&&b1=='1'&&c1=='1'&&d1=='1')||
       (a1=='0'&&b1=='0'&&c1=='0'&&d1=='0')||
       (a1=='1'&&b1=='0'&&c1=='1'&&d1=='0')||
       (a1=='1'&&b1=='1'&&c1=='1'&&d1=='0')||
       (a1=='1'&&b1=='1'&&c1=='0'&&d1=='1')||
       (a1=='1'&&b1=='0'&&c1=='1'&&d1=='1')||
       (a1=='0'&&b1=='1'&&c1=='0'&&d1=='0')||
       (a1=='0'&&b1=='0'&&c1=='1'&&d1=='0')||
       (a1=='0'&&b1=='0'&&c1=='0'&&d1=='1')||
       (a1=='0'&&b1=='1'&&c1=='0'&&d1=='1'))
    	return true;
    else 
		return false;
}
int search()
{
    for(int i=0;i<=15;i++)//初始化route数组
        route[i]=-1;//-1未经过，0已经过 
    que.push(a);//起始a状态0000合理，压入que队列 
    route[0]=0;//标记初始状态以经过 
    int test1=0,test2=0;//test1表示当前状态(十进制)，test2表示假设状态(十进制)
    while(!que.empty()&&route[15]==-1)//如果队列不空或者没有都到达对岸就继续搜索
    {
        b=que.front();//获取队头状态
        test1=8*(b[0]-'0')+4*(b[1]-'0')+2*(b[2]-'0')+1*(b[3]-'0');//将状态转化为十进制
        que.pop();//将队头状态弹出
        for(int i=1;i<=3;i++)//判断农夫是否能带三种对象过河
        {
            c=b;
            if(b[0]==b[i])//如果农夫和其中一个对象在同一个地方
            {
                if(c[0]=='0')//如果是0就过河换为1
                {
                    c[0]='1';
                    c[i]='1';
                }
                else
                {
                    c[0]='0';
                    c[i]='0';
                }
                test2=8*(c[0]-'0')+4*(c[1]-'0')+2*(c[2]-'0')+1*(c[3]-'0');//将假设状态转化为十进制
                if(safeorn(c[0],c[1],c[2],c[3])&&route[test2]==-1)//如果假设情况过河后状态是合法的同时这种状态还没有经过
                {
                    que.push(c);//将这种状态放入队列中
                    route[test2]=test1;//标记这种状态已经经过
                }
            }
        }
        c=b;//这种情况是考虑农夫不带任何东西过河，与上面判断情况相同
        if(c[0]=='0')
        {
            c[0]='1';
        }
        else
        {
            c[0]='0';
        }
        test2=8*(c[0]-'0')+4*(c[1]-'0')+2*(c[2]-'0')+1*(c[3]-'0');
        if(safeorn(c[0],c[1],c[2],c[3])&&route[test2]==-1)
        {
            que.push(c);
            route[test2]=test1;
        }
    }
    if(route[15]!=-1)//如果最终全部都过了河，倒序输出过河步骤
    {
        cout<<"15   1111"<<endl;//15情况没有后继直接输出
        for(int i=15;i>0;i=route[i])
        {
            cout<<"情况序号："<<route[i]<<"   ";//输出该状态对应前驱
            
            cout<<' '<<"农夫、狼、羊、菜的状态："<<" ";
            switch(route[i])//输出该状态十进制数对应的二进制数
            {
                case 0:cout<<"0 0 0 0"<<endl;break;
                case 1:cout<<"0 0 0 1"<<endl;break;
                case 2:cout<<"0 0 1 0"<<endl;break;
                case 3:cout<<"0 0 1 1"<<endl;break;
                case 4:cout<<"0 1 0 0"<<endl;break;
                case 5:cout<<"0 1 0 1"<<endl;break;
                case 6:cout<<"0 1 1 0"<<endl;break;
                case 7:cout<<"0 1 1 1"<<endl;break;
                case 8:cout<<"1 0 0 0"<<endl;break;
                case 9:cout<<"1 0 0 1"<<endl;break;
                case 10:cout<<"1 0 1 0"<<endl;break;
                case 11:cout<<"1 0 1 1"<<endl;break;
                case 12:cout<<"1 1 0 0"<<endl;break;
                case 13:cout<<"1 1 0 1"<<endl;break;
                case 14:cout<<"1 1 1 0"<<endl;break;
            }
            if(i==0)
                break;
        }
    }
}
int main()
{
	
    search();
}
