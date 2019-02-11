
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data[5];
    int length;
    struct Node *link[6];
};

struct Node *root;
struct Node *parent;

struct Node *createNode(int data, struct Node *left, struct Node *right);
void insert(int data);
void split(struct Node *ptr);
void sort(struct Node *ptr);
struct Node *search(int data, struct Node *ptr, int flag);
void traverse(struct Node *ptr);

void main() {
    int data, choice;
    printf("1. Insertion\n");
    printf("2. Searching\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
    while (choice != 4){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your input: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (search(data, root, 0) != NULL)
                    printf("Number %d is absent!\n", data);
                break;
            case 3:
                traverse(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid option!!\n");
                break;
        }
        printf("\n");
    }
}

struct Node *createNode(int data, struct Node *left, struct Node *right){
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data[0] = data;
        newNode->length = 1;
        newNode->link[0] = left;
        newNode->link[1] = right;
        return newNode;
}

void insert(int data){
    //If tree is empty
    if (root == NULL){
        root = createNode(data, NULL, NULL);
        return;
    }
    //Find leaf node
    struct Node *ptr = search(data, root, 0);

    if (ptr == NULL){ //If number is already present
        return;
    }
    else {
        ptr->data[ptr->length] = data;
        (ptr->length)++;
        ptr->link[ptr->length] = ptr->link[(ptr->length)-1];
        sort(ptr);
        int i;
        for (i=0; i<ptr->length; i++){
            if (ptr->link[i] != NULL){
                ptr->link[ptr->length] = ptr->link[i];
                ptr->link[i] = NULL;
                break;
            }
        }

        if ((ptr->length) > 4){
            split(ptr);
        }
    }
}

void split(struct Node *ptr){

    //find parent node
    search(ptr->data[(ptr->length)-1], root, 1);

    //split node
    struct Node *newNode = createNode(ptr->data[2], ptr->link[2], ptr->link[3]);
    newNode->data[1] = ptr->data[3];
    newNode->link[2] = ptr->link[4];
    newNode->data[2] = ptr->data[4];
    newNode->link[3] = ptr->link[5];
    newNode->length = 3;
    ptr->length = 2;
    ptr->link[2] = newNode;

    //push median up
    if (ptr == root){
        parent = createNode(ptr->data[2], ptr, newNode);
        root = parent;
    }
    else {
        parent->data[parent->length] = ptr->data[2];
        (parent->length)++;
        parent->link[parent->length] = newNode;
        sort(parent);

        //check parent
        if ((parent->length) > 2){
            split(parent);
        }
    }
}

// Bubble Sort
void sort(struct Node *ptr){
    int i,j;
    int temp;
    struct Node *temp_ptr;
    for (i = 0; i < (ptr->length)-1; i++){
        for (j = 0; j < ((ptr->length)-i-1); j++){
            if (ptr->data[j] > ptr->data[j+1]){
                temp = ptr->data[j];               //
                temp_ptr = ptr->link[j+1];         //
                ptr->data[j] = ptr->data[j+1];
                ptr->link[j+1] = ptr->link[j+2];
                ptr->data[j+1] = temp;             //
                ptr->link[j+2] = temp_ptr;         //
            }
        }
    }
}

struct Node *search(int data, struct Node *ptr, int flag){
    int i;
    if (ptr != NULL){
        for (i=0; i<(ptr->length); i++){    // Loop through node

            if (data == ptr->data[i]){
                if (flag == 0)              //Flag 0 == number searching, 1 == parent searching
                    printf("Number %d is present! hiiiii\n", data);
                return NULL;


            }
            else if (data < ptr->data[i]){  // Check previous link
                parent = ptr;
                return search(data, ptr->link[i], flag);
            }
        }
        // Loop ended without search then check last link
        parent = ptr;
        return search(data, ptr->link[ptr->length], flag);
    }
    //if null ptr reached return leaf node
    return parent;
}

void traverse(struct Node *ptr){
    int i;
    while ((ptr->link[0]) != NULL){
        ptr = ptr->link[0];
    }

    while (ptr != NULL){
        for (i=0; i<(ptr->length); i++){
            printf("%d ", ptr->data[i]);
        }
        ptr = ptr->link[ptr->length];
    }
}

/*OUTPUT:

C:\Users\dani\Desktop>gcc -g bptree.c

C:\Users\dani\Desktop>a
1. Insertion
2. Searching
3. Traverse
4. Exit
Enter your choice: 1
Enter your input: 50

Enter your choice: 1
Enter your input: 40

Enter your choice: 1
Enter your input: 30

Enter your choice: 1
Enter your input: 45

Enter your choice: 3
30 40 45 50

Enter your choice: 1
Enter your input: 10

Enter your choice: 3
10 30 40 45 50

Enter your choice: 1
Enter your input: 41

Enter your choice:
1
Enter your input: 47

Enter your choice: 3
10 30 40 41 45 47 50

Enter your choice: 1
Enter your input: 5

Enter your choice: 1
Enter your input: 15

Enter your choice: 3
5 10 15 30 40 41 45 47 50

Enter your choice: 2
Enter the element to search: 47
Number 47 is present!

Enter your choice: 1
Enter your input: 15
Number 15 is present!

Enter your choice: 1
Enter your input: 12

Enter your choice: 2
Enter the element to search: 13
Number 13 is absent!

Enter your choice: 4
Exiting...


C:\Users\dani\Desktop>
*/
