#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int count=0;int sumcount=0;int pass=1;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;int countl=0; int countr=0;
    /* create temp arrays */
    int L[n1], R[n2];
    printf("PASS NO%d\n",pass++);
    printf("Array before merging is\n");
    for(i=l;i<=m;i++){
        printf("%d ",arr[i]);
    }
    for(i=m+1;i<=r;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            countl++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            countr++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    sumcount+=countl+countr;
    printf("%d is the number of total comparisions from the left and right sub-arrays\n",countl+countr);
    printf("The array after merging is ");
    for(i=0;i<k;i++)
        {
            printf("%d ",arr[i]);
        }
    printf("\n----------------------------------------------------------------------------------\n");
}
void mergeSort(int arr[], int l, int r)
{
    int i;
    if (l < r)
    {
        count++;
        int m = l+(r-l)/2;
       // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
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
    mergeSort(a, 0,n-1);
    cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("The time taken by the mergesort algorithm to execute is %lf\n  ",cpu_time_used1);
    printf("\nTotal no of comparisons made in the array are %d\n",sumcount);
    printf("\nSorted array is \n");
    printArray(a,n);
}
