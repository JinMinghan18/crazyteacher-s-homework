	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <string>
	#include <algorithm>
	#include <cmath>
	using namespace std;
	template <typename T>
	void ssort( T array[],const int cnt)
	{
		//sort(array,array+cnt);����Ҳ���Ժܿ��� 
		T temp;
		for(int i = 0;i < cnt;i++)
			{
				for(int j = 0;j<cnt - 1;j++)
				{
					if(array[i]<array[j])
					{
						temp = array[i];
						array[i] = array[j];
						array[j] = temp; 
					}
				}
			}
	}
	template <typename T> 
	void print(const T array,const int cnt)
	{
		for(int i=0;i<cnt;i++)
		{
			cout<<array[i]<<' ';
		}
		cout<<endl;
	}
	int main()
	{
		const int cnt = 5;//�������鳤��Ϊ5
		int array1[cnt];
		double array2[cnt];
		char array3[cnt];
		string array4[cnt];
		/*---------------------------------------------*/
		cout<<"������"<<cnt<<"�����β������飺\n"; 
		for(int i=0;i<cnt;i++)
		cin>>array1[i];
		cout<<"����������Ϊ��\n" ;
		ssort(array1,cnt);
		print(array1,cnt); 
		/*---------------------------------------------*/
		cout<<"������"<<cnt<<"��double�β������飺\n"; 
		for(int i=0;i<cnt;i++)
		cin>>array2[i];
		cout<<"����������Ϊ��\n" ;
		ssort(array2,cnt);
		print(array2,cnt);
		/*---------------------------------------------*/
		cout<<"������"<<cnt<<"��char�β������飺\n" ;
		for(int i=0;i<cnt;i++)
		cin>>array3[i];
		cout<<"����������Ϊ��\n" ;
		ssort(array3,cnt);
		print(array3,cnt);
		/*---------------------------------------------*/ 
		cout<<"������"<<cnt<<"��string�β������飺\n" ;
		for(int i=0;i<cnt;i++)
		cin>>array4[i];
		cout<<"����������Ϊ��\n" ;
		ssort(array4,cnt);
		print(array4,cnt); 
		
	 } 

