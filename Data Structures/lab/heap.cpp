#include <stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

class Heap
{
	
   int heap[20],size,n;
   public:
   	   Heap(int n);
   	   void insert();
       int deletemin();
       void findmin();
      void display();
	
};
 Heap::Heap(int n)
  {
  	n=n;
  	size=0;
  }
void Heap:: insert()
	{
	  int i,x;
	  if(size>n)
	    printf("heap is full");
	  else
	   {
		size++;
		printf("enter ele to insert:");
		scanf("%d",&x);
		for(i=size;heap[i/2]>x;i=i/2)
		  {
			heap[i]=heap[i/2];
		  }
			heap[i]=x;
		}
	}

	int Heap:: deletemin()
	{
	  int i=0,child,min,last;
	  if(size==0)
	    printf("heap is empty");
	  else
	   {
		min=heap[1];
		last=heap[size--];
		for(i=1;i*2<=size;i=child)
		  {
			child=i*2;
			if(child!=size&&heap[child+1]<heap[child])
			   child++;
			if(last>heap[child])
			   heap[i]=heap[child];
			else
				break;
		  }
		heap[i]=last;

        }
	 printf("min ele deleted successfully.....");
	 return min;
	}
	
	void Heap::findmin()
	{ 
	  if(size==0)
		printf("heap is empty");
	  else
		printf("min ele is %d",heap[1]);
	}
	
	void Heap::display()
	{
	  int i;
	  if(size==0)
		printf("heap is empty");
	  else
		for(i=1;i<=size;i++)
		printf("%d\t",heap[i]);
	}
	
   int main()
	{
	  int opt;
	  int n;
	  cout<<"enter size of the array";
	  cin>>n;
	  Heap h(n);
	  while(1)
	  {
		printf("\n1.insert\n2.deletemin\n3.display\n4.findmin\n5.exit\n");
		printf("enter ur choice");
		scanf("%d",&opt);
		switch(opt)
		  {
			case 1:
			        h.insert();
					break;
			case 2:
					printf("ele deleted is %d",h.deletemin());
					break;
			case 3:
					h.display();
					break;
			case 4:
					h.findmin();
					break;
			case 5:
					exit(0);
		  }
	   }
	 getch();
	}

	
