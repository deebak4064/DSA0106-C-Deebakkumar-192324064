#include <iostream>
#include <string>

class Device {
protected:
    std::string macAddress;

public:
    Device(const std::string &mac) : macAddress(mac) {
        std::cout << "Device configured with MAC: " << macAddress << std::endl;
    }
};

class Sensor : public Device {
private:
    int samplingRate;

public:
    // Base constructor invoked explicitly in the member initializer list
    Sensor(const std::string &mac, int rate) : Device(mac), samplingRate(rate) {
        std::cout << "Sensor configured at " << samplingRate << " Hz" << std::endl;
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
