#include<iostream>
using namespace std;

int main()
{
	int n, count=1;
	cout<<"Enter size : ";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j<i)
			{
				cout<<"0 ";
			}
			else
			{
				cout<<count<<" ";
				count++;
			}
		}
		cout<<endl<<endl;
	}
	
}
