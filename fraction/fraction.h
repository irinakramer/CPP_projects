//******************************************************
// Irina Kramer
// Project 3B - Fraction Class
//******************************************************
//    Class specification file - fraction.h
//******************************************************

class fraction {
    public:
        // function prototypes
        fraction ();
        fraction (int, int);
        fraction AddedTo(fraction) const;
        fraction Subtract(fraction) const;
        fraction MultipliedBy(fraction) const;
        fraction DividedBy(fraction) const;
        bool isGreaterThan(fraction) const;
        bool isEqualTo(fraction) const;
        void print() const;
        void ReduceFrac();

    private:
        // data members
        int numerator;
        int denominator;
};

unsigned int gcd(unsigned int, unsigned int); // **
// ** source: http://en.m.wikipedia.org/wiki/Binary_GCD_algorithm
