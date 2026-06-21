#include <iostream>
#include "line.h"

int main() {
    Line l;
    Point p;

    std::cin >> l.a >> l.b >> l.c >> p.x >> p.y;
    double g = gradient(&l, &p);
    std::cout << CheckPointPosition(g) << std::endl;
    std::cout << std::endl;
    
    return 0;
}