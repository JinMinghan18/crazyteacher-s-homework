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
	cout<<"������Ԫ�صĸ�����\n";
	int n;
	cin>>n;
	cout<<"����������ķ���������1ѡ����������-1ѡ���򣩣�\n";
	int flag;
	cin>>flag;
	cout<<"����������Ԫ�أ��Կո��������\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	intsort B(a,n,flag);
	B.Sort();
	B.print();
	return 0;
}
