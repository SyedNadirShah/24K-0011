#include <stdio.h>

// Recursive function to calculate the sum of digits of a number
int sumOfDigits(int number) {
    // Base case: if the number is 0, return 0 (no more digits to add)
    if (number == 0) {
        return 0;
    }
    
    // Recursive case: sum the last digit and recurse with the number divided by 10
    return (number % 10) + sumOfDigits(number / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the recursive function and print the result
    printf("Sum of digits: %d\n", sumOfDigits(num));

    return 0;
}

