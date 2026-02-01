//Aim: implementation of insertion and deletion in specific position in an array using functions
//Problem: write a menu driven program for array operations insertion ,deletation ,display using functions
#include <stdio.h>
#define MAX 100
void insert(int arr[], int *n, int pos, int val) {
    if (*n >= MAX) {
        printf("Array is full. Cannot insert new element.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
    printf("Element %d inserted at position %d.\n", val, pos);
}
void delete(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    int deletedValue = arr[pos];
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element %d deleted from position %d.\n", deletedValue, pos);
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
    int n = 0;
    int choice, pos, val;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(arr, &n, pos, val);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
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