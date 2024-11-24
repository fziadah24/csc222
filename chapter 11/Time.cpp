#include <iostream>
#include "Time.h"
#include <string>
using namespace std;
Time::Time(int hour, int  minute, int second){
    int h = hour;
    int m = minute;
    int s = second;
}
Time::Time(int hour){
    int h = hour;
    int m = 0;
    int s = 0;
}
Time::Time(){
    int h = 0;
    int m = 0;
    int s = 0;
}
string Time::toString(){
    return "0";
}