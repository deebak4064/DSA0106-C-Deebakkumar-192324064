#include <iostream>

// Distinct parameter types make every overload unambiguous
struct Cube     { double side; };
struct Cylinder { double radius; double height; };
struct Cuboid   { double length; double width = 1.0; double height = 1.0; };

double computeVolume(const Cube &c) {
    return c.side * c.side * c.side;
}

double computeVolume(const Cylinder &c) {
    return 3.14159 * c.radius * c.radius * c.height;
}

double computeVolume(const Cuboid &c) {
    return c.length * c.width * c.height;
}

int main() {
    std::cout << "Cube Volume: " << computeVolume(Cube{5.0}) << std::endl;
    std::cout << "Cylinder: " << computeVolume(Cylinder{3.0, 7.0}) << std::endl;
    std::cout << "Cuboid (5): " << computeVolume(Cuboid{5.0}) << std::endl;
    std::cout << "Cuboid (5 x 2): " << computeVolume(Cuboid{5.0, 2.0}) << std::endl;
    std::cout << "Cuboid (5 x 2 x 3): " << computeVolume(Cuboid{5.0, 2.0, 3.0}) << std::endl;
    return 0;
}
