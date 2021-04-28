#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int a[], int n)
{	
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}

void Merge(int arr[], int L[], int R[])
{
	int i=0,j=0,k=0;
	int nL=sizeof(L)/sizeof(L[0]);
	int nR=sizeof(R)/sizeof(R[0]);
	
	while(j<nL && k<nR)
	{
		if(L[j]<R[k])
		{
			arr[i]=L[j];
			j++;
		}
		else
		{
			arr[i]=R[k];
			k++;
		}
		i++;
	}
	while(j<nL)
	{
		arr[i]=L[j];
		j++;i++;
	}
	while(k<nR)
	{
	    arr[i]=R[k];
		k++;i++;
	}
}

void MergeSort(int arr[])
{
	int n = sizeof(arr)/sizeof(arr[0]);
	int *L, *R;
	if(n<2) return;
	
	int mid=n/2;
	L=(int*)malloc(mid*sizeof(int));
	R=(int*)malloc((n-mid)*sizeof(int));
	
	for(int i=0;i<mid;i++)
	{
		L[i]=arr[i];
	}
	for(int i=mid;i<n;i++)
	{
		R[i-mid]=arr[i];
	}
	MergeSort(L);
	MergeSort(R);
	Merge(arr,L,R);
	free(L);
	free(R);
}


int main()
{
	int arr[10] = {1,10,5,15,4,7,12,6,11,9};
	cout<<"Sorted order is : ";
	MergeSort(arr);
	printArray(arr,10);
	
	return 0;
}
