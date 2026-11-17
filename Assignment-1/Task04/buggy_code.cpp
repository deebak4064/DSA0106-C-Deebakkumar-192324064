#include <iostream>

int main() {
    int a = 25;

    // Line 7: Reference declaration without immediate binding
    int &refA;
    refA = a;

    // Line 11: Non-const lvalue reference bound to an rvalue literal
    int &refLiteral = 100;

    // Line 14: Non-const reference bound to an expression requiring conversion
    double pi = 3.14159;
    int &refInt = pi;

    // Line 17: Modification through a const reference
    const int &constRef = 50;
    constRef = constRef + 10;

    std::cout << a << " " << refA << std::endl;
    return 0;
}
