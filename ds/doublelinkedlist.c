#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *Llink;
	struct Node *Rlink;
};
struct Node *header=NULL;

//create node
struct Node *createNode(int data)
{
	struct Node *newnode;
	newnode=malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->Llink=NULL;
	newnode->Rlink=NULL;
	return(newnode);
}

//insert at front

void insertatfront(int data)
{	
	struct Node *newnode;
	if(header==NULL)
	{
		newnode=createNode(data);
		header=newnode;
	}
	else
	{
		newnode=createNode(data);
		newnode->Rlink=header;
		header->Llink=newnode;
		header=newnode;
	}
}

//Insert at last

void insertatlast(int data)
{	
	struct Node *ptr;
	struct Node *newnode;
	ptr=header->Rlink;
	newnode=createNode(data);
	while(ptr->Rlink!=NULL)
	{
		ptr=ptr->Rlink;
		
	}
		ptr->Rlink=newnode;
		header->Llink=ptr;
}
//Delete at front

void deleteatfront()
{
	struct Node *ptr;
	ptr=header;
	header=ptr->Rlink;
	free(ptr);
}
//Delete at last

void deleteatend()
{
	struct Node *ptr;
	struct Node *ptr1;
	ptr=header;
	while(ptr->Rlink!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->Rlink;
	}
		ptr1->Rlink=NULL;
		free(ptr);
}

//Traversal

void traversal()
{
	struct Node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->Rlink;
	}
}
int main()
{
//struct Node *node
	insertatfront(10);
	insertatfront(20);
	insertatlast(30);
	deleteatfront();
	deleteatend();
	traversal();
	return(0);
}
