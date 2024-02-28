/*                  [intToEnglish.c]
 Converts integer values to plain-English terms
 with formatted print statements and user-friendly interface
    - Spencer Levy (251-225-677)                           */

#include <stdio.h>

// Declaring helper functions
void printHundredNums(int digit);            // Plain numbers
void printNumsOneToNine(int digit);          // Hyphenated numbers
void printTeens(int digit);                  // Uniquely named 10's numbers that start with 1
void printNumties(int digit, int onesDigit); // "Forties" "Fifties" "___ties". Makes sense.

int main() {
    // Number inputted by user, and array to store each digit of that number
    int chosenNumber;
    int numAsArray[3];

    // Main loop of the program
    do {
        // Prompting for the user to input a number
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &chosenNumber);

        // Converting the number to an array
        int tempNumber = chosenNumber;
        for (int i = 2; i >= 0; i--) {
            numAsArray[i] = tempNumber % 10;  // Get the last digit
            tempNumber /= 10;                 // Remove the last digit
        }

        // Printing final statement if user doesn't quit:
        if (chosenNumber != 0) printf("You entered the number ");

    // 100's slot
        if (numAsArray[0] != 0) {
            // Case 1: "hundred" (no numbers following)
            if (numAsArray[1] == 0 && numAsArray[2] == 0) {
                printHundredNums(numAsArray[0]);
                printf(" hundred");
            }
                // Case 2: "and": (numbers following)
            else {
                printHundredNums(numAsArray[0]);
                printf(" hundred and ");
            }
        }

    // 10's and 1's slot
        // If there is a number in the 10's place OR the 1's:
        if (numAsArray[1] != 0 || numAsArray[2] != 0) {
            if (numAsArray[1] != 0) { // If there is a number in the 10's place
                printNumties(numAsArray[1], numAsArray[2]);}
            else {                   // If there is no number in the 10's place
                printHundredNums(numAsArray[2]);}
        }

        // Separating next iteration
        printf("\n\n");

    } while (chosenNumber != 0); // Continue the loop until the user chooses to quit

    // End of the program
    return 0;
}

// Helper methods
void printHundredNums(int digit) {
    switch (digit) {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
    }
}

void printNumsOneToNine(int digit) {
    switch (digit) {
        case 1:
            printf("-one");
            break;
        case 2:
            printf("-two");
            break;
        case 3:
            printf("-three");
            break;
        case 4:
            printf("-four");
            break;
        case 5:
            printf("-five");
            break;
        case 6:
            printf("-six");
            break;
        case 7:
            printf("-seven");
            break;
        case 8:
            printf("-eight");
            break;
        case 9:
            printf("-nine");
            break;
    }
}

void printTeens(int digit) {
    switch (digit) {
        case 0:
            printf("ten");
            break;
        case 1:
            printf("eleven");
            break;
        case 2:
            printf("twelve");
            break;
        case 3:
            printf("thirteen");
            break;
        case 4:
            printf("fourteen");
            break;
        case 5:
            printf("fifteen");
            break;
        case 6:
            printf("sixteen");
            break;
        case 7:
            printf("seventeen");
            break;
        case 8:
            printf("eighteen");
            break;
        case 9:
            printf("nineteen");
            break;
    }
}

void printNumties(int digit, int onesDigit) {
    switch (digit) {
        case 1:
            printTeens(onesDigit);
            break;
        case 2:
            printf("twenty");
            printNumsOneToNine(onesDigit);
            break;
        case 3:
            printf("thirty");
            printNumsOneToNine(onesDigit);
            break;
        case 4:
            printf("forty");
            printNumsOneToNine(onesDigit);
            break;
        case 5:
            printf("fifty");
            printNumsOneToNine(onesDigit);
            break;
        case 6:
            printf("sixty");
            printNumsOneToNine(onesDigit);
            break;
        case 7:
            printf("seventy");
            printNumsOneToNine(onesDigit);
            break;
        case 8:
            printf("eighty");
            printNumsOneToNine(onesDigit);
            break;
        case 9:
            printf("ninety");
            printNumsOneToNine(onesDigit);
            break;
    }
}
