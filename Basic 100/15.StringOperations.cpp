#include <iostream>
#include <string.h>
using namespace std;

int len(string s)
{
	int length=0, temp=0;
	while(s[temp]!='\0')
    {
    	length++;
    	temp++;
	}
	return length;
}

void insert_substring()
{
	string text, substring;
	int pos;      
	cout<<"Enter text : ";
	getline(cin,text);
	cout<<"Enter substring : ";
	getline(cin,substring);
	cout<<"Enter position : ";
	cin>>pos;
	pos--;
	
	int len_t = len(text);
	int len_s = len(substring);
	int tl = len_t+len_s;
	
	char fs[tl];
	
	for(int i=0;i<pos;i++)
	{
		fs[i]=text[i];
	}
	for(int i=pos;i<pos+len_s;i++)
	{
		fs[i]=substring[i-pos];
	}
	for(int i=pos+len_s;i<tl;i++)
	{
		fs[i]=text[i-len_s];
	}
	
	for(int i=0;i<tl;i++)
	{
		cout<<fs[i];
	}
	
}

void delete_substring()
{
	string text;
	int pos,n;
	        
	cout<<"Enter text : ";
	getline(cin,text);
	cout<<"Enter position : ";
	cin>>pos;
	pos=pos-2;
	cout<<"Enter n : ";
	cin>>n;
	
	char s1[len(text)-n];
	for(int i=0 ; i<pos ; i++)
	{
		s1[i]=text[i];
	}
	for(int i=pos+n;i<len(text);i++)
	{
		s1[i-n]=text[i];
	}
	for(int i=0;i<len(text);i++)
	{
		cout<<s1[i];
	}
	
}

int main()
{
	int option;
	cout<<"Choose any one option .."<<endl<<"1. Insert Substring "<<endl<<"2. Delete Substring "<<endl;
	cin>>option;
	switch(option)
	{
		case 1 : {
	        insert_substring();
			break;
		}
		
		case 2 : {
	        delete_substring();
			break;
		}
	}	
return 0;
}

