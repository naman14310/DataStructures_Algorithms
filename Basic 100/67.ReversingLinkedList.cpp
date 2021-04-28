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

void traverse()
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	snode* t=head;
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

void insert(snode* node)
{
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		snode* t=head;
		while(t->next!=NULL) t=t->next;
		t->next=node;
	}
	cout<<"Node Inserted! \n";
}

void reverse()
{
	if(head==NULL)
	{
		cout<<"Linked list is empty !"<<endl<<endl;
	}
	else if(head->next==NULL)
	{
		cout<<"Reversed linked list : "<<head->data<<endl<<endl;
	}
	else
	{
		snode* prevNode=NULL; snode* currentNode=head; snode* nextNode=NULL;
		while(currentNode)
		{
			nextNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = nextNode;
		}
		head = prevNode;
	}
}

int main()
{
	int n, val;
	cout<<"how many number you want to insert in linked list : ";
	cin>>n;
	
	cout<<endl<<endl;
	for(int i=0; i<n; i++)
	{ 
	    cout<<"Enter value of node "<<i+1<<" : ";
	    cin>>val;
		snode* newNode = createNewNode(val);
		insert(newNode);
	}
	
	cout<<endl;
	
	cout<<endl<<"Before reversing : ";traverse();
	reverse();
	cout<<endl<<"After reversing : ";traverse();
	
}
