#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void insert(Queue *q, char element) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert '%c'\n", element);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->data[++(q->rear)] = element;
    printf("Inserted '%c' into the queue\n", element);
}

char delete(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete element\n");
        return '\0';
    }
    char element = q->data[(q->front)++];
    printf("Deleted '%c' from the queue\n", element);
    return element;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%c ", q->data[i]);
    printf("\n");
}

void demonstrateOverflow(Queue *q) {
    init(q);
    printf("Demonstrating Overflow:\n");
    for (int i = 0; i < MAX; i++)
        insert(q, 'A' + (i % 26));
    insert(q, 'Z'); // Will cause overflow
}

void demonstrateUnderflow(Queue *q) {
    init(q);
    printf("Demonstrating Underflow:\n");
    delete(q); // Will cause underflow
}

int main() {
    Queue q;
    init(&q);
    int choice;
    char element;

    while (1) {
        printf("\n---- Queue Menu ----\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Demonstrate Overflow\n");
        printf("4. Demonstrate Underflow\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(&q, element);
                break;

            case 2:
                delete(&q);
                break;

            case 3:
                demonstrateOverflow(&q);
                break;

            case 4:
                demonstrateUnderflow(&q);
                break;

            case 5:
                display(&q);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
