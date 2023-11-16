#include<stdio.h>


void main()
{
	int a[100],n,i;
	void input(int a[],int n);
	void output(int a[],int n);
	int split(int a[],int lb,int ub);
	void quick(int a[],int lb,int ub);
	printf("enter how many elements \n");
	scanf("%d",&n);
	
		printf("enter array elements\n");
		for(i=0;i<n;i++)
	  		scanf("%d",&a[i]);
		
		quick(a,0,n-1);
		
		printf("sorted array elements are\n");
	    for(i=0;i<n;i++)
	       printf("%d ",a[i]);	
}




void quick(int a[100],int lower, int upper)
{
	if ( upper > lower )
	{
		int sp = split (a,lower,upper ) ;
		quick(a,lower, sp - 1 ) ;
		quick(a,sp + 1, upper ) ;
	}
}
int split( int a[100], int lower, int upper )
{
	int i, p, j, t ;
 	i = lower + 1 ;
	j = upper ;
	p = a[lower] ;
	while (j>=i)
	{
		while ( a[i] <= p )
			i++;
		while ( a[j] > p )
			j-- ;
		if ( j > i )
		{
			t    = a[i] ;
			a[i] = a[j] ;
			a[j] = t ;
		}
	}
	t = a[lower];
	a[lower] = a[j];
	a[j] = t;
	return j;
}
