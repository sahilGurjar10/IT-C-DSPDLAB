#include <stdio.h>
#define SIZE 7

int hash(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    int i = 0;
    while (table[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) return;
    }
    table[(index + i) % SIZE] = key;
}

void display(int table[]) {
    for (int i = 0; i < SIZE; i++)
        printf("Slot %d: %d\n", i, table[i]);
}

int main() {
    int table[SIZE];
    for (int i = 0; i < SIZE; i++) table[i] = -1;
    int n, key;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }
    printf("Final hash table:\n");
    display(table);
    return 0;
}
