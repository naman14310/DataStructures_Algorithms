#include<iostream>
using namespace std;

int main()
{   int n;
    cin>>n;
	int arr[n];
        for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=arr[0];
	for(int i=1; i<n; i++)
	{
		if(arr[i]>max) max=arr[i];
	}
	cout<<max;
}
