#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Line 11: Declaring operator<< as a member function
    std::ostream& operator<<(std::ostream &os) {
        os << numerator << "/" << denominator;
        return os;
    }
};

int main() {
    Fraction f1(3, 4);

    // Line 20: Natural stream syntax fails to compile!
    std::cout << f1 << std::endl;

    // Line 23: Compiles, but inverts standard semantics
    f1 << std::cout;

    return 0;
}
