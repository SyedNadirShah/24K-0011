#include <stdio.h>

float calculate(float a, float b, char operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Error! Division by zero.\n");
                return 0;
            }
        default:
            printf("Invalid operation!\n");
            return 0;
    }
}

int main() {
    float num1, num2;
    char operation;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    float result = calculate(num1, num2, operation);
    printf("Result: %.2f\n", result);

    return 0;
}
