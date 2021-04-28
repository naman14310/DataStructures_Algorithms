#include<iostream>
#include<string.h>
using namespace std;

struct emp1
{
	char name[20];
	int age;
	
}s1, s2;

int compare(struct emp1 s1, struct emp1 s2)
{
	if(strcmp(s1.name,s2.name)!=0 || s1.age!=s2.age) return 0;
	else return 1;
}

int main()
{
	cout<<endl<<"Enter s1.name : ";
	cin>>s1.name;
	cout<<"Enter s1.age : ";
	cin>>s1.age;
	
	cout<<endl<<"Enter s2.name : ";
	cin>>s2.name;
	cout<<"Enter s2.age : ";
	cin>>s2.age;
	
	int cmp = compare(s1, s2);
	if(cmp==0) cout<<endl<<"Both are different";
	else cout<<endl<<"Both are same";
}

