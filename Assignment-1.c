#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Function to display the array
void display(int arr[], int n)
{
    if (n == 0)
    {
        printf("\nArray is empty.");
        return;
    }
    printf("\nArray elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function to insert an element at a specific position
int insert(int arr[], int n)
{
    int pos, val;
    if (n >= MAX)
    {
        printf("\nArray Overflow!");
        return n;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &val);
    printf("Enter the position (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("\nInvalid position!");
        return n;
    }
    // Shifting elements to the right
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    printf("\nElement inserted successfully.");
    return n + 1; // Return new size
}
// Function to delete an element from a specific position
int delete(int arr[], int n)
{
    int pos;
    if (n == 0)
    {
        printf("\nArray Underflow! Nothing to delete.");
        return n;
    }
    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n)
    {
        printf("\nInvalid position!");
        return n;
    }
    // Shifting elements to the left
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("\nElement deleted successfully.");
    return n - 1; // Return new size
}

void main()
{
    int arr[MAX], n = 0, c;
    printf("\n--- Array Operations Menu ---");
    printf("\n1. Insert Element");
    printf("\n2. Delete Element");
    printf("\n3. Display Array");
    printf("\n4. Exit");
    do
    {

        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            n = insert(arr, n);
            break;
        case 2:
            n = delete(arr, n);
            break;
        case 3:
            display(arr, n);
            break;
        case 4:
            printf("Prgroam Terminated");
            break;
        default:
            printf("\nInvalid choice! Please try again.");
        }
    } while (c != 4);
}
