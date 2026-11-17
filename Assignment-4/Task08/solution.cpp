#include <iostream>
#include <iomanip>
using namespace std;

class Point2D {
public:
    double x, y;
    Point2D(double xVal = 0.0, double yVal = 0.0) : x(xVal), y(yVal) {
        cout << "Point2D constructed at (" << x << ", " << y << ")" << endl;
    }
};

class Circle {
private:
    Point2D centerPoint;      // has-a: member object
    double radius;
public:
    Circle() : centerPoint(0.0, 0.0), radius(1.0) {
        cout << "Circle constructed, radius " << radius << endl;
    }
    Circle& SetCenter(double newX, double newY) {
        centerPoint.x = newX;
        centerPoint.y = newY;
        cout << "SetCenter(" << newX << ", " << newY << ") -> returns *this" << endl;
        return *this;
    }
    Circle& SetRadius(double r) {
        if (r > 0.0) {
            radius = r;
            cout << "SetRadius(" << r << ") -> returns *this" << endl;
        } else {
            cout << "SetRadius(" << r << ") rejected: radius must be > 0" << endl;
        }
        return *this;
    }
    void Draw() const {
        const double PI = 3.14159265358979;
        cout << fixed << setprecision(2);
        cout << "Circle: center (" << centerPoint.x << ", " << centerPoint.y
             << "), radius " << radius << endl;
        cout << "        area " << PI * radius * radius
             << ", circumference " << 2 * PI * radius << endl;
        cout.unsetf(ios::fixed);
    }
};

int main() {
    Circle myCircle;
    myCircle.SetCenter(12.5, 30.0).SetRadius(7.5).Draw();
    myCircle.SetRadius(-3.0).Draw();
    return 0;
}
