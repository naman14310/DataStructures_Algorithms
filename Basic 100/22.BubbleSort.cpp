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

void smartbubbleSort(int arr[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}

}

int main()
{
	int arr[10] = {1,10,5,15,4,7,12,6,11,9};
	cout<<"Sorted order is : ";
	smartbubbleSort(arr,10);
	printArray(arr,10);
}
