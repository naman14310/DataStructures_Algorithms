#include<iostream>
using namespace std;

int main()
{
	int pos, n=11, item;
	int arr[11]={1,2,3,4,5,6,7,8,9,10};
	
	cout<<"Enter position : ";
	cin>>pos;
	pos--;
	
	cout<<endl<<"Enter element : ";
	cin>>item;
	
	for(int i=n-1; i>pos; i--)
	{
		arr[i]=arr[i-1];
	}
	
	arr[pos]=item;
	
	cout<<endl<<"After insertion : " ;
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
