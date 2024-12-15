#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d){
    numerator = n;
    denominator = d; 
}

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(string s){
    string slash = "/", s2 = s;
    int slashpos = s.find(slash);
    numerator = stoi (s.erase(slashpos));
    denominator = stoi (s2.erase(0, slashpos+1));

}

string Fraction::to_string(){
    return ::to_string(numerator) + "/" + ::to_string(denominator);
}