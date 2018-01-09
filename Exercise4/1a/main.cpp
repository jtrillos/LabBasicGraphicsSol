#include <iostream>
#include <math.h>
#include "vector3.h"

using namespace std;

int main(){
    double s=-2;
    const Vector3 a{1, 2, 3};
    const Vector3 b{-1, 2, -2};

    Vector3 ad = add(a, b);
    Vector3 sub = substract(a, b);
    Vector3 mul = multiply(s, b);
    double dp = dot_product(a, b);
    double l = length(a);
    Vector3 no = normalize(a);
    Vector3 cp = cross_product(a, b);
    cout << "Add: ";
    print(ad);
    cout << "Substraction: ";
    print(sub);
    cout << "Multiply: ";
    print(mul);
    cout << "Dot product: ";
    cout << dp << endl;
    cout << "Length: ";
    cout << l << endl;
    cout << "Normalize: ";
    print(no);
    cout << "Cross product: ";
    print(cp);
    return 0;
}

void print(const Vector3& a){
    cout << "x=" << a.x << "  y=" << a.y << "  z=" << a.z << endl;
}

Vector3 add(const Vector3& a, const Vector3& b){
    Vector3 ad;
    ad.x = a.x + b.x;
    ad.y = a.y + b.y;
    ad.z = a.z + b.z;
    return ad;
}

Vector3 substract(const Vector3& a, const Vector3& b){
    Vector3 sub;
    sub = add(a, multiply(-1, b));
    return sub;
}

Vector3 multiply(double s, const Vector3& b){
    Vector3 mul;
    mul.x = s * b.x;
    mul.y = s * b.y;
    mul.z = s * b.z;
    return mul;

}

double dot_product(const Vector3& a, const Vector3& b){
    double dp;
    dp = a.x * b.x + a.y * b.y + a.z * b.z;
    return dp;
}

double length(const Vector3& a){
    double l;
    l = sqrt(dot_product(a, a));
    return l;

}

Vector3 normalize(const Vector3& a){
    Vector3 no;
    no.x = a.x/length(a);
    no.y = a.y/length(a);
    no.z = a.z/length(a);
    return no;

}

Vector3 cross_product(const Vector3& a, const Vector3& b){
    Vector3 cp;
    //a x b = { a2b3 - b2a3 , a3b1 - b3a1 , a1b2 - a2b1 }
    cp.x = a.y * b.z - b.y * a.z;
    cp.y = a.z * b.x - b.z * a.x;
    cp.z = a.x * b.y - a.y * b.x;
    return cp;
}
