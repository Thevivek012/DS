#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node slnode;

slnode *start=NULL,*last=NULL;

void main()
{
	int ch,key;
	void create();
	void insert(int);
	void display();
	void delete_node(int);
	void search(int);
	do
	{
		printf("M E N U\n1. CREATE \n2. INSERT\n3.DELETE\n");
		printf("4.DISPLAY\n5.SEARCH\n6.EXIT\n");
		
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2:
					printf("In which node before you have to insert the node\n");
					scanf("%d",&key);
					insert(key);
					break;
			case 3:
					printf("In which node you have to delete\n");
					scanf("%d",&key);
					delete_node(key);
					break;
			case 4: display();
					break;
			case 5: 
					printf("Enter value to be search\n");
					scanf("%d",&key);
					search(key);
					break;
		}
	}while(ch!=6);
 }
	void create()
	{
		slnode *temp;
		int val;
		while(1)
		{
			printf("enter value to be insert");
			scanf("%d",&val);
			if(val==0)
				break;
			else
			    {
			  	  temp=(slnode*)malloc(sizeof(slnode));
			  	  temp->data=val;
			  	  temp->next=NULL;
			  	  if(start==NULL)
			  	    {
			  	    	start=temp;
			  	    	last=temp;
					  }
				else
					{
						last->next=temp;
						last=temp;
					}
				}	
		}
	}
	void delete_node(int key)
	{
		slnode *curr,*prev;
		curr=prev=start;
		while(curr->data!=key && curr->next!=NULL)
		  {
		  	prev=curr;
		  	curr=curr->next;
		  }
		
		if(curr==start)
		{
			printf("it is frist");
			start=start->next;
			curr->next=NULL;
			free(curr);
		}
		else
			if(curr==last && curr->data != key)
		  		printf("Element not found\n");
			else
		  		if(curr==last && curr->data ==key)
		    		{
		    			last=prev;
		    			prev->next=NULL;
		    			free(curr);
					}
		  		else
		     			{
		     				prev->next =curr->next;
		     				free(curr);
			 			}
	}
	void display()
	{
		slnode *temp;
		temp=start;
		if(temp==NULL)
		  printf("List is empty\n");
		else
		  {
		  	printf("List values are :\n");
		  	while(temp!=NULL)
		  	{
		  		printf("%d ",temp->data);
		  		temp=temp->next;  	
			}
		  }
		
	}
	void insert(int key)
	{
		slnode *curr,*prev,*temp;
		curr=prev=start;
		while(curr->data!=key && curr->next!=NULL)
		  {
		  	prev=curr;
		  	curr=curr->next;
		  }
		temp=(slnode*)malloc(sizeof(slnode));
		printf("enter value to be insert");
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(curr==start)
		{
			temp->next=curr;
			start=temp;
		}
		else
		   	if(curr->data !=key && curr==last)
		  	  {
		  	  	last->next=temp;
		  	  	last=temp;
				}
		  	else
		  	   {
		  	   	temp->next=curr;
		  	   	prev->next=temp;
				 }
	}
	void search(int key)
	{
		slnode *temp;
		temp=start;
		if(temp==NULL)
		  printf("List is empty\n");
		else
		  {
		  	while(temp!=NULL)
		  	{
		  		if(temp->data==key)
		  		  {
		  		  	printf("element found\n");
		  		  	break;
					}
		  		temp=temp->next;  	
			}
			if(temp==NULL)
			  printf("Element not found\n");
		  }
	}
	

