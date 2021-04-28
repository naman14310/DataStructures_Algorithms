#include<iostream>
#include<stdlib.h>
using namespace std;

struct student
{
	char name[20];
	int marks;
}s1, s2;

void strCopy(char* s1, char* s2)
{
	while(*s2++=*s1++);
}

void copy(struct student* s1, struct student* s2)
{
	strCopy(s1->name, s2->name);
	s2->marks=s1->marks;
}

int main()
{
	cout<<endl<<"Enter s1.name : ";
	cin>>s1.name;
	cout<<"Enter s1.marks : ";
	cin>>s1.marks;
	
	copy(&s1,&s2);
	
    cout<<endl<<endl<<"s2.name : "<<s2.name;
	cout<<endl<<"s2.marks : "<<s2.marks;
}
