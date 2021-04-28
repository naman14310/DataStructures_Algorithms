#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cout<<endl<<"Enter no. of rows : ";
	cin>>n;
	cout<<endl<<"Enter no. of columns : ";
	cin>>m;
	
	int matrix1[n][m], matrix2[n][m];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>matrix1[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>matrix2[i][j];
		}
	}
	cout<<endl<<endl;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<matrix1[i][j]+matrix2[i][j]<<" ";
		}
		cout<<endl<<endl;
	}
	
}
