#pragma once
#include <string>
#include <iostream>

class Time {
private:
    int total_seconds; // Store total seconds for easy calculations

public:
    
    //constructors 
    Time(int hour, int minute, int second);
    Time(int seconds);
    Time();

    //functions
    std::string to_string() const; // Function to return time as a string

    Time operator+(const Time& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Time& time);


};