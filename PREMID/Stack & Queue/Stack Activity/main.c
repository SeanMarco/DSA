#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

#define STACK_COUNT 3

int main() {
    Stack stacks[STACK_COUNT];
    for (int i = 0; i < STACK_COUNT; i++) {
        initializeStack(&stacks[i]);
    }

    int choice, id;
    while (1) {
        printf("\n--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter container ID to push: ");
                scanf("%d", &id);
                found = 0;
                for (int i = 0; i < STACK_COUNT; i++) {
                    if (!isFull(&stacks[i])) {
                        push(&stacks[i], id);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("All stacks are full. Cannot push %d.\n", id);
                }
                break;

            case 2: 
                found = 0;
                for (int i = 0; i < STACK_COUNT; i++) {
                    if (!isEmpty(&stacks[i])) {
                        popped = pop(&stacks[i]);
                        if (popped != -1) {
                            printf("Container %d popped successfully.\n", popped);
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: All stacks are empty. Cannot pop container.\n");
                }
                break;

            case 3: 
                printf("Enter container ID to check: ");
                scanf("%d", &id);
                found = 0;
                for (int i = 0; i < STACK_COUNT; i++) {
                    for (int j = 0; j <= stacks[i].top; j++) {
                        if (stacks[i].items[j] == id) {
                            printf("Container %d exists in a stack.\n", id);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Container %d does not exist in any stack.\n", id);
                }
                break;

            case 4: 
                for (int i = 0; i < STACK_COUNT; i++) {
                    printf("\n--- Stack %d ---\n", i + 1);
                    display(&stacks[i]);
                }
                break;

            case 5: // Exit
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
