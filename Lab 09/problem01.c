#include <stdio.h>
#include <string.h>

int isPalindrome(char word[]) {
    int start = 0, end = strlen(word) - 1;
    while (start < end) {
        if (word[start] != word[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

int main() {
    char words[5][21];
    for (int i = 0; i < 5; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }
    for (int i = 0; i < 5; i++) {
        if (isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }
    return 0;
}
