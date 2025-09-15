#include <stdio.h>
#include "types.h"
#include "arrayQueue.h"

int main() {
    Queue* regular = initialize();
    Queue* priority = initialize();

    int choice, num = 1;

    while (1) {
        printf("\n--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(regular, num);
                printf("You have entered the Regular queue. Your number is %d.\n", num);
                num++;
                break;
            case 2:
                enqueue(priority, num);
                printf("You have entered the Priority queue. Your number is %d.\n", num);
                num++;
                break;
            case 3:
                if (!isEmpty(priority)) {
                    printf("Calling next customer from Priority Queue. Customer number: %d\n", dequeue(priority));
                } else if (!isEmpty(regular)) {
                    printf("Calling next customer from Regular Queue. Customer number: %d\n", dequeue(regular));
                } else {
                    printf("No customers in queue.\n");
                }
                break;
            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Regular Queue: ");
                display(regular);
                printf("Priority Queue: ");
                display(priority);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
