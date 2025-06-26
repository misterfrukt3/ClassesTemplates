#include "rational.h"
#include <cstring>
#include <cmath>


Rational::Rational() : numerator(0), denominator(1) {}


Rational::Rational(const char* str) {
    int whole = 0;
    int num = 0;
    int denom = 0;
    bool negative = false;

    const char* slash = std::strchr(str, '/');
    const char* space = std::strchr(str, ' ');

    if (str[0] == '-') {
        negative = true;
        str++;
    }

    if (space != nullptr) {
        whole = std::atoi(str);
        str = space + 1;
    }

    if (slash != nullptr) {
        num = std::atoi(str);
        denom = std::atoi(slash + 1);
    } else {
        whole = std::atoi(str);
    }

    if (denom == 0) {
        throw std::invalid_argument("Неверна введена дробь.");
    }

    numerator = whole * denom + num;
    if (negative) {
        numerator = -numerator;
    }
    denominator = denom;
    reduce();
}


Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw std::invalid_argument("Неверна введена дробь.");
    }
    reduce();
}


Rational::Rational(double value, int precision) {
    denominator = 1;
    for (int i = 0; i < precision; ++i) {
        denominator *= 10;
    }
    numerator = static_cast<int>(value * denominator);
    reduce();
}


int greatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void Rational::reduce() {
    if (numerator == 0) {
        denominator = 1;
        return;
    }

    int gcd = greatestCommonDivisor(std::abs(numerator), std::abs(denominator));
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}


std::ostream& operator<<(std::ostream& out, const Rational& frac) {
    if (frac.denominator == 1) {
        out << frac.numerator;
    } else if (std::abs(frac.numerator) > frac.denominator) {
        int whole = frac.numerator / frac.denominator;
        int remNum = std::abs(frac.numerator) % frac.denominator;
        out << whole << " " << remNum << "/" << frac.denominator;
    } else {
        out << frac.numerator << "/" << frac.denominator;
    }
    return out;
}


std::istream& operator>>(std::istream& in, Rational& frac) {
    char buffer[100];
    in.getline(buffer, 100);
    frac = Rational(buffer);
    return in;
}


Rational Rational::operator+(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    Rational result(num, denom);
    result.reduce();
    return result;
}

Rational Rational::operator+(int value) const {
    return *this + Rational(value);
}

Rational Rational::operator+(double value) const {
    return *this + Rational(value);
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator+=(int value) {
    *this = *this + value;
    return *this;
}

Rational& Rational::operator+=(double value) {
    *this = *this + value;
    return *this;
}

Rational operator+(int value, const Rational& frac) {
    return frac + value;
}

Rational operator+(double value, const Rational& frac) {
    return frac + value;
}
