#include <iostream>
using namespace std;

int BinarySearch(int arr[], int start, int end, int value)
{
	
	if(end<start) 
	{
		return -1;
	}
	
    int mid = (end+start)/2;
    
    if(arr[mid]==value)
	{
    	return mid;
	}
	else if(arr[mid]<value)
	{
		BinarySearch(arr,mid+1,end,value);
	}
	else if(arr[mid]>value)
	{
		BinarySearch(arr,start,mid-1,value);
	}
} 

int main()
{
	int arr[15] = {1,2,4,5,6,7,9,10,11,12,14,15,16,19,55};
	int no;
	cout<<"Enter no. you want search : ";
	cin>>no;
	int ans = BinarySearch(arr,0,14,no);
	if(ans==-1)
	{
		cout<<endl<<"Error 404 : Number not Found !";
	}
	else cout<<endl<<"Number found at position : "<<ans+1;
return 0;
}
