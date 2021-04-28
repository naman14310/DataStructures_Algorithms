#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,gcd;
	cout<<"Enter a and b : ";
	cin>>a>>b;
    for(int i=1 ; i<=a && i<=b ; i++)
    {
    	if(a%i==0 && b%i==0)
    	{
    		gcd=i;
		}
	}
	cout<<"GCD : "<<gcd;
	
}
