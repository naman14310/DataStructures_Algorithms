#include<iostream>
#define maxSize 5
using namespace std;

int queue[maxSize];
int front=-1, rear=-1;

void traverse()
{
	for(int i=front; i<=rear; i++)
	{
		cout<<queue[i]<<" ";
	}
}

void enqueue(int item)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		queue[rear]=item;
	}
	else if(rear==maxSize-1)
	{
		cout<<endl<<"Queue overflow"<<endl;
	}
	else
	{
		queue[++rear]=item;
		cout<<endl<<"Element inserted"<<endl;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
	    cout<<endl<<"Queue Underflow"<<endl;	
	}
	else if(front==rear)
	{
		cout<<endl<<"Element deleted : "<<queue[front]<<endl;
		front = rear = -1;
	}
	else
	{
		cout<<endl<<"Element deleted : "<<queue[front++]<<endl;
	}
}

int main()
{
	int op;
	while(1)
	{	
	cout<<endl<<endl<<"1. Press 1 for inserting element"<<endl<<"2. Press 2 for deleting element"<<endl<<"3. Press 3 to print Queue"<<endl<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
		    {
		    	int item;
		    	cout<<endl<<"Enter element : ";
		    	cin>>item;
		    	enqueue(item); break;
			
		    } 
			
		case 2: dequeue(); break;
		
		case 3:
		    {   cout<<endl<<"Queue : ";
		    	traverse();
				cout<<endl<<endl;
				break;
		    } 
		
		default: cout<<endl<<"Invalid option !"<<endl;
			
	}
    } 
}
