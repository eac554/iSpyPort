// Review_Problem2/main.cpp -o s
#include <iostream>
#include <fstream> // ifstream -- input file stream -- reading from a file
                  // ofstream -- output file stream -- writing to a file
                  // fout -- is not standard output(don't need to use std::cout)

using namespace std;


int triN(int n)
{

    return n * (n + 1) / 2;

}

int main()
{

    int N = 0;
    int tri[20] = { 0 }; // set the entire array to 0's, declares all 20 instantces as 0

/* cout << "This program outputs 20 triangular numbers starting at the nth triangular number." << endl;
    // exit condition loop
    do { // while (N < 1)
    cout << "What is the value of n(>0) ? " << endl;
    cin >> N;

    } while (N < 1);

    // entry condition loop

    while (N < 1)
    {
        cout << "What is the value of n(> 0) ? ";
        cin >> N;

    }
*/

    ofstream fout; // create an output file stream object

    fout.open("triangle.txt"); // open the file
    if (!fout.is_open()) // check to see if the file opened correctly
    {

        cerr << "Error: Failed to open file!" << endl; // error message to stander error
        return 1; // return with error code(other than 0 because 0 means successfully completed)
    }


        for (int i = 0; i < 20; i++)
    {

            cout << tri[i] << endl;
        }


    fout.close(); // close the file


    return 0;
}


// Triagnle1 - 1 --> *
// Triangle - 2 -->  *
//                   **

// Triangle - 3 -->  *
//                   **
//                   ***
