#include"big4.h"
#include<iostream>
#include<cmath>
using namespace std;
//====================================
//====================================
void Numberlist::checkLen()
{
  Node*p =last;
  int i=0;
  for(;p!=head->front;p=p->front)
	  i++;
  len=i;
 
}
//======================================
//将高位没有用的0删除
void Numberlist::checkNumber()
{ 
 
  Node* p=last;
  Node* t=p;
  for( ;p!=head; )
  {
     if(p->data==0)
	 {
	   p=p->front;
	   delete t;  
	   t=p;
	 }
	 else break;
  }last=p;
}
//====================================
//====================================
void Numberlist::insert(int a)
{
  Node* p=head;
  p->front=new Node(a);
  head=p->front;
  head->next=p;
}
//====================================
//建立链表
void Numberlist::inputNumber(string& s)
{
  head=new Node;
  Node* p=head;
  Node* t=head;
  len=s.length();
  for(int i=len-1;i>0;i--)
  {
   p->data=int(s[i]-'0');
   p->next=new Node;
   p=p->next;
   p->front=t;
   t=p;
  }
   p->data=int(s[0]-'0');                 
   last=p;
} 
//=====================================
//=====================================
//输出
void Numberlist::printNumber()
{ 
  Node* p=last;
  if(mark==1)
	  cout<<"-";
  while(p->front!=NULL)
  {cout<<p->data;
  p=p->front;}
  cout<<p->data;
  cout<<endl;
}
ofstream out("end.txt");
void Numberlist::printTxt()
{
	Node*p=last;
	if(mark==1)
		out<<"-";
	while(p->front!=NULL)
	{
		out<<p->data;
		p=p->front;
	}
	out<<p->data;
	out<<endl;
}
//======================================
//=======================================
string Numberlist::toString()
{ 
  string s;
  Node* p=last;
  for(;p!=NULL;p=p->front)
  {
    s+=(p->data+48);
  }
  return s;
}
//======================================
Numberlist Numberlist::operator ++()
{
	int temp=0;
	Node* p=head;
    temp=p->data+1;
	p->data=temp%10;
	temp/=10;
	if(temp>0)
	{for(p=p->next;p!=NULL;p=p->next)
		{
		  temp=p->data+temp;
		  p->data=temp%10;
          temp/=10;
		}
		if(temp>0)
		{ len++;
		  last->next=new Node(1);
		  p=last;
		  last=last->next;
		  last->front=p;
		}
	}
	  return *this;
}
//=======================================
//+操作
Numberlist Numberlist::operator +(Numberlist& list)
{
	int temp=0;
	Node* p1=head;
    Node* p2=list.head;
	if(len>list.len)
	{
	  for(;p2!=list.last->next;p2=p2->next)
	  {temp=p1->data+p2->data+temp;
	  p1->data=temp%10;
	  p1=p1->next;
	  temp=temp/10;}
	  
	  if(temp>0)
	  {
	   for(;p1!=NULL;p1=p1->next)
		{
		  temp=p1->data+temp;
		  p1->data=temp%10;
          temp/=10;
		}	   
		if(temp>0)
		{ len++;
		  last->next=new Node(1);
		  p1=last;
		  last=last->next;
		  last->front=p1;
		}
	  }
	  return *this;
	}
	if(len<list.len)
	{
	  for(;p1!=last->next;p1=p1->next)
	  {temp=p1->data+p2->data+temp;
	  p2->data=temp%10;
	  p2=p2->next;
	  temp=temp/10;}
	  if(temp>0)
	  {
	   for(;p2!=NULL;p2=p2->next)
		{
		  temp=p2->data+temp;
		  p2->data=temp%10;
          temp/=10;
		}
		if(temp>0)
		{ len++;
		  list.last->next=new Node(1);
		  p2=list.last;
		  list.last=list.last->next;
		  list.last->front=p2;
		}
	  }

	  return list;
	}
    if(len==list.len)
	{
	  for(;p1!=last->next;p1=p1->next)
	  {temp=p1->data+p2->data+temp;
	  p2->data=temp%10;
	  p2=p2->next;
	  temp=temp/10;}
	  if(temp>0)
	  {Node* t=list.last;
	  p2=new Node;
	  p2->front=t;
	  list.last=p2;
	  p2->data+=temp;}
	  return list;
	}
}
//===================================
bool operator >(Numberlist& list1,Numberlist& list2)
{
  if(list1.len>list2.len)
	  return true;
  else 
	  if(list1.len<list2.len)
		  return false;
	  else
		  
		  {
		     Node* p1=list1.last;
	         Node* p2=list2.last;
	         while(p1!=NULL)
			 {
	           if(p1->data < p2->data)
		       return false;
	           if(p1->data > p2->data)
		       return true;
	           p1=p1->front;
	           p2=p2->front;
			 }
	        return false;
		  }
}
//===================================
//比较
bool Numberlist::compare(Numberlist& list)
{
   if(len>list.len)
	   return true;
   else if(len<list.len)
	   return false;
   if(len==list.len) 
   {
     Node* p1=last;
	 Node* p2=list.last;
	 while(p1!=NULL)
	 {
	   if(p1->data < p2->data)
		   return false;
	   if(p1->data > p2->data)
		   return true;
	   p1=p1->front;
	   p2=p2->front;
	 }
	 return true;
   }
}
//===================================
//-操作
Numberlist Numberlist::operator -(Numberlist& list)
{
    int temp=0; 
	Node* p1=head;
    Node* p2=list.head;
    if(compare(list))
	{for(;p2!=NULL;p2=p2->next,p1=p1->next)
		{
		    temp=p1->data-p2->data+temp;
			if(temp<0)
			p1->data=10-abs(temp);
			else p1->data=temp;
			temp=(temp<0 ? -1:0);
		}
		if(temp==-1)
		{
			int flag=0;
		 	while(p1->data==0)
				{
				p1=p1->next;
				flag++;
				}
		  	p1->data+=temp;
		  	if(flag>0) p1->front->data=9;
		}
		return *this;
	}
		
    else
	{ 
	  list.mark=1;
	  for(;p1!=NULL;p2=p2->next,p1=p1->next)
		{
		    temp=p2->data-p1->data+temp;
			if(temp<0)
			p2->data=10-abs(temp);
			else p2->data=temp;
			temp=(temp<0 ? -1:0);
		}
		if(temp==-1)
		{ int flag=0;
		  while(p2->data==0)
		  {p2=p2->next;flag++;}
		  p2->data+=temp;
		  if(flag>0) p2->front->data=9;
		}
	  return list;
	}
}	
//===================================
//===================================
//乘操作
Numberlist Numberlist::operator *(Numberlist& list)
{
  int temp=0;
  string s;
  Node* p1=head;
  Node* p2=list.head;
  for(int i=0;i<len+list.len;i++)
	  s+="0";
  Numberlist newlist;
  newlist.inputNumber(s);
  Node* p3=newlist.head;
  Node* t=newlist.head;
  for(;p1!=NULL;p1=p1->next)
  {
	  p3=t;
	  for(p2=list.head;p2!=NULL;p2=p2->next)
	  {
		  p3->data=p1->data*p2->data+p3->data;
		  p3=p3->next;
	  }
	  t=t->next;
  }
  p3=newlist.head;
  for(;p3!=NULL;p3=p3->next)
  {
    temp=p3->data+temp; 
	p3->data=temp%10;
	temp=temp/10;	
  }
  return newlist;
}
//=================================
//=================================
//除法操作
Numberlist Numberlist::operator /(Numberlist& list)
{
   //length分子大于分母的情况
	if(len>list.len)
   { 
	 Node* p=last;
     string marks;
     string result;
     for(int i=0;i<list.len;i++)
	 {
       marks+=(p->data+48);
	   p=p->front;
	 }
    // p=p->next;
     Numberlist newlist;char count; 
     newlist.inputNumber(marks); 
     for(;p!=NULL;p=p->front)
	 {
       count='0';
	   while(!(list>newlist))
	   {
	     newlist=newlist-list;		
		 newlist.checkNumber();
		 newlist.checkLen();
		 count++;
	   }
	   result+=count;
	   newlist.insert(p->data);
	   newlist.checkNumber();
	   newlist.checkLen();
	 }
	 count='0';
	 while(!(list>newlist))
	   { 
	     newlist=newlist-list;
		 newlist.checkNumber();
		 newlist.checkLen();
		 count++;
	   }
	 result+=count;
     Numberlist temp;
	 temp.inputNumber(result);	
	 temp.checkNumber();
     return temp;
	}
   //length相同情况下
	if(len==list.len)
   {
     string s=toString();
	 Numberlist temp;
	 temp.inputNumber(s);
	 char  count='0';
	 while(temp.compare(list))
	 {
	    temp=temp-list;
		count++;
	 }
	string newS;
	newS+=count;
    Numberlist newTemp;
	newTemp.inputNumber (newS);
	return newTemp;
   }
   //length分子小与分母，结果一定小于1
	if(len<list.len)
   {
	 string s="0";
	 Numberlist temp;
	 temp.inputNumber(s);
	 return temp;
   }
}
//===========================================
//指数操作
string Numberlist::mi(Numberlist &list)
{
  Numberlist temp,marklist,temp1;
  string s=this->toString();
  temp.inputNumber(s);
  string s1="1";
  temp1.inputNumber(s1);
  string s2=list.toString();
  
  marklist.inputNumber(s1);
  while(list.compare(marklist))
  {
    temp1=temp1*temp;
	//temp1.printNumber();
	++marklist;
	//marklist.printNumber();
  }
  	temp1.checkNumber();
  string s3=temp1.toString();
  return s3;
}

