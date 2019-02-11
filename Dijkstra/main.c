#include<stdio.h>
struct data
{
    int lv;
    int fv;
    int lw;
    int fw;
    int flag;
};
int min(struct data obj[],int n)
{
    int i;
    int index;
    int min=100;

    for(i=0;i<n; i++)
    {
        if(min>obj[i].lw&&obj[i].flag!=1)
        {
            min=obj[i].lw;
            index=i;
        }
    }
    return index;
}
void main()
{
    int n,i,j,sc,minind,val,temp,sc1;
    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    struct data obj[n];
    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("enter the weight of node if it is connect from %d to %d else enter 0\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        obj[i].flag=0;
        obj[i].fw=999;
        obj[i].fv=999;
        for(j=0; j<n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source node index\n");
    scanf("%d",&sc);
    sc1=sc;
    obj[sc].flag=1;
    obj[sc].fw=123;
    obj[sc].fv=123;
    printf("Node index\tVia\tCurrent Weight\n");
    for(i=0;i<n;i++){
        if(a[sc][i]==0)
        {
            obj[i].lw=123;
            obj[i].lv=123;
        }
        else
        {
            obj[i].lw=a[sc][i];
            obj[i].lv=sc;
        }
        printf("%d         \t%d  \t%d\n",i,obj[i].lv,obj[i].lw);
    }
    minind=min(obj,n);
    printf("Minimum index is %d\n",minind);
    val=obj[minind].lw;
    obj[minind].fw=val;
    obj[minind].fv=sc;
    printf("Minimum Value is %d\n",val);
    obj[minind].flag=1;
    int count=2;
    printf("\nNode index\tVia\tCurrent Weight\n");
    for(i=0;i<n-1;i++)
        {
            sc=minind;
            for(j=0; j<n; j++)
            {
                temp=a[sc][j];
                if((sc!=j)&&(obj[j].flag!=1)&&(a[sc][j]!=0))
                {
                    if((temp+obj[sc].fw)<obj[j].lw)
                       {
                            obj[j].lw=temp+obj[sc].fw;
                            obj[j].lv=sc;

                        }

                }
               printf("%d         \t%d  \t%d\n",j,obj[j].lv,obj[j].lw);

            }
                   minind=min(obj,n);
                   printf("Minimum index is %d\n",minind);
                   val=obj[minind].lw;
                   obj[minind].fw=val;
                   printf("Minimum Value is %d\n",val);
                   obj[minind].flag=1;
                   count++;
                if(count<n)
                    printf("\nNode index\tVia\tCurrent Weight\n");
                sc=minind;
                if(count==n)
                {
                    printf("\n---------------------------------\n");
                    printf("The shortest distance from the source node %d is given below\n",sc1);
                    printf("\nNode index\tVia\tCurrent Weight\n");
                    i=100;
                    j=100;
                }
            }
            for(i=0;i<n;i++)
            {
                obj[i].fv=obj[i].lv;

                if(obj[i].fv==123||obj[i].fw==123)
                    printf("%d         \t--  \t--\n",i);
                else
                    printf("%d         \t%d  \t%d\n",i,obj[i].lv,obj[i].lw);

            }

}
/*Output:
1.)Example 1
0       4       0       0       0       0       0       8       0
4       0       8       0       0       0       0       11      0
0       8       0       7       0       4       0       0       2
0       0       7       0       9       14      0       0       0
0       0       0       9       0       10      0       0       0
0       0       4       14      10      0       2       0       0
0       0       0       0       0       2       0       1       6
8       11      0       0       0       0       1       0       7
0       0       2       0       0       0       6       7       0
Enter the source node index
0
Node index      Via     Current Weight
0               123     123
1               0       4
2               123     123
3               123     123
4               123     123
5               123     123
6               123     123
7               0       8
8               123     123
Minimum index is 1
Minimum Value is 4

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               123     123
4               123     123
5               123     123
6               123     123
7               0       8
8               123     123
Minimum index is 7
Minimum Value is 8

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               123     123
4               123     123
5               123     123
6               7       9
7               0       8
8               7       15
Minimum index is 6
Minimum Value is 9

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               123     123
4               123     123
5               6       11
6               7       9
7               0       8
8               7       15
Minimum index is 5
Minimum Value is 11

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               5       25
4               5       21
5               6       11
6               7       9
7               0       8
8               7       15
Minimum index is 2
Minimum Value is 12

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               2       19
4               5       21
5               6       11
6               7       9
7               0       8
8               2       14
Minimum index is 8
Minimum Value is 14

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               2       19
4               5       21
5               6       11
6               7       9
7               0       8
8               2       14
Minimum index is 3
Minimum Value is 19

Node index      Via     Current Weight
0               123     123
1               0       4
2               1       12
3               2       19
4               5       21
5               6       11
6               7       9
7               0       8
8               2       14
Minimum index is 4
Minimum Value is 21

---------------------------------
The shortest distance from the source node 0 is given below

Node index      Via     Current Weight
0               --      --
1               0       4
2               1       12
3               2       19
4               5       21
5               6       11
6               7       9
7               0       8
8               2       14

2.) Example 2
0       0       13      0       16      8
0       0       0       6       0       10
13      0       0       14      0       11
0       6       14      0       5       17
16      0       0       5       0       7
8       10      11      17      7       0
Enter the source node index
0
Node index      Via     Current Weight
0               123     123
1               123     123
2               0       13
3               123     123
4               0       16
5               0       8
Minimum index is 5
Minimum Value is 8

Node index      Via     Current Weight
0               123     123
1               5       18
2               0       13
3               5       25
4               5       15
5               0       8
Minimum index is 2
Minimum Value is 13

Node index      Via     Current Weight
0               123     123
1               5       18
2               0       13
3               5       25
4               5       15
5               0       8
Minimum index is 4
Minimum Value is 15

Node index      Via     Current Weight
0               123     123
1               5       18
2               0       13
3               4       20
4               5       15
5               0       8
Minimum index is 1
Minimum Value is 18

Node index      Via     Current Weight
0               123     123
1               5       18
2               0       13
3               4       20
4               5       15
5               0       8
Minimum index is 3
Minimum Value is 20

---------------------------------
The shortest distance from the source node 0 is given below

Node index      Via     Current Weight
0               --      --
1               5       18
2               0       13
3               4       20
4               5       15
5               0       8
*/
