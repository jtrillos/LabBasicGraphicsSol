#ifndef VECTOR3_H
#define VECTOR3_H

#include <stdio.h>

struct Vector3
{
    double x;
    double y;
    double z;
};

void print(const Vector3& a);
Vector3 add(const Vector3& a, const Vector3& b);
Vector3 substract(const Vector3& a, const Vector3& b);
Vector3 multiply(double s, const Vector3& b);
double dot_product(const Vector3& a, const Vector3& b);
double length(const Vector3& a);
Vector3 normalize(const Vector3& a);
Vector3 cross_product(const Vector3& a, const Vector3& b);
#endif // VECTOR3_H
