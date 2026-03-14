#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

// Pure math functions (no IO)
inline double add(double a, double b) { return a + b; }
inline double subtract_(double a, double b) { return a - b; }
inline double multiply(double a, double b) { return a * b; }
inline double divide(double a, double b) {
    if (b == 0.0) throw invalid_argument("division by zero");
    return a / b;
}

// Read a single double with validation. Returns true on success.
bool read_double(const string &prompt, double &out) {
    cout << prompt;
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

// Read two doubles, re-prompt on invalid input.
void read_two_doubles(double &a, double &b) {
    while (true) {
        cout << "Enter two numbers separated by space: ";
        if (cin >> a >> b) break;
        cout << "Invalid input. Please enter numeric values." << '\n';
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    int choice = -1;
    cout << "\nCalculator App!\n\n";

    do {
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number from the menu." << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double a, b;
                read_two_doubles(a, b);
                cout << "Result: " << add(a, b) << '\n';
                break;
            }
            case 2: {
                double a, b;
                read_two_doubles(a, b);
                cout << "Result: " << subtract_(a, b) << '\n';
                break;
            }
            case 3: {
                double a, b;
                read_two_doubles(a, b);
                cout << "Result: " << multiply(a, b) << '\n';
                break;
            }
            case 4: {
                double a, b;
                read_two_doubles(a, b);
                while (b == 0.0) {
                    cout << "Denominator cannot be 0. Enter denominator again: ";
                    if (!(cin >> b)) {
                        cout << "Invalid input." << '\n';
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                }
                cout << "Result: " << divide(a, b) << '\n';
                break;
            }
            case 0:
                cout << "Exiting." << '\n';
                break;
            default:
                cout << "Please choose a valid menu option." << '\n';
                break;
        }

    } while (choice != 0);

    return 0;
}
