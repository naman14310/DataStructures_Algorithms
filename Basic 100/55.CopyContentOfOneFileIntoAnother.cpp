#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	FILE* ptr1; FILE* ptr2;
	
	ptr1 = fopen(__FILE__, "r");
	ptr2 = fopen("test.txt", "w");
	while(!feof(ptr1))
	{
		fputc(fgetc(ptr1), ptr2);
	}
	fclose(ptr1);
	fclose(ptr2);
	cout<<"File copied !";
}
