#include<iostream>
using namespace std;

int main()
{
	int arr[5][10];
	cout<<"Enter elements in 5 BY 10 matrix : ";
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<10; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int min=arr[0][0], max=arr[0][0];
	
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(arr[i][j]<min)
		    {
			    min=arr[i][j];
		    }
		    else if(arr[i][j]>max)
		    {
		    	max=arr[i][j];
	    	}
	    }
		
	}
	cout<<"smallest : "<<min<<endl<<"largest : "<<max;
}
