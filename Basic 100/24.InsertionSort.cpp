#include <iostream>
using namespace std;

void printArray(int a[], int n)
{	
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}

void insertionSort(int arr[], int n)
{
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main()
{
	int arr[10] = {1,10,5,15,4,7,12,6,11,9};
	cout<<"Sorted order is : ";
	insertionSort(arr,10);
	printArray(arr,10);
}
