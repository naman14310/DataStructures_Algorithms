#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

typedef struct node snode;
snode* head = NULL; snode* rear = NULL;

snode* createNewNode(int val)
{
	snode* newNode = (snode*)malloc(sizeof(snode));
	
	if(newNode==NULL) 
	{
	    cout<<"Queue overflow"<<endl;
		return 0;	
	}
	else
	{
		newNode->data=val;
		newNode->next=NULL;
		return newNode;
	}
}

void enqueue(snode* node)
{
	if(head==NULL)
	{
		head=node;
		rear=node;
	}
	else
	{
		rear->next=node;
		rear=node;
	}
	cout<<"Node Inserted! \n";
}

void dequeue()
{
	if(head==NULL)
	{
		cout<<endl<<"Queue underflow"<<endl;
	}
	else
	{
		snode* p = head;
		head = head->next;
		free(p);
		cout<<"Node Deleted!"<<endl;
		
	}
}

void traverse()
{
	snode* t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}

int main()
{
	int op;
	while(1)
	{	
	cout<<endl<<endl<<"1. Press 1 for insert item"<<endl<<"2. Press 2 for delete item"<<endl<<"3. Press 3 to print queue"<<endl<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
		    {
		    	int item;
		    	cout<<endl<<"Enter item : ";
		    	cin>>item;
		    	snode* newNode = createNewNode(item);
		    	enqueue(newNode);
			    break;
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
