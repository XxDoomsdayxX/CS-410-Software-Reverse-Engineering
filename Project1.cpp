#include <iostream>
#include <string>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

struct Client {
    string name;
    int service; // 1 = Brokerage, 2 = Retirement
};

// VULNERABILITY: Client data is hardcoded into the binary and exposed to reverse engineering
// RECOMMENDATION: Load client data securely from a file or database that is encrypted and access-controlled
vector<Client> clients = {
    {"Bob Jones", 1},
    {"Sarah Davis", 2},
    {"Amy Friendly", 1},
    {"Johnny Smith", 1},
    {"Carol Spears", 2}
};

// VULNERABILITY: Plaintext password and username checked directly in code
// RECOMMENDATION: Store hashed/salted passwords in a secure config or database
const string ADMIN_USER = "admin";
const string ADMIN_PASS = "123"; // vulnerable!

// VULNERABILITY: No rate-limiting on login attempts initially
// RECOMMENDATION: Implement rate-limiting and lock account after multiple failed attempts
bool checkUserPermissionAccess() {
    string username, password;
    cout << "Hello! Welcome to our Investment Company\n";
    cout << "Enter your username:\n";
    getline(cin, username); // RECOMMENDATION: using getline for safe input
    cout << "Enter your password:\n";
    getline(cin, password);

    return (username == ADMIN_USER && password == ADMIN_PASS);
}

// VULNERABILITY: No input validation on data access; could cause buffer overflow or logic errors
// RECOMMENDATION: Validate all indexes and choices before using them
void displayClientList() {
    cout << "Client's Name  Service Selected (1 = Brokerage, 2 = Retirement)\n";
    for (int i = 0; i < (int)clients.size(); i++) {
        cout << i + 1 << ". " << clients[i].name << " selected option " << clients[i].service << "\n";
    }
}

// VULNERABILITY: No validation for client index or choice; can cause invalid data or crash
// RECOMMENDATION: Validate input ranges and check for input errors before using them
void changeClientChoice() {
    int clientIndex;
    int newChoice;

    cout << "Enter client number to change:\n";
    if (!(cin >> clientIndex)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    if (clientIndex < 1 || clientIndex > (int)clients.size()) {
        cout << "Invalid client index!\n";
        return;
    }

    cout << "Enter new choice (1 = Brokerage, 2 = Retirement):\n";
    if (!(cin >> newChoice)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    if (newChoice != 1 && newChoice != 2) {
        cout << "Invalid choice!\n";
        return;
    }

    clients[clientIndex-1].service = newChoice;
    cout << clients[clientIndex-1].name << "'s choice updated successfully!\n";
}

// VULNERABILITY: No limit on login attempts initially
// RECOMMENDATION: Implement rate-limiting and account lock after 3 failed attempts
int main() {
    int choice = 0;
    int attemptCount = 0;

    while (attemptCount < 3) {
        if (checkUserPermissionAccess()) {
            break;
        } else {
            cout << "Access denied!\n";
            attemptCount++;
        }
    }
    if (attemptCount == 3) {
        cout << "Too many failed login attempts. Goodbye.\n";
        return 0;
    }

    do {
        cout << "\nWhat would you like to do?\n";
        cout << "1. DISPLAY the client list\n";
        cout << "2. CHANGE a client's choice\n";
        cout << "3. Exit the program\n";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                displayClientList();
                break;
            case 2:
                changeClientChoice();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}