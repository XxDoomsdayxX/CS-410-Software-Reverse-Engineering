#include <iostream>
#include <string>

using namespace std;

// Global variables (used by all functions)
string customerName = "John Doe";
string customerEmail = "johndoe@example.com";
string customerPhone = "555-1234";
string customerAddress = "123 Main St";
string customerPassword = "pass123";

// Function prototypes
void DisplayInfo();
void ChangeCustomerChoice();
int CheckUserPermissionAccess();

int main() {
    cout << "Created by Darrell Walker - SNHU CS410 Project One" << endl;

    int permissionLevel = CheckUserPermissionAccess();
    if (permissionLevel == 0) {
        cout << "Access Denied." << endl;
        return 1;
    }

    int choice = 0;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Customer Info\n";
        cout << "2. Change Customer Info\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                DisplayInfo();
                break;
            case 2:
                ChangeCustomerChoice();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 3);

    return 0;
}

void DisplayInfo() {
    cout << "\n--- Customer Information ---" << endl;
    cout << "Name: " << customerName << endl;
    cout << "Email: " << customerEmail << endl;
    cout << "Phone: " << customerPhone << endl;
    cout << "Address: " << customerAddress << endl;
    // For security, password is not displayed.
}

void ChangeCustomerChoice() {
    int option;
    cout << "\nWhat would you like to change?" << endl;
    cout << "1. Name\n2. Email\n3. Phone\n4. Address\n5. Password\n";
    cout << "Enter your choice: ";
    cin >> option;
    cin.ignore(); // Clear newline from input buffer

    string newValue;
    cout << "Enter new value: ";
    getline(cin, newValue);

    switch (option) {
        case 1: customerName = newValue; break;
        case 2: customerEmail = newValue; break;
        case 3: customerPhone = newValue; break;
        case 4: customerAddress = newValue; break;
        case 5: customerPassword = newValue; break;
        default: cout << "Invalid option." << endl;
    }
}

int CheckUserPermissionAccess() {
    string enteredPassword;
    cout << "\nPlease enter your password to access the system: ";
    cin >> enteredPassword;

    if (enteredPassword == customerPassword) {
        return 2; // Full access
    } else {
        return 0; // Denied
    }
}