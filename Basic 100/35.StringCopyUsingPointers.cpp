#include <iostream>
#include <string>
using namespace std;

void strcpy(char* s, char* t)
{
	
	while(*t++=*s++);
}

int main()
{   char s[500], t[500];
	cout<<"Enter string : ";
	gets(s);
	strcpy(s,t);
	cout<<endl<<endl<<"Target string is : "<<t;
	
}
