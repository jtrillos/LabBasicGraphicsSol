
#include <iostream>
#include <math.h>
#include "vector3.h"

using namespace std;

int main()
{
    const Vector3 o{0.0, 0.0, 0.0};
    const Vector3 p1{sqrt(1.0/8), sqrt(1.0/8), sqrt(3.0/4)};
    const Vector3 p2{0.0, 2 * sqrt(1.0/8), 0.0};
    const Vector3 p3{sqrt(1.0/8) + sqrt(3.0/8), sqrt(1.0/8) + sqrt(3.0/8), sqrt(3.0/4) - sqrt(1.0/4)};
    const Vector3 q1{1.0, 1.0, 1.0};
    const Vector3 q2{-1.0, -1.0, 1.0};

    Plane plane(p1, p2, p3);

    Vector3 norm = plane.get_normal();
    double d = plane.get_hnf_d();
    cout << "norm is: ";
    print(norm);

    double dist1, dist2, dist3, dist4, dist5;
    dist1 = plane.distance_to(p1);
    dist2 = plane.distance_to(p2);
    dist3 = plane.distance_to(p3);
    Vector3 p123 = add(p1, add(p2, p3));
    Vector3 p1233 = multiply((1.0/3), p123);
    dist4 = plane.distance_to(p1233);
    dist5 = plane.distance_to(p123);
    cout << "The distance to p1 is: " << dist1 << endl;
    cout << "The distance to p2 is: " << dist2 << endl;
    cout << "The distance to p3 is: " << dist3 << endl;
    cout << "The distance to p123/3 is: " << dist4 << endl;
    cout << "The distance to p123 is: " << dist5 << endl << endl;

    cout << "d is: " << d << endl << endl;

    double dist2o = plane.distance_to(o);
    cout << "Recalculate the distance to origin is: " << dist2o << endl << endl;

    Vector3 closo = plane.closest_point(o);
    cout << "The closet point to o is:  ";
    print(closo);
    double disto =plane.distance_to(o);
    cout << "The distance to o is:  " << disto << endl << endl;

    cout << "I do not know answer e." << endl << endl;

    Line line(q1, q2);

    double distp1 = line.distance_to(p1);
    double distp2 = line.distance_to(p2);
    double distp3 = line.distance_to(p3);
    cout << "The distance to p1 is: " << distp1 << endl;
    cout << "The distance to p2 is: " << distp2 << endl;
    cout << "The distance to p3 is: " << distp3 << endl << endl;

    Vector3 interp = plane.intersect_line(line);
    cout << "The intersect point is: ";
    print(interp);
    double distplane = plane.distance_to(interp);
    double distline = line.distance_to(interp);
    cout << "The distance to plane is: " << distplane << endl;
    cout << "The distance to line is: " << distline << endl;
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
