#include <stdio.h>
#include <stdlib.h>
struct node{
    int petrol;
    int dis;
    struct node *next;
};
struct node *head;
void Create(int n)
{
    int i,p,d;
    struct node *prevNode,*newNode;
    if(n>=1)
    {
        head=(struct node *)malloc(sizeof(struct node));
        printf("enter the petrol in first petrol pump\n");
        scanf("%d",&p);
        printf("enter the distance to next petrol pump\n");
        scanf("%d",&d);
        head->petrol=p;
        head->dis=d;
        head->next=NULL;
        prevNode =head;
        for(i=2;i<=n;i++)
        {

            newNode=(struct node *)malloc(sizeof(struct node));
            printf("enter the petrol in %d petrol pump\n",i);
        scanf("%d",&p);
        printf("enter the distance to next petrol pump\n");
        scanf("%d",&d);
        newNode->petrol=p;
        newNode->dis=d;
        newNode->next=NULL;
        prevNode->next=newNode;
        prevNode=newNode;
        }
        prevNode->next=head;
    }
}
void display()
{
    printf("Petrol \t\t\tDistance\n\n");
    struct node *current;

    if(head==NULL)
        printf("No petrol pumps\n");
    else{
        current=head;
        do{
            printf("%d\t\t\t%d\n\n",current->petrol,current->dis);
            current=current->next;

        }while(current!=head);
}
}
void calc(int n)
{
    int i=1;int tank,cd=0;
    struct node *current;
    struct node *temp;
    temp=head;

    int sumpetrol=0;
    int total=0;
    if(head==NULL)
        printf("No petrol pumps\n");
    else{
        current=head;
        do{
            sumpetrol+=current->petrol;
            total+=current->dis;
            current=current->next;

        }while(current!=head);
    }
        if(sumpetrol<total)
            printf("NO petrol pump available\n");
        else{
            while(i<=n)
            {

                current=temp;
                tank=current->petrol;
                do
                {

                   cd+=current->dis;
                   if(tank<(current->dis))
                    break;
                   else{
                   tank=tank-current->dis;
                   current=current->next;
                   tank+=current->petrol;
                   }

                }while(current!=temp);
                if(cd==total)
                {
                    printf("Petrol pump no. %d can be used as starting point\n",i);
                }

                    cd=0;
                    temp=temp->next;
                i++;
                }
            }

        }



void main()
{
    int choice=1;int n;

    while(choice!=0)
    {
        printf("Press 1. to add petrol pumps\nPress 2. to display the list\nPress 3. to find out the correct petrol pump\nPress 0. To exit\n");
        printf("Enter choice\n");
    scanf("%d",&choice);
        switch(choice)
    {

    case 1:
        printf("Enter the no. of petrol pumps\n");
        scanf("%d",&n);
        Create(n);
        break;
    case 2:
        display();
        break;
    case 3:
        calc(n);
        break;
    case 0:
        break;

    }
}
}

