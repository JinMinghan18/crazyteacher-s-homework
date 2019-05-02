#include <iostream>
#include<cstring> 
using namespace std;
template <class T> 
class array
{
	public:
		array(const int s)
		{
			size = s;
		}
		void set_ele();
		void print();
		void search(T num);
		
	private:
		T *ptr;
		int size;
}; 
template <class T>
void array<T>::set_ele() 
{
	ptr = new T[size];
	cout<<"�����������е�����\n";
	for(int i=0;i<size;i++)
	{
		cin>>ptr[i];
	}
}
template <class T>
void array<T>::print(){
	for(int i=0;i<size;i++){
		cout<<ptr[i]<<' ';
	}
	cout<<'\n';
}
template <class T>
void array<T>::search(T num){
	int flag = 0;
	for(int i = 0;i<size;i++){
		if(num == ptr[i]){
			flag = 1;	
			cout<<num<<"Ϊ�����е�"<<i+1<<"������\n"; 
		}
		else if(num != ptr[i] && i != size-1)
			continue;
		if(!flag)
			cout<<"error!num does not exist in this array\n";
	}	
}
int main()
{
	cout<<"��������������ĳ��ȣ� "; 
	int s;
	cin>>s; 
	array<int>a(s);
	a.set_ele();
	cout<<"��������飺\n";
	a.print();
	cout<<"��������Ҫ�ҵ���Ԫ��: ";
	int num1;
	cin>>num1;
	a.search(num1);
	/*---------------------------*/ 
	cout<<"������double������ĳ��ȣ� "; 
	cin>>s; 
	array<double>b(s);
	b.set_ele();
	cout<<"��������飺\n";
	b.print();
	cout<<"��������Ҫ�ҵ���Ԫ��: ";
	double num2;
	cin>>num2;
	b.search(num2);
	/*---------------------------*/ 
	cout<<"������string������ĳ��ȣ� "; 
	cin>>s; 
	array<string>c(s);
	c.set_ele();
	cout<<"��������飺\n";
	c.print();
	cout<<"��������Ҫ�ҵ���Ԫ��: ";
	string num3;
	cin>>num3;
	c.search(num3); 
}
