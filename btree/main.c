struct Node {
    int data[3];
    int length;
    struct Node *link[4];
};

struct Node *root;
struct Node *parent;
struct Node *createNode(int data, struct Node *left, struct Node *right);
void insert(int data);
void split(struct Node *ptr);
void sort(struct Node *ptr);
struct Node *search(int data, struct Node *ptr);
struct Node *searchandprint(int data, struct Node *ptr);
void inorder(struct Node *ptr);

void main() {
    int data, choice;
    while (choice != 4){
        printf("1. Inserting a value in the B tree\n");
        printf("2. Searching a value in the B tree\n");
        printf("3. Inorder Traversal of the B tree\n");
        printf("4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value you want to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the element you want to search: ");
                scanf("%d", &data);
                if (searchandprint(data, root) != NULL)
                    printf("%d Can't be found in the B tree!\n", data);
                break;
            case 3:
            	inorder(root);
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
    struct Node *ptr = search(data, root);

    if (ptr == NULL){ //If number is already present
        return;
    }
    else {
        ptr->data[ptr->length] = data;
        (ptr->length)++;
        ptr->link[ptr->length] = NULL;
        sort(ptr);

        if ((ptr->length) > 2){
            split(ptr);
        }
    }
}

void split(struct Node *ptr){
    //split node
    struct Node *newNode = createNode(ptr->data[2], ptr->link[2], ptr->link[3]);
    ptr->length = 1;

    //find parent node
    search(ptr->data[0], root);

    //push median up
   	if (ptr == root){
	parent = createNode(ptr->data[1], ptr, newNode);
	root = parent;
	}
    else {
    	parent->data[parent->length] = ptr->data[1];
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
    for (i = 0; i < ptr->length; i++){
        for (j = 0; j < ((ptr->length)-i-1); j++){
            if (ptr->data[i] > ptr->data[i+1]){
                temp = ptr->data[i];
                temp_ptr = ptr->link[i+1];
                ptr->data[i] = ptr->data[i+1];
                ptr->link[i+1] = ptr->link[i+2];
                ptr->data[i+1] = temp;
                ptr->link[i+2] = temp_ptr;
            }
        }
    }
}

struct Node *search(int data, struct Node *ptr){
    int i;
    if (ptr != NULL){
        for (i=0; i<(ptr->length); i++){    // Loop through node

            if (data == ptr->data[i]){

                return NULL;
            }
            else if (data < ptr->data[i]){  // Check previous link
                parent = ptr;
                return search(data, ptr->link[i]);
            }
        }
        // Loop ended without search then check last link
        parent = ptr;
        return search(data, ptr->link[ptr->length]);
    }
    //if null ptr reached return leaf node
    return parent;
}
struct Node *searchandprint(int data, struct Node *ptr){
    int i;
    if (ptr != NULL){
        for (i=0; i<(ptr->length); i++){    // Loop through node

            if (data == ptr->data[i])
                {
                    printf("Number %d is present!\n", data);
                return NULL;
                }

            else if (data < ptr->data[i]){  // Check previous link
                parent = ptr;
                return searchandprint(data, ptr->link[i]);
            }
        }
        // Loop ended without search then check last link
        parent = ptr;
        return searchandprint(data, ptr->link[ptr->length]);
    }
    //if null ptr reached return leaf node
    return parent;
}


void inorder(struct Node *ptr){
	int i;
	if (ptr != NULL){
	for (i=0; i<(ptr->length); i++){
	inorder(ptr->link[i]);
	printf("%d ", ptr->data[i]);
	}
	inorder(ptr->link[i]);
	}
}
