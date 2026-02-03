// write a program to reverse an array using stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void push(int stack[], int *top, int value) {
    if (*top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
}
void pop(int stack[], int *top, int *value) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    *value = stack[(*top)--];
}
void reverseArray(int arr[], int n) {
    int stack[MAX];
    int top = -1;
    for (int i = 0; i < n; i++) {
        push(stack, &top, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        pop(stack, &top, &arr[i]);
    }
}
void display(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[MAX];
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array:\n");
    display(arr, n);
    reverseArray(arr, n);
    printf("Reversed array:\n");
    display(arr, n);
    return 0;
}