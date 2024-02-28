/*                  [assign2-part1.c]
User creates array specifying amount of values, and values of the array.
6 main functions perform operations on the array, without changing original array.
    - Spencer Levy (251-225-677)     */

#include <stdio.h>

int main() {

    // 6 main Part functions
    void p1_print(int userArray[], int size);
    void p2_reverse(int userArray[], int size);
    void p3_even(int userArray[], int size);
    void p4_sum(int userArray[], int size);
    void p5_ascending(int userArray[], int size);
    void p6_firstLastSwap(int userArray[], int size);

    // Where user's choice will be stored
    int numIntegers;

    // Infinite loop until valid input is received
    while (1) {

        // 1: User prompted for amount of integers
        printf("Please enter the number of integers to process (between 5-12): ");
        scanf("%d", &numIntegers);

            // Ensuring valid amount of inputs
            if (numIntegers >= 5 && numIntegers <= 12) {
                break; // Exit the loop if input is valid
            } else {printf("Invalid amount of inputs. Please try again.\n\n");} }

    // Making array: (a) Printing # of integers, (b) Array size in bytes
        int userArray[numIntegers];
        printf("• There is enough room in your array for %d integers (%lu bytes): \n", numIntegers, sizeof(userArray));

    // 2: Prompt and collect integers
    printf("\nPlease enter your integers separated by spaces: ");
    for (int i=0; i < numIntegers; i++){
        scanf("%d", &userArray[i]);}

    // 3: Parts 1-6: array operations
    p1_print(userArray, numIntegers);
    p2_reverse(userArray, numIntegers);
    p3_even(userArray, numIntegers);
    p4_sum(userArray, numIntegers);
    p5_ascending(userArray, numIntegers);
    p6_firstLastSwap(userArray, numIntegers);

    // End of program
    return 0;
}

// Part 1-6 methods
void p1_print(int userArray[], int size) {
    printf("\nPart 1:\n   Your array is: ");
    for (int i=0; i < size; i++){             // [i] starts at 0, increments to the last element
        printf("[%d] = %d ", i, userArray[i]);}
}

void p2_reverse (int userArray[], int size) {
    printf("\n\nPart 2:\n   Your array in reverse is: ");
    for (int i = size-1; i >= 0 ; i--){      // [i] starts at end of list, decrements towards first element [0]
        printf("[%d] = %d ", i, userArray[i]);}
}

void p3_even (int userArray[], int size) {
    printf("\n\nPart 3:\n   The even elements in the array is: ");
    int hasEven = 0;
    for (int i=0; i < size; i++){            // Only prints elements that are divisible by 2 using [%] operator
        if (userArray[i] % 2 == 0) {printf("[%d] = %d ", i, userArray[i]);
        hasEven = 1;}}
    if (hasEven == 0) {printf("Array has no even elements!");}
}

void p4_sum (int userArray[], int size) {
    printf("\n\nPart 4:\n   The sum of all values in your array is: ");
    int sum = 0;                  // Loops through the array and adds each value to sum counter
    for (int i=0; i < size; i++){
        sum += userArray[i];}
    printf("%d", sum);            // Prints [sum] when the array has been looped through and added up
}

void p5_ascending (int userArray[], int size) {

    // Copying array (to preserve original)
    int copyArray[size];
    for (int i = 0; i < size; i++) {
        copyArray[i] = userArray[i];}

    // Bubble sort copied array
    for (int i=0; i < size -1; i++) {
        for (int j=0; j < size -1; j++) {
            if(copyArray[j] > copyArray[j+1]) {
                int temp = copyArray[j];
                copyArray[j] = copyArray[j+1];
                copyArray[j+1] = temp;} } // [j] loop
    } // [i] loop

    // Using sorted array to print for userArray: [original index] = sorted value:
    printf("\n\nPart 5:\n   Your array in sorted order is: ");
    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++) {
            if (copyArray[i] == userArray[j]) {
                printf("[%d] = %d ", j, userArray[j]);
                break;}} // [j] loop
        } // [i] loop
}

void p6_firstLastSwap (int userArray[], int size) {
    printf("\n\nPart 6:\n   Your array with first and last element switched is: ");

        // Print last element, first
        printf("[%d] = %d ", (size-1), userArray[size-1]);

        // Print elements from [1] -> [size-2]
            for (int i=1; i < size-1; i++) {
                printf("[%d] = %d ", i, userArray[i]);}

        // Print first element, last
        printf("[0] = %d ", userArray[0]);

    printf("\n");
}