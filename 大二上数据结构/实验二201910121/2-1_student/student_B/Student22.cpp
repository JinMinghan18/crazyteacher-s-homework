#include "student2.h"
#include <iostream>
using namespace std;
Student::Student(){
	name = new char[20];
	name[0] = '\0';
}
Student::Student(const char* n)
{
//	cout<<n<<endl;
	name = new char[20];
	int i;
	for(i=0;n[i] !='\0';i++){
		name[i] = n[i];
	}
	name[i] = '\0';
//	cout<<name<<endl;
}
Student::Student(const Student &o){
	int i;
	name = new char[20];
	for( i=0;o.name[i] != '\0';i++)
		name[i] = o.name[i];
	name[i] = '\0';
}

void Student::ChangeName(const char *n)
{
    int i;
    for(i=0;n[i]!='\0';i++)
	name[i]=n[i];
    name[i]='\0';
}

char* Student::GetName()
{
	return name;
}
void Student::operator=(const Student& o)
{
	int i;
        for( i=0;o.name[i]!='\0';i++)
		name[i]=o.name[i];
	name[i]='\0';
}
Student::~Student()
{
	delete []name;
}
