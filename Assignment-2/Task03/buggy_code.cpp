#include <iostream>

// Overload 1: Cuboid volume with default dimensions
double computeVolume(double length, double width = 1.0, double height = 1.0) {
    return length * width * height;
}

// Overload 2: Dedicated function for cube volume
double computeVolume(double side) {
    return side * side * side;
}

// Overload 3: Cylinder volume calculation
double computeVolume(double radius, double height) {
    return 3.14159 * radius * radius * height;
}

int main() {
    // Line 19: Call with 1 argument fails compilation
    std::cout << "Volume: " << computeVolume(5.0) << std::endl;

    // Line 22: Call with 2 arguments
    std::cout << "Cylinder: " << computeVolume(3.0, 7.0) << std::endl;
    return 0;
}
