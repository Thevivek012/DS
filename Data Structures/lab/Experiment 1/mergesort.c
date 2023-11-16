#include<stdio.h>
int n;
int main()
{
			int i, arr[100];
	void MergeSort(int a[], int low, int high);
	void merge(int [], int , int , int );

	printf("\nEnter the number of data element to be sorted: ");
	scanf("%d",&n);
 	for(i = 0; i < n; i++)
	{
		printf("Enter element %d ",i+1);
		scanf("%d",&arr[i]);
	}
 
	MergeSort(arr, 0, n-1);
 

	printf("\nSorted Data \n");
	for (i = 0; i < n; i++)
        printf("%d ",arr[i]);
 
	return 0;
}
void merge(int a[], int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[n];
	i = low;
	k = low;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i];
	}
}
void MergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(int)(low+high)/2;// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 		merge(a,low,high,mid);
	}
}


 


 

