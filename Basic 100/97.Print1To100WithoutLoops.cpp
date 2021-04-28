#include<iostream>
using namespace std;
int num = 100;
void fun(int n)
{
	if(n>0)
	{
		cout<<num-n+1<<" ";
		fun(--n);
	}
}

int main()
{
	fun(num);
}
