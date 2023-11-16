#include<stdio.h>
int s[100],top=0,size=5;
void main()
{
	void push(int);
	int pop();
	void disp();
	int ch,val;
	
	do{
		printf("\n\t\t M E N U\n 1. PUSH\n 2. POP \n 3. DISPLAY\n 4. EXIT\n");
		printf("Enter one option from above menu\n");
		scanf("%d",&ch);
		switch(ch)
			{
			 	case 1: printf("enter value to be push\n");
			 			scanf("%d",&val);
			 			push(val);
			 			break;
			 	case 2: val=pop();
			 			if(val==-1)
			 				printf("Stack is underflow\n");
			 			else
			 				printf("deleted element is %d",val);
			 			break;
			 	case 3: disp();
			 			break;
			}
		}while(ch!=4);
 }
	void push(int ele)
	{
		
		if(size==top)
		  printf("Stack is overflow\n");
		  
		else
		  {
		  	s[top++]=ele;
		  	printf("element is inserted");

		  }
	}
	
	int pop()
	{
		if(top==0)
			return(-1);
		else
			{
				top--;
				return(s[top]);
			}
	}
	void disp()
	{
		int i;
		if(size==0)
		  printf("stack is empty\n");
		else
		{
			printf("stack data is \n");
			 for(i=top-1;i>=0;i--)
			  printf("%d ",s[i]);
		}
	}

