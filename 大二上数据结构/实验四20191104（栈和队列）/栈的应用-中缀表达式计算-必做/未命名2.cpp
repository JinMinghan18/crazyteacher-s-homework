#include <iostream>
#include <stack>
using namespace std;
 
int main()
{
    stack<double> s;
    char ch;
    double result,left,right,operand,value;
    while(cin>>ch)
    {
        if(isdigit(ch))                 //�ж�������ַ��Ƿ���0--9֮�������
           {	
               cin.putback(ch);       //�������������򽫸��ַ��Ż�����������ΪҪ����Ĳ��������ܴ���10������С��������double��������
               cin>>operand;          //��double�������������
               s.push(operand);        //������ѹջ
           }
        else {
                right=s.top();s.pop();left=s.top();s.pop();     //��ջ��Ԫ�أ�������ֵ������Ϊ�������߳���������ջ����ջ��Ԫ�أ�������ֵ�������Ǳ�����������������ջ
            switch(ch)
              {
                 case '+':{value=left+right;break;}
                 case '-':{value=left-right;break;}
                 case '*':{value=left*right;break;}
                 case '/':{value=left/right;break;}
              }
              s.push(value);
 
        }
 
    }
    result=s.top();
    cout<<result<<endl;
    return 0;
}

