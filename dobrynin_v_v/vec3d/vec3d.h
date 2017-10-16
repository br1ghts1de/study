#ifndef VEC3D_H
#define VEC3D_H

#include <iostream>
#include <cmath>

class vec3d
{
    //private:
private:
    double x{ 0 };
    double y{ 0 };
    double z{ 0 };

public:
    vec3d(const double x, const double y, const double z);
    ~vec3d() {}
    vec3d() = default;

public:
    bool operator==(const vec3d& input) const;
    bool operator!=(const vec3d& input) const;
    vec3d& operator-()const;
    vec3d& operator+()const;
    vec3d& operator+(const vec3d& input);
    vec3d& operator-(const vec3d& input);
    vec3d& operator-=(const vec3d& input);
    vec3d& operator+=(const vec3d& input);
    
    double dotproduct(const vec3d& input1, const vec3d& input2);
    vec3d crossproduct(const vec3d& input1, const vec3d& input2);
};



#endif