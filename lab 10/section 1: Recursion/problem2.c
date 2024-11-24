#include <stdio.h>
#include <string.h>

// Recursive function to reverse the string
void reverseString(char str[], int start, int end) {
    // Base case: If start index is greater than or equal to the end index, stop recursion
    if (start >= end) {
        return;
    }

    // Swap the characters at the start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively call for the next pair of characters
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Input the string to reverse
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // This will handle spaces in the string
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

    int length = strlen(str);

    // Call the recursive function to reverse the string
    reverseString(str, 0, length - 1);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}

