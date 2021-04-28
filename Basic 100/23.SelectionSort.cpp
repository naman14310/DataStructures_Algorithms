#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(int a[], int n)
{	
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}

void selectionSort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1; j<n ; j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		swap(&arr[i],&arr[min_index]);
	}

}


int main()
{
	int arr[10] = {1,10,5,15,4,7,12,6,11,9};
	cout<<"Sorted order is : ";
	selectionSort(arr,10);
	printArray(arr,10);
}
