
#include "vector3.h"
#include <math.h>


Line::Line(const Vector3& p1, const Vector3& p2){
    point1=p1;
    point2=p2;
}

const Vector3& Line::get_point1() const{
    return point1;
}
const Vector3& Line::get_point2() const{
    return point2;
}

Vector3 Line::closest_point(const Vector3& p){
    Vector3 a_c;
    Vector3 b_a;
    Vector3 cp;
    a_c = substract(point1, p);
    b_a = substract(point2, point1);
    double temp1, temp2, temp3;
    temp1 = dot_product(a_c, b_a);
    temp2 = dot_product(b_a, b_a);
    temp3 = temp1/temp2;
    cp = substract(point1, multiply(temp3, b_a));
    return cp;
}

double Line::distance_to(const Vector3& p){
    double d;
    Vector3 closestp = Line::closest_point(p);
    d = length(substract(p, closestp));
    return d;
}


Plane::Plane(Vector3 p1, Vector3 p2, Vector3 p3){
    Vector3 a_c, b_c;
    a_c = substract(p1, p3);
    b_c = substract(p2, p3);
    Vector3 numerator = cross_product(a_c, b_c);
    double denominator = length(numerator);
    normal = multiply((1.0 / denominator), numerator);
    point = p1;

}

const Vector3& Plane::get_point() const{
    return point;
}


const Vector3& Plane::get_normal() const{
    return normal;
}

double Plane::get_hnf_d() const{

    double c = -dot_product(get_point(), get_normal());
    return c;

}

Vector3 Plane::closest_point(const Vector3& p){
    Vector3 norm = get_normal();
    double d = get_hnf_d();
    Vector3 clop, temp2;
    double temp1;
    temp1 = d + dot_product(p, norm);
    temp2 = multiply(temp1, norm);
    clop = substract(p, temp2);
    return clop;

}

double Plane::distance_to(const Vector3& p){
    double d;
    Vector3 closestp = Plane::closest_point(p);
    d = length(substract(closestp, p));
    return d;

}
Vector3 Plane::intersect_line(const Line &l){
    Vector3 norm = get_normal();
    double d = get_hnf_d();
    Vector3 a = l.get_point1();
    Vector3 b = l.get_point2();
    Vector3 b_a, temp4, interLine;
    b_a = substract(b, a);
    double temp1, temp2, temp3;
    temp1 = dot_product(a, norm);
    temp2 = dot_product(b_a, norm);
    temp3 = (d + temp1)/temp2;
    temp4 = multiply(temp3, b_a);
    interLine = substract(a, temp4);
    return interLine;
}
