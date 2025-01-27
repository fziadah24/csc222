#include <string>
using namespace std;

class BigInt
{
    bool negative;
    string digits;

    public:
    BigInt();
    BigInt(int);
    BigInt(string);

    bool operator==(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<=(const BigInt&) const;



    string to_string() const;
};