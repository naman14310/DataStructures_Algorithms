#include<iostream>
using namespace std;

int main()
{
	int n; 
	cout<<"Enter height of the triangle : ";
	cin>>n;
	int value;
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		value=1;
		for(int space=0; space<n-i-1; space++)
		{
			cout<<" ";
		}
		for(int j=0; j<i+1; j++)
		{
			cout<<" "<<value;
			value=value*(i-j)/(j+1);
		}
		cout<<endl<<endl;
	}
	return 0;
}
