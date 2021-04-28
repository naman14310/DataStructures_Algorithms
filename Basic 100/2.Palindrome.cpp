#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
    string s1;
    int i=0, len=0, temp=0, flag=0;
    cout<<"Enter string : ";
    cin>>s1;
    
    while(s1[temp]!='\0')
    {
    	len++;
    	temp++;
    }
    
    while(i<len/2)
    {
    	if(s1[i]!=s1[len-i-1])
    	{
    		flag=1;
    		break;
		}
		i++;
	}
	
	if(flag==0)
	cout<<"The string is palindrome";
	else
	cout<<"The string  is not a palindrome";
	
return 0;
} 
