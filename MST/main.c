#include <stdio.h>
struct data
{
	int v;
	int cp;
	int fp;
	int w;
};
int c[100];int vis[10][10]={0};
int min(struct data obj[],int n,int b[],int count)
{
    int i;
    int index;
    int min=100;
    int k=0;int count1=0;int j=0;

    for(i=0;i<count; i++)
    {

    count1++;

        if(min>b[i]&&vis[k][j]!=1&&b[i]!=0)/*&&(!search(c,i,n))*///&&obj[i].v!=1)
        {
            min=b[i];
            index=i;
            printf("HI%d  %d  %d %d\n",min,vis[k][j],k,j);

        }
        j++;

        if(count1%n==0)
            {
                k++;
                j=0;

            }
    }
    if(index<=n)
    {
        vis[k-1][index]=1;
        return index;

    }

    else
        {

            vis[k-1][index%n]=1;

            printf("GOing in else\n");

            return (index%n);
        }
}


void main()
{
    int n,i,j,sc,minind,minind1,val,k;
    printf("Enter the no. of nodes\n");
    scanf("%d",&n);
    struct data obj[n];
    int a[n][n];
    int b[n*n];



    int x=0;int y=0;
    for(i=0; i<n*n; i++)
    b[i]=999;


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
        for(j=0; j<n; j++)
        {
            printf("enter the weight of node if it is connect from %d to %d else enter 0\n",i,j);
            printf("%d",a[i][j]);
	   }
	   printf("\n");
	}

	printf("Enter the source index");
	scanf("%d",&sc);
	c[x++]=sc;




	int count=0;

		for(i=0;i<n;i++)
		{

			b[count]=a[sc][i];
			printf("Source value is %d\n",b[count]);
			count++;
		}
		minind=min(obj,n,b,count);
		c[x++]=minind;
        count=minind*n;
        printf("Min ind is %d\n",minind);
        for(i=0; i<n; i++)
            for(j=0;j<n;j++)
        {
            if(vis[i][j]==1)
                vis[j][i]=1;
            printf("Visited status of %d%d is %d\n",i,j,vis[i][j]);
        }
		for(j=0;j<n-1;j++)
		{
			for(i=0;i<n;i++)
			{

			b[count]=a[minind][i];
			printf(" After that %d\n",b[count]);
			count++;
			}
			if(count==n*n-1)
			break;

			minind=min(obj,n,b,count);
			c[x++]=minind;
			count=minind*n;
			printf("Min ind outside if is %d\n",minind);







         for(i=0; i<n; i++)
            for(k=0;k<n;k++)
        {
            if(vis[i][k]==1)
                vis[k][i]=1;
            printf("Visited status of %d%d is %d\n",i,k,vis[i][k]);
        }
     }
     for(i=0; i<n*n; i++)
        printf("%d\n",b[i]);

        printf("PAth is\n");
        for(i=0; i<n; i++)
            printf("%d- - - -",c[i]);


}
