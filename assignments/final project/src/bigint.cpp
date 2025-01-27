#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i < 0); 
    digits = std::to_string(std::abs(i)); 
}

BigInt::BigInt(string n)
{
    if (n.empty()) {
        throw std::invalid_argument("Input string is empty");
    }
    if (n.front() == '-') {
        if (n.size() == 1 || n.substr(1).find_first_not_of("0123456789") != std::string::npos) {
            throw std::invalid_argument("Invalid number format");
        }
        negative = true;
        digits = n.substr(1);
    } else if (n.front() == '+') {
        if (n.size() == 1 || n.substr(1).find_first_not_of("0123456789") != std::string::npos) {
            throw std::invalid_argument("Invalid number format");
        }
        negative = false;
        digits = n.substr(1);
    } else {
        if (n.find_first_not_of("0123456789") != std::string::npos) {
            throw std::invalid_argument("Invalid number format");
        }
        negative = false;
        digits = n;
    }

    while (digits.size() > 1 && digits.front() == '0') {
        digits.erase(0, 1);
    }

    if (digits == "0") {
        negative = false;
    }
}

bool BigInt::operator==(const BigInt&) const;
bool BigInt::operator>(const BigInt&) const;
bool BigInt::operator<(const BigInt&) const;
bool BigInt::operator!=(const BigInt&) const;


string BigInt::to_string() const
{
    return negative ? "-" + digits : digits;
}