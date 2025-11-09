#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

Node* search(Node *root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

Node* deleteLeaf(Node *root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data) root->left = deleteLeaf(root->left, value);
    else if (value > root->data) root->right = deleteLeaf(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
    }
    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL, *found;
    int choice, value;
    while (1) {
        printf("\n1. Search Element\n2. Insert Element\n3. Delete Leaf Element\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                found = search(root, value);
                if (found == NULL) printf("NULL\n");
                else printf("Found\n");
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter leaf value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
