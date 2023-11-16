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
	int key,ch;
	void create();
	void display();
	void rev_display();
	void search(int);
	do
	{
		printf("M E N U\n1. CREATE \n");
		printf("2.DISPLAY\n3.Reverse DISPLAY\n 4.SEARCH\n5.EXIT\n");
		
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2:	display();
					break;
			case 3:rev_display();
					break;
			case 4: 
					printf("Enter value to be search\n");
					scanf("%d",&key);
					search(key);
					break;
		}
	}while(ch!=5);
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
	void rev_display()
	{
		slnode *temp;
		int s[100],i,top=0;
		temp=start;
		while(temp!=NULL)
		  {
		  	s[top++]=temp->data;
		  	temp=temp->next;
		  }
		printf("List elements in revese order is \n");
		for(i=top-1;i>=0;i--)
		  printf("%d ",s[i]);
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
	

