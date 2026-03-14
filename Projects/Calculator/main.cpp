#include <iostream>

using namespace std;

double user_num;
double user_num2;

// functions to do the math for cleaner code
double addition(double user_num, double user_num2) {
    cout << "enter two inputs: ";

    cin >> user_num;
    cin >> user_num2;

    cout << "Your answer is: " << user_num + user_num2 << endl;
    
    return 0;
}
double subtraction (double user_num, double user_num2) {
    cout << "enter two inputs: ";

    cin >> user_num;
    cin >> user_num2;

    cout << "Your answer is: " << user_num - user_num2 << endl;
    return 0;
}
double multiplication (double user_num, double user_num2) {
    cout << "enter two inputs: ";

    cin >> user_num;
    cin >> user_num2;

    cout << "Your answer is: " << user_num * user_num2 << endl;

    return 0;
}

double division (double user_num, double user_num2) {
    cout << "enter two inputs: ";
    cin >> user_num;
    cin >> user_num2;

    // ensure denominator is not zero
    while (user_num2 == 0) {
        cout << "Denominator cannot be 0. Enter denominator again: ";
        cin >> user_num2;
    }
    cout << "Your answer is: " << user_num / user_num2 << endl;

    return 0;
}

int main() {
    int choice;
// Main function to control the entire application
    cout << endl;
    cout << "Calculator App! " << endl << endl;
    cout << "What would you like to do? " << endl << endl;

    do {
    cout << "1. Addition " << endl << endl;
    cout << "2. Subtraction " << endl << endl;
    cout << "3. Multiplication " << endl << endl;
    cout << "4. Division " << endl;
    cin >> choice;
// switch statement to  understand what problem to solve
    switch(choice) {
        case 1:
            cout << "You chose Addition, ";
            addition(user_num, user_num2);
            break;
        case 2:
            cout << "You chose Subtraction, ";
            subtraction(user_num, user_num2);
            break;
        case 3:
            cout << "You chose Multiplication, ";
            multiplication(user_num, user_num2);
            break;
        case 4:
            cout << "You chose Division, ";
            division(user_num, user_num2);
            break;
        default:
            choice = 0;
    }
} while (choice != 0);
return 0;
}