#include<string.h>
#include<stdio.h>
int n;
int pathExists=0;
int printVariable=0;
void DFS(int i,char c[][100],int adjmat[n][n],int n,int visit[n])
{
    int j;
    printf("%s\n",c[i]);
    visit[i]=1;

    for(j=0;j<n;j++)
    {
        if(!visit[j]&&adjmat[i][j]==1)
                    {
                        DFS(j,c,adjmat,n,visit);
                    }
    }
}
void checkDFS(int i,int n,int visit[n],int adjmat[n][n],int destcityid,char c[][100],int printer)
{
    int j;

    if(printVariable==0)
    {
          if(printer==1)
            printf("%s\n",c[i]);
    }
    visit[i]=1;

    if(i==destcityid-1)
        {
            pathExists=1;
            printVariable=1;
        }
    for(j=0;j<n;j++)
    {
        if(!visit[j]&&adjmat[i][j]==1)
            checkDFS(j,n,visit,adjmat,destcityid,c,printer);
    }
}

void bfs(int source,int visited[n],char c[][100],int adjmat[n][n],int n)
{
    int queue[10];
    int i, front, rear, root;
    front = rear = 0;
    visited[source] = 1;
    queue[rear++] = source;
    printf("%s\n",c[source]);
    while (front != rear)
    {
        root = queue[front];
        for (i = 0; i <n; i++)
            if (adjmat[root][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
                printf("%s\n",c[i]);
            }
        front++;
    }
}

void main()
{
    int choice=1;
    int sourcecityid=0,destcityid=0;

   int m;

	printf("Enter number of cities:\n");
	scanf("%d",&n);

	char c[n][100];

	char routeCities[n][100];

	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Enter city #%d:",i+1);
		scanf("%s",c[i]);
	}

	int adjmat[n][n];
	int visit[n];

	for(i=0;i<n;i++)
    {
        visit[i]=0;
    }

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			adjmat[i][j]=0;
		}
	}

	for(i=0;i<n;i++)
	{
		printf("Enter number of paths from city %s:",c[i]);
		int numberOfadjmat;
		scanf("%d",&numberOfadjmat);

		if(numberOfadjmat<=n-1)
		{
			for(j=0;j<numberOfadjmat;j++)
			{
				printf("Enter destination city number for route #%d for city %s:",j+1,c[i]);
				int destinationNumber;
				scanf("%d",&destinationNumber);

				if(destinationNumber-1==i)
				{
					printf("Please Note: Source and Destination cannot be same!\n");
					j--;
				}

				else if(destinationNumber>n)
				{
					printf("Caution: Enter a valid city number!\n");
					j--;
				}

				else
				{
					adjmat[i][destinationNumber-1]=1;
				}
			}
		}

		else
		{
			printf("Please Note: Only a maximum of %d paths are possible from any city!\n",n-1);
			i--;
		}
	}
    printf("The adjacency matrix is as follows:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",adjmat[i][j]);
		}

		printf("\n");
	}
	while(choice!=0)
    {
        printVariable=0;
    printf("Press 1.To display Depth First Traversal-DFS\n");
    printf("Press 2.To display Breadth First Traversal-BFS\n");
    printf("Press 3.To display any possible path between Source and Destination\n");
    printf("Press 0.To EXIT\n");
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter the number of the Starting Place \n");
            scanf("%d",&m);
            for(i=0;i<n;i++)
                visit[i]=0;
            DFS(m-1,c,adjmat,n,visit);
        }
         break;

        case 3:
            {
            printVariable=0;
            printf("Enter the number of the starting place\n");
            scanf("%d",&sourcecityid);
            printf("Enter the number of the destination\n");
            scanf("%d",&destcityid);
            for(i=0;i<n;i++)
            {visit[i]=0;
            }
            checkDFS(sourcecityid-1,n,visit,adjmat,destcityid,c,0);
            if(pathExists==1)
            {
                printf("Therefore a route is possible: \n");
                for(i=0;i<n;i++)
                {visit[i]=0;
                }
                printVariable=0;
                checkDFS(sourcecityid-1,n,visit,adjmat,destcityid,c,1);
                printf("\n");
            }
            else
            {
                printf("No route is possible\n\n");
            }
            pathExists=0;
            }
           break;

        case 2:
            {
            printf("Enter the number of the Starting Place \n");
            scanf("%d",&m);
            for(i=0;i<n;i++)
            visit[i]=0;
            bfs(m-1,visit,c,adjmat,n);
            }
            break;
        case 0:
            break;
       }
    }
}
