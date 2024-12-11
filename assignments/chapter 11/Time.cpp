#include <iostream>
#include "Time.h"
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

Time::Time(int hour, int minute, int second) {
    total_seconds = hour * 3600 + minute * 60 + second;
}

Time::Time(int seconds) {
    total_seconds = seconds;
}

Time::Time(){
    total_seconds = 0;
}

std::string Time::to_string() const {
    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

   stringstream ss;
    ss << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    return ss.str();
}

Time Time::operator+(const Time& other) const {
    return Time(total_seconds + other.total_seconds);
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.to_string();
    return os;
}