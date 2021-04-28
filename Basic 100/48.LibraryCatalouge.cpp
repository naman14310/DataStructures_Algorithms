#include<iostream>
#include<stdlib.h>
using namespace std;

struct library
{
	int accesNumber;
	char authorName[20];
	char title[20];
	char publisherName[20];
	int year;
	int price;
};

int main()
{
	int n;
	cout<<endl<<"Enter number of books : ";
	cin>>n;
	
	struct library* arr = (struct library*) malloc(n*sizeof(struct library));
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<"Enter accesNumber of book "<<i+1<<" : ";
		cin>>arr[i].accesNumber;
		cout<<"Enter author name of book "<<i+1<<" : ";
		cin>>arr[i].authorName;
		cout<<"Enter title of book "<<i+1<<" : ";
		cin>>arr[i].title;
		cout<<"Enter publisher name of book "<<i+1<<" : ";
		cin>>arr[i].publisherName;
		cout<<"Enter publication year of book "<<i+1<<" : ";
		cin>>arr[i].year;
		cout<<"Enter price of book "<<i+1<<" : ";
		cin>>arr[i].price;
	}
	
	cout<<endl<<"Details of all books :-";
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<endl<<"Book :"<<i+1;
		cout<<endl<<"AccesNumber : "<<arr[i].accesNumber;
		cout<<endl<<"Author name : "<<arr[i].authorName;
		cout<<endl<<"Title : "<<arr[i].title;
		cout<<endl<<"Publisher name : "<<arr[i].publisherName;
		cout<<endl<<"Publication year : "<<arr[i].year;
		cout<<endl<<"Price : "<<arr[i].price;
		cout<<endl;
	}
	
}
