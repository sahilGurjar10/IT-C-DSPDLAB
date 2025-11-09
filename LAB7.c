#include <stdio.h>
#include <stdlib.h>

#define N 9   


int adj[N+1][N+1];
int degree[N+1];

int queue[N+1];
int front = 0, rear = 0;

void enqueue(int val) { queue[rear++] = val; }
int dequeue() { return queue[front++]; }
int isQueueEmpty() { return front == rear; }


int stack[N+1];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
int isStackEmpty() { return top == -1; }


void buildGraph() {
    int i, r, c;
    for (i = 1; i <= N; i++) {
        r = (i - 1) / 3;
        c = (i - 1) % 3;
        
        if (r > 0) adj[i][degree[i]++] = i - 3;
       
        if (r < 2) adj[i][degree[i]++] = i + 3;
       
        if (c > 0) adj[i][degree[i]++] = i - 1;
       
        if (c < 2) adj[i][degree[i]++] = i + 1;
    }
}


void BFS(int start) {
    int visited[N+1] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS Order: ");
    while (!isQueueEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        
        for (int i = 0; i < degree[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
        }
    }
    printf("\n");
}


void DFS(int start) {
    int visited[N+1] = {0};
    push(start);

    printf("DFS Order: ");
    while (!isStackEmpty()) {
        int node = pop();
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);

           
            for (int i = degree[node] - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    push(neighbor);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    buildGraph();
    BFS(1);
    DFS(1);
    return 0;
}
