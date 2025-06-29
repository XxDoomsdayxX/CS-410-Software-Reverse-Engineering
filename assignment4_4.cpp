#include <iostream>
using namespace std;

int main() {
    long total = 0;
    long multiplier = 1;
    long input;

    cout << "Enter a number: ";
    cin >> input;

    while (input != 0) {
        long quotient = input / 10;
        long remainder = input - (quotient * 10);
        total += remainder * multiplier;
        multiplier *= 2;
        input = quotient;
    }

    cout << "Total: " << total << endl;
    return 0;
}
