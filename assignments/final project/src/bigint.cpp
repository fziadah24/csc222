#include <iostream>
#include <string>
#include <algorithm>
#include "bigint.h"
using namespace std;

string add_strings(const string& a, const string& b) {
    string result;
    int carry = 0, sum = 0; 
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
    sum = carry;
    if (i >= 0) sum += a[i--] - '0';
    if (j >= 0) sum += b[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
     }

    reverse(result.begin(), result.end());  
    return result;
}

    int compare_strings(const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
            return a.compare(b);
}

BigInt::BigInt() : negative(false), digits("0") {}
BigInt::BigInt(int i) : negative(i < 0), digits(std::to_string(abs(i))) {}

BigInt::BigInt(string n) {
    if (n.empty()) {
        throw std::invalid_argument("Input string is empty");
    }
    
    if (n.front() == '-') {
        if (n.size() == 1 || n.substr(1).find_first_not_of("0123456789") != string::npos) {
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

string BigInt::to_string() const {
    return negative ? "-" + digits : digits;
}