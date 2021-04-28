#include<iostream>
#include<stdlib.h>
using namespace std;

struct student
{
	int sno;
	char name[20];
	int marks;
};

int average(struct student* arr, int n)
{
	int sum=0, av;
	for(int i=0; i<n; i++)
	{
		sum+=arr[i].marks;
	}
	
	av=sum/n;
	return av;
}

int main()
{
	int n;
	cout<<endl<<"Enter number of students : ";
	cin>>n;
	
	struct student* arr = (struct student*) malloc(n*sizeof(struct student));
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<"Enter sno. of student "<<i+1<<" : ";
		cin>>arr[i].sno;
		cout<<"Enter name of student "<<i+1<<" : ";
		cin>>arr[i].name;
		cout<<"Enter marks of student "<<i+1<<" : ";
		cin>>arr[i].marks;
	}
	
	int avg = average(arr,n);
	
	cout<<endl<<"Details of good students are :-";
	
	for(int i=0; i<n; i++)
	{
		if(arr[i].marks>avg)
		{
	    cout<<endl<<endl<<"Sno. of student : "<<arr[i].sno;
		cout<<endl<<"Name of student : "<<arr[i].name;
		cout<<endl<<"Marks of student : "<<arr[i].marks;
		}
		cout<<endl;
	}
	
}
