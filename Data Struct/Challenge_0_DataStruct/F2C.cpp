// inputs: temeperature in F (double)
// outputs: temperature in C (double)

#include <iostream>

// istream -- input stream
// ostream -- output stream
// 3 instances
    // cin -- istream -- input stream from keyboard
    // cout -- ostream -- output stream from keyboard
    // cerr -- ostream -- output to the console, output error messages

using namespace std;

double F2C(double temp)
{

    return 5.0/9.0 * (temp - 32);
}

double C2F(double temp)

        return 9 * temp / 5 + 32;

int main() {
// declare variables
    double tempF = 0.0;
    double tempC = 0.0;

// prompt user for a temperature
    cout << "Enter a temperature in F: ";
// read a value from the keyboard
    cin >> tempF;
// C = 5/9 * (F - 32)
    tempC = 5.0 / 9.0 * (tempF - 32);
// Output the final temperature
    cout << "Temperature in Celsisus is: " << F2C(temp) << endl;


    return 0;
}
