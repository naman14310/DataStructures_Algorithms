#include<iostream>
using namespace std;

int main()
{
	int n=10;
	int min1,min2;
	int arr[n]={0,-1,-10,-2,-5,-13,-222,0,0,-222};
	if(arr[0]<arr[1])
	{
		min1=arr[0];
		min2=arr[1];
	}
	else
	{
		min1=arr[1];
		min2=arr[0];
	}
	for(int i=2; i<n; i++)
	{
		if(arr[i]<min1)
		{
			min2=min1;
			min1=arr[i];
		}
		else if(arr[i]<min2 && arr[i]!=min1) 
		{
			min2=arr[i];
		}
	}
	cout<<min2;
	
}
