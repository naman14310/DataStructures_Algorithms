#include<iostream>
#define maxSize 10
using namespace std;

int stack[maxSize];
int top=0;

void push(int element)
{
	if(top==maxSize)
	{
		cout<<endl<<"Stack overflow"<<endl;
	}
	else
	{
		stack[top++] = element;
	}
}

void pop()
{
	if(top==0) cout<<endl<<"Stack underflow"<<endl;
	else cout<<endl<<"element deleted : "<<stack[--top]<<endl;
}

int main()
{
	int op;
	
	while(1)
	{
	
	cout<<"1. Press 1 for push operation"<<endl<<"2. Press 2 for pop operation"<<endl<<endl;
	cin>>op;
	
	switch(op)
	{
		case 1:
			{
				int element;
				cout<<endl<<"Enter element : ";
				cin>>element;
				push(element);
				break;
			}
			
		case 2:
			{
				pop(); break;
			}
			
		default:
			cout<<endl<<"Invalid option !"<<endl;
			
	}
	
	cout<<endl<<"Stack : ";
	for(int i=0; i<top; i++)
	{
		cout<<stack[i]<<" ";
	}
	
	cout<<endl<<endl;
    } 
	
}
