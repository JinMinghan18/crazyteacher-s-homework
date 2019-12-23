#include "LinkedList.h"
#include <cassert>
using namespace std;

LinkedList::LinkedList()//����
{  mySize=0;
   first=NULL;
}

LinkedList::~LinkedList()//����
{
	delete []first; 
}

LinkedList::LinkedList(const LinkedList& origList)//��������
{
	mySize=origList.mySize;
	if(origList.first!=NULL)
	{
		node* p=origList.first;
		first=new node(p->data);
		p=p->next;
		node* pp=first;
		while(p){
			pp->next=new node(p->data);
			p=p->next;
            pp=pp->next;
		}
    }
	else
		first=NULL;
}

LinkedList& LinkedList::operator=(const LinkedList& right)//��ֵ����
{
	mySize=right.mySize;
	if(right.first!=NULL)
	{
		delete []first;
		node* p=right.first;
		first=new node(p->data);
		p=p->next;
		node* pp=first;
		while(p){
			pp->next=new node(p->data);
			p=p->next;
            pp=pp->next;
		}
    }
	else
		first=NULL;
	return *this;
}
    
bool LinkedList::empty() const//�п�
{
	return first==NULL;
}

void LinkedList::insert(ElementType item,node* pre)//��pre����룬preΪ�����������
{
	mySize++;
	if(pre == 0)
	{
		node *a = new node(item);
		a->next = first;
		first = a;
	} 
	else
	{
		node *pt;
		pt = first;
		while(pt != pre)
		{
			pt = pt->next; 
		}
		node *a = new node(item,pt->next);
		pt = a;
	}
}

void LinkedList::erase(node* pre)//ɾ��pre��ģ�preΪ����ɾ����
{
	mySize--;
	if(pre == 0)
	{
		node* temp = first;
		first = temp->next;
	}
	else 
	{
		node *temp = first;
		while(temp != pre)
		{
			temp = temp->next;
		}
		node * n1 = temp->next;
		temp->next = n1->next;
	}
}

void LinkedList::display(ostream& out) const//�������
{
    for(node* p=first;p;p=p->next)
		out<<p->data<<endl;
}


node* LinkedList::find(ElementType item,int& success)
//�����ض���ֵitem,���ڷ��ذ�����ֵ����ǰ���Ͳ��ҳɹ��ı��1�������ڷ��ز���ʧ�ܱ��-1��NULL
{   node* pre=NULL,*p=first;
	while(p->next != 0&&p->data!=item)
	{
		pre=p;
		p=p->next;
	}
	if(p->data==item) 
	{
		success=1;
		return pre;
	}
	else
	{
		success=-1;
		return NULL;
	}

}


ostream& operator<<(ostream& out,const LinkedList& aList)//���������
{//�벹��
	aList.display(out);
	return out;
}
