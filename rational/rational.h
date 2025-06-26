#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int numerator;     
    int denominator;
    void reduce();

public:
    static const int DEFAULT_PRECISION = 4;

    Rational();
    Rational(const char* str);
    Rational(int num, int denom = 1);
    Rational(double value, int precision = DEFAULT_PRECISION);

    friend std::ostream& operator<<(std::ostream& out, const Rational& frac);
    friend std::istream& operator>>(std::istream& in, Rational& frac);


    Rational operator+(const Rational& other) const;
    Rational operator+(int value) const;
    Rational operator+(double value) const;

    Rational& operator+=(const Rational& other);
    Rational& operator+=(int value);
    Rational& operator+=(double value);

    friend Rational operator+(int value, const Rational& frac);
    friend Rational operator+(double value, const Rational& frac);
};

#endif // RATIONAL_H
