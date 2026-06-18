#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Simple Calculator\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nChoose an operation:\n";
    cout << "+ : Addition\n";
    cout << "- : Subtraction\n";
    cout << "* : Multiplication\n";
    cout << "/ : Division\n";
    cout << "Enter operator: ";
    cin >> op;

    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "Result = " << result;
            break;

        case '-':
            result = num1 - num2;
            cout << "Result = " << result;
            break;

        case '*':
            result = num1 * num2;
            cout << "Result = " << result;
            break;

        case '/':
            if(num2 != 0)
                cout << "Result = " << num1 / num2;
            else
                cout << "Error! Division by zero is not allowed.";
            break;

        default:
            cout << "Invalid operator!";
    }

    return 0;
}