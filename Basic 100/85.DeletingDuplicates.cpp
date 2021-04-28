#include<iostream>
using namespace std;

int main()
{
	int size;
	cout<<endl<<"Enter size : ";
	cin>>size;
	
	int arr[size];
	cout<<endl<<"Enter array : ";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(arr[i]==arr[j])
			{
				for(int k=j+1; k<size; k++)
				{
					arr[k-1]=arr[k];
				}
				size--;
				j--;
			}
		}
	}
	
	cout<<endl<<"Final array : ";
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
}

