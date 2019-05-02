#include<iostream>
#include <cstring>
using namespace std;
template <class T>
class Stack //定义栈类
{           
	public:
		Stack(){size=0;elements = new T;};        //创建一个空栈
		bool empty();         //若栈为空，则返回真
		int peek();            //返回栈顶元素
		void push(T value);   //将一个整数存入栈顶
		T pop();            //弹栈，删除栈顶元素，并将其返回
		int getSize();         //返回栈中元素个数
		int clear(){};
	private:
		T *elements;   //用于保存栈中元素
		int size;            //栈中元素个数
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
	cout<<"请输入int型数的个数：";
	Stack<int> s1;
	int num;
	cin>>num;
	int a;
	cout<<"请依次输入想要push的数\n";
	for(int i=0;i<num;i++)
	{
		cin>>a;
		s1.push(a);
	}
	cout<<"pop出的数依次为:\n";
	while(!s1.empty())
		cout<<s1.pop()<<" ";
	cout<<endl;
	s1.clear();
	/*---------------------------*/
	cout<<"请输入double型数的个数：";
	Stack<double> s2;
	cin>>num;
	cout<<"请依次输入想要push的数\n";
	double b;
	for(int i=0;i<num;i++)
	{
		cin>>b;
		s2.push(b);
	}
	cout<<"pop出的数依次为:\n";
	while(!s2.empty())
		cout<<s2.pop()<<" ";
	cout<<endl;
	s2.clear();
	/*---------------------------*/
	cout<<"请输入char型数的个数：";
	Stack<char> s3;
	cin>>num;
	cout<<"请依次输入想要push的数\n";
	string c;
	for(int i=0;i<num;i++)
	{
		cin>>c[i];
		s3.push(c[i]);
	}
	cout<<"pop出的数依次为:\n";
	while(!s3.empty())
		cout<<s3.pop()<<" ";
	cout<<endl;
	s3.clear();
	return 0;
}

