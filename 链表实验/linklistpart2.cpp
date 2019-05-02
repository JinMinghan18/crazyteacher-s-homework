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
		cout<<"输入想要执行的功能\n";
	    printf("1--建立新的链表\n");
	    printf("2--添加元素\n");
	    printf("3--删除元素\n");
	    printf("4--输出当前表中的元素\n");
	    printf("0--退出\n");
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
				cout<<"请输入插入的学生学号与成绩\n";
				stu = new student;
				cin>>stu->num>>stu->score;
				insertstu(head,stu);
				break;
			case 3:
				cout<<"请输入要删除的学生学号\n";
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

