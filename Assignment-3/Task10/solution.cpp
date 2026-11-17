#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;
public:
    Vector2D(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {}

    Vector2D& operator++() {          // prefix
        x += 1.0; y += 1.0;
        return *this;
    }
    Vector2D operator++(int) {        // postfix
        Vector2D snapshot = *this;
        x += 1.0; y += 1.0;
        return snapshot;
    }
    Vector2D& operator+=(const Vector2D &rhs) {
        x += rhs.x; y += rhs.y;
        return *this;
    }
    void Display(const char *name) const {
        cout << name << " = (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector2D v1(5.0, 8.0);
    v1.Display("v1 (start)");
    Vector2D v2 = ++v1;
    cout << "After v2 = ++v1:" << endl;
    v1.Display("  v1"); v2.Display("  v2");
    Vector2D v3 = v1++;
    cout << "After v3 = v1++:" << endl;
    v1.Display("  v1"); v2.Display("  v2"); v3.Display("  v3");
    v1 += v2;
    cout << "After v1 += v2:" << endl;
    v1.Display("  v1");
    return 0;
}
