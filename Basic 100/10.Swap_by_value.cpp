#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int a, int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<"After swapping : "<<a<<" "<<b<<endl;
}

int main()
{
	int a, b;
	cout<<"Enter two no. : ";
	cin>>a>>b;
	cout<<"Before swapping : "<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<"Main values after swapping : "<<a<<" "<<b;
}
