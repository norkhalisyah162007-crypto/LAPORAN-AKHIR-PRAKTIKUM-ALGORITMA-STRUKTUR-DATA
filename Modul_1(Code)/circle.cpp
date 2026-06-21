#include "circle.h"
#include <cmath>

double distance(const Circle* c, const Point* p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    return sqrt(dx * dx + dy * dy) - c->radius;
}

std::string CheckPointInCircle(double distance) {
    if (fabs(distance) < EPSILON) return "On Circle";
    else if (distance < 0) return "Inside";
    else return "Outside";
}