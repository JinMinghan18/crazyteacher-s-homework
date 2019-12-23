#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
	private:
		long long data;
		
	public:
		//���������ӿڷ��ؽڵ��data/front/next 
		Node *next;//ָ��������ӵĽڵ� 
		Node *front;//ָ��ǰһ���ڵ� 
		void setData(int a)
		{
			data  = a;
		} 
		int getData()
		{
			return data;
		}
//		Node getFront();
//		Node getnext();
		Node(){data = 0;next = 0;front = 0;}
		Node(int a){data = a;next = 0;front = 0;}//�趨����; 
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
		NumList(){head = 0;last = 0;len = 0;flag = 0;}
		NumList(int a){head = new Node(a);last = head;len = 1;flag = 0;}
		void checkNum();//ɾ����λ��0�� 
		void checkLen();//ȷ������ĳ������ڱȽϡ�
		void printNum();//�� 
		void inputNum(string &s);//��������ַ�ת�浽�������
		void printTxt();// �� 
		string listToString();//����תΪ�ַ�����
		void insert(int a);//�����λ�����֡�
		//����������� 
		NumList operator +(NumList &list);
		NumList operator -(NumList &list);
		NumList operator *(NumList &list);
		NumList operator /(NumList &list);
		NumList operator ++();
		bool compareto(NumList &list);//�������С�Ƚ�
		friend bool operator >(NumList &left,NumList &right);
		string mi(NumList &list); 
};

