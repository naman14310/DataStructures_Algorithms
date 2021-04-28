#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main()
{   int limit, sum=0;
	cout<<"How many numbers you want to enter : ";
	cin>>limit;
	int* arr = (int*) malloc(limit*sizeof(int));
	
	for(int i=0; i<limit; i++)
	{
		cin>>*(arr+i);
	}
	
	for(int i=0; i<limit; i++)
	{
	    sum+=arr[i];	
	}
	cout<<endl<<"Sum : "<<sum;
	
}
