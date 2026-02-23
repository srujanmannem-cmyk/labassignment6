#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);
    front++;
}

void find(int key) {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        if (queue[i] == key) {
            printf("Element %d found at position %d\n", key, i);
            return;
        }
    }

    printf("Element not found\n");
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    find(20);
    dequeue();
    display();
    return 0;
}
