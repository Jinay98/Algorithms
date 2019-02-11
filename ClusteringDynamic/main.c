#include <stdio.h>
#include <stdlib.h>
struct store
{
    int value;
    int index;
};
int minCost(int a[], int n, int k,struct store obj[n+1][k+1])
{
        int i,j,m;int min=9999;

        for (i = 0; i <= n; i++)
            for (j = 0; j <= k; j++)
                {
                    obj[i][j].value=9999;
                }
        obj[0][0].value=0;
        for (j = 1; j <= k; j++)
        {
            for (i = 1; i <= n; i++)
            {
                min=9999;
                int index=0;
                for(m=i;m>0;m--)
                {
                    int temp = obj[m-1][j-1].value + ((a[i]-a[m])*(a[i]-a[m]));
                    if(temp < min){
                        min = temp;
                        index = m;
                    }
                    else if(temp==min){
                        index = m;
                    }
                }
                obj[i][j].value=min;
                obj[i][j].index=index;
            }
        }
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= k; j++)
            {
                printf("%d\t",obj[i][j].value);
            }
            printf("\n");
        }
        printf("\n");
        int y = k;
        int x = n;
        int z=0;
        int al[k+1];
        while(x!=0){
            al[z++]=obj[x][y].index;
            x = obj[x][y].index - 1;
            y--;
        }

        sort(al,k+1);

        printf("The Clusters are :\n");

        int p=0;
        for(i = 1;i<n+1;i++,p++){

            if(search(al,k+1,i)==1)
            {
                printf(" |  ");
            }
            printf("%d  ",a[i]);
        }
        printf("\n\n");
        return obj[n][k].value;
    }

void sort(int a[],int n)
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }

}
int search(int a[],int n,int x)
{
    int flag=-1;int i;
    for(i=1;i<n;i++)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }
    return flag;

}
int main()
{
    int n,i,k,j;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements of the array\n%");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number of partitions\n");
    scanf("%d",&k);
    struct store obj[n+1][k+1];
    printf("The Minimum cost is %d",(minCost(a, n, k,obj)));
}
/*Output:-
Enter the number of elements in the array
4
Enter the elements of the array
1 5 8 10
Enter the number of partitions
2
0       9999    9999
9999    0       9999
9999    16      0
9999    49      9
9999    81      20

The Clusters are :
1  5   |  8  10

The Minimum cost is 20
----------------------------------------------------------------------------
Enter the number of elements in the array
7
Enter the elements of the array
1 2 8 9 3 6 5
Enter the number of partitions
4
0       9999    9999    9999    9999
9999    0       9999    9999    9999
9999    1       0       9999    9999
9999    49      1       0       9999
9999    64      2       1       0
9999    4       1       2       1
9999    25      4       1       2
9999    16      5       2       1

The Clusters are :
1   |  2  8  9  3   |  6   |  5

The Minimum cost is 1
-------------------------------------------------------------------------------------
Enter the number of elements in the array
8
Enter the elements of the array
2 4 6 7 8 11 13 14
Enter the number of partitions
4
0       9999    9999    9999    9999
9999    0       9999    9999    9999
9999    4       0       9999    9999
9999    16      4       0       9999
9999    25      5       1       0
9999    36      8       4       1
9999    81      29      8       4
9999    121     40      12      8
9999    144     45      17      9

The Clusters are :
2  4   |  6  7  8   |  11   |  13  14

The Minimum cost is 9
*/
