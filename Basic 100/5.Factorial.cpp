#include<iostream>
using namespace std;

int main()
{
	int n, i=2, fact=1;
	cout<<"enter n : ";
	cin>>n;
	while(i<=n)
	{
		fact=fact*i;
		i++;
	}
	cout<<"Factorial is : "<<fact;
	return 0;
}
