#include<iostream>
using namespace std;

int main()
{
	int arr[10] = {1,10,5,15,4,7,12,6,11,9};
	int min=arr[0], max=arr[0];
	
	for(int i=1; i<10; i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
		else if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	cout<<"smallest : "<<min<<endl<<"largest : "<<max;
}
