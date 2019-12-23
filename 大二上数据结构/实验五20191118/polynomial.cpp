#include "Polynomial.h"

void Polynomial::del(term *p)
{
    if (p->nx == NULL)
		p->pre->nx = NULL;
    else
    {
		p->pre->nx = p->nx;
		p->nx->pre = p->pre;
    }
    delete p;
}

Polynomial::Polynomial(const Polynomial& obj)
{
    cout<<&obj;
	myterms = new term;
    term *p1 = myterms,*p2 = obj.myterms->nx;
    while (p2 != NULL)
    {
        term *tmp = new term(p2->coef,p2->expo,NULL,p1);
        p2 = p2->nx;
        p1->nx = tmp;
        p1 = tmp;
    }
}

Polynomial& Polynomial::operator = (const Polynomial &obj)
{
    term *p1 = myterms,*p2 = obj.myterms->nx;
    while (p2 != NULL)
    {
        term *tmp = new term(p2->coef,p2->expo,NULL,p1);
        p1->nx = tmp;
        p1 = tmp;
    }
    return *this;
}

void Polynomial::add(int coef,int expo)
{
    if (coef == 0) return;
    term *p1 = myterms->nx,*pre = myterms;
    while (p1 != NULL && p1->expo <= expo)
    {
        if (p1 ->expo == expo)
        {
            p1->coef += coef;
            if (p1->coef == 0) delete(p1);
            return;
        }
        pre = p1,p1 = p1->nx;
    }
    if (p1 != NULL)
    {
        term *p = new term(coef,expo,p1,pre);
        pre->nx = p;
        p1->pre = p;
    }
    else
    {
        term *p = new term(coef,expo,NULL,pre);
        pre->nx = p;
    }
}

Polynomial operator + (const Polynomial &obj1,const Polynomial &obj2)
{
    Polynomial temp;
    term *p1 = obj1.myterms->nx;
    term *p2 = obj2.myterms->nx;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo == p2->expo)
        {
            temp.add(p1->coef + p2->coef,p1->expo);
            p1 = p1->nx;
            p2 = p2->nx;
        }
        else if (p1->expo < p2->expo)
        {
            temp.add(p1->coef,p1->expo);
            p1 = p1->nx;
        }
        else
        {
            temp.add(p2->coef,p2->expo);
            p2 = p2->nx;
        }
    }
    while (p1 != NULL)
    {
        temp.add(p1->coef,p1->expo);
        p1 = p1->nx;
    }
    while (p2 != NULL)
    {
        temp.add(p2->coef,p2->expo);
        p2 = p2->nx;
    }
    return temp;
}

Polynomial operator * (const Polynomial &obj1,const Polynomial &obj2)
{
    Polynomial temp1;
    term *p1 = obj1.myterms->nx;
    while (p1 != NULL)
    {
        term *p2 = obj2.myterms->nx;
        while (p2 != NULL)
        {
            temp1.add(p1->coef * p2->coef,p2->expo + p1->expo);
            p2 = p2->nx;            
        }
        p1 = p1->nx;
    }
    return temp1;
}

Polynomial Polynomial::differentiate()
{
    Polynomial tmp;
    term *p = myterms->nx;
    while (p != NULL)
    {
        tmp.add(p->coef * p->expo,p->expo - 1);
        p = p->nx;
    }
    return tmp;
}

void Polynomial::write()
{
    term *p = myterms->nx;
    while (p != NULL)
    {
        if (p->expo != 0)
		{
			if (p->coef != 1) cout<<p->coef;
			cout<<"x";
			if (p->expo != 1) cout<<'^'<<p->expo;
		} 
        else cout<<p->coef;
        p = p->nx;
        if (p != NULL) cout<<" + ";
    }
    cout<<'\n';
}

ostream& operator << (ostream& out,Polynomial& p)
{
    p.write();
    return out;
}
