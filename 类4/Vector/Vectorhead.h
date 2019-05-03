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
		Vec operator+(const Vec& x);  //���������ȳ����򰴶��߳������ɽ������
		Vec operator-(const Vec& x);  //���������ȳ����򰴶��߳������ɽ������
		int& operator[](int idx);  
		void print();   //�����ʽΪÿ��Ԫ���Զ��ż�������߿���Բ����
	private:
		int* a;
		int size;
};
//------------------------------
#endif    // endof HEADER_VEC

