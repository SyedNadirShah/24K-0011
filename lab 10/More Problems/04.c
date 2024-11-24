#include <stdio.h>
#include <string.h>

#define MAX_CARS 100  // Maximum number of cars the dealership can store

// Structure to store details about a car
struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

// Global array to store cars
struct Car cars[MAX_CARS];
int carCount = 0;  // Keep track of how many cars have been added

// Function to add a new car to the dealership
void addCar() {
    if (carCount >= MAX_CARS) {
        printf("Cannot add more cars, dealership is full.\n");
        return;
    }

    struct Car newCar;
    
    // Get car details from the user
    printf("Enter car make: ");
    getchar();  // To consume any newline left by previous input
    fgets(newCar.make, sizeof(newCar.make), stdin);
    newCar.make[strcspn(newCar.make, "\n")] = '\0';  // Remove the newline character
    
    printf("Enter car model: ");
    fgets(newCar.model, sizeof(newCar.model), stdin);
    newCar.model[strcspn(newCar.model, "\n")] = '\0';  // Remove the newline character
    
    printf("Enter car year: ");
    scanf("%d", &newCar.year);
    
    printf("Enter car price: ");
    scanf("%f", &newCar.price);
    
    printf("Enter car mileage: ");
    scanf("%f", &newCar.mileage);

    // Add the new car to the array
    cars[carCount] = newCar;
    carCount++;

    printf("Car added successfully!\n");
}

// Function to display all available cars
void displayCars() {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }
    int i;

    printf("\nList of available cars:\n");
    for ( i = 0; i < carCount; i++) {
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %.2f miles\n", cars[i].mileage);
        printf("--------------------------\n");
    }
}

// Function to search cars by make or model
void searchCars() {
    char searchTerm[50];
    printf("Enter make or model to search for: ");
    getchar();  // To consume any newline left by previous input
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // Remove the newline character

    int found = 0, i;
    printf("\nSearch results for '%s':\n", searchTerm);
    for (i = 0; i < carCount; i++) {
        // Compare make or model with the search term (case-sensitive)
        if (strstr(cars[i].make, searchTerm) != NULL || strstr(cars[i].model, searchTerm) != NULL) {
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %.2f miles\n", cars[i].mileage);
            printf("--------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching '%s'.\n", searchTerm);
    }
}

int main() {
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add a new car\n");
        printf("2. Display all available cars\n");
        printf("3. Search cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();  // Add a new car
                break;
            case 2:
                displayCars();  // Display all available cars
                break;
            case 3:
                searchCars();  // Search cars by make or model
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);  // Repeat until the user chooses to exit

    return 0;
}

