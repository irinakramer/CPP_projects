//******************************************************
// Irina Kramer
// Assignment # 3.3 - ISP
// 9/24/2013
// CS10 - #1368 (S. Sarkar)
//******************************************************
// This program calculates a customer's monthly bill
// for Internet access based on three different packages
// and on monthly usage hours.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int package;        // package choice
    double hours;          // usage hours
    const double pkgA = 9.95;
    const double pkgB = 14.95;
    const double pkgC = 19.95;
    string total = "The total amount due is $";

// User input
    cout << "Select a subscription package:" << endl
        << "1. Package A" << endl
        << "2. Package B" << endl
        << "3. Package C" << endl
        << "4. Quit" << endl;
    cin >> package;

    if ((package < 1) || (package > 4)) //validate package data range
        cout <<  "The valid choices are 1 through 4." << endl
            << "Run the program again and select one of those." << endl;
            else if (package == 4)
            {
                cout << "Quit." << endl;
                return 0;
            }
    else
    {
        cout << "\nHow many hours were used? ";
        cin >> hours;

        if ((hours < 0.00) || (hours > 744.00))
            cout << "The hours used must be between 0.00 and 744.00." << endl;
        else
        {

    // Selection and calculations
            switch (package)
            {
                case 1 :
                    if (hours > 10)
                        cout << total << pkgA + ((hours - 10) * 2) << endl;
                    else
                        cout << total << pkgA << endl;
                    break;
                case 2 :
                    if (hours > 20)
                        cout << total << pkgB + (hours - 20) << endl;
                    else
                        cout << total << pkgB << endl;
                    break;
                case 3 :
                        cout << total << pkgC << endl;
                    break;
                default :
                        cout << "Invalid input." << endl;
                    break;
            }
        } // close hours else
    }

    return 0;
}

