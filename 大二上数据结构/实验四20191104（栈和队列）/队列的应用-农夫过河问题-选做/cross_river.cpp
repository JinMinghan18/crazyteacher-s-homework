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
//����Ϊũ���ǡ��򡢲� 
bool safeorn(char a1 ,char b1,char c1,char d1)//���庯�������Ϸ�״̬
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
    for(int i=0;i<=15;i++)//��ʼ��route����
        route[i]=-1;//-1δ������0�Ѿ��� 
    que.push(a);//��ʼa״̬0000����ѹ��que���� 
    route[0]=0;//��ǳ�ʼ״̬�Ծ��� 
    int test1=0,test2=0;//test1��ʾ��ǰ״̬(ʮ����)��test2��ʾ����״̬(ʮ����)
    while(!que.empty()&&route[15]==-1)//������в��ջ���û�ж�����԰��ͼ�������
    {
        b=que.front();//��ȡ��ͷ״̬
        test1=8*(b[0]-'0')+4*(b[1]-'0')+2*(b[2]-'0')+1*(b[3]-'0');//��״̬ת��Ϊʮ����
        que.pop();//����ͷ״̬����
        for(int i=1;i<=3;i++)//�ж�ũ���Ƿ��ܴ����ֶ������
        {
            c=b;
            if(b[0]==b[i])//���ũ�������һ��������ͬһ���ط�
            {
                if(c[0]=='0')//�����0�͹��ӻ�Ϊ1
                {
                    c[0]='1';
                    c[i]='1';
                }
                else
                {
                    c[0]='0';
                    c[i]='0';
                }
                test2=8*(c[0]-'0')+4*(c[1]-'0')+2*(c[2]-'0')+1*(c[3]-'0');//������״̬ת��Ϊʮ����
                if(safeorn(c[0],c[1],c[2],c[3])&&route[test2]==-1)//�������������Ӻ�״̬�ǺϷ���ͬʱ����״̬��û�о���
                {
                    que.push(c);//������״̬���������
                    route[test2]=test1;//�������״̬�Ѿ�����
                }
            }
        }
        c=b;//��������ǿ���ũ�򲻴��κζ������ӣ��������ж������ͬ
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
    if(route[15]!=-1)//�������ȫ�������˺ӣ�����������Ӳ���
    {
        cout<<"15   1111"<<endl;//15���û�к��ֱ�����
        for(int i=15;i>0;i=route[i])
        {
            cout<<"�����ţ�"<<route[i]<<"   ";//�����״̬��Ӧǰ��
            
            cout<<' '<<"ũ���ǡ��򡢲˵�״̬��"<<" ";
            switch(route[i])//�����״̬ʮ��������Ӧ�Ķ�������
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
