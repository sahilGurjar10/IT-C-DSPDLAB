#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node *head) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Number of nodes in the list: %d\n", count);
}

int main() {
    Node *head = NULL;
    int value;

    printf("Enter integers to add to the linked list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0)
            break;
        append(&head, value);
    }

    printf("\nLinked List Elements:\n");
    display(head);

    // Free memory
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
