// Copyright (c) 2022 Nathan Araujo All rights reserved.
//
// Created by: Nathan Araujo
// Created on: December 7, 2022
// This program round the persons number depending on
// how many decimal places the user enters

#include <cmath>
#include <iostream>
#include <string>

// This function round the users number to
// the amount of decimal places they want
void RoundDecimal(float &num, int numDecimals) {
    // Declared Variable
    int numberInt;
    // Multiples the users number by 10 to the power of num_decimals
    num *= pow(10, numDecimals);

    // Adds 0.5 to the users number
    num += 0.5;

    // Casts the number to an integer to remove the decimals
    num = static_cast<int>(num);

    // Divides the user num by 10 to the power of num_decimals
    num /= pow(10, numDecimals);
}

int main() {
    // Declared Variables
    std::string userNumStr, userNumDecimalsStr;
    float userNum, userNumDecimalsFloat;
    int userNumDecimals;

    // Asks user for the decimal number to round
    std::cout << "Enter a decimal number: ";
    std::getline(std::cin, userNumStr);

    // Asks the user for the number of decimal places to round
    std::cout << "Enter the number of decimal places to round to: ";
    std::getline(std::cin, userNumDecimalsStr);

    // Uses try catch to check for errors
    try {
        // Converts userNumberString to float
        userNum = static_cast<float>(userNumDecimals);

        // Converts userNumDecimalsString to a float
        userNumDecimalsFloat = stof(userNumDecimalsStr);

        // Converts userNumDecimalsString to an integer
        userNumDecimals = stoi(userNumDecimalsStr);

        // Checks if the user entered a negative number
        if (userNum < 0 || userNumDecimals != userNumDecimalsFloat) {
            // Displays error message
            std::cout << "You must enter an integer for the "
                      << "number of decimal places." << std::endl;
            // IF the user's inputs are all valid
        } else {
            // Calls RoundDecimal(userNum, userNumDecimals)
            RoundDecimal(userNum, userNumDecimals);

            // Displays the rounded number to the user
            std::cout << userNumStr << " rounded to " << userNumDecimals
                      << " decimal places: " << userNum << std::endl;
        }
        // In the event of an exception
    } catch (std::invalid_argument) {
        std::cout << "You entered invalid number(s)!" << std::endl;
    }
}
