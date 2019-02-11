#include<stdio.h>
void main()
{
    int n,m,i,j;
    printf("Enter the length of first string\n");
    scanf("%d",&n);
    printf("enter the length of the second string\n");
    scanf("%d",&m);
    char x[n+1];
    char y[m+1];
    printf("Enter the first string\n");
    for(i=1;i<=n;i++)
        scanf(" %c",&x[i]);
    for(i=1;i<=n;i++)
        printf("%d------------->%c\n",i,x[i]);
    printf("enter the second string\n");
    for(i=1;i<=m;i++)
        scanf(" %c",&y[i]);
    int a[n+1][m+1];
    int d[n+1][m+1];
    for(i=0;i<=n;i++)
        {
            a[i][0]=0;
            d[i][0]=0;
        }

    for(i=0;i<=m;i++)
        {
            a[0][i]=0;
            d[0][i]=0;
        }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                a[i][j]=a[i-1][j-1]+1;
                d[i][j]=3;
            }
            else
            {
                if(a[i-1][j]>=a[i][j-1])
                    {
                        a[i][j]=a[i-1][j];
                        d[i][j]=2;
                    }
                else
                    {
                        a[i][j]=a[i][j-1];
                        d[i][j]=1;
                    }
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    char ans[n];
    int index=0;
    for(i=1;i<=n;i++)
        printf("%d------------->%c\n",i,x[i]);
    i=n;
    j=m;
    //ans[index++]=x[i];
    while(j>0)
    {
        if(d[i][j]==1)
        {
            printf("j oldvalue is %d\n",j);
            j=j-1;
            printf("j newvalue is %d\n",j);
        }
        if(d[i][j]==2)
            {
                printf("i oldvalue is %d\n",i);
                i=i-1;
                printf("i newvalue is %d\n",i);
            }

        if(d[i][j]==3)
        {
            printf("i value is %d\n",i);
            printf("%c  is selected\n",x[i]);
            ans[index++]=x[i];
            i=i-1;
            j=j-1;
        }
    }
    for(i=index-1;i>=0;i--)
        printf("%c\t",ans[i]);
}
