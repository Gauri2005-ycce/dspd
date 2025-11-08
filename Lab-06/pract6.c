#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void search(struct Node* root, int key) {
    if (root == NULL)
        printf("NULL\n");
    else if (root->data == key)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Not a leaf node, cannot delete!\n");
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n\n1. Search\n2. Insert\n3. Delete Leaf\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to search: ");
            scanf("%d", &val);
            search(root, val);
            break;
        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            printf("Inserted!\n");
            break;
        case 3:
            printf("Enter leaf element to delete: ");
            scanf("%d", &val);
            root = deleteLeaf(root, val);
            printf("Deleted (if leaf)!\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}
