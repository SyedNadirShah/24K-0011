#include <stdio.h>

// Recursive linear search function
int linearSearch(int arr[], int size, int target, int currentIndex) {
    // Base case: If current index exceeds array size, target is not found
    if (currentIndex == size) {
        return -1;  // Target not found
    }

    // If the target is found at the current index
    if (arr[currentIndex] == target) {
        return currentIndex;  // Return the index of the target
    }

    // Recursively search in the next index
    return linearSearch(arr, size, target, currentIndex + 1);
}

int main() {
    int arr[] = {34, 78, 23, 56, 12, 89, 67};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);  // Size of the array
    int target;

    // Ask the user for the target element to search for
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Call the linearSearch function starting from index 0
    int result = linearSearch(arr, size, target, 0);

    // Output the result
    if (result == -1) {
        printf("Target element %d not found in the array.\n", target);
    } else {
        printf("Target element %d found at index %d.\n", target, result);
    }

    return 0;
}

