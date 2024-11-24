#include <stdio.h>

// Recursive Bubble Sort function
void bubbleSort(int arr[], int size) {
    // Base case: If the array has only one element or no elements, it's already sorted
    if (size == 1) {
        return;
    }
    int i;

    // Perform a pass over the array, comparing adjacent elements and swapping if necessary
    for ( i = 0; i < size - 1; i++) {
        // Swap if elements are in the wrong order
        if (arr[i] > arr[i + 1]) {
            // Swap the elements
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // After one full pass, the largest element is in its correct position, so reduce the size for the next recursive call
    bubbleSort(arr, size - 1);
}

// Helper function to print the array
void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, size);

    // Call recursive bubbleSort
    bubbleSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

