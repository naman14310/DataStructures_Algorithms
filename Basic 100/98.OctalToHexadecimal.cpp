#include<iostream>
using namespace std;

int pow(int base, int exp)
{
	if(exp==0) return 1;
	
	int temp = base;
	for(int i=1; i<exp; i++)
	{
		base=base*temp;
	}
	return base;
}

int main()
{
	int octal, decimal, p=0, i=0;
	char hex[50];
	
	cout<<endl<<"Enter octal number : ";
	cin>>octal;
	
	while(octal>0)
	{
		int digit = octal%10;
		decimal = decimal+digit*pow(8,p++);
		octal=octal/10;
	}
	
	cout<<endl<<"Decimal : "<<decimal<<endl;
	
	while(decimal>0)
	{
		int digit = decimal%16;
		if(digit<10) 
		{
			hex[i]= digit+48;
			i++;
		}
		else
		{
			hex[i]= digit+55;
			i++;
		} 
		decimal=decimal/16;
	}
	
	cout<<endl<<"Hexadecimal : ";
	
	for(int j=i-1; j>=0; j--)
	{
		cout<<hex[j];
	}
	
}
