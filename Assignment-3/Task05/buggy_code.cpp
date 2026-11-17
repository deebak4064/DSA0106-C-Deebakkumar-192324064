#include <iostream>

class MathVector {
public:
    double x, y;
    MathVector(double a, double b) : x(a), y(b) {}

    // Line 8: Attempting to overload member access dot operator
    bool operator.(const MathVector &other) {
        return (x == other.x && y == other.y);
    }
};

// Line 14: Attempting to overload operator for built-in primitive types
int operator+(int a, int b) {
    return a * b;
}

// Line 19: Attempting to invent a non-existent operator '**' for exponentiation
MathVector operator**(MathVector a, int power) {
    // ...
}

int main() {
    MathVector v1(2.0, 3.0), v2(2.0, 3.0);
    return 0;
}
