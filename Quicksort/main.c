#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int sumcount=0;int pass=1;
void quickSort(int arr[], int low, int high,int size)
{

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high,size);
        quickSort(arr, low, pi - 1,size);
        quickSort(arr, pi + 1, high,size);
    }

}
/* The partition function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high,int size)
{

    int j;
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int temp;int count=0;
    printf("Pass no is %d\n",pass++);
    printf("Initial array is\n");
    printArray(arr,size);
    printf("\n");
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            count++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            //swap(&arr[i], &arr[j]);
        }
    }
    sumcount+=count+1;
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    printf("The pivotal element was %d and it is placed at the %d position after %d swaps (%d internal and 1 external)\n",pivot,i+2,count+1,count);
    printf("Array after partitioning is \n");
    printArray(arr,size);
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n");
    return (i + 1);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ",arr[i]);
}
void main()
{
    int n;int i;
    printf("Enter the no. of elements to be sorted\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    clock_t start1, end1;
    double cpu_time_used1;
    start1 = clock();
    quickSort(a,0,n-1,n);
    cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("Total number of swaps required are = %d\n",sumcount);
    printf("The time taken by the quicksort algorithm to execute is %lf\n",cpu_time_used1);
    printf("The sorted array is as follows:-\n");
    printArray(a,n);
}

