#include <stdio.h>
#include <stdbool.h>
#include "types.h"


void initializeStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        s->items[++s->top] = value;
        printf("Container %d pushed successfully.\n", value);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    } else {
        return s->items[s->top];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}
