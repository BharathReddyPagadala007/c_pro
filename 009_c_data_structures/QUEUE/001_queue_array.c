////////////////////////////////////////////////////
//
//    queue using array
//     [FIFO]
//
//   ----->>in  | | | | | | | | | | | | | | ---->out
//              |                       |
//              |                       |
//              |                       |
//              back/tail		front/head
//                rear                  [first inserted]
//             [last inserted]
//
//
//      [0,1,2,3,4,5]   //enqueue rear + 1
//       |         |
//       front     rear
//
//
//      [0,1,2,3,4,5]   //dequeue  front + 1
//         |       |
//       front     rear
//
////////////////////////////////////////////////////




#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum number of elements in the queue

// Define a structure for the queue
struct Queue {
    int data[MAX];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        // Queue is now empty
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50); // Queue is full after this

    displayQueue(q);
    
    dequeue(q);
    dequeue(q);

    displayQueue(q);

    enqueue(q, 60);
    enqueue(q, 70); // Should work because of circular nature

    displayQueue(q);

    return 0;
}

