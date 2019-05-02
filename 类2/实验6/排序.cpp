#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
class intsort
{
	public:
		intsort(int *,int ,int );
		void Sort();
		void print();
		int Flag;
		int N;
		int *A;		
}; 
intsort::intsort(int* a,int n,int flag):A(a),N(n),Flag(flag){}
void intsort::Sort()
{
	if(Flag == 1)
	{
		sort(A,A+N);
	}
	else sort(A,A+N,cmp);
}
void intsort::print()
{
	for(int i=0;i<N;i++)
	{
		cout<<A[i]<<" "; 
	}
} 
int main()
{
	int a[100];
	cout<<"请输入元素的个数：\n";
	int n;
	cin>>n;
	cout<<"请输入排序的方法（输入1选择升序；输入-1选择降序）；\n";
	int flag;
	cin>>flag;
	cout<<"请输入数组元素（以空格隔开）：\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	intsort B(a,n,flag);
	B.Sort();
	B.print();
	return 0;
}
