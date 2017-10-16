#include <iostream>
#include <sstream>
#include <cmath>
#include "vec3d.h"

int main()
{
    vec3d temp;
    vec3d a(1, 2, 3);
    vec3d b(4, 5, 6);
    
    std::cout << a.dotproduct(a, b);
    temp = a.crossproduct(a, b);

    return 0;
}