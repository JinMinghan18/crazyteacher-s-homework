#include "ArrayList.h"
#include <cassert>
using namespace std;

ArrayList::ArrayList(int maxSize)//构造
{
    myCapacity=maxSize;
	mySize=0;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
}

ArrayList::~ArrayList()//析构
{
	delete []myArray; 
}

ArrayList::ArrayList(const ArrayList& origList)//拷贝构造
{
    myCapacity=origList.myCapacity;
	myArray=new ElementType[myCapacity];
	assert(myArray!=0);
	mySize=origList.mySize;
	for(int i=0;i<mySize;i++) myArray[i]=origList.myArray[i];
}


ArrayList& ArrayList::operator=(const ArrayList& right)//赋值重载
{ 
	myCapacity=right.myCapacity;
	myArray=new ElementType[myCapacity];
	mySize=right.mySize;
	for(int i=0;i<mySize;i++) myArray[i]=right.myArray[i];
}


bool ArrayList::empty() const //判空
{
   return mySize==0;
}


void ArrayList::insert(ElementType item,int pos)//插入
{ 
	mySize++;
	for(int i = mySize;i>pos;i--)
	{
		myArray[i] = myArray[i-1];  
	}
	myArray[pos] = item;
}

void ArrayList::erase(int pos)//删除
{
	for(int i=pos;i<mySize;i++)
	{
		myArray[i] = myArray[i+1];
	}
	mySize--;
}


void ArrayList::display(ostream& out) const//遍历输出
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


ostream& operator<<(ostream& out,const ArrayList& aList)//输出流重载
{
	for(int i=0;i<aList.mySize;i++)
	out<<i<<":"<<aList.myArray[i]<<endl;

}
