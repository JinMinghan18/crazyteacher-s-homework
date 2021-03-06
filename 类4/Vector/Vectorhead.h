#ifndef HEADER_VEC
#define HEADER_VEC
#include <iostream>
using namespace std;
class Vec{
	
	public:
		Vec(int n=0); 
		Vec(const Vec& x);
		Vec& operator=(const Vec& x);
		~Vec();
		Vec operator+(const Vec& x);  //若向量不等长，则按短者长度生成结果向量
		Vec operator-(const Vec& x);  //若向量不等长，则按短者长度生成结果向量
		int& operator[](int idx);  
		void print();   //输出格式为每个元素以逗号间隔，两边框以圆括号
	private:
		int* a;
		int size;
};
//------------------------------
#endif    // endof HEADER_VEC

