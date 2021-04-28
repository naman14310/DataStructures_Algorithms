#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

typedef struct node snode;
snode* head = NULL;

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

void insertAtBegining(snode* node, int* count)
{
	if(head==NULL)
	{
		head=node;
		node->next=NULL;
	}
	else 
	{
		node->next=head;
		head=node;
	}
	cout<<"Node Inserted! \n";
	++*count;;
}

void insertAtEnd(snode* node, int* count)
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
	++*count;
}

void insertAtPos(snode* node, int pos, int* count)
{
	if(pos<1 || pos>*count+1)
	{
		cout<<"Please enter valid position !\n";
	}
	else if(pos==1)
	{
		insertAtBegining(node,count);
	}
	else if(pos==*count+1)
	{
		insertAtEnd(node,count);
	}
	else
	{
		snode* t=head;
		for(int i=1; i<pos-1; i++)
		{
			t=t->next;
		}
		node->next=t->next;
		t->next=node;
		cout<<"Node inserted! \n";
		++*count;
	}
}

void deleteFirst(int* count)
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty"<<endl;
	}
	else
	{
		snode* p = head;
		head = head->next;
		free(p);
		cout<<"Node Deleted!"<<endl;
		--*count;
	}
}

void deleteLast(int* count)
{
	if(head==NULL)
	{
		cout<<endl<<"List is empty"<<endl;
	}
	else
	{
		snode* t = head; snode* p;
		while(t->next->next!=NULL) t=t->next;
		p = t->next;
		t->next=NULL;
		free(p);
		cout<<"Node Deleted!"<<endl;
		--*count;
	}
}

void deleteAtPos(int pos, int* count)
{
	if(pos<1 || pos>*count)
	{
		cout<<"Please enter valid position !\n";
	}
	else if(pos==1)
	{
		deleteFirst(count);
	}
	else if(pos==*count)
	{
		deleteLast(count);
	}
	else
	{
		snode* t = head; snode* p;
		for(int i=1; i<pos-1; i++)
		{
			t=t->next;
		} 
		t->next=t->next->next;
		p=t->next;
		free(p);
		cout<<"Node Deleted\n";
		--*count;
	}
}

int main()
{
	static int count;
	int op; char ch;
	cout<<"Which operation you want to perform ?"<<endl<<endl;
	
	do
	{
		cout<<"1. Press 1 to traverse linked list"<<endl<<"2. Press 2 to insert at begining"<<endl<<"3. Press 3 to insert at end"<<endl<<"4. Press 4 to insert at desired position"<<endl<<"5. Press 5 to delete first node"<<endl<<"6. Press 6 to delete last node"<<endl<<"7. Press 7 to delete node at desired position"<<endl<<endl;
	    cin>>op;
	    switch(op)
	    {
		    case 1:
			{
				cout<<endl<<"TRAVERSING..."<<endl<<endl;
				traverse();
				cout<<endl;
				break;
			} 
			       
			case 2: 
			{
				int data;
			    cout<<endl<<"INSERT AT BEGINING..."<<endl<<endl;
			    cout<<"Enter data : ";
			    cin>>data;
			    snode* newNode = createNewNode(data);
			    insertAtBegining(newNode, &count);
			    break;
			}
			    
			case 3:
			{
			    int data;
			    cout<<endl<<"INSERT AT END..."<<endl<<endl;
			    cout<<"Enter data : ";
			    cin>>data;
			    snode* newNode = createNewNode(data);
			    insertAtEnd(newNode, &count);
			    break;
			} 
			    
			case 4:
			{
				int data, pos;
			    cout<<endl<<"INSERT AT DESIRED POSITION..."<<endl<<endl;
			    cout<<"Enter data : ";
			    cin>>data;
			    cout<<"Enter position : ";
			    cin>>pos;
			    snode* newNode = createNewNode(data);
			    insertAtPos(newNode, pos, &count);
			    break;
			}
			
			case 5:
			{
				cout<<endl<<"DELETE FIRST NODE..."<<endl<<endl;
				deleteFirst(&count);
				break;
			}
			
			case 6:
			{
				cout<<endl<<"DELETE LAST NODE..."<<endl<<endl;
				deleteLast(&count);
				break;
			}
			
			case 7:
			{
				int pos;
			    cout<<endl<<"DELETE AT DESIRED POSITION..."<<endl<<endl;
			    cout<<"Enter position : ";
			    cin>>pos;
			    deleteAtPos(pos, &count);
			    break;
			}
				   
	    }
	    
	    cout<<endl<<"Do you want to continue y/n : ";
	    cin>>ch;
	    cout<<endl;
	}
	while(ch=='y' || ch=='Y');
}

