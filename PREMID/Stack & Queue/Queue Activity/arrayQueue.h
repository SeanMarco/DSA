#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->list.count++;
    } else {
        printf("Queue is full!\n");
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int value = q->list.items[q->front];
        q->front = (q->front + 1) % MAX;
        q->list.count--;
        return value;
    }
    return -1; 
}

bool isFull(Queue* q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i, index;
    for (i = 0; i < q->list.count; i++) {
        index = (q->front + i) % MAX;
        printf("%d ", q->list.items[index]);
    }
    printf("\n");
}
