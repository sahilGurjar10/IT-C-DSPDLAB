#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
    printf("%d pushed onto stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->data[(s->top)--];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

void checkPalindrome() {
    char str[100];
    Stack s;
    init(&s);
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        push(&s, str[i]);
    int palindrome = 1;
    for (int i = 0; i < len; i++) {
        char ch = pop(&s);
        if (ch != str[i]) {
            palindrome = 0;
            break;
        }
    }
    if (palindrome)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
}

int main() {
    Stack s;
    init(&s);
    int choice, value;

    while (1) {
        printf("\n---- Stack Menu ----\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow/Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2:
                value = pop(&s);
                if (value != -1)
                    printf("Popped element: %d\n", value);
                break;

            case 3:
                checkPalindrome();
                break;

            case 4:
                printf("Demonstrating Overflow:\n");
                while (!isFull(&s)) push(&s, rand() % 100);
                push(&s, 999); // Overflow
                printf("Demonstrating Underflow:\n");
                while (!isEmpty(&s)) pop(&s);
                pop(&s); // Underflow
                break;

            case 5:
                display(&s);
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
