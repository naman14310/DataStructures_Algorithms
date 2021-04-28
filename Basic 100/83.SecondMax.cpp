#include<iostream>
using namespace std;

int main()
{
	int n=10;
	int max1,max2;
	int arr[n]={0,-1,-10,-2,-5,-13,-13,0,0,-222};
	if(arr[0]>arr[1])
	{
		max1=arr[0];
		max2=arr[1];
	}
	else
	{
		max1=arr[1];
		max2=arr[0];
	}
	for(int i=2; i<n; i++)
	{
		if(arr[i]>max1)
		{
			max2=max1;
			max1=arr[i];
		}
		else if(arr[i]>max2 && arr[i]!=max1) 
		{
			max2=arr[i];
		}
	}
	cout<<max2;
	
}
