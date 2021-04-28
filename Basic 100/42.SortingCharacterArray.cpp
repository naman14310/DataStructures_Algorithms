#include <iostream>
using namespace std;
void swap(char *a, char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(char a[], int n)
{	
	for(int i=0; i<n; i++)
	{
		cout<<a[i];
	}
}

void smartbubbleSort(char str[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		int flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(str[j]>str[j+1])
			{
				swap(&str[j],&str[j+1]);
				flag=1;
			}
		}
		if(flag==0) break;
	}

}

int main()
{
	char str[100];
	cout<<"Enter string : ";
	gets(str);
	int count=0;
	while(str[count]!='\0')
	{
		count++;
	}
	cout<<"count : "<<count<<endl;
	cout<<"Sorted order is : ";
	smartbubbleSort(str,count);
	printArray(str,count);
}
