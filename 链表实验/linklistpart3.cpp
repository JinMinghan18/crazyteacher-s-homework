#include<iostream> 
using namespace std;
struct student 
{
	int num;
	int score;
	struct student* next;
};

/*����һ���ڵ㣬����ѧ������*/
student* insertstu(student *head,student* stud) 	//����һ���ڵ� 
{
	int n=0;
	student *p0,*p1,*p2;
	p1 = head;	p0 =stud;
	if(head == NULL)		//�������Ϊ�գ������p0����head��� 
		head = p0, p0->next = NULL;
	else 					//һ����� 
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

/*ɾ��ѧ��Ϊnum��ѧ���Ľ��*/
student* del(student* head,int num)		//ɾ��ѧ��Ϊnum��ѧ����� 
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
/* ���������ȸ�ͷ�ļ�һ���յ�ַ��
ָ��p1,p2����ռ䣬�����׸�ѧ����ַ
���Ű��������������n�����������
�ڵ㣬n == 1ʱͷָ��ָ��p1��p2ָ��
p1������ĵ�ַ��������ʱ��p2->nextָ���*/

student *create()			//�������� 
{
	student *head,*p1,*p2;
	int n = 0;
	head = NULL;
	p1 = p2 = new student ;
	cout<<"�����1��ѧ��ѧ�źͳɼ�:";
	cin>>p1->num>>p1->score;//����ͷ��� 
	cout<<"\n";
	while(p1->num!=0) 
	{
		n+=1;
		if(n == 1)	head = p1; 
		else p2->next = p1;
		p2 = p1;
		p1 = new student;
		cout<<"�����"<<n+1<<"��ѧ��ѧ�źͳɼ�:" ;
		cin>>p1->num>>p1->score;
		cout<<"\n";
	}
	p2->next = NULL;
	return(head);
}

/*���������*/
void print(student *head)
{
	cout<<"������Ϊ"<<endl; 
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

