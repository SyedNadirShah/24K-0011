#include <stdio.h>

// Recursive function to print all elements of the array
void printArray(int arr[], int size) {
    // Base case: if size is 0, return (end of array)
    if (size == 0) {
        return;
    }

    // Print the first element
    printf("%d ", arr[0]);

    // Recursive case: call the function with the rest of the array (size-1)
    printArray(arr + 1, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    printf("Array elements: ");
    printArray(arr, size);  // Call the recursive function to print elements

    return 0;
}

