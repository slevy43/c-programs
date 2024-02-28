/*                  [converter.c]
 Converts different units of measure to each-other
 with formatted print statements and user-friendly interface
    - Spencer Levy (251-225-677)                           */

#include <stdio.h>

int main() {
    // Conversion constants
    float KILOGRAM_TO_POUND_RATIO = 2.20462f;
    float HECTARE_TO_ACRE_RATIO = 2.47105f;
    float LITRE_TO_GALLON_RATIO = 0.264172f;
    float KILOMETRE_TO_MILE_RATIO = 0.621371f;

    // Initializing variables for the user's decisions
    int typeChoice;
    char directionChoice;
    float numToConvert = 0;
    float convertedNum = 0;

    // Main loop of the program
    do {
        // Prompting for which type of unit conversion
        printf("\nWhat type of unit conversion would you like to do?\n"
               "[1]: Conversion between Kilograms and Pounds\n"
               "[2]: Conversion between Hectares and Acres\n"
               "[3]: Conversion between Litres and Gallons\n"
               "[4]: Conversion between Kilometres and Miles\n"
               "[5]: Quit\n\n"
               "Your selection: ");
        scanf("%d", &typeChoice);

        // Branches for 5 options presented to the user
        switch (typeChoice) {
            // Kilograms and Pounds
            case 1:
                printf("\nWhich direction would you like to convert in?\n"
                       "[K]: Kilograms → Pounds\n"
                       "[P]: Pounds → Kilograms\n"
                       "Your selection: ");
                scanf(" %c", &directionChoice);

                // Kilograms → Pounds
                if (directionChoice == 'k' || directionChoice == 'K') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert * KILOGRAM_TO_POUND_RATIO;
                    printf("%.2f Kilograms is equal to %.2f Pounds.\n", numToConvert, convertedNum);

                // Pounds → Kilograms
                } else if (directionChoice == 'p' || directionChoice == 'P') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert / KILOGRAM_TO_POUND_RATIO;
                    printf("%.2f Pounds is equal to %.2f Kilograms.\n", numToConvert, convertedNum);

                // Invalid input, sends back to the loop
                } else {
                    printf("\nInvalid input. Please try again.\n");
                    continue; // Go to the next iteration of the loop
                }
                break;

                // Hectares and Acres
            case 2:
                printf("\nWhich direction would you like to convert in?\n"
                       "[H]: Hectares → Acres\n"
                       "[A]: Acres → Hectares\n"
                       "Your selection: ");
                scanf(" %c", &directionChoice);

                // Hectares → Acres
                if (directionChoice == 'h' || directionChoice == 'H') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert * HECTARE_TO_ACRE_RATIO;
                    printf("%.2f Hectares is equal to %.2f Acres.\n", numToConvert, convertedNum);

                // Acres → Hectares
                } else if (directionChoice == 'a' || directionChoice == 'A') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert / HECTARE_TO_ACRE_RATIO;
                    printf("%.2f Acres is equal to %.2f Hectares.\n", numToConvert, convertedNum);

                // Invalid input, sends back to the loop
                } else {
                    printf("\nInvalid input. Please try again.\n");
                    continue; // Go to the next iteration of the loop
                }
                break;

                // Litres and Gallons
            case 3:
                printf("\nWhich direction would you like to convert in?\n"
                       "[L]: Litres → Gallons\n"
                       "[G]: Gallons → Litres\n"
                       "Your selection: ");
                scanf(" %c", &directionChoice);

                // Litres → Gallons
                if (directionChoice == 'l' || directionChoice == 'L') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert * LITRE_TO_GALLON_RATIO;
                    printf("%.2f Litres is equal to %.2f Gallons.\n", numToConvert, convertedNum);

                // Gallons → Litres
                } else if (directionChoice == 'g' || directionChoice == 'G') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert / LITRE_TO_GALLON_RATIO;
                    printf("%.2f Gallons is equal to %.2f Litres.\n", numToConvert, convertedNum);

                // Invalid input, sends back to the loop
                } else {
                    printf("\nInvalid input. Please try again.\n");
                    continue; // Go to the next iteration of the loop
                }
                break;

                // Kilometres and Miles
            case 4:
                printf("\nWhich direction would you like to convert in?\n"
                       "[K]: Kilometres → Miles\n"
                       "[M]: Miles → Kilometres\n"
                       "Your selection: ");
                scanf(" %c", &directionChoice);

                // Kilometres → Miles
                if (directionChoice == 'k' || directionChoice == 'K') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert * KILOMETRE_TO_MILE_RATIO;
                    printf("%.2f Kilometres is equal to %.2f Miles.\n", numToConvert, convertedNum);

                    // Miles → Kilometres
                } else if (directionChoice == 'm' || directionChoice == 'M') {
                    printf("\nPlease enter the value you'd like to convert: ");
                    scanf("%f", &numToConvert);
                    convertedNum = numToConvert / KILOMETRE_TO_MILE_RATIO;
                    printf("%.2f Miles is equal to %.2f Kilometres.\n", numToConvert, convertedNum);

                    // Invalid input, sends back to the loop
                } else {
                    printf("\nInvalid input. Please try again.\n");
                    continue; // Go to the next iteration of the loop
                }
                break;

                // Quit
            case 5:
                printf("Exiting the program.\n");
                break;

                // Default case for invalid choices
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
                break;
        }

    } while (typeChoice != 5); // Continue the loop until the user chooses to quit

    // End of the program
    return 0;
}