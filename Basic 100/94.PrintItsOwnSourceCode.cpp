#include<cstdio>
using namespace std;

int main()
{
	FILE *ptr;
	ptr = fopen(__FILE__, "r");
	while(!feof(ptr))
	{
		printf("%c",fgetc(ptr));
	}
	fclose(ptr);
}

//This is miracle
