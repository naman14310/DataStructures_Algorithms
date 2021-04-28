#include<iostream>
using namespace std;

void printArray(int **arr, int r, int c)
{
    for(int i=0; i<r; i++)
	{
	    for(int j=0; j<c; j++)
		{
		    cout<<arr[i][j]<<" ";
	    } 
	    cout<<endl<<endl;
	}	
}

//RETURNING 2-D ARRAY POINTER USING DYNAMIC MEMORY ALLOCATION
int** transpose(int** arr, int row, int col)
{
    int** at = new int*[col];
    for(int i=0; i<col; i++)
    {
    	at[i]=new int[row];
    	for(int j=0; j<row; j++)
    	{
    	    at[i][j]=arr[j][i];
		}
	}
	return at;
}

int main()
{
	int row=2, col=3;
	cout<<"Enter elements.."<<endl<<endl;
	
	// Create 2-D array dynamically and take user input 
	int** arr = new int*[2];
	for(int i=0; i<row; i++)
	{
		arr[i] = new int[3];
		for(int j=0; j<col; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<endl<<endl<<"Before.."<<endl<<endl;
    printArray(arr,row,col);
    
    // "at" will hold the pointer to 2-D array
	int** at = transpose(arr,row,col);
	
	cout<<"After..."<<endl<<endl;
    printArray(at,col,row);
	
} 
