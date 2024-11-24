#include <stdio.h>
#include <math.h>

// Structure to represent a point in 2D space
struct Point {
    float x;
    float y;
};

// Function to calculate the distance between two points
float distance(struct Point p1, struct Point p2) {
    // Euclidean distance formula
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Function to check if a point lies within a rectangular boundary
// The rectangle is defined by bottom-left (x1, y1) and top-right (x2, y2) corners
int isPointWithinRectangle(struct Point p, struct Point bottomLeft, struct Point topRight) {
    // Check if the point lies within the bounds of the rectangle
    if (p.x >= bottomLeft.x && p.x <= topRight.x && p.y >= bottomLeft.y && p.y <= topRight.y) {
        return 1;  // Point is within the rectangle
    }
    return 0;  // Point is outside the rectangle
}

int main() {
    struct Point p1, p2;
    struct Point bottomLeft, topRight;

    // Input for the two points to calculate distance
    printf("Enter coordinates of point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates of point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    // Calculate and print the distance between p1 and p2
    float dist = distance(p1, p2);
    printf("Distance between the points: %.2f\n", dist);

    // Input for the rectangular boundary
    printf("Enter bottom-left corner of rectangle (x y): ");
    scanf("%f %f", &bottomLeft.x, &bottomLeft.y);

    printf("Enter top-right corner of rectangle (x y): ");
    scanf("%f %f", &topRight.x, &topRight.y);

    // Check if point 1 lies within the rectangle
    if (isPointWithinRectangle(p1, bottomLeft, topRight)) {
        printf("Point 1 is inside the rectangle.\n");
    } else {
        printf("Point 1 is outside the rectangle.\n");
    }

    // Check if point 2 lies within the rectangle
    if (isPointWithinRectangle(p2, bottomLeft, topRight)) {
        printf("Point 2 is inside the rectangle.\n");
    } else {
        printf("Point 2 is outside the rectangle.\n");
    }

    return 0;
}

