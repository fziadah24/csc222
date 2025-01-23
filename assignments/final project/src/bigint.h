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

    string to_string() const;
};