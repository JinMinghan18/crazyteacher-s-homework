#include <iostream>
using namespace std;
struct student 
{
	int num;
	int score;
	struct student* next;
};

int main()
{
	int n;
	student *insertstu(student*,student*);
	student* del(student* ,int );
	student *create();
	void print(student *head);
	student* head,*stu;
	int i=1,score,num;
	while(i)
	{
		cout<<"������Ҫִ�еĹ���\n";
	    printf("1--�����µ�����\n");
	    printf("2--���Ԫ��\n");
	    printf("3--ɾ��Ԫ��\n");
	    printf("4--�����ǰ���е�Ԫ��\n");
	    printf("0--�˳�\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:
				return 0;
				break;
			case 1:
				head =  create();
				break;
			case 2:
				cout<<"����������ѧ��ѧ����ɼ�\n";
				stu = new student;
				cin>>stu->num>>stu->score;
				insertstu(head,stu);
				break;
			case 3:
				cout<<"������Ҫɾ����ѧ��ѧ��\n";
				cin>>num;
				head = del(head,num);
				break;
			case 4:
				print(head);
				break;
			default:
				printf("ERROR\n");
		}
	}
}

