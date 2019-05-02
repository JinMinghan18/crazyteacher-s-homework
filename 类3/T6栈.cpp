#include<iostream>
#include <cstring>
using namespace std;
template <class T>
class Stack //����ջ��
{           
	public:
		Stack(){size=0;elements = new T;};        //����һ����ջ
		bool empty();         //��ջΪ�գ��򷵻���
		int peek();            //����ջ��Ԫ��
		void push(T value);   //��һ����������ջ��
		T pop();            //��ջ��ɾ��ջ��Ԫ�أ������䷵��
		int getSize();         //����ջ��Ԫ�ظ���
		int clear(){};
	private:
		T *elements;   //���ڱ���ջ��Ԫ��
		int size;            //ջ��Ԫ�ظ���
};
template <class T>
bool Stack<T>::empty() 
{
	return(size==0);
}
template <class T>
int Stack<T>::peek() 
{
	return elements[size-1];	
}
template <class T>
void Stack<T>::push(T value) 
{
	elements[size++]=value;	
} 
template <class T>
T Stack<T>::pop() 
{
	return elements[--size];	
}
template <class T>
int Stack<T>::getSize()
{
	return size;
}
int main()
{
	cout<<"������int�����ĸ�����";
	Stack<int> s1;
	int num;
	cin>>num;
	int a;
	cout<<"������������Ҫpush����\n";
	for(int i=0;i<num;i++)
	{
		cin>>a;
		s1.push(a);
	}
	cout<<"pop����������Ϊ:\n";
	while(!s1.empty())
		cout<<s1.pop()<<" ";
	cout<<endl;
	s1.clear();
	/*---------------------------*/
	cout<<"������double�����ĸ�����";
	Stack<double> s2;
	cin>>num;
	cout<<"������������Ҫpush����\n";
	double b;
	for(int i=0;i<num;i++)
	{
		cin>>b;
		s2.push(b);
	}
	cout<<"pop����������Ϊ:\n";
	while(!s2.empty())
		cout<<s2.pop()<<" ";
	cout<<endl;
	s2.clear();
	/*---------------------------*/
	cout<<"������char�����ĸ�����";
	Stack<char> s3;
	cin>>num;
	cout<<"������������Ҫpush����\n";
	string c;
	for(int i=0;i<num;i++)
	{
		cin>>c[i];
		s3.push(c[i]);
	}
	cout<<"pop����������Ϊ:\n";
	while(!s3.empty())
		cout<<s3.pop()<<" ";
	cout<<endl;
	s3.clear();
	return 0;
}

