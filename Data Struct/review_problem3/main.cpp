#include <iostream>
#include <fstream>
using namespace std;

void displayMenu()
{
        cout << "Would you like to \n "
        << "1. Convert F to C \n "
        << "2. Convert F to K \n "
        << "3. Convert C to F \n "
        << "4. Convert C to K \n " 
        << "5. Convert K to F \n "
        << "6. Convert K to C \n "
        << "7. Exit " << endl;
}

double F2C(double tempF) {

    double tempC = 5.0 / 9.0 * (tempF - 32); // could be faster
    return tempC;
}

double F2K(double tempF ) {

    double tempK = (tempF - 32) * 5.0 / 9.0 + 273.15; // could be faster
    return tempK;
}

double C2F(double tempC) {

    double tempF = 9.0 / 5.0 * tempC + 32;
    return tempF;
}

double C2K(double tempC) {

    double tempK = tempC + 273.15;
    return tempK;
}

double K2F(double tempK) {

    double tempF = (tempK - 273.15) * 9.0 / 5.0 + 32;
    return tempF;
}

double K2C(double tempK) {

    double tempC = tempK - 273.15;
    return tempC;
}









int main() {
    
    int opt = 0;
    double temp = 0.0;
    double tempF;
    double tempC;
    double tempK;

    displayMenu();

    while (true)
    {
        cout << "> ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter temperature in F >";
            cin >> tempF;
            cout << "Temperature in C is " << F2C(tempF) << endl;
            break;
        case 2:
            cout << "Enter temperature in F >";
            cin >> tempF;
            cout << "Temperature in K is " << F2K(tempF) << endl;
            break;
        case 3:
            cout << "Enter temperature in C >";
            cin >> tempC;
            cout << "Temperature in F is " << C2F(tempC) << endl;
            break;
        case 4:
            cout << "Enter temperature in C >";
            cin >> tempC;
            cout << "Temperature in K is " << C2K(tempC) << endl;
            break;
        case 5:
            cout << "Enter temperature in K >";
            cin >> tempK;
            cout << "Temperature in F is " << K2F(tempK) << endl;
            break;
        case 6:
            cout << "Enter temperature in K >";
            cin >> tempK;
            cout << "Temperature in C is " << K2C(tempK) << endl;
            break;
        case 7:
            return 0;
        default:
            displayMenu();
            break;

        }

    }
    return 0;
}