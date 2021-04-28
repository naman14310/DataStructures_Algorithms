#include <iostream>
using namespace std;

int main()
{
	int n=3, m=3, flag=0;
	int matrix[n][m]={{1,1,-1},{1,2,0},{-1,0,9}};
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<m; j++)
		{
			if(matrix[i][j] != matrix[j][i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	}
	if(flag==0) cout<<"Matrix is symmetric";
	else cout<<"Matrix is not symmetric";
}
