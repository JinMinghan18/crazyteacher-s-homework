#ifndef POLYNOMIAL
#define POLYNOMIAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template<class Coeftype>class Polynomial;
template<class Coeftype>ostream& operator<<(ostream& out, Polynomial<Coeftype>&a);

template <typename Coeftype>
class Polynomial
{
	private:
	class Term
	{
		public:
		Coeftype coef;//系数 
		unsigned expo;//幂 
	};
	class Node
	{
		public:
		Term data;
		Node *next;
		
		Node(Coeftype co = 0,int ex = 0,Node *ptr = 0)
		{
			data.coef = co;
			data.expo = ex;
			next = ptr;
		}
	};
	//typedef Node *NodePointer;
	public:
		void myfree();
		Polynomial();
		Polynomial<Coeftype> operator+(const Polynomial<Coeftype> & secondPoly);
		Polynomial<Coeftype> operator*(const Polynomial<Coeftype> & secondPoly);	
		Polynomial<Coeftype> &operator=(const Polynomial<Coeftype> & secondPoly);
		void initial();
		friend ostream &operator<< <Coeftype>(ostream &out,Polynomial<Coeftype> & a);
		 
	private:
		int highestdigit;
		Node *first;
		int num;//记录项数	
};
#endif 
