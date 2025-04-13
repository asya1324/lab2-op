#pragma once
#include <cmath>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    double areavik() const;
    bool degtr() const;
    bool storcheck(const Point &P) const;

    bool contains(const Point &P) const {
        Triangle T1 = {A, B, P};
        Triangle T2 = {B, C, P};
        Triangle T3 = {C, A, P};

        double S_main = area();
        double S_sum = T1.area() + T2.area() + T3.area();

        return fabs(S_main - S_sum) < 1e-9;
    }

    bool containsvik(const Point &P) const {
        Triangle T1 = {A, B, P};
        Triangle T2 = {B, C, P};
        Triangle T3 = {C, A, P};

        double S_main = areavik();
        double S_sum = T1.areavik() + T2.areavik() + T3.areavik();

        return fabs(S_main - S_sum) < 1e-9;
    }

};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
double Viktor(const Triangle &tr);
