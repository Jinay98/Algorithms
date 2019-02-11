/*Name:Jinay Parekh
Batch :C Roll NO:46*/
#include<stdio.h>
void main()
{
    int n,m;
    int k;
    printf("Enter the length of the text\n");
    scanf("%d",&n);
    printf("Enter the length of the pattern\n");
    scanf("%d",&m);
    if(m>n)
    {
        printf("The pattern size is greater than the text size\n");
    }
    else
    {
        char p[m];
        int f[m];
        f[0]=0;
        char t[n];
        printf("Enter the Text\n");
        scanf("%s",t);
        printf("Enter the Pattern\n");
        scanf("%s",p);
        printf("pattern is %s\n",p);
        printf("text is %s\n",t);
        int i=1;
        int j=0;
        while(i<m)
        {
            if(p[j]==p[i])
            {
                f[i]=j+1;
                i++;
                j++;
            }
            else if(j>0)
            {
                j=f[j-1];
            }
            else
            {
                f[i]=0;
                i++;
            }
        }
        printf("The failure function is as follows\n");
        for(k=0;k<m;k++)
        {
            printf("%c  -->  %d\n",p[k],f[k]);
        }
        int a=0;int b=0;int flag=-1;
        while(a<n)
        {
            if(p[b]==t[a])
            {
                if(b==m-1)
                {
                    printf("Pattern matching started at index %d\n",(a-m+1));
                    flag=1;
                    break;
                }
                a++;
                b++;

            }
            else if(b>0)
                b=f[b-1];
            else
                a++;
        }
        if(flag!=1)
            printf("There is no pattern match\n");
    }
}
/*Output:-
1.)
Enter the length of the text
11
Enter the length of the pattern
6
Enter the Text
aaabaabaaab
Enter the Pattern
aabaaa
pattern is aabaaa
text is aaabaabaaab
The failure function is as follows
a  -->  0
a  -->  1
b  -->  0
a  -->  1
a  -->  2
a  -->  2
Pattern matching started at index 4

2.)
Enter the length of the text
2
Enter the length of the pattern
4
The pattern size is greater than the text size

3.)
Enter the length of the text
6
Enter the length of the pattern
3
Enter the Text
abcdef
Enter the Pattern
abx
pattern is abx
text is abcdef
The failure function is as follows
a  -->  0
b  -->  0
x  -->  0
There is no pattern match
*/

