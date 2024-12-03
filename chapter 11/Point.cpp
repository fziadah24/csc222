#include "Point.h"
#include <iostream>
#include <string>

using namespace std;

Point::Point(int xx){
    x = xx;
    y = 0;
}

Point::Point(int xx, int yy){
    x = xx;
    y = yy;
}

Point::Point(){
    x = 0;
    y = 0;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);

}

string Point::to_string(){

    return "(" + ::to_string(x) + ".000000, " + ::to_string(y) + ".000000)";
}