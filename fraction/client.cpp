//******************************************************
// Irina Kramer
// Project 3B - Fraction Class
// 11/20/2013
// CS10 - #1368 (S Sarkar)
//******************************************************
// This program defines Fractions Class and conducts
// arithmetic operations with different fractions
//******************************************************
//                  Client file - client.cpp
//******************************************************
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    fraction f1(9,8); //calling a parameterized class constructor
    fraction f2(2,3); //calling a parameterized class constructor
    fraction result;  //calling a default class constructor
    fraction f3; //calling a default class constructor

    cout << "The result starts off at ";
    result.print(); //calling an observer function
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";

    result = f1.MultipliedBy(f2); //a class binary operation - function
    result.print();
    cout << endl;


    f3 = result; //assignment

    if (f2.isGreaterThan(f3)){ //a class relational expression - boolean operation/function
        f2.print();
        cout <<" is greater than ";
        f3.print();
        cout<<endl;
    } else {
        f2.print();
        cout <<" is less than ";
        f3.print();
        cout<<endl;
    }

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.AddedTo(f2); //a class binary operation - function
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.Subtract(f2); //a class binary operation - function
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){ //a class relational expression - boolean operation/function
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }

    const fraction f4(12, 8);
    const fraction f5(202, 303);

    result = f4.DividedBy(f5); //a class binary operation - function
    cout << "The quotient of ";
    f4.print();
    cout << " and ";
    f5.print();
    cout << " is ";
    result.print();
    cout << endl;


    return 0;
}
