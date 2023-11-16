#include<stdio.h>
int q[100],front=0,rear=0,size=5;
void main()
{
	void insert(int);
	int delete();
	void disp();
	int ch,val;
	
	do{
		printf("\n\t\t M E N U\n 1. Insert\n 2. Delete \n 3. Display\n 4. Exit\n");
		printf("Enter one option from above menu\n");
		scanf("%d",&ch);
		switch(ch)
			{
			 	case 1: printf("enter value to be push\n");
			 			scanf("%d",&val);
			 			insert(val);
			 			break;
			 	case 2: val=delete();
			 			if(val==-1)
			 				printf("Queue is underflow\n");
			 			else
			 				printf("deleted element is %d",val);
			 			break;
			 	case 3: disp();
			 			break;
			}
		}while(ch!=4);
 }
	void insert (int ele)
	{
		
		if(size==rear)
		  printf("Queue is overflow\n");
		else
		  {
		  	q[rear++]=ele;
		  	printf("element is inserted");
		  }
	}
	
	int delete()
	{
		int ele;
		if(front==rear)
			return(-1);
		else
			{
				ele=q[front];
				front++;
				return(ele);
			}
	}
	
	void disp()
	{
		int i;
		if(rear==front)
		  printf("Queue is empty\n");
		else
		{
			printf("Queue data is \n");
			 for(i=front;i<rear;i++)
			  printf("%d ",q[i]);
		}
	}

