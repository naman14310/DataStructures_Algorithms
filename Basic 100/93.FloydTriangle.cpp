#include <iostream>
using namespace std;

void floyd(int n)
{
	int no=1;
	for(int i=n-1 ; i>=0 ; i--)
	{
		for(int j=0 ; j<n-i ; j++)
		{
			cout<<no<<" ";
			no++;
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	cout<<endl<<endl; floyd(n);
}
