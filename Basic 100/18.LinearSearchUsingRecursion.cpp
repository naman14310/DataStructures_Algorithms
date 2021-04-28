#include <iostream>
using namespace std;

int LinearSearch(int index, int value, int arr[], int n)
{

	if(index>=n)
	{
		return 0;
	}
	else if(arr[index]==value)
	{
		return index+1;
	}
	else
	{
		LinearSearch(index+1,value,arr,10);
	}
} 

int main()
{
	int arr[10] = {1,12,43,2,3,224,77,100,15,10};
	int no;
	cout<<"Enter no. you want search : ";
	cin>>no;
	int ans = LinearSearch(0,no,arr,10);
	if(ans==0)
	{
		cout<<endl<<"Error 404 : Number not Found !";
	}
	else cout<<endl<<"Number found at position : "<<ans;
return 0;
}
