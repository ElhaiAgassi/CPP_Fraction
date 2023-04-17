#define CATCH_CONFIG_MAIN // This tells Catch2 to generate a main() function
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdexcept>
#include "sources/Fraction.hpp"

TEST_CASE("Fraction Addition")
{
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction result = f1 + f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction Subtraction")
{
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result = f1 - f2;
    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 4);
}

TEST_CASE("Fraction Multiplication")
{
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction result = f1 * f2;
    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 8);
}

TEST_CASE("Fraction Division")
{
    Fraction f1(3, 4);
    Fraction f2(2, 1);
    Fraction result = f1 / f2;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 8);
}

TEST_CASE("Fraction Equality")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    CHECK(f1 == f2);
}

TEST_CASE("Fraction Comparison")
{
    Fraction f1(1, 2);
    Fraction f2(1, 4);
    CHECK(f1 > f2);
    CHECK(f1 >= f2);
    CHECK(f2 < f1);
    CHECK(f2 <= f1);
}

TEST_CASE("Fraction Increment/Decrement")
{
    Fraction f1(1, 2);
    Fraction result = ++f1;
    CHECK(result.getNumerator() == 3);
    CHECK(result.getDenominator() == 2);

    Fraction f2(3, 4);
    result = --f2;
    CHECK(result.getNumerator() == -1);
    CHECK(result.getDenominator() == 4);
}
// TEST_CASE("Fraction Output Stream")
// {
//     Fraction f1(3, 4);
//     std::ostringstream os1;
//     os1 << f1;
//     CHECK(os1.str() == "3/4");
// }

// TEST_CASE("Fraction Input Stream")
// {
//     Fraction f1;
//     std::istringstream iss("5/6");
//     iss >> f1;
//     CHECK(f1.getNumerator() == 5);
//     CHECK(f1.getDenominator() == 6);
// }
