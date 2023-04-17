#include "Fraction.hpp"
#include <iostream>
#include <sstream>


// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

// Constructor with numerator and denominator
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

// Arithmetic operators

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

// Overloaded operator+ with Fraction and double operand
Fraction operator+(const Fraction& fraction, double value) {
    return Fraction(fraction.numerator + fraction.denominator * value, fraction.denominator);
}

// Overloaded operator- with Fraction and double operand
Fraction operator-(const Fraction& fraction, double value) {
    return Fraction(fraction.numerator - fraction.denominator * value, fraction.denominator);
}

// Overloaded operator* with Fraction and double operand
Fraction operator*(const Fraction& fraction, double value) {
    return Fraction(fraction.numerator * value, fraction.denominator);
}

// Overloaded operator/ with Fraction and double operand
Fraction operator/(const Fraction& fraction, double value) {
    return Fraction(fraction.numerator / value, fraction.denominator);
}

// Overloaded operator+ with double and Fraction operand
Fraction operator+(double value, const Fraction& fraction) {
    return Fraction(fraction.numerator + fraction.denominator * value, fraction.denominator);
}

// Overloaded operator- with double and Fraction operand
Fraction operator-(double value, const Fraction& fraction) {
    return Fraction(fraction.denominator * value - fraction.numerator, fraction.denominator);
}

// Overloaded operator* with double and Fraction operand
Fraction operator*(double value, const Fraction& fraction) {
    return Fraction(fraction.numerator * value, fraction.denominator);
}

// Overloaded operator/ with double and Fraction operand
Fraction operator/(double value, const Fraction& fraction) {
    return Fraction(value * fraction.denominator, fraction.numerator);
}

// Comparison operators

bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

// Increment/Decrement operators

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    numerator += denominator;
    return temp;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    numerator -= denominator;
    return temp;
}

// Output/Input stream operators

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& fraction) {
    char slash;
    is >> fraction.numerator >> slash >> fraction.denominator;
    return is;
}
