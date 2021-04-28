#include<iostream>
using namespace std;

long factorial(long no)
{
	if(no==0 || no==1) return 1;
	
	long fact=no;
	for(long i=no-1; i>1; i--)
	{
		fact=fact*i;
	}
	return fact;
}


long nCr(long n, long r)
{
	if(r==0 || n-r==0) return 1;
	else if(r==1 || n-r==1) return n;
	else return ((factorial(n))/(factorial(r)*factorial(n-r)));
}

int main()
{   long n, r;
	cout<<"Enter n and r : ";
	cin>>n>>r;
	cout<<endl<<endl<<"nCr : "<<nCr(n,r);
}

