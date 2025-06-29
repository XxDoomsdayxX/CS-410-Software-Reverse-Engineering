#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int limit = num - 1;
    int i = 1;

    while (i <= num) {
        int j = 1;
        while (j <= limit) {
            cout << "*";
            j++;
        }
        limit--;
        j = 1;
        int range = 2 * i - 1;
        while (j <= range) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

    limit = 1;
    i = 1;

    while (i <= num - 1) {
        int j = 1;
        while (j <= limit) {
            cout << "*";
            j++;
        }
        limit++;
        j = 1;
        int range = 2 * (num - i) - 1;
        while (j <= range) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

    return 1;
}
