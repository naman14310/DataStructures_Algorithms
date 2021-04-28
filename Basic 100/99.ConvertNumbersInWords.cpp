#include<iostream>
using namespace std;

int main()
{
	int num, arr[100], i=0;;
	cout<<"Enter number : ";
	cin>>num;
	
	while(num>0)
	{
		arr[i++] = num%10;
		num/=10;
	}
	i--;
	while(i>=0)
	{
		switch(arr[i--])
		{
			case 0: cout<<"Zero "; break;
			case 1: cout<<"One "; break;
			case 2: cout<<"Two "; break;
			case 3: cout<<"Three "; break;
			case 4: cout<<"Four "; break;
			case 5: cout<<"Five "; break;
			case 6: cout<<"Six "; break;
			case 7: cout<<"Seven "; break;
			case 8: cout<<"Eight "; break;
			case 9: cout<<"Nine "; break;
		}
	}
	
	
}
