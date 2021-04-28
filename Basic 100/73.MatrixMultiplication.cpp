#include <iostream>
using namespace std;

int checkCompatibility(int row1, int col1, int row2, int col2)
{
	if(col1==row2) return 1;
	return 0;
}

int main()
{
	int row1=2, col1=3, row2=3, col2=2;
	int matrix1[row1][col1]={{0,1,2},{1,0,2}};
	int matrix2[row2][col2]={{1,0},{2,2},{1,1}};
	int chk = checkCompatibility(2,3,3,2);
	if(chk==0)
	{
		cout<<"Matrix are not compatible ! ";
	}
	else
	{
		for(int i=0; i<row1; i++)
		{
			for(int j=0; j<col2; j++)
			{
				int res=0;
				for(int k=0; k<col1;k++)
				{
					res=res+(matrix1[i][k]*matrix2[k][j]);
				
				}
				cout<<res<<" ";
			}
			cout<<endl<<endl;
		}
		
	}
	
}

