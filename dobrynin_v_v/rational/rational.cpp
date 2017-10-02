#include "rational.h"
#include <iostream>
#include <sstream>

inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
inline int lcm(int a, int b) { return a*b / gcd(a, b); }

void Rational::easy()
{
    int temp = abs(gcd(num, den));
    num /= temp;
    den /= temp;
    if (den < 0)
    {
        den = -den;
        num = -num;
    }
}

//constructors
Rational::Rational(const int a, const int b) :num(a), den(b)
{
    easy();
}
Rational::Rational(const int a) : num(a) {}

Rational& Rational::operator=(const int &a)
{
    num = a; den = 1;
    return *this;
}
Rational& Rational::operator=(const Rational &a)
{
    den = a.den;
    num = a.num;
    return *this;
}

bool operator==(const Rational &a, const Rational &b)
{
    return (a.den == b.den && a.num == b.num);
}
bool operator!=(const Rational &a, const Rational &b)
{ 
    return !(a.den == b.den && a.num == b.num); 
}

Rational operator-(const Rational &a)
{
    Rational temp(-a.num, a.den);
    return temp;
}
Rational operator+(const Rational &a)
{
    return Rational(a.num, a.den);
}

Rational operator++(const Rational &a) 
{
    Rational t(a.num + a.den, a.den);
    t.easy();
    return t;
}
Rational operator--(const Rational &a) 
{
    Rational t(a.num - a.den, a.den);
    t.easy();
    return t;
}

Rational operator+(const Rational &a, const Rational &b)
{
    int znam = a.den * b.den;
    int c1 = b.den * a.num;
    int c2 = a.den * b.num;
    c1 += c2;
    Rational r(c1, znam);
    r.easy();
    return r;
}
Rational operator-(const Rational &a, const Rational &b)
{
    return a + (-b);
}

Rational&Rational::operator++()
{
    num = num + den;
    easy();
    return *this;
}
Rational&Rational::operator++(int)
{
    Rational temp = *this;
    ++*this;
    return temp;
}
Rational&Rational::operator--()
{
    num = num - den;
    easy();
    return *this;
}
Rational&Rational::operator--(int)
{
    Rational temp = *this;
    --*this;
    return temp;
}

Rational&Rational::operator+=(const Rational&input)
{
    *this = *this + input;
    return *this;
}
Rational&Rational::operator-=(const Rational&input)
{
    *this = *this - input;
    return *this;
}
Rational&Rational::operator*=(const Rational&input)
{
    *this = *this*input;
    return *this;
}
Rational&Rational::operator/=(const Rational&input)
{
    *this = *this / input;
    return *this;
}

Rational operator*(const Rational &a, const Rational &b)
{
    Rational temp{ a.num*b.num,a.den*b.den };
    temp.easy();
    return temp;
}
Rational operator/(const Rational &a, const Rational &b)
{
    Rational temp{ b.den,b.num };
    return a*temp;
}
//Rational operator*= (const Rational &a)




std::ostream &Rational::writeTo(std::ostream &ostrm) const
{
    ostrm << num << frac << den;
    return ostrm;
}
std::istream &Rational::readFrom(std::istream &istrm)
{
    int deninp = -1;
    int numinp = 0;
    char frac(0);
    istrm >> numinp >> frac >> deninp;

    //std::cout << istrm.good() << std::endl;
    //std::cout << istrm.eof()<< std::endl;
    //std::cout << istrm.fail() << std::endl;
    //std::cout << istrm.bad() << std::endl;
    //std::cout << istrm.rdstate() << std::endl;
    // TESTING
    
    if (istrm.good())
    {
        if (Rational::frac == frac)
        {
            num = numinp;
            den = deninp;
            easy();
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

inline std::ostream &operator<<(std::ostream &ostrm, const Rational &out)
{
    return out.writeTo(ostrm);
}
inline std::istream &operator>>(std::istream &istrm, Rational &inp)
{
    return inp.readFrom(istrm);
}

////////////////////////////////////////////////////???????????
extern inline bool testParse(const std::string &inp)
{
    std::istringstream istrm(inp);
    Rational a;
    istrm >> a;
    if (istrm.good())
    {
        std::cout << "Success: " << inp << "->" << a << std::endl;
    }
    else
    {
        std::cout << "ERROR: " << inp << "->" << a << std::endl;
    }
    return istrm.good();
}
