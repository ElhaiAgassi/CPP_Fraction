#include "Fraction.hpp"
#include <iostream>
#include <sstream>
using namespace std;
namespace ariel
{

    // Default constructor
    Fraction::Fraction() : numerator(0), denominator(1) {}

    // Constructor with numerator and denominator
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    // Arithmetic operators

    Fraction Fraction::operator+(const Fraction &other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den).reduce();
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den).reduce();
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den).reduce();
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den).reduce();
    }

    // Overloaded operator+ with Fraction and double operand
    Fraction operator+(const Fraction &fraction, double value)
    {
        return Fraction(fraction.numerator + fraction.denominator * value, fraction.denominator).reduce();
    }

    // Overloaded operator- with Fraction and double operand
    Fraction operator-(const Fraction &fraction, double value)
    {
        return Fraction(fraction.numerator - fraction.denominator * value, fraction.denominator).reduce();
    }

    // Overloaded operator* with Fraction and double operand
    Fraction operator*(const Fraction &fraction, double value)
    {
        return Fraction(fraction.numerator * value, fraction.denominator).reduce();
    }

    // Overloaded operator/ with Fraction and double operand
    Fraction operator/(const Fraction &fraction, double value)
    {
        return Fraction(fraction.numerator / value, fraction.denominator).reduce();
    }

    // Overloaded operator+ with double and Fraction operand
    Fraction operator+(double value, const Fraction &fraction)
    {
        return Fraction(fraction.numerator + fraction.denominator * value, fraction.denominator).reduce();
    }

    // Overloaded operator- with double and Fraction operand
    Fraction operator-(double value, const Fraction &fraction)
    {
        return Fraction(fraction.denominator * value - fraction.numerator, fraction.denominator).reduce();
    }

    // Overloaded operator* with double and Fraction operand
    Fraction operator*(double value, const Fraction &fraction)
    {
        return Fraction(fraction.numerator * value, fraction.denominator).reduce();
    }

    // Overloaded operator/ with double and Fraction operand
    Fraction operator/(double value, const Fraction &fraction)
    {
        return Fraction(value * fraction.denominator, fraction.numerator).reduce();
    }

    // Comparison operators

    bool Fraction::operator==(const Fraction &other) const
    {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }

    bool Fraction::operator>(const Fraction &other) const
    {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    bool Fraction::operator<(const Fraction &other) const
    {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    // Overloaded operator> with double and Fraction operand
    bool operator>(const Fraction &fraction, double value)
    {
        return value > (static_cast<double>(fraction.getNumerator()) / fraction.getDenominator());
    }

    // Overloaded operator< with Fraction and double operand
    bool operator<(const Fraction &fraction, double value)
    {
        return (static_cast<double>(fraction.getNumerator()) / fraction.getDenominator()) < value;
    }

    // Overloaded operator>= with Fraction and double operand
    bool operator>=(const Fraction &fraction, double value)
    {
        return (static_cast<double>(fraction.getNumerator()) / fraction.getDenominator()) >= value;
    }

    // Overloaded operator<= with Fraction and double operand
    bool operator<=(const Fraction &fraction, double value)
    {
        return (static_cast<double>(fraction.getNumerator()) / fraction.getDenominator()) <= value;
    }

    bool Fraction::operator>=(const Fraction &other) const
    {
        return !(*this < other);
    }

    bool Fraction::operator<=(const Fraction &other) const
    {
        return !(*this > other);
    }

    // Increment/Decrement operators

    Fraction &Fraction::operator++()
    {
        numerator += denominator;
        this->reduce();
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
        Fraction temp(*this);
        numerator += denominator;
        this->reduce();
        return temp;
    }

    Fraction &Fraction::operator--()
    {
        numerator -= denominator;
        // this->reduce();
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction temp(*this);
        numerator -= denominator;
        this->reduce();
        return temp;
    }

    // Output/Input stream operators

    std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
    {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
    istream &operator>>(istream &is, Fraction &fraction)
    {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        return is;
    }
    // Accessor functions for numerator and denominator
    int Fraction::getNumerator() const
    {
        return numerator;
    }

    int Fraction::getDenominator() const
    {
        return denominator;
    }

    Fraction Fraction::reduce()
    {
        // Find the greatest common divisor of numerator and denominator
        int gcd = ariel::gcd(numerator, denominator);

        // Reduce the fraction by dividing both numerator and denominator by the gcd
        numerator /= gcd;
        denominator /= gcd;
        return *this;
    }

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }

} // namespace ariel
