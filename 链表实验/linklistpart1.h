#include <iostream>
#include <stdio.h>
using namespace std;
struct student 
{
	int num;
	int score;
	struct student* next;
};
student* insertstu(student *,student* );		//����һ���ڵ� 
student* del(student* ,int );		//ɾ��ѧ��Ϊnum��ѧ����� 
student *create();			//�������� 
void print(student *);
int main();
