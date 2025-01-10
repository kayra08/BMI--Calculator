#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a structure to store user data
typedef struct {
    char username[50];
    double lastBMI;
    int isFirstEntry;
} UserData;

// Function prototypes
double calculateBMI(double weight, double height);
const char* interpretBMI(double bmi);
int isValidNumber(const char *str);
void printMenu();
void clearInputBuffer();
void updateUserData(UserData* user, double newBMI);
void displayProgress(UserData* user, double newBMI);

// Main function
int main() {
    char username[50];
    char weightInput[50], heightInput[50];
    double weight = 0.0, height = 0.0, bmi = 0.0;
    UserData user;

    // Initialize user data
    user.isFirstEntry = 1;
    user.lastBMI = 0.0;

    // Display menu
    printMenu();

    // Get username
    printf("\nEnter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character
    strncpy(user.username, username, sizeof(user.username) - 1);
    user.username[sizeof(user.username) - 1] = '\0'; // Ensure null termination

    printf("\nWelcome, %s! Let's calculate your BMI.\n", user.username);

    // Input weight in kilograms
    while (1) {
        printf("\nPlease enter your weight in kilograms (e.g., 70.5): ");
        if (fgets(weightInput, sizeof(weightInput), stdin)) {
            weightInput[strcspn(weightInput, "\n")] = 0; // Remove trailing newline
            if (isValidNumber(weightInput)) {
                weight = atof(weightInput);
                if (weight > 0) {
                    break;
                } else {
                    printf("Error: Weight must be a positive number.\n");
                }
            } else {
                printf("Error: Invalid input. Please enter a numeric value.\n");
            }
        } else {
            clearInputBuffer();
        }
    }

    // Input height in meters
    while (1) {
        printf("\nPlease enter your height in meters (e.g., 1.75): ");
        if (fgets(heightInput, sizeof(heightInput), stdin)) {
            heightInput[strcspn(heightInput, "\n")] = 0; // Remove trailing newline
            if (isValidNumber(heightInput)) {
                height = atof(heightInput);
                if (height > 0) {
                    break;
                } else {
                    printf("Error: Height must be a positive number.\n");
                }
            } else {
                printf("Error: Invalid input. Please enter a numeric value.\n");
            }
        } else {
            clearInputBuffer();
        }
    }

    // Calculate BMI
    bmi = calculateBMI(weight, height);

    // Update user data and display progress
    updateUserData(&user, bmi);
    displayProgress(&user, bmi);

    // Display results
    printf("\n====================================\n");
    printf("Your BMI is: %.2f\n", bmi);
    printf("BMI Category: %s\n", interpretBMI(bmi));
    printf("====================================\n\n");

    printf("Thank you for using the BMI Calculator, %s. Stay healthy!\n", user.username);

    // Wait for user input before exiting
    printf("\nPress Enter to exit the program...");
    clearInputBuffer(); // Clear any residual input buffer
    getchar(); // Wait for the user to press Enter

    return 0;
}

// Function to calculate BMI based on weight and height
double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

// Function to interpret BMI value and return the category
const char* interpretBMI(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        return "Normal weight";
    } else if (bmi >= 25 && bmi < 29.9) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

// Function to validate numeric input
int isValidNumber(const char *str) {
    int dotCount = 0;
    if (*str == '\0') {
        return 0; // Empty string is not valid
    }
    while (*str) {
        if (!isdigit(*str)) {
            if (*str == '.' && dotCount == 0) {
                dotCount++;
            } else {
                return 0; // Return false if a non-numeric character is found
            }
        }
        str++;
    }
    return 1; // Return true if all characters are numeric or a single decimal point
}

// Function to print menu and instructions
void printMenu() {
    printf("====================================\n");
    printf("          BMI CALCULATOR MENU          \n");
    printf("====================================\n");
    printf("1. Enter your username.\n");
    printf("2. Input your weight and height.\n");
    printf("3. View your BMI and category.\n");
    printf("4. See progress since your last BMI entry.\n");
    printf("5. Exit the program.\n");
    printf("====================================\n\n");
}

// Function to clear the input buffer in case of invalid input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Clear the buffer
    }
}

// Function to update user data
void updateUserData(UserData* user, double newBMI) {
    if (user->isFirstEntry) {
        user->isFirstEntry = 0;
    }
    user->lastBMI = newBMI;
}

// Function to display progress based on BMI changes
void displayProgress(UserData* user, double newBMI) {
    if (user->isFirstEntry) {
        printf("\nThis is your first BMI entry. Keep tracking your progress!\n");
    } else {
        if (newBMI < user->lastBMI) {
            printf("\nGreat job, %s! Your BMI has improved since your last entry.\n", user->username);
        } else if (newBMI > user->lastBMI) {
            printf("\nTake care, %s. Your BMI has increased since your last entry. Consider consulting a healthcare professional.\n", user->username);
        } else {
            printf("\nYour BMI remains the same, %s. Stay consistent and keep up the good work!\n", user->username);
        }
    }
}
