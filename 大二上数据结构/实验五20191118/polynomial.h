#include<iostream>
using namespace std;

class Polynomial;

class term{
    public:
    	friend class Polynomial;
		term(int co = 0,int ex = 0,term *tnx = NULL,term *tpre = NULL):coef(co),expo(ex),nx(tnx),pre(tpre){}
		friend Polynomial operator + (const Polynomial&,const Polynomial&);
		friend Polynomial operator * (const Polynomial&,const Polynomial&);
		friend ostream& operator << (ostream&,Polynomial&);
        ~term()
        {
            delete nx,pre;
        }
    private:
        int coef,expo;
        term *nx,*pre;
};

class Polynomial{
    public:
        Polynomial()
        {
            myterms = new term();
        }
		//求导 
        Polynomial differentiate();
		//拷贝 
		Polynomial(const Polynomial &obj);
        //插入项 
		void add(int,int);
        void del(term*);
        Polynomial& operator = (const Polynomial &);
        friend Polynomial operator + (const Polynomial&,const Polynomial&);        
        friend Polynomial operator * (const Polynomial&,const Polynomial&);
        friend ostream& operator << (ostream&,Polynomial&);
		void write();
    private:
        term* myterms;
};
