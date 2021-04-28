#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[13] = {1,12,43,2,3,224,77,100,15,10,45,65,123};
	int no, flag=0, pos;
	cout<<"Enter no. you want search : ";
	cin>>no;
	for(int i=0;i<13;i++)
	{
		if(arr[i]==no){
			flag=1;
			pos=i+1;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"Error 404 : Number not Found !";
	}
	else cout<<endl<<"Number found at position : "<<pos;
return 0;
}
