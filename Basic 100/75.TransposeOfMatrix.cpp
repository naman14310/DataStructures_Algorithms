#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cout<<endl<<"Enter no. of rows : ";
	cin>>n;
	cout<<endl<<"Enter no. of columns : ";
	cin>>m;
	cout<<endl;
	
	int matrix1[n][m];
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>matrix1[i][j];
		}
	}
	
	int matrix2[m][n];
	
	cout<<endl<<endl;
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<matrix1[j][i]<<" ";
		}
		cout<<endl<<endl;
	}
	
}
