#include <iostream>

class Vehicle {
public:
    int maxSpeed;
    Vehicle(int s) : maxSpeed(s) {}
    virtual ~Vehicle() {}                 // safe delete through Vehicle*
    void honk() { std::cout << "General Horn" << std::endl; }
    virtual void describe() const { std::cout << "Vehicle, max " << maxSpeed << " km/h" << std::endl; }
};

class SportsCar : public Vehicle {
public:
    bool turboEnabled;
    SportsCar(int s, bool turbo) : Vehicle(s), turboEnabled(turbo) {}
    void engageTurbo() { std::cout << "Turbo Engaged!" << std::endl; }
    void describe() const override {
        std::cout << "SportsCar, max " << maxSpeed << " km/h, turbo "
                  << (turboEnabled ? "on" : "off") << std::endl;
    }
};

int main() {
    Vehicle *vPtr = new SportsCar(300, true);
    vPtr->honk();

    // Explicit downcast, checked at run time
    SportsCar *carPtr = dynamic_cast<SportsCar*>(vPtr);
    if (carPtr != nullptr) {
        carPtr->engageTurbo();
    }

    SportsCar car(250, true);

    // Slicing: only the Vehicle part of car is copied
    Vehicle plainVehicle = car;
    std::cout << "By value  : "; plainVehicle.describe();

    // No slicing: a reference or pointer refers to the whole object
    Vehicle &vehicleRef = car;
    Vehicle *vehiclePtr = &car;
    std::cout << "Reference : "; vehicleRef.describe();
    std::cout << "Pointer   : "; vehiclePtr->describe();

    delete vPtr;
    return 0;
}
