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
		//sort(array,array+cnt);快排也可以很快解决 
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
		const int cnt = 5;//设置数组长度为5
		int array1[cnt];
		double array2[cnt];
		char array3[cnt];
		string array4[cnt];
		/*---------------------------------------------*/
		cout<<"请输入"<<cnt<<"个整形测试数组：\n"; 
		for(int i=0;i<cnt;i++)
		cin>>array1[i];
		cout<<"升序排序结果为：\n" ;
		ssort(array1,cnt);
		print(array1,cnt); 
		/*---------------------------------------------*/
		cout<<"请输入"<<cnt<<"个double形测试数组：\n"; 
		for(int i=0;i<cnt;i++)
		cin>>array2[i];
		cout<<"升序排序结果为：\n" ;
		ssort(array2,cnt);
		print(array2,cnt);
		/*---------------------------------------------*/
		cout<<"请输入"<<cnt<<"个char形测试数组：\n" ;
		for(int i=0;i<cnt;i++)
		cin>>array3[i];
		cout<<"升序排序结果为：\n" ;
		ssort(array3,cnt);
		print(array3,cnt);
		/*---------------------------------------------*/ 
		cout<<"请输入"<<cnt<<"个string形测试数组：\n" ;
		for(int i=0;i<cnt;i++)
		cin>>array4[i];
		cout<<"升序排序结果为：\n" ;
		ssort(array4,cnt);
		print(array4,cnt); 
		
	 } 

