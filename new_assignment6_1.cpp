#include <iostream>
#include <limits>  // Used to handle invalid user input
using namespace std;

// DisplayMenu()
// This function prints the calculator menu options for the user
// Matches the original DisplayMenu function seen in the assembly
void DisplayMenu() {
    cout << "\n\n--- Calculator Menu ---" << endl;          // (Title added for user clarity)
    cout << "-----------------------" << endl;
    cout << "1. Subtract" << endl;                           // Option 1
    cout << "2. Add" << endl;                                // Option 2
    cout << "3. Divide" << endl;                             // Option 3 added to complete menu
    cout << "4. Multiply" << endl;                           // Option 4
    cout << "5. Exit" << endl;                               // Option 5 to exit program
    cout << "-----------------------" << endl;
    cout << "Enter your choice: ";                           // Clarifies when and where to enter a number
}

int main() {
    int choice = 0;  // Stores user's menu selection
    int a, b;        // Variables used for arithmetic operations

    while (choice != 5) {
        DisplayMenu();  // Call separate menu display function

        cin >> choice;  // Capture user’s menu selection

        // Input validation for menu choice
        // Prevents invalid characters (e.g., letters) from crashing the program
        if (cin.fail()) {
            cin.clear();  // Clear input stream error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;  // Skip rest of loop and return to menu
        }

        // Only prompt for numbers if a valid operation was selected
        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";  // Prompt user for two operands
            cin >> a >> b;

            // Input validation for operands a and b
            // Ensures both inputs are valid integers
            if (cin.fail()) {
                cin.clear();  // Clear any stream errors
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Remove invalid input
                cout << "Invalid numbers entered. Try again." << endl;
                continue;
            }
        }

        // Main operation logic using switch for cleaner branching
        switch (choice) {
            case 1:
                // Subtraction operation
                cout << a << " - " << b << " = " << (a - b) << endl;
                break;

            case 2:
                // Addition operation
                cout << a << " + " << b << " = " << (a + b) << endl;
                break;

            case 3:
                // Division operation
                // Originally missing in the C++ logic — added here to complete functionality
                // Security Vulnerability Fixed: Added divide-by-zero check
                if (b == 0) {
                    cout << "Error: Cannot divide by zero." << endl;  // Prevents program crash
                } else {
                    cout << a << " / " << b << " = " << (a / b) << endl;
                }
                break;

            case 4:
                // Multiplication operation
                cout << a << " * " << b << " = " << (a * b) << endl;
                break;

            case 5:
                // Exit option
                cout << "Exiting program." << endl;
                break;

            default:
                // Handles out-of-range numbers (e.g., 6 or 99)
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;  // Return successful exit code
}