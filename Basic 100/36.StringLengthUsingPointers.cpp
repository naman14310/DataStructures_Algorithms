#include <iostream>
#include <string>
using namespace std;

int strlen(char* s)
{
	int count=0;
	while(*s++) count++;
	return count;
}

int main()
{   char s[500];
	cout<<"Enter string : ";
	gets(s);
	int len = strlen(s);
	cout<<endl<<endl<<"Length of string is : "<<len;
	
}
