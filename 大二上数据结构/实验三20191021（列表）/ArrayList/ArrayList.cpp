#include "ArrayList.h"
#include <cassert>
using namespace std;

ArrayList::ArrayList(int maxSize)//����
{
    myCapacity=maxSize;
	mySize=0;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
}

ArrayList::~ArrayList()//����
{
	delete []myArray; 
}

ArrayList::ArrayList(const ArrayList& origList)//��������
{
    myCapacity=origList.myCapacity;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
	mySize=origList.mySize;
	for(int i=0;i<mySize;i++) myArray[i]=origList.myArray[i];
}


ArrayList& ArrayList::operator=(const ArrayList& right)//��ֵ����
{ 
	myCapacity=right.myCapacity;
	myArray=new ElementType[myCapacity];
	mySize=right.mySize;
	for(int i=0;i<mySize;i++) myArray[i]=right.myArray[i];
}


bool ArrayList::empty() const //�п�
{
   return mySize==0;
}


void ArrayList::insert(ElementType item,int pos)//����
{ 
	mySize++;
	for(int i = mySize;i>pos;i--)
	{
		myArray[i] = myArray[i-1];  
	}
	myArray[pos] = item;
}

void ArrayList::erase(int pos)//ɾ��
{
	for(int i=pos;i<mySize;i++)
	{
		myArray[i] = myArray[i+1];
	}
	mySize--;
}


void ArrayList::display(ostream& out) const//�������
{
	for(int i=0;i<mySize;i++)
		out<<i<<":"<<myArray[i]<<endl;
}

int ArrayList::find(ElementType item)
{
	for(int i = 0;i<mySize;i++)
	{
		if(myArray[i] == item)
		{
			return i;
		}
	}
	return -1;
}


ostream& operator<<(ostream& out,const ArrayList& aList)//���������
{
	for(int i=0;i<aList.mySize;i++)
	out<<i<<":"<<aList.myArray[i]<<endl;

}
