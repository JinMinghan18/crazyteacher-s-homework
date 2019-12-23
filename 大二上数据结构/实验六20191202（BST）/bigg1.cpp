#include <iostream>
#include <fstream>
#include <cmath>
#include"bigg.h" 
using namespace std;

void NumList::checkNum()
{
	Node *p = last; 
	Node *t = p;
	for( ; p!=head;)//�Ӹ�λ��ʼ 
	{
		if(p->getData() == 0)//Ϊ0��ɾ�� 
		{
			p = p->front;
			delete t;
			t = p;//��tָ��ɾ������һ�� ��λ 
		}
		else break;//���û�и�λ0�ͽ��� 
	}
	last = p;//ĩβ���ɾ�����p 
}


void NumList::checkLen()
{
	Node *p = last;
	int cnt = 0;
	for(;p!=head->front;p = p->front)//ָ��pָ��Ĳ������һλ ��������һλ 
	{
		cnt++;
	}
	len = cnt;//�������ĳ��ȸ�ֵ��len 
}


void NumList::insert(int a)
{
	Node *p = head;
	p->front = new Node(a);
	head = p->front;
	head->next = p;
}


void NumList::inputNum(string &s)
{
	head = new Node;
	Node *p = head;
	Node *t = head;
	len = s.length();//������Ϊ�ַ�������
	for(int i=len-1;i>0;i--)
	{
		p->setData(int(s[i]-'0'));//����λ��ֵ 
		p->next = new Node;//�ѵ�λ��������ǰ�� 
		p = p->next;//ָ�������½��ĵ�λ�ڵ� 
		p->front = t;//ԭ��
		t = p;
	}
	p->setData(int(s[0]-'0'));
	last = p; 
}
//�������Ļ 


void NumList::printNum()
{
	Node *p = last;
	if(flag == 1)
		cout<<"-";
	while(p->front!=0)
	{
		cout<<p->getData();
		p = p->front;
	}
	cout<<p->getData()<<endl;
}	 
//�����end.txt�ļ��� 


ofstream out("end.txt");
void NumList::printTxt()
{
	Node *p = last;
	if(flag == 1)
		cout<<"-";
	while(p->front != 0)
	{
		out<<p->getData();
		p = p->front;
	}
	out<<p->getData()<<endl; 
}
//������ת�����ַ��� 


string NumList::listToString()
{
	string s;
	Node *p = last;
	for(;p!=0;p = p->front)
	{
		s+=(p->getData()+'0');
	}
	return s;
}
//�Լ� 
/*NumList NumList::operator ++()
{
	int tmp = 0;
	Node *p = head;
	tmp = p->getData()+1;
	p->setData(tmp%10);
	tmp/=10;
	if(tmp>0)//���ǽ�λ 
	{
		for(p = p->front;p!=0;p = p->front)
		{
			tmp += p->getData();
			p->setData(tmp%10);
			tmp/=10; 
		}
		if(tmp>0)//������λҲ��λ,��λ����1 
		{
			len++;
			last->front = new Node(1);
			p = last;
			last = last->front;
			last->front =p; 
		} 
	}
	return *this;
}*/


NumList NumList::operator +(NumList &list)
{
	int tmp = 0;
	Node *p1 = head; //������ͷ 
	Node *p2 = list.head; //������ͷ 
	if(len>list.len) //����ұ߳� 
	{
		for(;p2!=list.last->next/*��Ϊ���λ��һλ*/;p2 = p2->next) 
		{
			tmp = p1->getData()+p2->getData()+tmp;//��Ӧλ������ټӽ�λʱ���� 
			p1->setData(tmp%10);//������Ķ�Ӧ�ڵ���Ӻ�����Ϊtmp%10 
			p1 = p1->next;//���������λ 
			tmp /= 10; //tmp����ʮλ�� 
		}
		if(tmp>0)//����н�λ 
		{
			for(;p1!=0;p1 = p1->next)
			{
				tmp = p1->getData()+tmp;
				p1->setData(tmp%10);
				tmp /=10; 
			}
			if(tmp>0){ // ������λ��λ�� 
				len++;
				last->next = new Node(1);
				p1 = last;
				last = last->next;
				last->front = p1;
			}
		}
		return *this;
	}
	if(len<list.len)
	{
		for(;p1!=last->next;p1 = p1->next)
		{
			tmp = p1->getData()+p2->getData()+tmp;
			p2->setData(tmp%10);
			p2 = p2->next;
			tmp/=10;
		}
		if(tmp>0)
		{
			for(;p2!=0;p2= p2->next)
			{
				tmp = p2->getData()+tmp;
				p2->setData(tmp%10);
			}
			if(tmp>0)
			{
				len++;
				last->next = new Node(1);
				p1 = last;
				last = last->next;
				last->front = p2;
			}
		}
		return list;
	}
	if(len == list.len)
	{
		for(;p1 != last->next;p1 = p1->next)
	{
		tmp = p1->getData()+p2->getData()+tmp;
		p2->setData(tmp%10);
		p2 = p2->next;
		tmp = tmp/10;
	}
	if(tmp>0)
	{
		Node* t = list.last;
		p2 = new Node;
		p2->front = t;
		list.last = p2;
		p2->setData(p2->getData()+tmp);	
	} 
	return list;
}
}


bool operator >(NumList &list1,NumList &list2)
{
	if(list1.len>list2.len)
		return true;
	else if(list1.len<list2.len)
		return false;
	else 
	{
		Node *p1 = list1.last;
		Node *p2 = list2.last;
		while(p1 != 0)
		{
			if(p1->getData()<p2->getData())
				return false;
			else 
				return true;
			p1 = p1->front;
			p2 = p2->front;
		}
		return false; 
	}
}


bool NumList::compareto(NumList &list)
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
			if(p1->getData() < p2->getData())
				return false;
			if(p1->getData() > p2->getData())
				return true;
			p1=p1->front;
	    	p2=p2->front;
		}
		return true;
    }
}


NumList NumList::operator -(NumList &list)
{
	int tmp = 0;
	Node *p1 = head;
	Node *p2 = list.head;
	if(compareto(list))
	{
		for(;p2 != 0;p2 = p2->next,p1 = p1->next)
		{
			tmp = p1->getData()-p2->getData()+tmp;
			if(tmp<0)
				p1->setData(10-abs(tmp));
			else p1->setData(tmp);
			
			tmp = (tmp<0?-1:0);
		}
		if(tmp == -1)
		{
			int check = 0;
			while(p1->getData() == 0)
			{
				p1 = p1->next;
				check++;
			}
			p1->setData(p1->getData()+tmp);
			if(check>0) p1->front->setData(9);
		} 
		return *this;	
	}
	else
	{
		list.flag = 1;
		for(;p1 != 0;p2 = p2->next,p1 = p1->next)
		{
			tmp = p2->getData()-p1->getData()+tmp;
			if(tmp<0)
				p2->setData(10-abs(tmp));
			else 
				p2->setData(tmp);
			tmp = (tmp<0?-1:0);
		}
		if(tmp == -1)
		{
			int check = 0;
			while(p2->getData() == 0)
			{
				p2 = p2->next;
				check++;
			}
			p2->setData(p2->getData()+tmp);
			if(flag>0) p2->front->setData(9);
		}
		return list;
	}
}


NumList NumList::operator *(NumList &list)
{
	int tmp = 0;
	string s;
	Node *p1 = head;
	Node *p2 = list.head;
	for(int i = 0;i<len+list.len;i++)
	{
		s+="0";
	}
	NumList newlist;
	newlist.inputNum(s);
	Node *p3 = newlist.head;
	Node *t = newlist.head;
	for(;p1 != 0;p1= p1->next)
	{
		p3 = t;
		for(p2 = list.head;p2!= 0;p2 = p2->next)
		{
			p3->setData(p1->getData()*p2->getData()+p3->getData());
			p3 = p3->next; 
		}
		t = t->next;
	}
	p3 = newlist.head;
	for(;p3 != 0;p3 = p3->next)
	{
		tmp = p3->getData()+tmp;
		p3->setData(tmp%10);
		tmp /=10;
	}
	return newlist;
}
NumList NumList::operator /(NumList &list)
{
	if(len>list.len)//���Ӵ����� 
	{
		Node *p = last;
		string marks;
		string result;
		for(int i = 0;i<list.len;i++)
		{
			int a = p->getData(); 
			marks += (a+48);
			p = p->front;
		}
		NumList newlist;char count;
		for(;p != 0;p = p->front)
		{
			count = '0';
			while(!(list>newlist))
			{
				newlist = newlist - list;
				newlist.checkNum();
				newlist.checkLen();
				count++;
			} 
			result += count;
			newlist.insert(p->getData());
			newlist.checkNum();
			newlist.checkLen();
		}
		count = '0';
		while(!(list>newlist))
		{
			newlist = newlist-list;
			newlist.checkNum();
			newlist.checkLen();
			count++;
		}
		result+=count;
		NumList tmp;
		tmp.inputNum(result);
		tmp.checkNum();
		return tmp;
	}
	if (len == list.len)
	{
		string s = listToString();
		NumList tmp;
		tmp.inputNum(s);
		char count = '0';
		while (tmp.compareto(list))
		{
			tmp = tmp - list;
			count++;
		} 
		string news;
		news += count;
		NumList newTmp;
		newTmp.inputNum(news);
		return newTmp;
	}
	if (len < list.len)
	{
		string s = "0";
		NumList tmp;
		tmp.inputNum(s);
		return tmp;
	}
}
string NumList::mi(NumList &list)
{
	return "";
}


