#include<iostream>
using namespace std;

int max(int arr[], int n)
{
	int max=arr[0];
	for(int i=1; i<n; i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<"Maximum element is : "<<max(arr,10);
}
