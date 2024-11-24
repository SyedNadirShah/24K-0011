#include <stdio.h>
#include <string.h>

// Define structure to store information about travel packages
struct TravelPackage {
    char packageName[50];
    char destination[50];
    int duration;     // Duration of the trip in days
    float cost;       // Cost of the package
    int availableSeats; // Number of available seats
};

// Function to display available travel packages
void displayPackages(struct TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No travel packages available.\n");
        return;
    }
    int i;

    printf("\nAvailable Travel Packages:\n");
    for (i = 0; i < count; i++) {
        printf("Package Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Available Seats: %d\n", packages[i].availableSeats);
        printf("---------------------------\n");
    }
}

// Function to book a travel package
void bookPackage(struct TravelPackage packages[], int count) {
    char packageName[50];
    int found = 0;
	int i;
	
    // Get the package name to book
    printf("\nEnter the package name you want to book: ");
    getchar();  // To consume newline left by previous input
    fgets(packageName, sizeof(packageName), stdin);
    packageName[strcspn(packageName, "\n")] = '\0';  // Remove the newline character

    // Search for the package and book it
    for ( i = 0; i < count; i++) {
        if (strcmp(packages[i].packageName, packageName) == 0) {
            found = 1;
            if (packages[i].availableSeats > 0) {
                packages[i].availableSeats--;
                printf("You have successfully booked the package: %s\n", packages[i].packageName);
                printf("Remaining seats: %d\n", packages[i].availableSeats);
            } else {
                printf("Sorry, no seats are available for this package.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Package with the name '%s' not found.\n", packageName);
    }
}

int main() {
    // Initialize a list of travel packages
    struct TravelPackage packages[] = {
        {"Beach Vacation", "Hawaii", 7, 1200.00, 10},
        {"Mountain Adventure", "Colorado", 5, 800.00, 5},
        {"European Tour", "France", 14, 3000.00, 8},
        {"City Escape", "New York", 3, 500.00, 12}
    };

    int count = sizeof(packages) / sizeof(packages[0]);  // Number of packages

    int choice;
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Display available travel packages\n");
        printf("2. Book a travel package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, count);  // Display available packages
                break;
            case 2:
                bookPackage(packages, count);  // Book a package
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);  // Continue until the user exits the program

    return 0;
}

