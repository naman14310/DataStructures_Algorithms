#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if(b!=0)
	{
		return gcd(a,a%b);
	}
	else return a;
	
}

int main()
{
	int a, b;
	cout<<"Enter two no. : ";
	cin>>a>>b;
	cout<<"GCD is : "<<gcd(a,b);
}
