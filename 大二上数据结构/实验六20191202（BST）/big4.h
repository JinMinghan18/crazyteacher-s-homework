#include<string>
#include<iostream>
#include<fstream>
using std::string;

struct Node{
   int data;
   Node* next;
   Node* front;
   Node(){data=0;front=NULL;next=NULL;}
   Node(int a){data=a;front=NULL;next=NULL;}
};

class Numberlist{
private:
	Node* head;    //指向节点的投
	Node* last;    //指向节点的尾
	int len;       //链表的长度
	int mark;      //正负标记，0正，1负
public:
	Numberlist(){head=NULL;last=NULL;len=0;mark=0;}
	Numberlist(int a){head=new Node(a);last=head;len=1;mark=0;}
	void checkNumber();//将高位没有用的0删除
	void checkLen();//检查len的值，比较函数需要涉及到len
	void inputNumber(string& s);//将字串输入到链表中,建立双向链表
	void printNumber();//输出字串
	void printTxt();
	string toString();//返回String 
	int getmark();//得到整数的正负
	void insert(int a);//在最低位（head）添加数字
	Numberlist operator +(Numberlist& list);//进行+操作
	Numberlist operator -(Numberlist& list);//进行-操作
    Numberlist operator *(Numberlist& list);//进行*操作
	Numberlist operator /(Numberlist& list);//进行/操作
	Numberlist operator ++();//进行自加操作
	bool compare(Numberlist& list);//比较两个数的大小
	friend bool operator >(Numberlist& list1,Numberlist& list2);//对>的操作符重载
	string mi(Numberlist &list);//进行指数操作
};

