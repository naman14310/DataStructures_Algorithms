#include<iostream>
#include<stdlib.h>
using namespace std;

union car
{
	char* name;
	int price;
	
};

int main()
{
	union car car1, car2, *car3=&car1;
	car1.price=2500000;
	car1.name="BMW"; //variable which initialize at the end will store the value
	
	cout<<"Size of union : "<<sizeof(car);
	
	cout<<endl<<"Name : "<<car1.name;
	cout<<endl<<car3->name;
	
	cout<<endl<<"Price : "<<car1.price;
	cout<<endl<<car3->price;
}
