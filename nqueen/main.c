#include<stdio.h>
#include<math.h>
int count;
int main()
{
 int n,i,j;
printf("Enter number of Queens:\n");
 scanf("%d",&n);
 int board[n*(n+1)];
 queen(1,n,board);

}
//function for printing the solution
void print(int n,int board[])
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);

 for(i=1;i<=n;i++)
  printf("\t%d",i);

 for(i=1;i<=n;i++)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)
  {
   if(board[i]==j)
    printf("\tQ");
   else
    printf("\t-");
  }
 }
}

/*funtion to check if queen is placed at correct position checking diagonal and same column
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column,int board[])
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column){
        //printf("row no %d is in the same column\n",i);
    return 0;
  }

  else
   if(abs(board[i]-column)==abs(i-row))
    {
        //printf("row %d is in the same diagonal\n",i);
        return 0;
    }
 }

 return 1;
}

//function which places the queen on the board and does the backtracking as well
void queen(int row,int n,int board[])
{
 int column;
 for(column=1;column<=n;++column)
 {

  if(place(row,column,board))
  {
   board[row]=column;
   if(row==n)
    {
        print(n,board);
    }
   else
   {//try queen with next position
       queen(row+1,n,board);
   }
  }
 }
}
/*Output:-
Enter number of Queens:
4
Solution 1:

        1       2       3       4

1       -       Q       -       -

2       -       -       -       Q

3       Q       -       -       -

4       -       -       Q       -

Solution 2:

        1       2       3       4

1       -       -       Q       -

2       Q       -       -       -

3       -       -       -       Q

4       -       Q       -       -*/


