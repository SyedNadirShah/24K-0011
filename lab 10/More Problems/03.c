#include <stdio.h>

// Define a constant for the maximum allowable temperature (in Celsius)
#define MAX_TEMP 30

// Function to compare input temperature with the maximum allowable temperature
// It uses a static variable to count how many times the temperature exceeded the limit
void compareTemperature(float temp) {
    // Static variable to keep track of how many times the temperature exceeded the limit
    static int exceededCount = 0;

    // Compare the temperature with the maximum allowable temperature
    if (temp > MAX_TEMP) {
        exceededCount++;  // Increment the count if temperature exceeds the limit
        printf("Temperature %.2f°C exceeded the limit of %.2f°C.\n", temp, MAX_TEMP);
    } else {
        printf("Temperature %.2f°C is within the allowable limit of %.2f°C.\n", temp, MAX_TEMP);
    }

    // Print the total number of times the limit was exceeded
    printf("Total number of times the temperature exceeded the limit: %d\n", exceededCount);
}

int main() {
    float temp1, temp2, temp3;

    // Get temperature inputs from the user
    printf("Enter the first temperature (°C): ");
    scanf("%f", &temp1);

    printf("Enter the second temperature (°C): ");
    scanf("%f", &temp2);

    printf("Enter the third temperature (°C): ");
    scanf("%f", &temp3);

    // Compare each temperature with the maximum allowable temperature
    compareTemperature(temp1);
    compareTemperature(temp2);
    compareTemperature(temp3);

    return 0;
}

