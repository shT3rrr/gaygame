#include "Vector.h"
#include <algorithm>

Vector::Vector(int new_x, int new_y) :
        x(std::clamp(new_x, 0, 100)),
        y(std::clamp(new_y, 0, 100)) {
}

Vector::Vector():
        x(0),
        y(0){
}


