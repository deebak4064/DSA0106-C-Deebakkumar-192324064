#include <iostream>
#include <cmath>

class MathVector {
public:
    double x, y;
    MathVector(double a, double b) : x(a), y(b) {}

    // Equality: replaces the illegal operator.
    bool operator==(const MathVector &other) const {
        return (x == other.x && y == other.y);
    }

    // Vector addition: at least one operand is a user-defined type
    MathVector operator+(const MathVector &other) const {
        return MathVector(x + other.x, y + other.y);
    }

    // Ordinary member function instead of an invented ** operator
    MathVector power(int n) const {
        return MathVector(std::pow(x, n), std::pow(y, n));
    }

    friend std::ostream& operator<<(std::ostream &os, const MathVector &v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

int main() {
    MathVector v1(2.0, 3.0), v2(2.0, 3.0);
    std::cout << std::boolalpha;
    std::cout << "v1 == v2      : " << (v1 == v2) << std::endl;
    std::cout << "v1 + v2       : " << (v1 + v2) << std::endl;
    std::cout << "v1.power(3)   : " << v1.power(3) << std::endl;
    std::cout << "2 + 3 (built-in, unchanged): " << (2 + 3) << std::endl;
    return 0;
}
