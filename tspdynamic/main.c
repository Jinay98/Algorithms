#include<stdio.h>
int mat[10][10];int v[10],n,cost=0;
inv=0;
void getmat()
{

    int i,j;
    printf("enter the no of cities\n");
    scanf("%d",&n);
    printf("\nEnter the matrix--------->\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter  distance of Row ;%d\n",i+1);
        for(j=0;j<n;j++)
        {

            scanf("%d",&mat[i][j]);
        }
       v[i]=0;
    }
    printf("\n\n Cost matrix is=\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            printf("%d\t",mat[i][j]);
        }
        printf("\n");

    }
}
void mincost(int city)
{

    int i,ncity;
    v[city]=1;
    printf("%d---->  ",city+1);
    ncity=least(city);
    if(ncity==999)
    {

        ncity=0;
        printf("%d ",ncity+1);
        cost+=mat[city][ncity];
        return;
    }
    mincost(ncity);
}
int least(int c)
{

    int i,nc=999;
    int min=999;
    int kmin;
    for(i=0;i<n;i++)
    {

        if((mat[c][i]!=0)&&(v[i]==0))
        {
            if(mat[c][i]+mat[i][c]<min)
            {

                min=mat[i][0]+mat[c][i];
                kmin=mat[c][i];
                nc=i;
                }
        }
    }
    if(min!=999)
        cost+=kmin;
    return nc;
}
void main()
{
    getmat();
    printf("Optimal pATH is  \n");
    mincost(inv);
    printf("Minimum cost is %d\n",cost);

}
