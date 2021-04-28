#include<iostream>
#define size 5
using namespace std;

int queue[size];
int front=-1, rear=-1, count=0;

void enqueue(int item)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=item;
		cout<<endl<<"Element inserted"<<endl;
		count++;
	}
	else if((rear+1)%size==front)
	{
		cout<<endl<<"Queue overflow"<<endl;
	}
	else
	{
		rear++;
		queue[rear%size]=item;
		cout<<endl<<"Element inserted"<<endl;
		count++;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
	{
		cout<<endl<<"Queue underflow"<<endl;
	}
	else if(front==rear)
	{
		int temp= queue[front];
		front=rear=-1;
		cout<<endl<<"Element deleted is : "<<temp<<endl;
		count--;
	}
	else
	{
		int temp=queue[front++];
		cout<<endl<<"Element deleted is : "<<temp<<endl;
		count--;
	}
}

void traverse()
{
     for(int i=0; i<count; i++)
     {
     	cout<<queue[(front+i)%size]<<" ";
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
