#include <iostream>
using namespace std;

int main()
{   int n;
	cout<<"Enter number : ";
	cin>>n;
	int sum=0;
	while(n>0)
	{
		int digit=n%10;
		sum+=digit;
		n/=10;
	}
	cout<<"Sum of Digits : "<<sum;
}
