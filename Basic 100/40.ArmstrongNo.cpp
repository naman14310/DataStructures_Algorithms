#include<iostream>
using namespace std;

int count(int n)
{
	int c=0;
	while(n>0)
	{
		c++;
		n=n/10;
	}
	
	return c;
}

int power(int base, int exp)
{
	if(exp==0) return 1;
	int pow = base;
	for(int i=1; i<exp; i++)
	{
		pow=pow*base;
	}
	return pow;
}

int main()
{
	int n,p,temp,sum=0,digit;
	cout<<"Enter number : ";
	cin>>n;
	temp=n;
	p=count(n);
	while(n)
	{
		digit=n%10;
		sum=sum+power(digit,p);
		n=n/10;
	}
	
	if(sum==temp) cout<<endl<<"Armstrong number";
	else  cout<<endl<<"Not an armstrong number";
	
	return 0;
}
