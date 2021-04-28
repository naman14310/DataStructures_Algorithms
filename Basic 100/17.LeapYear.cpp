#include <iostream>
using namespace std;

int main()
{
	int year;
	cout<<"Enter year : ";
	cin>>year;
	if((year%4==0 && year%100!=0)||(year%400==0))
	{
		cout<<endl<<"It is Leap Year";
	}
	else cout<<"Not a leap year";
}
