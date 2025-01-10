# BMI Calculator Project

## Project Description
The BMI Calculator project is a command-line tool designed to calculate the Body Mass Index (BMI) of users. This program provides BMI calculations based on the user's weight and height inputs, categorizes the BMI into various health ranges, and tracks the user's progress over time.

## Features
- *User-Friendly Interface*: Easy-to-follow menu-driven interaction.
- *Accurate BMI Calculation*: Calculates BMI using the formula BMI = weight / (height * height).
- *BMI Categories*: Provides interpretation of BMI into categories (e.g., Underweight, Normal weight, Overweight, Obese).
- *Progress Tracking*: Tracks and compares the user’s current BMI with the last recorded value.
- *Error Handling*: Validates user inputs for weight and height, ensuring only numeric and positive values are accepted.

## Technical Details
- *Language*: C
- *Key Libraries*: stdio.h, stdlib.h, ctype.h, string.h
- *Data Structures*: struct is used to manage user data effectively.

## Installation
### Prerequisites
- GCC compiler installed on your system.
- A terminal or command-line interface.

### Steps
1. Clone the project repository or download the source code.
2. Open a terminal and navigate to the project directory.
3. Compile the program using the following command:
   
   gcc -o bmi_calculator bmi_calculator.c
   
4. Run the program with:
   
   ./bmi_calculator
   

## Usage
1. Launch the program in your terminal.
2. Enter your username when prompted.
3. Input your weight in kilograms and height in meters when requested.
4. View your BMI and its category.
5. Track progress if you have a previous entry.
6. Exit the program by pressing Enter when prompted.

### Example
plaintext
====================================
          BMI CALCULATOR MENU          
====================================
1. Enter your username.
2. Input your weight and height.
3. View your BMI and category.
4. See progress since your last BMI entry.
5. Exit the program.
====================================

Enter your username: KayraBuyuk
Welcome, KayraBuyuk! Let's calculate your BMI.

Please enter your weight in kilograms (e.g., 70.5): 70.5
Please enter your height in meters (e.g., 1.75): 1.75

====================================
Your BMI is: 23.02
BMI Category: Normal weight
====================================

Thank you for using the BMI Calculator, KayraBuyuk. Stay healthy!


## Team Members
- *Kayra Küçük* - Project Lead
- *Canberk Çiroz, Altan Armağan, Merve Nur İncel, Elif Özer* - Contributors

## Screenshots
(Include relevant screenshots or demo images if applicable)

## File Structure
plaintext
.
├── bmi_calculator.c  # Source code for the BMI Calculator
└── README.md          # Documentation file


## Acknowledgments
- Inspired by the need for accessible health monitoring tools.
- Thanks to [Your Organization/Community] for support.

## License
This project is licensed under the MIT License. See the LICENSE file for details.
