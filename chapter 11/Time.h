#pragma once
#include <string>
using namespace std;
struct Time {
    //instance variables
    int hour, minute, second;
    
    //constructors 
    Time(int hour, int minute, int second);    
    Time(int seconds);
    Time();
    //functions
    string toString();
};