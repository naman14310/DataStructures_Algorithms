#include<iostream>
using namespace std;

int main()
{
	int n, m, sum=0;
	cout<<endl<<"Enter no. of rows : ";
	cin>>n;
	cout<<endl<<"Enter no. of columns : ";
	cin>>m;
	
	cout<<endl<<endl;
	
	int matrix[n][m];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>matrix[i][j];
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i==j)
			{
				sum+=matrix[i][j];
				break;
			}
		}
	}
	
	cout<<endl<<"Sum : "<<sum; 
	
}
