#include<stdio.h>
void main()
{
	int n,i,j,ele,s;
	int fact(int);
	
	printf("enter number of rows req");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  {
	  	for(s=0;s<=40-2*i;s++)
	  	  printf(" ");
	  	for(j=0;j<=i;j++)
	  	  {
	  	  	ele=fact(i)/(fact(i-j)*fact(j));
	  	  	printf("%4d",ele);
			}
			printf("\n");
	  }
}
int fact(int x)
  {
  	if(x<=0)
  	  return(1);
  	else
  	  return(x*fact(x-1));
  }
