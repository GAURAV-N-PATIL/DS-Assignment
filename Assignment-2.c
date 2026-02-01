//Problem: write a menu driven program for pop, push, peek and display using stack functions
#include <stdio.h>
#define MAX 100
void push(int stack[], int *top, int val) {
    if (*top >= MAX - 1) {
        printf("Stack overflow. Cannot push new element.\n");
        return;
    }
    stack[++(*top)] = val;
    printf("Element %d pushed onto stack.\n", val);
}
void pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack underflow. Cannot pop element.\n");
        return;
    }
    int poppedValue = stack[(*top)--];
    printf("Element %d popped from stack.\n", poppedValue);
}
void peek(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element is %d.\n", stack[top]);
}
int main() {
    int stack[MAX];
    int top = -1;
    int choice, val;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(stack, &top, val);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

