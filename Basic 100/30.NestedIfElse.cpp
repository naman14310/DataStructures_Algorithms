#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int grade;
	cout<<"Enter grade : ";
	cin>>grade;
	if(grade>60)
	{
		cout<<"First";
	}
	else if(grade>50)
	{
		cout<<"Second";
	}
	else if(grade>40)
	{
		cout<<"Third";
	}
	else
	{
		cout<<"Failed !";
	}
    return 0;
}
