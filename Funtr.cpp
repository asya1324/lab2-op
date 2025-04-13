#include "Funtr.h"


double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Viktor(const Triangle &tr){
    return 0.5 * fabs((tr.B.x -tr.A.x)*(tr.C.y -tr.A.y)-(tr.C.x -tr.A.x)*(tr.B.y -tr.A.y));
}


double Triangle::areavik() const {
    return Viktor(*this);
}

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::degtr() const{
    return areavik() == 0;
}

bool Triangle::storcheck(const Point &P) const{
    return (distance(A,P) + distance(B,P) == distance(A,B)) || 
    (distance(A,P) + distance(C,P) == distance(A,C)) ||
    (distance(B,P) + distance(C,P) == distance(B,C)) ;
}
