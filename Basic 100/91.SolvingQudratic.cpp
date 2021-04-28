#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,b,c,x1,x2;
	
	cout<<endl<<"Enter a : ";
	cin>>a;
	cout<<endl<<"Enter b : ";
	cin>>b;
	cout<<endl<<"Enter c : ";
	cin>>c;
	
	cout<<endl<<"Entered equation is : "<<a<<" x^2 + "<<b<<" x + "<<c<<" = 0";
	
	if(a==0 && b==0) cout<<endl<<"You have entered invalid equation !";
	else if(a==0 && b!=0)
	{
		x1=-(c/b);
		cout<<endl<<"This equation has only one root : "<<x1;
	}
	else if(a!=0)
	{
		int chk = b*b-4*a*c;
		if(chk<0)
		{
			cout<<endl<<"This equation does not have any real roots";
		}
		else
		{
			x1=(-b+sqrt(chk))/2*a;
			x2=(-b-sqrt(chk))/2*a;
			cout<<endl<<"This equation does have two real roots : root1 = "<<x1<<" root2 = "<<x2;

		}
	}
}
