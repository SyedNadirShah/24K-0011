#include <stdio.h>

// Define a constant for the conversion factor from meters to kilometers
#define METERS_TO_KM_CONVERSION_FACTOR 0.001

// Function to convert meters to kilometers and count how many times it is called
float convertMetersToKilometers(float meters) {
    static int callCount = 0;  // Static variable to count the number of times the function is called
    
    // Increment the call count each time the function is called
    callCount++;

    // Print the number of times the function has been called
    printf("Function called %d times.\n", callCount);

    // Convert meters to kilometers and return the result
    return meters * METERS_TO_KM_CONVERSION_FACTOR;
}

int main() {
    float meters;

    // Prompt the user for input (meters)
    printf("Enter distance in meters: ");
    scanf("%f", &meters);

    // Convert the input distance to kilometers
    float kilometers = convertMetersToKilometers(meters);

    // Output the result
    printf("%.2f meters is equal to %.4f kilometers.\n", meters, kilometers);

    // You can call the function multiple times to see the counter increase
    printf("\nEnter another distance in meters: ");
    scanf("%f", &meters);
    kilometers = convertMetersToKilometers(meters);
    printf("%.2f meters is equal to %.4f kilometers.\n", meters, kilometers);

    return 0;
}

