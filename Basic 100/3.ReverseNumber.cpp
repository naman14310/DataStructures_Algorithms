#include<iostream>
using namespace std;

int len(int no)
{
	int length=0;
	while(no>0)
	{
		length++;
		no/=10;
	}
	return length;
}

int pow(int p)
{
	int result=1;
	for(int i=0 ; i<p ; i++)
	{
		result = result*10;
	}
	return result;
}

int main()
{
	int n, rev=0, i=0;
	cout<<"Enter no : ";
	cin>>n;
	int l = len(n);
	while(n>0) 
	{
		int digit = n%10;
		rev=rev+digit*pow(l-i-1);
		n=n/10;
		i++;
	}
    cout<<"reverse : "<<rev;
} 

