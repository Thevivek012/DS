#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node clnode;

clnode *start=NULL,*last=NULL;

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
		clnode *temp;
		int val;
		while(1)
		{
			printf("enter value to be insert");
			scanf("%d",&val);
			if(val==0)
				break;
			else
			    {
			  	  temp=(clnode*)malloc(sizeof(clnode));
			  	  temp->data=val;
			  	  if(start==NULL)
			  	    {
			  	    	start=temp;
			  	    	last=temp;
			  	    	last->next=temp;
					  }
				else
					{
						last->next=temp;
						temp->next=start;
						last=temp;
					}
				}	
		}
	}
	void delete_node(int key)
	{
		clnode *curr,*prev;
		curr=prev=start;
		while(curr->data!=key && curr->next!=start)
		  {
		  	prev=curr;
		  	curr=curr->next;
		  }
		
		if(curr==start)
		{
			//remove first node
			start=start->next;
			curr->next=NULL;
			last->next=start;
			free(curr);
		}
		else
			if(curr==last && curr->data != key)
		  		printf("Element not found\n");
			else
		  		if(curr==last && curr->data ==key)
		    		{
		    			last=prev;
		    			prev->next=start;
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
		clnode *temp;
		temp=start;
		if(temp==NULL)
		  printf("List is empty\n");
		else
		  {
		  	printf("List values are :\n");
		  	do{
		  		printf("%d ",temp->data);
		  		temp=temp->next;  	
			  }while(temp!=start);
		  }	
	}
	void insert(int key)
	{
		clnode *curr,*prev,*temp;
		curr=prev=start;
		while(curr->data!=key && curr->next!=start)
		  {
		  	prev=curr;
		  	curr=curr->next;
		  }
		temp=(clnode*)malloc(sizeof(clnode));
		printf("enter value to be insert");
		scanf("%d",&temp->data);
		if(curr==start)
		{
			temp->next=curr;
			start=temp;
			last->next=start;
		}
		else
		   	if(curr->data !=key && curr==last)
		  	  {
		  	  	last->next=temp;
		  	  	last=temp;
		  	  	last->next=start;
				}
		  	else
		  	   {
		  	   	temp->next=curr;
		  	   	prev->next=temp;
				 }
	}
	void search(int key)
	{
		clnode *temp;
		temp=start;
		if(temp==NULL)
		  printf("List is empty\n");
		else
		  {
		  	do
		  	{
		  		if(temp->data==key)
		  		  {
		  		  	printf("element found\n");
		  		  	break;
					}
		  		temp=temp->next;  	
			}while(temp!=start);
			if(temp==start)
			  printf("Element not found\n");
		  }
	}
	

