#include<iostream>
using namespace std;

int main()
{
	int decimal, i=0;
	int octal[50];
	
	cout<<endl<<"Enter decimal number : ";
	cin>>decimal;
	
	while(decimal>0)
	{
		int digit = decimal%8;
		if(digit<10) octal[i++] = digit;
		decimal=decimal/8;
	}
	
	cout<<endl<<"Octal : ";
	
	for(int j=i-1; j>=0; j--)
	{
		cout<<octal[j];
	}
	
}
