#include <iostream>
#include <cstring>
#include <fstream>
#include"tryh.h" 
using namespace std;

void NumList::checkNum()
{
	Node *p = last; 
	Node *t = p;
	for( ; p!=head;)//从高位开始 
	{
		if(p->data == 0)//为0就删除 
		{
			p = p->front;
			delete t;
			t = p;//把t指向删除后下一个 高位 
		}
		else break;//如果没有高位0就结束 
	}
	last = p;//末尾设成删除后的p 
}

void NumList::checkLen()
{
	Node *p = last;
	int cnt = 0;
	for(;p!=head->front;p = p->front)//指针p指向的不是最后一位 就向下走一位 
	{
		cnt++;
	}
	len = cnt;//数出来的长度赋值给len 
}

void NumList::insert(int a)
{
	if (head == 0)
	{
		head = new Node(a);
		last = head;
		len++;
	}
	else
	{
		Node *p = head;
		p->front = new Node(a, p, 0);
		len++;
		head = p->front;
	}
}

void NumList::insertnum(int a)
{
	if (head == 0)
	{
		head = new Node(a);
		len++;
		last = head;
	}
	else
	{
		Node *pa = last;
		pa->next = new Node(a, 0, pa);
		len++;
		last = pa->next;
	}
}

void NumList::inputNum(string &s)
{
	head = new Node;
	Node *p = head;
	Node *t = head;
	len = s.length();//链表长度为字符串长度
	for(int i=len-1;i>0;i--)
	{
		p->data = int(s[i]-'0');//给高位赋值 
		p->next = new Node;//把低位放在链表前面 
		p = p->next;//指针移向新建的低位节点 
		p->front = t;//原来
		t = p;
	}
	p->data = int(s[0]-'0');
	last = p; 
}
//输出到屏幕 

void NumList::printNum()
{
	Node *p = last;
	if(flag == 1)
		cout<<"-";
	while(p->front!=0)
	{
		cout << p->data;
		p = p->front;
	}
	cout<<p->data<<endl;
}	 
//输出到end.txt文件中 

ofstream out("end.txt");
void NumList::printTxt()
{
	Node *p = last;
	if(flag == 1)
		cout<<"-";
	while(p->front != 0)
	{
		out<<p->data;
		p = p->front;
	}
	out<<p->data<<endl;
}
//将链表转换成字符串 

string NumList::listToString()
{
	string s;
	Node *p = last;
	for(;p!=0;p = p->front)
	{
		s+=(p->data +'0');
	}
	return s;
}
//自加 
NumList NumList::operator ++()
{
	int tmp = 0;
	Node *p = head;
	tmp = p->data+1;
	p->data = tmp%10;
	tmp/=10;
	if(tmp>0)//考虑进位 
	{
		for(p = p->front;p!=0;p = p->front)
		{
			tmp += p->data;
			p->data=tmp%10;
			tmp/=10; 
		}
		if(tmp>0)//如果最高位也进位,则位数加1 
		{
			len++;
			last->front = new Node(1);
			p = last;
			last = last->front;
			last->front =p; 
		} 
	}
	return *this;
}

NumList NumList::operator +(const NumList &list)
{
	NumList Sum;
	int tmp = 0;
	Node *p1 = head; //左链表头 
	Node *p2 = list.head; //右链表头 
	if (len > list.len)
	{
		Node *p1 = head;
		Node *p2 = list.head;
		int t = 0;
		while (p2 != NULL)
		{
			int tmp;
			if (t == 0)
			{
				tmp = p1->data + p2->data;
			}
			else
			{
				tmp = p1->data + p2->data + t;
			}
			t = tmp / 10;
			tmp = tmp % 10;
			Sum.insertnum(tmp);
			if (t != 0 && len == list.len &&p2->next == NULL)
			{
				Sum.insertnum(1);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != NULL)
		{
			if(t!= 0)
			{
				int tmp = p1->data + t;
				t = tmp / 10;
				tmp %= 100;
				Sum.insertnum(tmp);
				if (t != 0 && p1->next == NULL)
				{
					Sum.insertnum(1);
				}
			}
			else
			{
				Sum.insertnum(p1->data);
			}
			p1 = p1->next;
		}
		return Sum;
	}
	else 
	{
		Node* p1 = head;
		Node* p2 = list.head;
		int t = 0;
		while (p1 != 0)
		{
			int temp;
			if (t == 0)
			{
				temp = p1->data + p2->data;
			}
			else
			{
				temp = p1->data + p2->data + t;
			}
			t = temp / 10;
			temp = temp % 10;
			Sum.insertnum(temp);
			p1 = p1->next;
			p2 = p2->next;
		}
		while (p2 != 0)
		{
			if (t != 0)
			{
				int temp = p2->data + t;
				t = temp / 10;
				temp = temp % 10;
				Sum.insertnum(temp);
				if (t != 0 && p2->next == 0)
				{
					Sum.insertnum(1);
				}
			}
			else
			{
				Sum.insertnum(p2->data);
				Sum.len++;
			}
			p2 = p2->next;
		}
		return Sum;
	}
	//if(len>list.len) //左比右边长 
	//{
	//	for(;p2!=list.last->next/*不为最高位下一位*/;p2 = p2->next) 
	//	{
	//		tmp = p1->data +p2->data +tmp;//对应位置相加再加进位时的数 
	//		p1->data = tmp%10;//左链表的对应节点相加后设置为tmp%10 
	//		p1 = p1->next;//移向向更高位 
	//		tmp /= 10; //tmp保留十位数 
	//	}
	//	if(tmp>0)//如果有进位 
	//	{
	//		for(;p1!=0;p1 = p1->next)
	//		{
	//			tmp = p1->data +tmp;
	//			p1->data=tmp%10;
	//			tmp /=10; 
	//		}
	//		if(tmp>0){ // 如果最高位进位了 
	//			len++;
	//			last->next = new Node(1);
	//			p1 = last;
	//			last = last->next;
	//			last->front = p1;
	//		}
	//	}
	//	return *this;
	//}
	//if(len<list.len)
	//{
	//	for(;p1!=last->next;p1 = p1->next)
	//	{
	//		tmp = p1->data +p2->data +tmp;
	//		p2-> data =  tmp%10;
	//		p2 = p2->next;
	//		tmp/=10;
	//	}
	//	if(tmp>0)
	//	{
	//		for(;p2!=0;p2= p2->next)
	//		{
	//			tmp = p2->data+tmp;
	//			p2->data = tmp%10;
	//		}
	//		if(tmp>0)
	//		{
	//			len++;
	//			last->next = new Node(1);
	//			p1 = last;
	//			last = last->next;
	//			last->front = p2;
	//		}
	//	}
	//	return list;
	//}
	//if (len == list.len)
	//{
	//	for (; p1 != last->next; p1 = p1->next)
	//	{
	//		tmp = p1->data + p2->data + tmp;
	//		p2->data = tmp % 10;
	//		p2 = p2->next;
	//		tmp = tmp / 10;
	//	}
	//	if (tmp > 0)
	//	{
	//		Node* t = list.last;
	//		p2 = new Node;
	//		p2->front = t;
	//		list.last = p2;
	//		p2->data = p2->data + tmp;
	//	}
	//	return list;
	//}
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
			if(p1->data <p2->data)
				return false;
			else 
				return true;
			p1 = p1->front;
			p2 = p2->front;
		}
		return false; 
	}
}

bool NumList::compareto( NumList &list)
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
			if(p1->data < p2-> data)
				return false;
			if(p1->data > p2->data)
				return true;
			p1=p1->front;
	    	p2=p2->front;
		}
		return true;
    }
}

NumList NumList::operator -(const NumList &list)
{
	NumList Res;
	Node *p1 = head;
	Node *p2 = list.head;
	int tmp = 0;
	while (p2 != 0)
	{
		if (p1->data < p2->data)
		{
			int temp = p1->data + 10 - tmp - p2->data;
			tmp = 1;
			Res.insertnum(temp);
		}
		else if (p1->data == p2->data && tmp == 1)
		{
			tmp = 1;
			Res.insertnum(9);
		}
		else
		{
			int temp2 = p1->data - p2->data - tmp;
			tmp = 0;
			Res.insertnum(temp2);
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1 != 0)
	{
		if (p1->data < tmp)
		{
			Res.insertnum(9);
			tmp = 1;
		}
		else
		{
			if (p1->data - tmp == 0 && p1->next == 0)
			{
				break;
			}
			Res.insertnum(p1->data - tmp);
			tmp = 0;
		}
		p1 = p1->next;
	}
	while (Res.last->data == 0 && len > 1)
	{
		Res.last = Res.last->front;
		Res.last->next = 0;
		Res.len--;
		if (Res.last == Res.head) break;
	}
	return Res;
	
	
}

NumList NumList::operator *(const NumList &list)
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
			p3->data = p1->data*p2->data + p3->data;
			p3 = p3->next; 
		}
		t = t->next;
	}
	p3 = newlist.head;
	for(;p3 != 0;p3 = p3->next)
	{
		tmp = p3->data + tmp;
		p3->data = tmp%10;
		tmp /=10;
	}
	newlist.checkNum();
	return newlist;
}

bool NumList::operator<(const NumList &list)//(ok)
{
	Node *pa = last;
	Node *pb = list.last;
	if (len > list.len)  return false;
	else if (len < list.len) return true;
	else
	{
		while (pa != 0)
		{
			if (pa->data > pb->data) return false;
			else if (pa->data < pb->data) return true;
			pa = pa->front;
			pb = pb->front;
		}
		return false;
	}
}


NumList NumList::operator /(const NumList &list)//(ok)
{
	NumList temp1, temp2;
	temp1.insertnum(1);
	const NumList one = temp1;
	temp2 = list;
	NumList result;
	if (temp2 < one)
	{
		cout << "分母为0时除法无意义，该处返回0代替。" << endl;
		result.insertnum(0);
		return result;
	}
	if (len < list.len)
	{
		result.insertnum(0);
		return result;
	}
	else
	{
		NumList end;
		end.insertnum(0);
		NumList myself = *this;
		while (1)
		{
			NumList r = list;
			NumList temp;
			if (myself < r) break;
			int i;
			for (i = 0; i < myself.len - list.len; i++) r.insert(0);
			if (myself < r)
			{
				r = list;
				for (i = 0; i < myself.len - list.len - 1; i++)
					r.insert(0);
			}
			int s = 0;
			while (1)
			{
				if (myself < r) break;
				myself = myself - r;
				s++;
			}
			for (int j = 0; j < i; j++)
				temp.insertnum(0);
			temp.insertnum(s);
			end = end + temp;
		}
		return end;
	}
	/*
	if (len > list.len)
	{	
		Node *pa;
		pa = last;
		string marks;
		string result;
		for(int i = 0;i<list.len;i++)
		{
			marks += pa->data +48;
			pa = pa->front;
		}
		NumList newlist = NULL;
		char count;
		newlist.inputNum(marks);
		for(;pa != 0;pa = pa->front)
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
			newlist.insert(pa->data);
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
		NumList tmp = NULL;
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
	}*/
}

string NumList::mi(NumList &list)
{
	NumList tmp, marklist, tmp1;
	string s = this->listToString();
	tmp.inputNum(s);
	string s1 = "1";
	tmp1.inputNum(s1);
	string s2 = list.listToString();
	marklist.inputNum(s1);
	while (list.compareto(marklist)) 
	{
		tmp1 = tmp1 * tmp;
		++marklist;
	}
	tmp1.checkNum();
	string s3 = tmp1.listToString();
	return s3;
}

NumList NumList::operator %(const NumList &list)
{
	NumList result = *this;
	NumList temp, temp1;
	temp1 = list;
	temp = result / temp1;
	NumList temp2;
	temp2 = temp * temp1;
	result = result - temp2;
	return result;
}
