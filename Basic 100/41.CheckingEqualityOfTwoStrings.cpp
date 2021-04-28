#include <iostream>
using namespace std;

int strlen(char s[])
{
	int c=0;
	int i=0;
	while(s[i]!='\0')
	{
		c++;
		i++;
	}
	return c;
}

int main()
{
	char s1[10], s2[10];
	cout<<"Enter string 1 : ";
	gets(s1);
	cout<<"Enter string 2 : ";
	gets(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 != len2) cout<<"Strings are not equal";
	else
	{
		int flag=0;
	    for(int i=0;i<len1;i++)
	    {
	    	if(s1[i]!=s2[i])
	    	{
	    		flag=1;
	    		break;
			}
		}
		
		if(flag==1) cout<<"Strings are not equal";
		else cout<<"Strings are equal";
		
    }
}
