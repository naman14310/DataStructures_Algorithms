#include<iostream>
using namespace std;


int main()
{
	int n, a=0, b=1;
	cout<<"enter n : ";
	cin>>n;
	if(n==0) cout<<"0";
	else if(n==1) cout<<"0 "<<"1";
	else{
		cout<<"0 "<<"1 ";
	    for(int i=2 ; i<n ; i++)
	        {   int c = a+b;
		        cout<<c<<" ";
		        a=b;
		        b=c;
	        }
        }
	return 0;
}
