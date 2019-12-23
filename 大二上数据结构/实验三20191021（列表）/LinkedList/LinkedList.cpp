#include "LinkedList.h"
#include <cassert>
using namespace std;

LinkedList::LinkedList()//构造
{  mySize=0;
   first=NULL;
}

LinkedList::~LinkedList()//析构
{
	delete []first; 
}

LinkedList::LinkedList(const LinkedList& origList)//拷贝构造
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

LinkedList& LinkedList::operator=(const LinkedList& right)//赋值重载
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
    
bool LinkedList::empty() const//判空
{
	return first==NULL;
}

void LinkedList::insert(ElementType item,node* pre)//在pre后插入，pre为空则插入在首
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

void LinkedList::erase(node* pre)//删除pre后的，pre为空则删除首
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

void LinkedList::display(ostream& out) const//遍历输出
{
    for(node* p=first;p;p=p->next)
		out<<p->data<<endl;
}


node* LinkedList::find(ElementType item,int& success)
//查找特定的值item,存在返回包含该值结点的前驱和查找成功的标记1，不存在返回查找失败标记-1和NULL
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


ostream& operator<<(ostream& out,const LinkedList& aList)//输出流重载
{//请补充
	aList.display(out);
	return out;
}
