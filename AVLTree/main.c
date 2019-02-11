/*#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int ht;
};
struct node *RR(struct node *T);
struct node *LL(struct node *T);
struct node *LR(struct node *x);
struct node *RL(struct node *x);

struct node *insert(struct node *T,int x)
{
 if(T==NULL)
    {
        T=(struct node *)malloc(sizeof(struct node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)
        {
            T->right=insert(T->right,x);
            if(BF(T)==-2)
                {
                    if(x>T->right->data)
                    {
                        T=RR(T);
                        printf("B.F=-2 at the critical node\n");
                        printf("We use RightRight(RR) rotation\n");
                        printf("B.F after rotations\n");

                    }
                else
                    {
                        printf("B.F=-2 at the critical node\n");
                        T=RL(T);
                        printf("We use RightLeft(RL) rotation\n");
                        printf("B.F after rotations\n");
                    }
                }
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(BF(T)==2)
                {
                     if(x < T->left->data)
                        {
                            printf("B.F=2 at the critical node\n");
                            T=LL(T);
                            printf("We use LeftLeft(LL) rotation\n");
                            printf("B.F after rotations\n");
                        }
                    else
                        {
                            printf("B.F=2 at the critical node\n");
                            T=LR(T);
                            printf("We use LeftRight(LR) rotation\n");
                            printf("B.F after rotations\n");
                        }
                }
            }

        T->ht=height(T);

        return(T);

}
int height(struct node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    if(lh>rh)
        return(lh);

    return(rh);
}

int BF(struct node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    return(lh-rh);
}
void inorder(struct node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d (B.F=%d)-->",T->data,BF(T));
        inorder(T->right);
    }
}
struct node *rotateright(struct node *x)//used in LL rotations as right branch is modified
{
    struct node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
struct node *rotateleft(struct node *x)//used in RR rotations as left branch is modified
{
    struct node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}
struct node *RR(struct node *T)
{
    T=rotateleft(T);
    return(T);
}

struct node *LL(struct node *T)
{
    T=rotateright(T);
    return(T);
}
struct node *RL(struct node *x )
 {
	struct node *a = x;
	struct node *b = a->right;
	struct node *c = b->left;

	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;

	return( c );
}
 struct node *LR( struct node *x )
{
	struct node *a = x;
	struct node *b = a->left;
	struct node *c = b->right;

	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;

	return( c );
}
struct node *Delete(struct node *T,int x)
{
    struct node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else
        if(x > T->data)        // searching in right subtree
        {
            T->right=Delete(T->right,x);
            if(BF(T)==2)
                {
                    if(BF(T->left)>=0)
                    {
                        T=LL(T);
                    }
                else
                    {
                        T=LR(T);
                    }
                }
        }
        else
            if(x<T->data)
            {
                T->left=Delete(T->left,x);
                if(BF(T)==-2)    //Rebalance during windup
                    {
                        if(BF(T->right)<=0)
                        {
                            T=RR(T);
                        }
                    else
                        {
                            T=RL(T);
                        }
                    }
            }
            else
            {
                //when we reach the node that has to be deleted after traversing
                if(T->right!=NULL)
                {    //delete its inorder succesor
                    p=T->right;
                    while(p->left!= NULL)
                        {
                            p=p->left;
                        }

                    T->data=p->data;
                    T->right=Delete(T->right,p->data);

                    if(BF(T)==2)//Rebalance during windup
                        {
                            printf("The Balance Factor of the %d is 2 hence\n",T->data);
                            if(BF(T->left)>=0)
                            {
                                printf("We use LL rotation\n");
                                T=LL(T);
                            }
                        else
                            {
                                printf("We use LR rotation\n");
                                T=LR(T);
                            }
                        }
                }
                else
                    return(T->left);
            }
    T->ht=height(T);
    return(T);
}
int main()
{
    struct node *root=NULL;
    int x,n,i,op;

    do
    {
        printf("\n1)Insert an element in an AVL tree:");
        printf("\n2)Delete an element in an AVL tree:");
        printf("\n3)Quit:");
        printf("\nEnter Your Choice:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                    printf("\nEnter a data:");
                    scanf("%d",&x);
                    root=insert(root,x);
                    printf("\nThe Inorder traversal of the tree is:\n");
                    printf("B.F is The Balance Factor\n");
                    inorder(root);
                    break;

            case 2: printf("\nEnter the data that has to be deleted:");
                    scanf("%d",&x);
                    root=Delete(root,x);
                    printf("\nThe Inorder traversal of the tree is:\n");
                    printf("B.F is The Balance Factor\n");
                    inorder(root);
                    break;
          }
    }while(op!=3);

    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>

//Structure of node
typedef struct node
{
    int data;
    struct node *left,*right;
    int ht;
}node;

//Fuction Prototypes
node *insert(node *,int);
node *Delete(node *,int);
void inorder(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

//Driver Function
int main()
{
    node *root=NULL;
    int x,n,i,op;

    do
    {
        printf("\n1)Create:");
        printf("\n2)Insert:");
        printf("\n3)Delete:");
        printf("\n4)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                    printf("Enter no. of elements:\n");
                    scanf("%d",&n);
                    printf("Enter tree data:\n");
                    root=NULL;
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&x);
                        root=insert(root,x);
                        printf("BF=%d\n",BF(root));
                        printf("---------------------------------------------\n");
                        printf("Inorder sequence:\n");
                        inorder(root);
                        printf("\n");
                        printf("---------------------------------------------\n");
                        printf("---------------------------------------------\n");

                    }
            break;

            case 2:
                    printf("Enter a data:\n");
                    scanf("%d",&x);
                    root=insert(root,x);
                    printf("BF=%d\n",BF(root));
                    printf("---------------------------------------------\n");
                    printf("Inorder sequence:\n");
                    inorder(root);
                    printf("\n");
                    printf("---------------------------------------------\n");
                    printf("---------------------------------------------\n");

            break;

            case 3:
                    printf("Enter a data:\n");
                    scanf("%d",&x);
                    root=Delete(root,x);
                    printf("---------------------------------------------\n");
                    printf("Inorder sequence:\n");
                    inorder(root);
                    printf("\n");
                    printf("---------------------------------------------\n");
                    printf("---------------------------------------------\n");

            break;

        }
    }while(op!=4);

    return 0;
}

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)        // insert in right subtree
        {
            T->right=insert(T->right,x);
            if(BF(T)==-2)
            {
                if(x>T->right->data)
                {
                        T=RR(T);
                        printf("BF==-2 AT FIRST POINT OF IMBALANCE\n");
                        printf("RIGHT-RIGHT ROTATION ADOPTED\n");
                        printf("BF AFTER APPROPRIATE ROTATION\n");
                }
                else
                {
                        printf("BF==-2 AT FIRST POINT OF IMBALANCE\n");
                        T=RL(T);
                        printf("RIGHT-LEFT ROTATION ADOPTED\n");
                        printf("BF AFTER APPROPRIATE ROTATION\n");
                }
            }
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(BF(T)==2)
                {

                   if(x < T->left->data)
                   {
                        printf("BF==2 AT FIRST POINT OF IMBALANCE\n");
                        T=LL(T);
                        printf("LEFT-LEFT ROTATION ADOPTED\n");
                        printf("BF AFTER APPROPRIATE ROTATION\n");
                   }
                   else
                   {
                        printf("BF==2 AT FIRST POINT OF IMBALANCE\n");
                        T=LR(T);
                        printf("LEFT-RIGHT ROTATION ADOPTED\n");
                        printf("BF AFTER APPROPRIATE ROTATION\n");
                   }

                }
            }

        T->ht=height(T);

        return(T);
}

node * Delete(node *T,int x)
{
    node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else
        if(x > T->data)        // insert in right subtree
        {
            T->right=Delete(T->right,x);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else
            if(x<T->data)
            {
                T->left=Delete(T->left,x);
                if(BF(T)==-2)    //Rebalance during windup
                    if(BF(T->right)<=0)
                        T=RR(T);
                    else
                        T=RL(T);
            }
            else
            {
                //data to be deleted is found
                if(T->right!=NULL)
                {    //delete its inorder succesor
                    p=T->right;

                    while(p->left!= NULL)
                        p=p->left;

                    T->data=p->data;
                    T->right=Delete(T->right,p->data);

                    if(BF(T)==2)//Rebalance during windup
                        if(BF(T->left)>=0)
                            T=LL(T);
                        else
                            T=LR(T);
                }
                else
                    return(T->left);
            }
    T->ht=height(T);
    return(T);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    if(lh>rh)
        return(lh);
    else
        return(rh);
}

node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}

node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);

    return(y);
}

node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}

node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}

node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);

    return(T);
}

node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}

int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;

    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;

    return(lh-rh);
}

void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d(Bf=%d) ",T->data,BF(T));
        inorder(T->right);
    }
}
