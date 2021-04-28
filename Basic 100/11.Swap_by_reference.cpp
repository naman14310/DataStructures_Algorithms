#include<iostream>
using namespace std;

void swap(int *a, int *b)
{ int temp;
    temp=*a;
	*a=*b;
	*b=temp;
	cout<<"After swapping : "<<*a<<" "<<*b<<endl;
}

int main()
{
	int a, b;
	cout<<"Enter two no. : ";
	cin>>a>>b;
	cout<<"Before swapping : "<<a<<" "<<b<<endl;
	swap(&a,&b);
	cout<<"Main values after swapping : "<<a<<" "<<b;
}
