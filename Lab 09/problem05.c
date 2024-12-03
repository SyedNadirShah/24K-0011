#include <stdio.h>
#include <string.h>

void reverseString(char str[], char reversed[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string
}

int main() {
    char str[100], reversed[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character

    reverseString(str, reversed);
    printf("Reversed string: %s\n", reversed);

    return 0;
}
