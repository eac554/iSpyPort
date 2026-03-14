#include <iostream>
#include <string>

using namespace std;

int main() {
 
    string text;
    int sunday = 1;
    int monday = 2;
    int tuesday = 3;
    int wednesday = 4;
    int thursday = 5;
    int friday = 6;
    int saturday = 7;
    
    cout << "What day is it today? ";
    getline(cin, text);

    for (;;) {
    
        if (text == "Sunday" || text == "sunday") {
            cout << "There are " << friday - sunday << " days until Friday." << endl;
            break;

        } else if (text == "Monday" || text == "monday") {
            cout << "There are " << friday - monday << " days until Friday." << endl;
            break;

        } else if (text == "Tuesday" || text == "tuesday") {
            cout << "There are " << friday - tuesday << " days until Friday." << endl;
            break;

        } else if (text == "Wednesday" || text == "wednesday") {
            cout << "There are " << friday - wednesday << " days until Friday." << endl;
            break;

        } else if (text == "Thursday" || text == "thursday") {
            cout << "There is " << friday - thursday << " day until Friday." << endl;
            break;

        } else if (text == "Friday" || text == "friday") {
            cout << "Today is Friday!" << endl;
            break;

        } else if (text == "Saturday" || text == "saturday") {
            cout << "There are 6 days until Friday. " << endl;
            break;

        } else {
            cout << "Invalid input. Please enter a valid day of the week." << endl;
            break;
        }
    }
    
    return 0;
}