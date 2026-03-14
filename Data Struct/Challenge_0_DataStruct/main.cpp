#include <iostream>
#include <string>

using namespace std;

int main()
{
    char txt;

    cout << "Is it raining?" << endl;
    cin >> txt;

    if (txt == 'y') {
        cout << "It is raining outside." << endl;
    }

    else if (txt == 'n') {
        cout << "It is not raining outside." << endl;
    }

    else {
        cout << "Not valid answer" << endl;
    }

    return 0;
}
