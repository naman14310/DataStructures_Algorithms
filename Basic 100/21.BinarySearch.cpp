#include <iostream>
using namespace std;

int main()
{
	int arr[15] = {1,2,4,5,6,7,9,10,11,12,14,15,16,19,55};
	int no, start=0, end=14, flag=0, pos;
	cout<<"Enter no. you want search : ";
	cin>>no;
	while(end>=start)
	{
		int mid=(start+end)/2;
		
		if(arr[mid]==no)
		{
		    flag=1;
		    pos=mid+1;
		    break;
		}
		else if(arr[mid]<no)
		{
			start=mid+1;
		}
		else if(arr[mid]>no)
		{
			end=mid-1;
		}
	}
	
	if(flag==0)
	{
		cout<<endl<<"Error 404 : Number not Found !";
	}
	else cout<<endl<<"Number found at position : "<<pos;
return 0;
}
