#include<stdio.h>
#include<time.h>
void Selection(int a[],int n){
    clock_t start1, end1;
    double cpu_time_used1;
    start1 = clock();
    int i;int j;int k;
    int min;int temp;
    int count=0;
    int count1;
    printf("SELECTION SORT\n");
    for(i=0;i<n-1;i++)
    {
        min=i;
        count1=0;
        for(j=i+1;j<n;j++)
        {

            if(a[j]<a[min])
            {
                min=j;
                count++;
                count1++;
            }
        }
        printf("No. of swaps in iteration no. %d is=%d\n",i+1,count1);
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        for(k=0;k<n;k++)
        {
            printf("%d ",a[k]);
        }
        printf("   Is Array after iteration no %d\n",i+1);
    }
    printf("Sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);

    }
    printf("\nTotal number of comparisions in Selection sort is=%d\n",count);
    end1 = clock();
    cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("The time taken by the function-Selection Sort to execute is %lf\n  ",cpu_time_used1);
    printf("\n-----------------------------------------------------\n");
}
void insertionSort(int arr[], int n)
{
    clock_t start2, end2;
    double cpu_time_used2;
    start2 = clock();
    printf("\nINSERTION SORT\n");
    int i, key,k,j;int count=0;int temp=0;int count1;
    for (i = 1; i < n; i++)
    {
       count1=0;
       key = arr[i];
       j = i-1;
       while (j >= 0&& arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           count1++;
           count++;
       }
       arr[j+1] = key;
       printf("No. of comparisions in iteration no. %d is=%d\n",i,count1);
       for(k=0;k<n;k++)
        {
            printf("%d ",arr[k]);
        }
        printf("   Is Array after iteration no %d\n",i);

    }
    printf("Sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nTotal No. of comparisions in insertion is=%d\n",count);
    end2 = clock();
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("The time taken by the function-Insertion Sort to execute is %lf\n",cpu_time_used2);
}
void main()
{
    int n;int i;
    printf("Enter the no. of elements to be sorted\n");
    scanf("%d",&n);
    int a[n];int b[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
        b[i]=a[i];
    Selection(a,n);
    insertionSort(b,n);
}
