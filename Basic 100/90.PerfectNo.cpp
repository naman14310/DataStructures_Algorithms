#include<iostream>
using namespace std;

int main()
{
	int num, sum=1, temp;
	
	cout<<endl<<"Enter number : ";
	cin>>num;
	
	temp=num;
	for(int i=2; i<=num/2; i++)
	{
		if(num%i==0) sum+=i;
	}
	
	if(sum==temp)
	{
		cout<<endl<<"Perfect number";
	}
	else
	{
		cout<<endl<<"Sorry! Not so perfect";
	}
}

