#include<iostream>
using namespace std;

int main()
{
	int pos, n=10;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	
	cout<<"Enter position : ";
	cin>>pos;
	
	for(int i=pos; i<n; i++)
	{
		arr[i-1]=arr[i];
	}
	
	cout<<endl<<"After deletion : " ;
	
	for(int i=0; i<n-1; i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
