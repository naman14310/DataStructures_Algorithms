#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

typedef struct node snode;
snode* head=NULL;

snode* createNewNode(int val)
{
	snode* newNode = (snode*)malloc(sizeof(snode));
	
	if(newNode==NULL) 
	{
	    cout<<"Heap memory overflow"<<endl;
		return 0;	
	}
	else
	{
		newNode->data=val;
		newNode->next=NULL;
		return newNode;
	}
}

void push()
{
	int element;
	cout<<endl<<"Enter element : ";
	cin>>element;
	snode* newNode = createNewNode(element);
	
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head=newNode;
	}
	cout<<endl<<"Inserted"<<endl;
}

void pop()
{
	if(head==NULL)
	{
		cout<<endl<<"Stack underflow"<<endl;
	}
	else
	{
		snode* p = head;
		head = head->next;
		cout<<endl<<"Element deleted is : "<<p->data<<endl;
		free(p);
	}
}

void traverse(snode* t)
{
	if(t)
	{
		traverse(t->next);
		cout<<t->data<<" ";
	}
}

int main()
{
	int op;
	while(1)
	{	
	cout<<endl<<endl<<"1. Press 1 for push operation"<<endl<<"2. Press 2 for pop operation"<<endl<<"3. Press 3 to print stack"<<endl<<endl;
	cin>>op;
	switch(op)
	{
		case 1: push(); break;
			
		case 2: pop(); break;
		
		case 3:
		    {   cout<<endl<<"Stack : ";
		    	traverse(head);
				cout<<endl<<endl;
				break;
		    } 
		
		default: cout<<endl<<"Invalid option !"<<endl;
			
	}
    } 
}
