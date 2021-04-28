#include<iostream>
using namespace std;

int main()
{
	int arr[11]={-11,2,3,4,-5,6,11,7,15,9,-10};
	int max=arr[0],min=arr[0];
	
	for(int i=1; i<11; i++)
	{
		if(arr[i]>max) max=arr[i];
		else if(arr[i]<min) min=arr[i];
	}
	
	cout<<endl<<"Max : "<<max;
	cout<<endl<<"Min : "<<min;
	
}
