#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Fraction {
    int numerator, denominator; 
    Fraction(int n, int d);
    Fraction();
    Fraction(string s);
    void Print();
    string to_string();
};