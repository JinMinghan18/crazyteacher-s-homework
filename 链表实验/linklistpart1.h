#include <iostream>
#include <stdio.h>
using namespace std;
struct student 
{
	int num;
	int score;
	struct student* next;
};
student* insertstu(student *,student* );		//插入一个节点 
student* del(student* ,int );		//删除学号为num的学生结点 
student *create();			//创建链表 
void print(student *);
int main();
