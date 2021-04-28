#include <iostream>
using namespace std;

int pow(int a, int b)
{
	if(b==0)
	{
		return 1;
	}
	else if(b==1)
	{
		return a;
	}
	else
	{
		return a*pow(a,b-1);
	}
	
}

int main()
{
	int a,b;
	cout<<"Enter a and b : ";
	cin>>a>>b;
	cout<<"Power : "<<pow(a,b);
	
}
