#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleVIN;
    double baseWeightKg;
public:
    Vehicle(const string &vin, double weight) : vehicleVIN(vin), baseWeightKg(weight) {
        cout << "[1] Vehicle constructor" << endl;
    }
    virtual ~Vehicle() { cout << "[~1] Vehicle destructor" << endl; }
    void DisplaySpecs() const {
        cout << "VIN: " << vehicleVIN << ", base weight: " << baseWeightKg << " kg" << endl;
    }
};

class AutonomousVehicle : public Vehicle {
protected:
    string lidarSensorID, firmwareVersion;
public:
    AutonomousVehicle(const string &vin, double weight, const string &lidar, const string &fw)
        : Vehicle(vin, weight), lidarSensorID(lidar), firmwareVersion(fw) {
        cout << "[2] AutonomousVehicle constructor" << endl;
    }
    ~AutonomousVehicle() override { cout << "[~2] AutonomousVehicle destructor" << endl; }
};

class DeliveryDrone : public AutonomousVehicle {
private:
    double payloadCapacityKg;
    int batteryChargePercent;
public:
    DeliveryDrone(const string &vin, double weight, const string &lidar, const string &fw,
                  double payload, int battery)
        : AutonomousVehicle(vin, weight, lidar, fw),
          payloadCapacityKg(payload), batteryChargePercent(battery) {
        cout << "[3] DeliveryDrone constructor" << endl;
    }
    ~DeliveryDrone() override { cout << "[~3] DeliveryDrone destructor" << endl; }
    void DisplayFlightStatus() const {
        DisplaySpecs();
        cout << "LiDAR: " << lidarSensorID << ", firmware: " << firmwareVersion << endl;
        cout << "Payload: " << payloadCapacityKg << " kg, battery: " << batteryChargePercent << "%" << endl;
    }
};

int main() {
    Vehicle *vPtr = new DeliveryDrone("DRN-7X42-0091", 12.5, "LDR-360-A7", "v4.2.1", 5.0, 87);
    cout << "-- General specs via Vehicle* --" << endl;
    vPtr->DisplaySpecs();
    DeliveryDrone *dPtr = dynamic_cast<DeliveryDrone*>(vPtr);
    if (dPtr != nullptr) {
        cout << "-- Full telemetry via DeliveryDrone* --" << endl;
        dPtr->DisplayFlightStatus();
    }
    delete vPtr;
    return 0;
}
