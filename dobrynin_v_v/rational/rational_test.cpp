#include "rational.h"
#include <iostream>
#include <sstream>

int main()
{
    int a, b, c, d;
    //std::cin >> a >> b;
    Rational t1;
    Rational t2;
    Rational t3;

    while (true)
    {
        std::cin >> t1;
        std::cin >> t2;
        t1 -= 2;
        std::cout << t1 << " " << t2;
    }

    //testParse("2/10 ");
    //testParse("3/ 10");
    //testParse("3/ 15 ");
   

    return 0;
}