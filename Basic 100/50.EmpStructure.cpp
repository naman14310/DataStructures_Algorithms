#include<iostream>
#include<stdlib.h>
using namespace std;

struct emp
{
	char name[20];
	int basicPay;
};

int main()
{
	int n;
	cout<<endl<<"Enter number of employee : ";
	cin>>n;
	
	struct emp* arr = (struct emp*) malloc(n*sizeof(struct emp));
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<"Enter name of employee "<<i+1<<" : ";
		cin>>arr[i].name;
		cout<<"Enter basic salary of employee "<<i+1<<" : ";
		cin>>arr[i].basicPay;
		cout<<endl;
	}
	
	cout<<endl<<"List of all employee is :-";
	
	for(int i=0; i<n; i++)
	{
		double gs = 0.52*arr[i].basicPay+arr[i].basicPay;
		cout<<endl<<endl<<"Name of employee : "<<arr[i].name;
		cout<<endl<<"gross salary of employee : "<<gs;
		cout<<endl;
	}
}
