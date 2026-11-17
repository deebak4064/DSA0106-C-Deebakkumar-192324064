#include <iostream>
#include <string>

class Device {
protected:
    std::string macAddress;

public:
    // Parameterized constructor ONLY - no default constructor provided!
    Device(std::string mac) : macAddress(mac) {
        std::cout << "Device configured with MAC: " << macAddress << std::endl;
    }
};

class Sensor : public Device {
private:
    int samplingRate;

public:
    // Line 18: Derived constructor fails to explicitly call Device(mac)
    Sensor(std::string mac, int rate) {
        // Attempting to assign in body after base constructor already attempted
        macAddress = mac;
        samplingRate = rate;
    }

    void display() const {
        std::cout << "MAC: " << macAddress << ", Rate: " << samplingRate << " Hz" << std::endl;
    }
};

int main() {
    Sensor tempSensor("00:1A:2B:3C:4D:5E", 100);
    tempSensor.display();
    return 0;
}
