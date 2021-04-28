#include<iostream>
using namespace std;

int factorial(int n)
{
	if(n==0 || n==1) return 1;
	else
	{
		int fact=1;
		for(int i=2; i<=n; i++)
		{
			fact*=i;
		}
		return fact;
	}
}

int main()
{
	int num, sum=0, temp;
	
	cout<<endl<<"Enter number : ";
	cin>>num;
	
	temp=num;
	while(num>0)
	{
		int n=num%10;
		sum+=factorial(n);
		num/=10;
	}
	
	if(sum==temp)
	{
		cout<<endl<<"Strong number";
	}
	else
	{
		cout<<endl<<"Sorry! Not so strong";
	}
}

