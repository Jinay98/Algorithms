#include<stdio.h>
struct tree
{
    char data;
    struct tree *left,*right;
};
struct tree *STACK[20];
struct tree *node;
char stack[20];
char post[20];
int top = -1;
int i;
int TOP=-1;
    void PUSH(struct tree* node)
        {
            STACK[++TOP]=node;
        }

    struct tree * POP()
        {
            return(STACK[TOP--]);
        }
    int check(char ch)
        {
            if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
            return 2;
            else
            return 1;
        }
    void operand(char b)
        {
            node=(struct tree*)malloc(sizeof(struct tree));
            node->data=b;
            node->left=NULL;
            node->right=NULL;
            PUSH(node);
        }
    void operators(char a)
        {
            node=(struct tree*)malloc(sizeof(struct tree));
            node->data=a;
            node->right=POP();
            node->left=POP();
            PUSH(node);
        }
    void inorder(struct tree *node)
        {
            if(node!=NULL)
                {
                    inorder(node->left);
                    printf("%c",node->data);
                    inorder(node->right);
                }
        }
    void push(char x)
        {
            printf("PUSHING%c\n",x);
            stack[++top] = x;
        }

    char pop()
        {
            if(top == -1)
            return -1;
            else
            {
                printf("POPPING%c\n",stack[top]);
                return stack[top--];
            }

        }
    int priority(char x)
        {
            if(x == '(')
                return 0;
            if(x == '+' || x == '-')
                return 1;
            if(x == '*' || x == '/')
                return 2;
            if(x=='^')
                return 3;
        }
    int digit(char c)
        {
            if(c>='0'&&c<='9')
                return 1;
            else
                return 0;
        }
    void main()
        {
            char e[20];char x;
            int p;
            printf("Enter the infix expression ::\n ");
            scanf("%s",e);
            int count=0;
            int m=0;
            int j=0;
            printf("The stack operations are as follows:-\n");
            while( e[count]!= '\0')
            {
                if(digit(e[count]))
                {
                    post[m]=e[count];
                    m++;
                }
                else if(e[count] == '(')
                    push(e[count]);
                else if(e[count] == ')')
                {
                while((x = pop()) != '(')
                    {
                        post[m]=x;
                        m++;
                    }
                }
                else
                {
                    while(priority(stack[top]) >= priority(e[count]))
                    {
                        char a=pop();
                        post[m]=a;
                        m++;
                    }
                    push(e[count]);
                }
                count++;
            }
    while(top != -1)
    {
        char b=pop();
        post[m]=b;
        m++;
    }
    printf("the postfix expression is as follows\n");
    while(post[j]!='\0')
    {
        printf("%c",post[j]);
        j++;
    }
    for(i=0;post[i]!='\0';i++)
    {
        p=check(post[i]);
        if(p==1)
            operand(post[i]);
        else if(p==2)
            operators(post[i]);
    }
    printf("\nThe inorder traversal of the tree is as follows \n");
    inorder(STACK[TOP]);
}
