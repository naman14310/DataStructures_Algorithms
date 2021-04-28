#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char str[100];
	cout<<"Enter a String : ";
	gets(str);
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]<97)
		{
		   str[i]+=32;
		   cout<<str[i];
		}
		else
		{
			str[i]-=32;
			cout<<str[i];
		}
		i++;
	}
	
    return 0;
}
