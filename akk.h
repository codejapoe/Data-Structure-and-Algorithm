/* Belongs to Aung Kaung Khant
 * Created on 6-2-2022
 * This file contains
 * 1. new()
 * 2. print()
 * 3. create()
 * 4. count()
 * 6. push()
 * 7. append()
 * 8. insertAfter()
 * 9. search()
 * 10. update()
 * 11. deleteData()
 * 12. deleteusingIndex()
 * 13. swap()
 * 14. ascending()
 * 15. descending()
 *
 *                       Menu
 *        /                |                   \
 * Linked list Binary Search Tree   Stack Implement using Linked list
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *address;
};

struct Node* new(){
    struct Node *newNode = (struct Node*)malloc(sizeof (struct Node));
    return newNode;
}

void print(struct Node* node){
    printf("Your data: [ ");
    while(node != NULL){
        printf("%d",node->data);
        if (node->address != NULL){
            printf(", ");
        }
        node = node->address;
    }
    printf(" ]\n");
}

void create(struct Node **node, int data){
    struct Node *newNode = new();
    struct Node *ref = *node;

    newNode->data = data;
    newNode->address = NULL;

    if (*node == NULL) {
        *node = newNode;
        return;
    }

    while(ref->address != NULL){
        ref = ref->address;
    }
    ref->address = newNode;
    return;
}

int count(struct Node** node){
    int i = 1;
    struct Node* head = *node;
    while(head->address != NULL) {
        head = head->address;
        i++;
    }
    return i;
}

void push(struct Node** node, int userData){
    struct Node* newNode = new();
    newNode->data = userData;
    newNode->address = *node;
    *node = newNode;
}

void append(struct Node** node, int userData) {
    struct Node* newNode = new();
    newNode->data = userData;
    newNode->address = NULL;
    struct Node* ref = *node;

    while (ref->address != NULL){
        ref = ref->address;
    }
    ref->address = newNode;
    return;
}

void insertAfter(struct Node** node, int index, int userData) {
    int i = count(&*node);

    if (index >= i){
        printf("\nInvalid Index No.\n\n");
        return;
    }

    struct Node* newNode = new();
    newNode->data = userData;

    struct Node* ref = *node;
    struct Node* ref2 = *node;
    for(int j=0; j<index; j++){
        ref = ref->address;
    }
    for (int k=0; k<index; k++) {
        ref2 = ref2->address;
    }
    newNode->address = ref2->address;
    ref->address = newNode;
}

int search(struct Node* node, int query) {
    int i = 0;
    struct Node* ref = node;
    while (ref != NULL) {
        if (ref->data == query){
            return i;
        }
        ref = ref->address;
        i++;
    }
    return -1;
}

void update(struct Node** node, int index, int userData) {
    int i = count(&*node);

    if (index >= i || index < 0){
        printf("\nInvalid Index No.\n\n");
        return;
    }

    struct Node* newNode = *node;
    for (int j=0; j<index; j++){
        newNode = newNode->address;
    }
    newNode->data = userData;
}

int deleteData(struct Node** node, int query) {
    struct Node* temp = *node;
    struct Node* prev_node = NULL;

    if (temp->address != NULL && temp->data == query) {
        *node = temp->address;
        free(temp);
        return 1;
    } else if (temp->address == NULL && temp->data == query) {
        free(temp);
        return 0;
    } else {
        while (temp != NULL){
            if (temp->data == query) {
                prev_node->address = temp->address;
                free(temp);
                return 1;
            }
            prev_node = temp;
            temp = temp->address;
        }
        return -1;
    }
}

int deleteusingIndex(struct Node** node, int index) {
    struct Node* temp = *node;
    struct Node* prev_node = NULL;

    int i = count(&*node);

    if (index >= i || index < 0){
        return -1;
    }

    if (index==0 && temp->address!=NULL) {
        *node = temp->address;
        free(temp);
        return 1;
    } else if (index==0 && temp->address==NULL) {
        free(temp);
        return 0;
    } else {
        for (int j=0; j<i; j++){
            if (j==index) {
                prev_node->address = temp->address;
                free(temp);
                return 1;
            }
            prev_node = temp;
            temp = temp->address;
        }
    }
}

void swap(struct Node** node, int index1, int index2) {
    int i = count(&*node);

    if (index1 >= i || index2 >= i || index1 < 0 || index2 < 0){
        printf("\nInvalid Index No.\n\n");
        return;
    }

    struct Node* newNode = *node;
    struct Node* newNode2 = *node;
    for (int j=0; j<index1; j++){
        newNode = newNode->address;
    }
    int temp = newNode->data;
    for (int k=0; k<index2; k++){
        newNode2 = newNode2->address;
    }
    newNode->data = newNode2->data;
    newNode2->data = temp;
}

void ascending(struct Node** node) {
    int i = count(&*node);

    int smallest;
    for(int j=0; j < i; j++) {
        struct Node* newNode = *node;
        while (newNode->address != NULL) {
            if (newNode->data > (newNode->address)->data) {
                smallest = (newNode->address)->data;
                (newNode->address)->data = newNode->data;
                newNode->data = smallest;
            }
            newNode = newNode->address;
        }
    }
}

void descending(struct Node** node) {
    int i = count(&*node);

    int largest;
    for(int j=0; j < i; j++) {
        struct Node* newNode = *node;
        while (newNode->address != NULL) {
            if (newNode->data < (newNode->address)->data) {
                largest = (newNode->address)->data;
                (newNode->address)->data = newNode->data;
                newNode->data = largest;
            }
            newNode = newNode->address;
        }
    }
}

void options(struct Node* var, int type) {
    while (true) {
        int option = 0;
        printf("------------------------------------------------------------------------------------\n");
        printf("Options\n"
               "1. Push Data\n"
               "2. Append Data\n"
               "3. Insert after a Data\n"
               "4. Search\n"
               "5. Update\n"
               "6. Delete\n"
               "7. Delete using Index No.\n"
               "8. Swap\n"
               "9. Sort (Ascending Order)\n"
               "10. Sort (Descending Order)\n"
               "11. Count\n"
               "0. Exit\n\n"
               "Your Option:");
        scanf("%d",&option);
        if (option == 0) {
            break;
        } else {
            if (option == 1) {
                int data = 0;
                if (type == 1) {
                    int i = count(&var);
                    if (i == 10) {
                        printf("\nStack Full! Operation cannot be done.\n\n");
                    } else {
                        data = 0;
                        printf("Please enter a data to push:");
                        scanf("%d", &data);
                        push(&var, data);
                        print(var);
                        continue;
                    }
                } else {
                    data = 0;
                    printf("Please enter a data to push:");
                    scanf("%d", &data);
                    push(&var, data);
                    print(var);
                    continue;
                }
            } else if (option == 2) {
                int data = 0;
                if (type == 1) {
                    int i = count(&var);
                    if (i == 10) {
                        printf("\nStack Full! Operation cannot be done.\n\n");
                    } else {
                        data = 0;
                        printf("Please enter a data to append:");
                        scanf("%d",&data);
                        append(&var, data);
                        print(var);
                        continue;
                    }
                } else {
                    data = 0;
                    printf("Please enter a data to append:");
                    scanf("%d",&data);
                    append(&var, data);
                    print(var);
                    continue;
                }
            } else if (option == 3) {
                int index = 0;
                int data = 0;
                if (type == 1) {
                    int i = count(&var);
                    if (i == 10) {
                        printf("\nStack Full! Operation cannot be done.\n\n");
                    } else {
                        index = 0;
                        data = 0;
                        printf("Please enter index number:");
                        scanf("%d",&index);
                        printf("Please enter data for index no.%d to insert after:",index+1);
                        scanf("%d",&data);
                        insertAfter(&var, index, data);
                        print(var);
                        continue;
                    }
                } else {
                    index = 0;
                    data = 0;
                    printf("Please enter index number:");
                    scanf("%d",&index);
                    printf("Please enter data for index no.%d to insert after:",index+1);
                    scanf("%d",&data);
                    insertAfter(&var, index, data);
                    print(var);
                    continue;
                }
            } else if (option == 4){
                int data = 0;
                printf("Please enter a data to search:");
                scanf("%d",&data);
                int result = search(var, data);
                if (result == -1){
                    printf("\nData not found.\n\n");
                } else {
                    printf("\nWe found your data at index no.%d\n\n",result);
                }
                print(var);
                continue;
            } else if (option == 5) {
                int index = 0;
                int data = 0;
                printf("Please enter index number:");
                scanf("%d",&index);
                printf("Please enter data for index no. %d to update:",index);
                scanf("%d",&data);
                update(&var, index, data);
                print(var);
                continue;
            } else if (option == 6) {
                int data = 0;
                printf("Please enter a data to delete:");
                scanf("%d",&data);
                int result = deleteData(&var, data);
                if (result == 0) {
                    printf("\nYou have no data now...\n");
                    break;
                } else if (result == -1) {
                    printf("\nNot Found.\n\n");
                    continue;
                } else {
                    print(var);
                    continue;
                }
            } else if (option == 7) {
                int index = 0;
                printf("Please enter index number to delete:");
                scanf("%d",&index);
                int result = deleteusingIndex(&var, index);
                if (result == 0) {
                    printf("\nYou have no data now...\n");
                    break;
                } else if (result == -1) {
                    printf("\nInvalid Index No.\n\n");
                    print(var);
                    continue;
                } else {
                    print(var);
                    continue;
                }
            } else if (option == 8) {
                int index1 = 0;
                int index2 = 0;
                printf("Please enter 1st index number to swap:");
                scanf("%d",&index1);
                printf("Please enter 2nd index number to swap:");
                scanf("%d",&index2);
                swap(&var, index1, index2);
                print(var);
                continue;
            } else if (option == 9) {
                ascending(&var);
                print(var);
                continue;
            } else if (option == 10) {
                descending(&var);
                print(var);
                continue;
            } else if (option == 11) {
                int i = count(&var);
                printf("Total Size: %d data\n",i);
            } else {
                continue;
            }
        }
    }
}

void linkedList() {
    printf("----------Linked List----------\n");
    struct Node* var = new();
    while(true) {
        int n;
        printf("Size of data:");
        scanf("%d",&n);
        if (n == 0) {
            continue;
        } else {
            int data = 0;
            for (int i = 0; i < n; i++) {
                printf("Please enter Index No. %d's value:", i);
                scanf("%d", &data);
                if (i == 0) {
                    var->data = data;
                    var->address = NULL;
                } else {
                    create(&var, data);
                }
            }
            print(var);
            break;
        }
    }
    options(var, 0);
}

void stackwithLinkedList() {
    printf("----------Stack Implement with Linked List----------\n");
    struct Node* var = new();
    bool statement = true;
    bool firstTime = true;
    int num = 0;
    int n = 10;
    int data = 0;

    while (true) {
        printf("Please enter a value (Enter ! to stop):");
        scanf("%d", &data);
        if (data == 33) {
            break;
        } else if (statement == true) {
            var->data = data;
            var->address = NULL;
            statement = false;
        } else if (n == 0) {
            printf("Stack Overflow!!!\n");
            break;
        } else {
            create(&var, data);
        }
        num++;
        n--;
        firstTime = false;

        if (firstTime == false) {
            for (int i = 0; i < num; i++) {
                swap(&var, i, num - 1);
                num--;
            }

            print(var);
            options(var, 1);
        }
    }
}

struct b_tree {
    int data;
    struct b_tree *left, *right;
};

struct b_tree* newNode(int item) {
    struct b_tree* temp = (struct b_tree*)malloc(sizeof (struct b_tree));
    temp->data = item;
    temp->left = temp->right = NULL;
};

struct b_tree* insert(struct b_tree* root, int data){
    if (root == NULL){
        return newNode(data);
    } else {
        if (data < root->data){
            root->left = insert(root->left, data);
        } else if (data > root->data){
            root->right = insert(root->right, data);
        } else {
            printf("Data already exists.\n");
            return root;
        }
    }
    return root;
}

struct b_tree* delete(struct b_tree* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (root->data < key) {
        root->left = delete(root->left, key);
        return root;
    } else if (root->data > key) {
        root->right = delete(root->right, key);
        return root;
    }

    if (root->left == NULL) {
        struct b_tree* temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        struct b_tree* temp = root->right;
        free(root);
        return temp;
    } else {
        struct b_tree* parent = root;
        struct b_tree* child = root->right;
        while (child->left != NULL) {
            parent = child;
            child = child->left;
        }
        if (parent != root) {
            parent->left = child->right;
        } else {
            parent->right = child->right;
        }
        root->data = child->data;
        free(child);
        return root;
    }
}

int countTree(struct b_tree* node, int key) {
    if (node != NULL) {
        key = countTree(node->left, key++);
        key = countTree(node->right, key++);
        key++;
        return key;
    }
}

bool searchTree(struct b_tree* root, int key) {
    if (root == NULL) {
        return false;
    } else if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        bool flag = searchTree(root->left, key);
        return flag;
    } else if (key > root->data) {
        bool flag = searchTree(root->right, key);
        return flag;
    }
}

struct b_tree* render(struct b_tree* root, int key, int data) {
    if (root == NULL){
        return root;
    } else {
        if (key < root->data){
            root->left = render(root->left, key, data);
        } else if (key > root->data){
            root->right = render(root->right, key, data);
        } else {
            if (root->left == NULL && root->right == NULL ) {
                root->data = data;
                return root;
            } else if ((root->left == NULL) || (data > (root->left)->data)) {
                if ((root->right == NULL) || (data < (root->right)->data)) {
                    root->data = data;
                    return root;
                }
            } else {
                return root;
            }
        }
    }
    return root;
}

struct b_tree* replace(struct b_tree* node, int key, int data) {
    bool flag = searchTree(node, key);
    bool flag2 = searchTree(node, data);

    if (flag == true && flag2 == false) {
        node = render(node, key, data);
    } else {
        printf("Invalid data.\n");
    }
    return node;
}

void inorder(struct b_tree* root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d, ",root->data);
    inorder(root->right);
}

void preorder(struct b_tree* root){
    if (root == NULL) {
        return;
    }
    printf("%d, ",root->data);
    preorder(root->left);
    preorder(root->right);

}

void postorder(struct b_tree* root){
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d, ", root->data);
}

void BST() {
    printf("----------Binary Search Tree----------\n");
    int size;
    int menu;
    int data;
    struct b_tree* root = NULL;
    while (true) {
        printf("Size of data:");
        scanf("%d",&size);
        if (size == 0) {
            continue;
        } else {
            for (int i=0; i<size; i++) {
                data = 0;
                printf("Please enter data:");
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        }
    }
    while (true) {
        printf("----------Menu----------\n"
               "1. Insert\n"
               "2. Delete\n"
               "3. Count\n"
               "4. Replace\n"
               "5. Inorder Traversal\n"
               "6. Preorder Traversal\n"
               "7. Postorder Traversal\n"
               "0. Exit\n"
               "Choice:");
        scanf("%d", &menu);
        if (menu == 0) {
            break;
        } else if (menu == 1) {
            printf("Please enter data to insert:");
            scanf("%d", &data);
            root = insert(root, data);
            continue;
        } else if (menu == 2) {
            printf("Please enter data to delete:");
            scanf("%d", &data);
            root = delete(root, data);
            continue;
        } else if (menu == 3) {
            int data = countTree(root, 0);
            printf("Size of data in the Tree: %d\n", data);
            continue;
        } else if (menu == 4){
            int existingData = 0;
            int newData = 0;
            printf("Data in the tree:  {");
            inorder(root);
            printf("}\n");
            printf("Select existing data:");
            scanf("%d",&existingData);
            printf("Enter new data to replace:");
            scanf("%d",&newData);
            root = replace(root, existingData, newData);
            continue;
        } else if (menu == 5){
            printf("{");
            inorder(root);
            printf("}\n");
            continue;
        } else if (menu == 6){
            printf("{");
            preorder(root);
            printf("}\n");
            continue;
        } else if (menu == 7){
            printf("{");
            postorder(root);
            printf("}\n");
            continue;
        }
    }
}

void menu(){
    int menu;
    while (true) {
        printf("----------Menu----------\n"
               "1. Linked List\n"
               "2. Stack Implement with Linked List\n"
               "3. Binary Search Tree\n"
               "0. Exit\n"
               "Choice:");
        scanf("%d",&menu);
        if (menu == 1) {
            linkedList();
            continue;
        } else if (menu == 2) {
            stackwithLinkedList();
            continue;
        } else if (menu == 3) {
            BST();
            continue;
        } else {
            break;
        }
    }
}
