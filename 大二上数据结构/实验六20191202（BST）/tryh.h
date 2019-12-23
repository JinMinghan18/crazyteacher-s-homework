#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
	
	public:
		//���������ӿڷ��ؽڵ��data/front/next 
		Node *next = NULL;//ָ��������ӵĽڵ� 
		Node *front = NULL;//ָ��ǰһ���ڵ� 
		long long data;
		Node(){data = 0;next = 0;front = 0;}
		Node(int a,Node *n = 0,Node *f =0):data(a),next(n),front(f){}
};
//ʮ����������� 
class NumList
{
	private:
		int len;//������
		int flag;//��¼������Ϣ 0Ϊ�� 1Ϊ�� 
		Node *head;//���λ��������ǰ 
		Node *last;
	public:
		
		int getflag(){
			return flag;
		}
		const void setflag(int a) {
			flag = a;
		}
		NumList(){head = 0;last = 0;len = 0;flag = 0;}
		NumList(int a){head = new Node(a);last = head;len = 1;flag = 0;}
		void checkNum();//ɾ����λ��0�� 
		void checkLen();//ȷ������ĳ������ڱȽϡ�
		void printNum();//�� 
		void inputNum(string &s);//��������ַ�ת�浽�������
		void printTxt();// �� 
		string listToString();//����תΪ�ַ�����
		void insert(int a);//�����λ�����֡�
		void insertnum(int a);//�����λ������
		//����������� 
		bool operator <(const NumList &list);
		//bool operator >(const NumList &list);
		NumList operator +(const NumList &list);
		NumList operator -(const NumList &list);
		NumList operator *(const NumList &list);
		NumList operator /(const NumList &list);
		NumList operator %(const NumList &list);
		NumList operator ++();
		bool compareto(NumList &list);//�������С�Ƚ�
		friend bool operator >(NumList &left,NumList &right);
		string mi(NumList &list); 
};

