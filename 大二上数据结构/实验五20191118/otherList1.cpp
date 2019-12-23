#include <iostream>
#include "otherList.h"
using namespace std;
template <class T>
Polynomial<T>::Polynomial()
{
	first = new Node;
	num = 0;
	highestdigit = 0; 
}

template <class T>
void Polynomial<T>::myfree()
{
	Node *p = first,*q;
	while(p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	first = NULL;
	num = 0;
	highestdigit = 0;
}

template <class T>
Polynomial<T> & Polynomial<T>::operator=(const Polynomial<T>&second)
{
	myfree();
	highestdigit = second.highestdigit;
	num = second.num;
	first = second.first;
	
	return *this;
}

template <class T>
Polynomial<T>Polynomial<T>::operator+(const Polynomial<T>&second)
{
	Polynomial<T>sum;
	Node *pa = first->next,*pb = second.first->next,*pc = sum.first;
	while(pa && pb)
	{
		if(pa->data.expo == pb->data.expo)
		{
			T temp = pa->data.coef + pb->data.coef;
			if(temp)
			{
				pc->next = new Node(temp,pa->data.expo);
				pc = pc->next;
				++sum.num;
				if(sum.highestdigit<pa->data.expo) sum.highestdigit = pa->data.expo;
			}
			pa = pa->next;
			pb = pb->next;
		}
		else if(pa->data.expo > pb->data.expo)
		{	
			pc->next = new Node(pa->data.coef , pa->data.expo);
			if(sum.highestdigit < pa->data.expo) sum.highestdigit = pb->data.expo;
			++sum.num;
			pc = pc->next;
			pb = pb->next;
		}	
		else
		{
			pc->next = new Node(pa->data.coef,pa->data.expo);
			+sum.num;
			if(sum.highestdigit < pb->data.expo) sum.highestdigit = pb->data.expo;	
			pc = pc->next;
			pa = pa->next; 
		}
	}
	while(pa)
	{
		pc->next = new Node(pa->data.expo,pb->data.expo);
		++sum.num;
		if(sum.highestdigit < pb->data.expo) sum.highestdigit = pb->data.expo;
		pc = pc->next;
		pb = pb->next; 
	} 
	return sum;
} 
template<class T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial<T>& second){
    Polynomial<T> multi, temp;
    Node* pa = first->next, *pb = second.first->next, * pt;

    if (num >= second.num){ //拿项数多的那个链表乘以项数少的那个
        while(pb){          //pb是项数少的那个，
            pt = temp.first;
            while (pa){     //项数多的开始遍历  
                pt->next = new Node(pa->data.coef*pb->data.coef, pa->data.expo+pb->data.expo);//修改
                temp.num++;
                if( temp.highestdigit<pt->next->data.expo ) temp.highestdigit=pt->next->data.expo;
                pt = pt->next;
                pa = pa->next;
            }
            multi= temp+multi;
            temp.myfree();
            temp.first = new Node();
            pa = first->next;
            pb = pb->next;
        }
    }
    else{
        while(pa){
            pt = temp.first;
            while (pb){
                pt->next = new Node(pa->data.coef*pb->data.coef, pa->data.expo+pb->data.expo);//修改
                pt = pt->next;
                pb = pb->next;
            }
            multi = temp+multi;
            temp.myfree();
            temp.first = new Node();
            pb = first->next;//修改
            pa = pa->next;
        }
    }
    return multi;
}
template<class T>
void Polynomial<T>::initial()
{
    //释放链表，保留头节点
    Node* p = first->next, *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    first->next=NULL;//修改
    p = first;

    T a;
    int b;
    num = 0; highestdigit = 0;//修改
    while (cin >> a&&a != 0 && cin >> b){   //输入a=0时结束输入
        if (b >= highestdigit) highestdigit = b;
        ++num;
        p->next = new Node(a, b);
        p = p->next;
    }
    fflush(stdin);//修改
}

template<class T>
ostream& operator<<(ostream& out, Polynomial<T>& a)
{
	
    Polynomial<T>::Node *p = a.first->next;

    if (p == NULL) return out;//修改

    if (p->data.coef == 0)cout << endl;//修改
    else
	{
        if (p->data.coef != 1)
            out << p->data.coef << "x^" << p->data.expo;
        else    out << "x^" << p->data.expo;
    }
    p = p->next;
    while (p)
    {
        out << '+';
        if (p->data.coef != 1)
            out << p->data.coef << "x^" << p->data.expo;
        else    out << "x^" << p->data.expo;
        p = p->next;
    }
    return out;
}


