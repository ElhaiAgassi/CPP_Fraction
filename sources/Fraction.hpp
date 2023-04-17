#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
    Fraction();
    Fraction(int numerator, int denominator);

    // Arithmetic operators
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Added overload functions for arithmetic operators with double
    friend Fraction operator+(const Fraction& fraction, double value);
    friend Fraction operator-(const Fraction& fraction, double value);
    friend Fraction operator*(const Fraction& fraction, double value);
    friend Fraction operator/(const Fraction& fraction, double value);
    // Add the other way
    friend Fraction operator+(double value, const Fraction& fraction);
    friend Fraction operator-(double value, const Fraction& fraction);
    friend Fraction operator*(double value, const Fraction& fraction);
    friend Fraction operator/(double value, const Fraction& fraction);



    // Comparison operators
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;

    // Added overload functions for comparison operators with double
    friend bool operator>(double value, const Fraction& fraction);
    friend bool operator<(const Fraction& fraction, double value);
    friend bool operator>=(const Fraction& fraction, double value);
    friend bool operator<=(const Fraction& fraction, double value);

    // Increment/Decrement operators
    Fraction& operator++();    // Prefix increment
    Fraction operator++(int);  // Postfix increment
    Fraction& operator--();    // Prefix decrement
    Fraction operator--(int);  // Postfix decrement

    // Output/Input stream operators
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);

    // Accessor functions for numerator and denominator
    int getNumerator() const;
    int getDenominator() const;

private:
    int numerator;
    int denominator;

    // Helper functions

};

// // Implementation of accessor functions for numerator and denominator
// int Fraction::getNumerator() const {
//     return numerator;
// }

// int Fraction::getDenominator() const {
//     return denominator;
// }

#endif  // FRACTION_H
