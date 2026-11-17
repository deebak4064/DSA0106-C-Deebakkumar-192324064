#include <iostream>

class Vehicle {
public:
    int maxSpeed;
    Vehicle(int s) : maxSpeed(s) {}
    void honk() { std::cout << "General Horn" << std::endl; }
};

class SportsCar : public Vehicle {
public:
    bool turboEnabled;
    SportsCar(int s, bool turbo) : Vehicle(s), turboEnabled(turbo) {}
    void engageTurbo() { std::cout << "Turbo Engaged!" << std::endl; }
};

int main() {
    // Upcasting: Base pointer pointing to derived object
    Vehicle *vPtr = new SportsCar(300, true);

    vPtr->honk();

    // Line 22: Attempting to call derived method through Base pointer
    vPtr->engageTurbo(); // Compilation Error!

    // Line 26: Value assignment between polymorphic types
    SportsCar car(250, true);
    Vehicle plainVehicle = car; // Object Slicing occurs here!

    delete vPtr;
    return 0;
}
