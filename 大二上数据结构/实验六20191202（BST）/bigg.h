#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
	private:
		long long data;
		
	public:
		//三个函数接口返回节点的data/front/next 
		Node *next;//指向后面连接的节点 
		Node *front;//指向前一个节点 
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
		Node(int a){data = a;next = 0;front = 0;}//设定数据; 
};
//十进制运算的类 
class NumList
{
	private:
		int len;//链表长度
		int flag;//记录正负信息 0为正 1为负 
		Node *head;//最低位，链表最前 
		Node *last; 
	public:
		int getflag(){
			return flag;
		}
		NumList(){head = 0;last = 0;len = 0;flag = 0;}
		NumList(int a){head = new Node(a);last = head;len = 1;flag = 0;}
		void checkNum();//删除高位的0√ 
		void checkLen();//确定链表的长度用于比较√
		void printNum();//√ 
		void inputNum(string &s);//将输入的字符转存到链表里√
		void printTxt();// √ 
		string listToString();//链表转为字符串√
		void insert(int a);//在最低位加数字√
		//运算符的重载 
		NumList operator +(NumList &list);
		NumList operator -(NumList &list);
		NumList operator *(NumList &list);
		NumList operator /(NumList &list);
		NumList operator ++();
		bool compareto(NumList &list);//俩链表大小比较
		friend bool operator >(NumList &left,NumList &right);
		string mi(NumList &list); 
};

