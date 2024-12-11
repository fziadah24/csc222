#pragma once
#include <string>
#include <iostream>

class Point {
public:
    double x, y;

    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    std::string to_string() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << point.to_string();
        return os;
    }
};