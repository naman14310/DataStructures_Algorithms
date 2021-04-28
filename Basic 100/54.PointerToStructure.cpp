#include<iostream>
using namespace std;

struct pointer
{
	char name[20];
	int a;
}p1;

int main()
{
	struct pointer* p2 = &p1; 
	struct pointer** p3 = &p2;

	cout<<"Enter name : ";
	cin>>p1.name;
	cout<<"Enter age : ";
	cin>>p1.a;
	
	cout<<endl<<p1.name;
	cout<<endl<<p2->name;
	cout<<endl<<p2->a;
	cout<<endl<<p3;
	cout<<endl<<(*p3)->name;
	
}
