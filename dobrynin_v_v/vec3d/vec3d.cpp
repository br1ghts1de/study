#include "vec3d.h"
#include <iostream>
#include <cmath>

vec3d::vec3d(const double x, const double y, const double z)
    :x(x),
    y(y),
    z(z)
{
}


bool vec3d::operator==(const vec3d& input)const
{
    const double eps = 1e-7;
    return (abs(x) - eps >= abs(input.x) <= abs(x) + eps && abs(y) - eps >= abs(input.y) <= abs(y) + eps && abs(z) - eps >= abs(input.z) <= abs(z) + eps);
}
bool vec3d::operator!=(const vec3d& input)const
{
    return !(*this == input);
}

vec3d& vec3d::operator-()const
{
    return vec3d(-x, -y, -z);
}
vec3d& vec3d::operator+()const
{
    return vec3d(x, y, z);
}
vec3d& vec3d::operator+(const vec3d& input)
{
    return vec3d(x + input.x, y + input.y, z + input.z);
}
vec3d& vec3d::operator-(const vec3d& input)
{
    vec3d temp = *this;
    vec3d temp2 = -input;
    temp = temp + temp2;
    return temp;
}
vec3d& vec3d::operator+=(const vec3d& input)
{
    *this = *this + input;
    return *this;
}
vec3d& vec3d::operator-=(const vec3d& input)
{
    *this = *this - input;
    return *this;
}

vec3d vec3d::crossproduct(const vec3d& input1, const vec3d& input2)
{
    double x = input1.y*input2.z - input1.z*input2.y;
    double y = input1.x*input2.z - input1.z*input2.x;
    double z = input1.x*input2.y - input1.y*input2.x;
    return vec3d(x, -y, z);
}

double vec3d::dotproduct(const vec3d& input1, const vec3d& input2)
{
    return input1.x *input2.x + input1.y*input2.y + input1.z*input2.z;
}