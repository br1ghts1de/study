#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>


//inline bool testParse(const std::string &inp);

class Rational
{
public:
    // constructors
    Rational() { num = 0, den = 1; }
    Rational(const int a);
    Rational(const int a, const int b);

    // prisvaivanie
    Rational& operator=(const Rational &a);
    Rational& operator=(const int &a);
    
    // uproshenie
    void easy();
    
    // drobnaya cherta
    static const char frac{ '/' };

    // schitivanie
    std::ostream &writeTo(std::ostream &ostr) const;
    std::istream &readFrom(std::istream &istrm);

    // peregruzka unarnih ++ i --
    Rational & operator++();
    Rational & operator++(int);
    Rational & operator--();
    Rational & operator--(int);

    Rational & operator*=(const Rational &input);
    Rational & operator/= (const Rational &input);
    Rational & operator+=(const Rational &input);
    Rational & operator-=(const Rational &input);
    int num;
    int den;
};

Rational operator+(const Rational &a, const Rational &b);
Rational operator-(const Rational &a, const Rational &b);

bool operator==(const Rational &a, const Rational &b);
bool operator!=(const Rational &a, const Rational &b);

Rational operator-(const Rational &a);
Rational operator+(const Rational &a);

Rational operator*(const Rational &a, const Rational &b);
Rational operator/(const Rational &a, const Rational &b);



std::ostream &operator<<(std::ostream &ostrm, const Rational &out);
std::istream &operator>>(std::istream &istrm, Rational &inp);


#endif