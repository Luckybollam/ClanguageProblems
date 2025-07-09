#include <stdio.h>

void shiftArrayDown(int arr[], int size) {
    if (size <= 1) { // No shifting needed for arrays with 0 or 1 element
        return;
    }

    int lastElement = arr[size - 1]; // Store the last element

    // Shift elements to the right
    for (int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement; // Place the stored element at the beginning
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    shiftArrayDown(myArray, size);

    printf("Array after shifting down: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    return 0;
}