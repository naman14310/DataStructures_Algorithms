#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

typedef struct node snode;
snode *head1, *head2;

void traverse()
{
	snode* t = head1;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}

snode* createNewNode(int val)
{
	snode* newNode = (snode*)malloc(sizeof(snode));
	
	if(newNode==NULL) 
	{
	    cout<<"Memory not allocated"<<endl;
		return 0;	
	}
	else
	{
		newNode->data=val;
		newNode->next=NULL;
		return newNode;
	}
}

void insertInList1(snode* node)
{
	if(head1==NULL)
	{
		head1=node;
	}
	else
	{
		snode* t=head1;
		while(t->next!=NULL) t=t->next;
		t->next=node;
	}
	cout<<"Node Inserted! \n";
}

void insertInList2(snode* node)
{
	if(head2==NULL)
	{
		head2=node;
	}
	else
	{
		snode* t=head2;
		while(t->next!=NULL) t=t->next;
		t->next=node;
	}
	cout<<"Node Inserted! \n";
}

void combine()
{
	snode* t=head1;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=head2;
}

int main()
{
	int n1, n2, val;
	
	cout<<"how many numbers you want to insert in linked list 1 : ";
	cin>>n1;
	cout<<endl<<endl;
	for(int i=0; i<n1; i++)
	{ 
	    cout<<"Enter value of node "<<i+1<<" : ";
	    cin>>val;
		snode* newNode = createNewNode(val);
		insertInList1(newNode);
	}
	
	cout<<"how many numbers you want to insert in linked list 2 : ";
	cin>>n2;
	cout<<endl<<endl;
	for(int i=0; i<n2; i++)
	{ 
	    cout<<"Enter value of node "<<i+1<<" : ";
	    cin>>val;
		snode* newNode = createNewNode(val);
		insertInList2(newNode);
	}
	
	combine();
	cout<<"Combined linked list : ";traverse();
}
