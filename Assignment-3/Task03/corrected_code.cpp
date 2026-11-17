#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}

    // Non-member friend: stream on the left, Fraction on the right
    friend std::ostream& operator<<(std::ostream &os, const Fraction &f);
};

std::ostream& operator<<(std::ostream &os, const Fraction &f) {
    os << f.numerator << "/" << f.denominator;
    return os; // returning the stream enables chaining
}

int main() {
    Fraction f1(3, 4);
    Fraction f2(5, 8);

    std::cout << f1 << std::endl;
    std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
    return 0;
}
