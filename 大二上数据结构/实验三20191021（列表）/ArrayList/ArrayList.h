#include <iostream>
using namespace std;
#ifndef ARRAYLIST
#define ARRAYLIST

typedef int ElementType;

class ArrayList{
public:
	ArrayList(int maxSize=1024);//����
    ~ArrayList();//����
	ArrayList(const ArrayList& origList);//��������
	ArrayList& operator=(const ArrayList& right);//��ֵ����

	bool empty() const; //�п�
    void insert(ElementType item,int pos);//����
	void erase(int pos);//ɾ��
	void display(ostream& out) const;//�������

    int find(ElementType item);//����item���ڵ�λ��,�����ڷ���-1
	friend ostream& operator<<(ostream& out,const ArrayList& aList);//���������
private:
	int mySize;
	int myCapacity;
	ElementType *myArray;
};


#endif
