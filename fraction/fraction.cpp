//******************************************************
// Irina Kramer
// Project 3B - Fraction Class
//******************************************************
//          Implementation file fraction.cpp
//******************************************************
#include <iostream>
#include "fraction.h"
using namespace std;




//******************************************************
// Default constructor
// This function sets initial data member values to 0.
//******************************************************
 fraction::fraction ()
 // Post: numerator and denominator set to 0.
 {
     numerator = 0;
     denominator = 1;
 }




//******************************************************
// Parameterized constructor
// This function assigns variables to data members,
// it reduces the fraction to lowest form.
//******************************************************
 fraction::fraction (int n, int d)
 // Pre: n and d initialized
 // Post: numerator set to n, denominator set to 1 or d.
 //       Call ReduceFrac() function.
 {
     numerator = n;
     denominator = d == 0 ? 1 : d; // if d = 0, set d to 1, otherwise use d.
     ReduceFrac();
 }




//******************************************************
// Observer function
// This is a value returning function that adds two
// instances of a fraction
//******************************************************
fraction fraction::AddedTo(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: fraction + f object is returned.
{
    return fraction (numerator*f.denominator + f.numerator*denominator, denominator*f.denominator);
}




//******************************************************
// Observer function
// This is a value returning function that subtracts two
// instances of a fraction
//******************************************************
fraction fraction::Subtract(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: fraction - f object is returned.
{
    return fraction (numerator*f.denominator - f.numerator*denominator, denominator*f.denominator);
}




//******************************************************
// Observer function
// This is a value returning function that computes
// the product of two instances of a fraction
//******************************************************
fraction fraction::MultipliedBy(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: fraction * f object is returned
{
    return fraction (numerator * f.numerator,       // multiply numerators
                     denominator * f.denominator);  // multiply denominators
}




//******************************************************
// Observer function
// This is a value returning function that computes
// the division of two instances of a fraction
//******************************************************
fraction fraction::DividedBy(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: fraction / f instance object is returned
{
    return fraction (numerator * f.denominator, denominator * f.numerator);
}




//******************************************************
// Observer function
// This is a value returning function that compares
// two instances of a fraction class
//******************************************************
bool fraction::isGreaterThan(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: return true if fraction object is greater than
//      its instance f, otherwise return false.
{
    return (numerator*f.denominator > denominator*f.numerator);
}




//******************************************************
// Observer function
// This is a value returning function that returns true
// if two instances of a fraction class are equal
//******************************************************
bool fraction::isEqualTo(fraction f) const
// Pre: both fraction and f instance are initialized.
// Post: return true if both fractions are equal, otherwise return false.
{
    return (numerator == f.numerator && denominator == f.denominator);
}




//******************************************************
// Observer function
// This function outputs the fraction to the screen
// in the form numerator/denominator.
//******************************************************
void fraction::print() const
//Post: fraction is output to the screen
{
    cout << numerator << "/" << denominator;
}




//******************************************************
// Transformer function
// This function reduces the fraction instance
// to the lowest terms.
//******************************************************
void fraction::ReduceFrac()
// Post: numerator and denominator is reduced to the lowest
//      terms
{
    // declare divisor variable
    int divisor = gcd(numerator, denominator);  // calling gcd function
    numerator /= divisor;
    denominator /= divisor;
}




//******************************************************
// Greatest common divisor
// Source: http://en.m.wikipedia.org/wiki/Binary_GCD_algorithm
//
// This is a value returning function that computes
// the greatest common divisor of two integers.
// It is called in the ReduceFrac() function.
//******************************************************

unsigned int gcd(unsigned int n, unsigned int d)
{
    // simple cases (termination)
    if (n == d)
        return n;

    if (n == 0)
        return d;

    if (d == 0)
        return n;

    // look for factors of 2
    if (n % 2 == 0) // n is even
    {
        if (d % 2 != 0) // d is odd
            return gcd(n / 2, d);
        else // both n and d are even
            return gcd(n / 2, d / 2) * 2;
    }

    if (d % 2 == 0) // n is odd, d is even
        return gcd(n, d / 2);

    // reduce larger argument
    if (n > d)
        return gcd((n - d) / 2, d);

    return gcd((d - n) / 2, n);
}

