#include <iostream>

using namespace std;

int main() {

    // Declared variables for the input numbers from the user
    double num1 = 0;
    double num2 = 0;

    // Displayed a message for the user to enter two floating numbers
    cout << "Enter the first number (floating-point): ";
    cin >> num1;
    cout << "Enter the second number (floating-point): ";
    cin >> num2;

    // Declared variables to store the results of arithmetic operations
    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    double quotient = num1 / num2;

    // Performed arithmetic operations and displayed the results
    cout << "\nFloating-point results:\n";
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    // Converted floating numbers to integers
    int intNum1 = static_cast<int>(num1);
    int intNum2 = static_cast<int>(num2);

    // Declared variables to store integer division and modulus operation results
    int intQuotient = intNum1 / intNum2;
    int modulus = intNum1 % intNum2;

    // Performed integer division and modulus operation and displayed the results
    cout << "\nInteger results (using truncated values):\n";
    cout << "Integer Division Quotient: " << intQuotient << endl;
    cout << "Modulus: " << modulus << endl;

    return 0;
}