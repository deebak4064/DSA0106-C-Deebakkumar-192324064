#include <iostream>
using namespace std;

class Polynomial {
private:
    int degree;
    double *coeffArray;
    double outOfRangeSink;
public:
    Polynomial(int deg) : degree(deg), outOfRangeSink(0.0) {
        coeffArray = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) coeffArray[i] = 0.0;
    }
    Polynomial(const Polynomial &other) : degree(other.degree), outOfRangeSink(0.0) {
        coeffArray = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) coeffArray[i] = other.coeffArray[i];
    }
    ~Polynomial() { delete[] coeffArray; coeffArray = nullptr; }

    double& operator[](int index) {
        if (index < 0 || index > degree) {
            cout << "Error: index " << index << " outside 0.." << degree << endl;
            outOfRangeSink = 0.0;
            return outOfRangeSink;
        }
        return coeffArray[index];
    }

    Polynomial operator+(const Polynomial &rhs) const {
        int maxDeg = (degree > rhs.degree) ? degree : rhs.degree;
        Polynomial result(maxDeg);
        for (int i = 0; i <= maxDeg; ++i) {
            double a = (i <= degree) ? coeffArray[i] : 0.0;
            double b = (i <= rhs.degree) ? rhs.coeffArray[i] : 0.0;
            result.coeffArray[i] = a + b;
        }
        return result;
    }

    void Display() const {
        bool first = true;
        for (int i = degree; i >= 0; --i) {
            if (coeffArray[i] == 0.0) continue;
            if (!first) cout << " + ";
            if (coeffArray[i] != 1.0 || i == 0) cout << coeffArray[i];
            if (i >= 2) cout << "x^" << i; else if (i == 1) cout << "x";
            first = false;
        }
        if (first) cout << "0";
        cout << endl;
    }
};

int main() {
    Polynomial p1(2);
    p1[2] = 3.0; p1[1] = 2.0; p1[0] = 5.0;
    Polynomial p2(3);
    p2[3] = 4.0; p2[2] = 1.0; p2[0] = 7.0;
    cout << "P1(x) = "; p1.Display();
    cout << "P2(x) = "; p2.Display();
    Polynomial p3 = p1 + p2;
    cout << "P3 = P1 + P2 = "; p3.Display();
    Polynomial p4 = p3;            // deep copy
    p4[0] = 99.0;
    cout << "P4 (copy, P4[0] = 99) = "; p4.Display();
    cout << "P3 unchanged         = "; p3.Display();
    p1[5] = 1.0;                   // out-of-range write
    return 0;
}
