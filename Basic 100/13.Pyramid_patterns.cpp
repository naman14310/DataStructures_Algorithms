#include <iostream>
using namespace std;

void pyramid1(int n)
{
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int sp=0 ; sp<i ; sp++)
		{
			cout<<" ";
		}
		for(int j=0 ; j<n-i ; j++)
		{
			cout<<n-i<<" ";
		}
		cout<<endl;
	}
}

void pyramid2(int n)
{
	int no=1;
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int sp=0 ; sp<i ; sp++)
		{
			cout<<" ";
		}
		for(int j=0 ; j<n-i ; j++)
		{
			cout<<no<<" ";
			no++;
		}
		cout<<endl;
	}
}

void pyramid3(int n)
{
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int sp=0 ; sp<i ; sp++)
		{
			cout<<" ";
		}
		for(int j=0 ; j<n-i ; j++)
		{
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	cout<<endl<<"pyramid 1"<<endl; pyramid1(n);
	cout<<endl<<"pyramid 2"<<endl; pyramid2(n);
	cout<<endl<<"pyramid 3"<<endl; pyramid3(n);
}
