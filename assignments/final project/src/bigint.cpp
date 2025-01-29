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

string subtract_strings(const string& a, const string& b) {
    string result;
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0) {
        int sub = (a[i] - '0') - (j >= 0 ? (b[j] - '0') : 0) - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(sub + '0');
        i--; j--;
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

string multiply_strings(const string& a, const string& b) {  // Added multiplication
    if (a == "0" || b == "0") return "0";

    vector<int> result(a.size() + b.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {  // Remove leading zeros
            product.push_back(num + '0');
        }
    }

    return product.empty() ? "0" : product;
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

BigInt BigInt::operator+(const BigInt& other) const {
    if (negative == other.negative) {
        return BigInt((negative ? "-" : "") + add_strings(digits, other.digits));
    }
    
    // If signs are different, determine which number is larger
    if (compare_strings(digits, other.digits) >= 0) {
        return BigInt((negative ? "-" : "") + subtract_strings(digits, other.digits));
    } else {
        return BigInt((other.negative ? "-" : "") + subtract_strings(other.digits, digits));
    }
}

BigInt BigInt::operator-(const BigInt& other) const {  // Added subtraction
    if (negative != other.negative) {
        return BigInt((negative ? "-" : "") + add_strings(digits, other.digits));
    }
    
    if (compare_strings(digits, other.digits) >= 0) {
        return BigInt((negative ? "-" : "") + subtract_strings(digits, other.digits));
    } else {
        return BigInt((negative ? "" : "-") + subtract_strings(other.digits, digits));
    }
}

BigInt BigInt::operator*(const BigInt& other) const {  // Added multiplication
    string product = multiply_strings(digits, other.digits);
    bool result_negative = (negative != other.negative && product != "0");
    return BigInt((result_negative ? "-" : "") + product);
}