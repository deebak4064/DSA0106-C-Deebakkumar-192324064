#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r) : real(r), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }
    bool operator==(const Complex &other) const {
        const double EPSILON = 1e-9;
        return fabs(real - other.real) < EPSILON && fabs(imag - other.imag) < EPSILON;
    }
    void Display() const {
        if (imag >= 0) cout << real << " + " << imag << "i";
        else           cout << real << " - " << -imag << "i";
    }
};

int main() {
    Complex z0;
    Complex z1(5.0);
    Complex c1(3.0, 2.0), c2(1.0, 4.0);
    cout << "Default     : "; z0.Display(); cout << endl;
    cout << "One-arg     : "; z1.Display(); cout << endl;
    cout << "C1          : "; c1.Display(); cout << endl;
    cout << "C2          : "; c2.Display(); cout << endl;
    cout << "C1 + C2     : "; (c1 + c2).Display(); cout << endl;
    cout << "C1 * C2     : "; (c1 * c2).Display(); cout << endl;
    cout << boolalpha;
    cout << "C1 == C2    : " << (c1 == c2) << endl;
    cout << "C1 == (3,2) : " << (c1 == Complex(3.0, 2.0)) << endl;
    return 0;
}
