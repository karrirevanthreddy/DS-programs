#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow (Heap full)\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d\n", temp->data);
    
    front = front->next;
    if (front == NULL) {
        rear = NULL; 
    }
    
    free(temp);
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue (front -> rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
