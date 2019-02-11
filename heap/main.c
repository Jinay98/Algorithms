#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int min,max;
int maxHeap[MAX];
int minHeap[MAX];

void insert_max(int data){
    int temp,i;
    maxHeap[++max] = data;
    for(i=max;i>1;){
        if(maxHeap[i]>maxHeap[i/2]){
            temp = maxHeap[i];
            maxHeap[i] = maxHeap[i/2];
            maxHeap[i/2] = temp;
        }
        i=i/2;
    }
}

void delete_max(){
    int temp,i,c1,c2;
    temp = maxHeap[max];
    maxHeap[max]=maxHeap[1];
    maxHeap[1]=temp;
    max--;
    for(i=1;i<max;){
        if(maxHeap[i]<maxHeap[2*i] && 2*i<=max){
            c1 = maxHeap[2*i];
            c2 = maxHeap[2*i + 1];
            if(maxHeap[2*i]>maxHeap[2*i + 1]||(2*i + 1)>max){
                temp=maxHeap[2*i];
                maxHeap[2*i]=maxHeap[i];
                maxHeap[i] = temp;
            }
            else{
                temp = maxHeap[2*i + 1];
                maxHeap[2*i + 1]=maxHeap[i];
                maxHeap[i] = temp;
            }
        }
        if(c1>c2)
            i=2*i;
        else
            i=2*i + 1;
    }
}

void insert_min(int data){
    int temp,i;
    minHeap[++min] = data;
    for(i=min;i>1;){
        if(minHeap[i]<minHeap[i/2]){
            temp = minHeap[i];
            minHeap[i] = minHeap[i/2];
            minHeap[i/2] = temp;
        }
        i=i/2;
    }
}

void delete_min(){
    int temp,i,c1,c2;
    temp = minHeap[min];
    minHeap[min]=minHeap[1];
    minHeap[1]=temp;
    min--;
    for(i=1;i<min;){
        if(minHeap[i]>minHeap[2*i] && 2*i<=min){
            c1 = minHeap[2*i];
            c2 = minHeap[2*i + 1];
            if(minHeap[2*i]<minHeap[2*i + 1]||(2*i + 1)>min){
                temp=minHeap[2*i];
                minHeap[2*i]=minHeap[i];
                minHeap[i] = temp;
                }
                else{
                   temp = minHeap[2*i + 1];
                   minHeap[2*i + 1]=minHeap[i];
                   minHeap[i] = temp;
                }

        }
       if(c1<c2)
            i=2*i;
        else
            i=2*i + 1;
    }
}

void traversal_max(int n){
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",maxHeap[i]);
    }
    printf("\n");
}

void traversal_min(int n){
    int i;
    for(i=1;i<=n;i++){
        printf("%d ",minHeap[i]);
    }
    printf("\n");
}

void main(){
    int opt=0,n,m,data[MAX];
    printf("\nENTER NUMBER OF ELEMENTS YOU WISH TO INSERT\n");
    scanf("%d",&n);
    for(m=0;m<n;m++){
        printf("\nEnter value of data element %d : ",m+1);
        scanf("%d",&data[m]);
    }
    while(opt!=3){
        printf("\nPRESS 1 FOR MIN HEAP\nPRESS 2 FOR MAX HEAP\nPRESS 3 TO EXIT\n");
        scanf("%d",&opt);
        switch(opt){
            case 1: for(m=0;m<n;m++){
                        insert_min(data[m]);
                    }
                    printf("\nThe min heap structure is as follows:\n");
                    traversal_min(n);
                    for(m=0;m<n;m++){
                        delete_min();
                    }
                    printf("\nThe descending order is as follows\n");
                    traversal_min(n);
                    break;
            case 2: for(m=0;m<n;m++){
                        insert_max(data[m]);
                    }
                    printf("\nThe max heap structure is as follows:\n");
                    traversal_max(n);
                    for(m=0;m<n;m++){
                        delete_max();
                    }
                    printf("\nThe ascending order is as follows\n");
                    traversal_max(n);
                    break;
            case 3: break;
            default:printf("Invalid input.");
                    break;
        }
    }
}

/*...................................OUTPUT......................................*/
/*
ububt@becks:~$ gcc ads8.c
ububt@becks:~$ ./a.out

ENTER NUMBER OF ELEMENTS YOU WISH TO INSERT
5

Enter value of data element 1 : 11

Enter value of data element 2 : 33

Enter value of data element 3 : 20

Enter value of data element 4 : 22

Enter value of data element 5 : 99

PRESS 1 FOR MIN HEAP
PRESS 2 FOR MAX HEAP
PRESS 3 TO EXIT
1

The min heap structure is as follows:
11 22 20 33 99

The descending order is as follows
99 33 22 20 11

PRESS 1 FOR MIN HEAP
PRESS 2 FOR MAX HEAP
PRESS 3 TO EXIT
2

The max heap structure is as follows:
99 33 20 11 22

The ascending order is as follows
11 20 22 33 99

PRESS 1 FOR MIN HEAP
PRESS 2 FOR MAX HEAP
PRESS 3 TO EXIT
3
ububt@becks:~$ */
