/*Name:Jinay Parekh
Batch :C Roll no:46*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct data
{
    int s;
    int d;
    int w;
};
struct node{
int so;
int des;
int we;

};

void prims(int n,int array[n][n],int source,int answer[n][n],bool visited[n])
{
    int count=0,j,min,counter,i;
    int weight=0;
    int mincol=0;
    while(count<n)
    {    min=999;
        for(counter=0;counter<n;counter++)
        {
            if(visited[counter]==true)
            {
                for(j=0;j<n;j++)
                    {
                        if(array[counter][j]<min && visited[j]==false  && array[counter][j]>0)
                        {
                            min=array[counter][j];
                            mincol=j;
                            source=counter;
                        }
                   }
            }
        }
                printf("The edge considered is from %d to %d\n",source,mincol);
                printf("The minimum weight is %d\n",min);
                answer[source][mincol]=array[source][mincol];
                answer[mincol][source]=array[mincol][source];
                visited[mincol]=true;
                count++;
        }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            weight+=answer[i][j];
        }
    }
    printf("\nThe cost of the  minimum spanning tree is %d\n",weight/2);

}
void krus(int n,int a[n][n],int no[n],struct node obj[n])
{
    int temp[n][n];
    int i,j;int index=0;struct node c;
    int count=0;int mst=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            temp[i][j]=a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(temp[i][j]>0)
            {
                obj[index].so=i;
                obj[index].des=j;
                obj[index].we=temp[i][j];
                index++;count++;
                temp[j][i]=0;temp[i][j]=0;
            }
        }
    }

    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(obj[j].we>obj[j+1].we)
            {
                c=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=c;            }
        }
    }

    for(i=0;i<count;i++)
    {
        if(no[obj[i].so]==no[obj[i].des]&&!(no[obj[i].so]==999&&no[obj[i].des]==999))
          {
              printf("We are REJECTING the edge from %d to %d having wt %d as it forms a cycle\n",obj[i].so,obj[i].des,obj[i].we);
          }
        if(no[obj[i].so]==999&&no[obj[i].des]==999)
            {
                printf("We are selecting the edge from %d to %d having wt %d\n",obj[i].so,obj[i].des,obj[i].we);
                mst+=obj[i].we;
                no[obj[i].so]=i+1;
                no[obj[i].des]=i+1;

            }
          if(no[obj[i].so]!=no[obj[i].des])
          {
                printf("We are selecting the edge from %d to %d having wt %d\n",obj[i].so,obj[i].des,obj[i].we);
                mst+=obj[i].we;
                for(j=0;j<n;j++)
                {
                    if(no[j]==no[obj[i].des]&&(j!=obj[i].des)&&no[j]!=999)
                    {
                        no[j]=i+1;

                    }
                }
                no[obj[i].des]=i+1;
                for(j=0;j<n;j++)
                {
                    if(no[j]==no[obj[i].so]&&(j!=obj[i].so)&&no[j]!=999)
                    {
                        no[j]=no[obj[i].des];

                    }
                }
                no[obj[i].so]=i+1;
        }
    }
    printf("Cost of the Minimum Spanning Tree is %d\n",mst);
}
void main()
{
    int n,i,j,sc;
    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    struct data obj[n*n];
    struct node obj1[n*n];
    int answer[n][n];
    bool visited[n];
    int a[n][n];int no[n];
    for(i=0; i<n; i++)
    {
        no[i]=999;
        visited[i]=false;
        for(j=0; j<n; j++)
        {
            answer[i][j]=0;
            printf("enter the weight of node if it is connect from %d to %d else enter 0\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    int ch=0;
    while(ch!=3)
    {
        printf("1.PRIMS METHOD\n");
        printf("2.KRUSKAL METHOD\n");
        printf("3.EXIT\n");
        printf("ENTER CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the source node\n");
                scanf("%d",&sc);
                prims(n,a,sc,answer,visited);
                break;
            case 2:
                krus(n,a,no,obj1);
                break;
            case 3:
                break;
            default:
                printf("Wrong input try again\n");
        }
    }
}

/*Output:
1.)
0       3       1       6       0       0
3       0       5       0       3       0
1       5       0       5       6       4
6       0       5       0       0       2
0       3       6       0       0       6
0       0       4       2       6       0
1.PRIMS METHOD
2.KRUSKAL METHOD
3.EXIT
ENTER CHOICE
1
Enter the source node
0
The edge considered is from 0 to 0
The minimum weight is 999
The edge considered is from 0 to 2
The minimum weight is 1
The edge considered is from 0 to 1
The minimum weight is 3
The edge considered is from 1 to 4
The minimum weight is 3
The edge considered is from 2 to 5
The minimum weight is 4
The edge considered is from 5 to 3
The minimum weight is 2

The cost of the  minimum spanning tree is 13
1.PRIMS METHOD
2.KRUSKAL METHOD
3.EXIT
ENTER CHOICE
2
We are selecting the edge from 0 to 2 having wt 1
We are selecting the edge from 3 to 5 having wt 2
We are selecting the edge from 0 to 1 having wt 3
We are selecting the edge from 1 to 4 having wt 3
We are selecting the edge from 2 to 5 having wt 4
We are REJECTING the edge from 1 to 2 having wt 5 as it forms a cycle
We are REJECTING the edge from 2 to 3 having wt 5 as it forms a cycle
We are REJECTING the edge from 0 to 3 having wt 6 as it forms a cycle
We are REJECTING the edge from 2 to 4 having wt 6 as it forms a cycle
We are REJECTING the edge from 4 to 5 having wt 6 as it forms a cycle
Cost of the Minimum Spanning Tree is 13

2.)
0       2       0       6       0
2       0       3       8       5
0       3       0       0       7
6       8       0       0       9
0       5       7       9       0
1.PRIMS METHOD
2.KRUSKAL METHOD
3.EXIT
ENTER CHOICE
1
Enter the source node
4
The edge considered is from 4 to 0
The minimum weight is 999
The edge considered is from 0 to 1
The minimum weight is 2
The edge considered is from 1 to 2
The minimum weight is 3
The edge considered is from 1 to 4
The minimum weight is 5
The edge considered is from 0 to 3
The minimum weight is 6

The cost of the  minimum spanning tree is 16
1.PRIMS METHOD
2.KRUSKAL METHOD
3.EXIT
ENTER CHOICE
2
We are selecting the edge from 0 to 1 having wt 2
We are selecting the edge from 1 to 2 having wt 3
We are selecting the edge from 1 to 4 having wt 5
We are selecting the edge from 0 to 3 having wt 6
We are REJECTING the edge from 2 to 4 having wt 7 as it forms a cycle
We are REJECTING the edge from 1 to 3 having wt 8 as it forms a cycle
We are REJECTING the edge from 3 to 4 having wt 9 as it forms a cycle
Cost of the Minimum Spanning Tree is 16
*/

