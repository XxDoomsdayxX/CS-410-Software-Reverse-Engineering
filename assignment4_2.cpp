#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    num = num * num * num;

    double result = static_cast<double>(num) * 1.23;

    cout << "Final result: " << result << endl;

    return 0;
}
