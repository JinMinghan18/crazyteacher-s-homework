#include<iostream> 
using namespace std;
struct student 
{
	int num;
	int score;
	struct student* next;
};

/*插入一个节点，按照学号排列*/
student* insertstu(student *head,student* stud) 	//插入一个节点 
{
	int n=0;
	student *p0,*p1,*p2;
	p1 = head;	p0 =stud;
	if(head == NULL)		//如果链表为空，插入的p0就是head结点 
		head = p0, p0->next = NULL;
	else 					//一般情况 
	{
		while((p0->num>p1->num) && (p1->next != NULL)) 
			p2 = p1 , p1 = p1->next;
		if(p0->num<= p1->num)
		{
			if(p1 == head)
			{
				p0->next = head;
				head = p0; 
			}
			else 
			{
				p2->next = p0;
				p0->next = p1; 
			}
		}
		else 
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n +=1;
	return (head);
}

/*删除学号为num的学生的结点*/
student* del(student* head,int num)		//删除学号为num的学生结点 
{
	int n=0;
	student* p1,*p2;
	if(head == NULL)
		{head == NULL;cout<<"linklist if NUll"<<endl;return NULL;} 
	else
	{
		p1 = head ;
		while(p1->num!=num && p1->next!= NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if(p1->num == num)
		{
			int temp = head->num;
			if(num == temp)
			{
				head = head->next;
			}
			else
			{
				p2->next = p1->next;
			}
		}
		else cout<<"Not found\n";
		return head;
	}
}
/* 建立链表，先给头文件一个空地址，
指针p1,p2分配空间，输入首个学生地址
接着按照输入的链表长度n依次输入个个
节点，n == 1时头指针指向p1，p2指向
p1新引入的地址，结束的时候p2->next指向空*/

student *create()			//创建链表 
{
	student *head,*p1,*p2;
	int n = 0;
	head = NULL;
	p1 = p2 = new student ;
	cout<<"输入第1个学生学号和成绩:";
	cin>>p1->num>>p1->score;//输入头结点 
	cout<<"\n";
	while(p1->num!=0) 
	{
		n+=1;
		if(n == 1)	head = p1; 
		else p2->next = p1;
		p2 = p1;
		p1 = new student;
		cout<<"输入第"<<n+1<<"个学生学号和成绩:" ;
		cin>>p1->num>>p1->score;
		cout<<"\n";
	}
	p2->next = NULL;
	return(head);
}

/*输出该链表*/
void print(student *head)
{
	cout<<"该链表为"<<endl; 
	student* p;
	p = head;
	if(head != NULL)
	{
		do
		{
			printf("%d,%d",p->num,p->score);
			p = p->next;
			printf("\n");
		}while(p != NULL);
	}	 
}

