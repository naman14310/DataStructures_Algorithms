#include<iostream>
using namespace std;

double sumOfSeries(double n)
{
	double sum=0;
	for(double i=1; i<=n; i++)
	{
		sum=sum+(1/i);
	}
	return sum;
}

int main()
{   double n;
	cout<<"Enter number of terms : ";
	cin>>n;
	cout<<endl<<endl<<"Sum of series is : "<<sumOfSeries(n);
}

