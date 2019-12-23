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
	Node* head;    //ָ��ڵ��Ͷ
	Node* last;    //ָ��ڵ��β
	int len;       //����ĳ���
	int mark;      //������ǣ�0����1��
public:
	Numberlist(){head=NULL;last=NULL;len=0;mark=0;}
	Numberlist(int a){head=new Node(a);last=head;len=1;mark=0;}
	void checkNumber();//����λû���õ�0ɾ��
	void checkLen();//���len��ֵ���ȽϺ�����Ҫ�漰��len
	void inputNumber(string& s);//���ִ����뵽������,����˫������
	void printNumber();//����ִ�
	void printTxt();
	string toString();//����String 
	int getmark();//�õ�����������
	void insert(int a);//�����λ��head���������
	Numberlist operator +(Numberlist& list);//����+����
	Numberlist operator -(Numberlist& list);//����-����
    Numberlist operator *(Numberlist& list);//����*����
	Numberlist operator /(Numberlist& list);//����/����
	Numberlist operator ++();//�����ԼӲ���
	bool compare(Numberlist& list);//�Ƚ��������Ĵ�С
	friend bool operator >(Numberlist& list1,Numberlist& list2);//��>�Ĳ���������
	string mi(Numberlist &list);//����ָ������
};

