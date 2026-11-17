#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class OutOfBoundsException {
private:
    double value;
public:
    explicit OutOfBoundsException(double v) : value(v) {}
    double GetValue() const { return value; }
};

// May throw: noexcept(false)
double CalibrateThermalSensors(double rawVoltage) noexcept(false) {
    const double MIN_TEMP = -273.15, MAX_TEMP = 1500.0;
    double temperature = (rawVoltage - 0.5) * 100.0;   // 10 mV per degree, 0.5 V offset
    cout << "  Calibrate(" << rawVoltage << " V) -> " << temperature << " C" << endl;
    if (temperature < MIN_TEMP || temperature > MAX_TEMP)
        throw OutOfBoundsException(temperature);
    return temperature;
}

// Must never throw: noexcept contract
void CommitTelemetry(double finalTemp) noexcept {
    try {
        if (finalTemp > 1000.0)
            throw runtime_error("bus frame overflow");   // internal fault
        cout << "  Committed " << finalTemp << " C to avionics bus" << endl;
    }
    catch (...) {
        cout << "  Commit fault suppressed inside noexcept function" << endl;
    }
}

int main() {
    static_assert(noexcept(CommitTelemetry(0.0)), "CommitTelemetry must be noexcept");
    cout << boolalpha << fixed << setprecision(2);
    cout << "noexcept(CalibrateThermalSensors(0)) = " << noexcept(CalibrateThermalSensors(0.0)) << endl;
    cout << "noexcept(CommitTelemetry(0))         = " << noexcept(CommitTelemetry(0.0)) << endl;

    const double readings[3] = {3.20, -2.50, 12.00};
    for (double v : readings) {
        cout << "Reading " << v << " V:" << endl;
        try {
            double t = CalibrateThermalSensors(v);
            CommitTelemetry(t);
        }
        catch (const OutOfBoundsException &e) {
            cout << "  [MAIN] OutOfBoundsException: " << e.GetValue() << " C" << endl;
            cout << "         outside [-273.15, 1500.00]; reading rejected" << endl;
        }
        catch (...) {
            cout << "  [MAIN] unknown calibration failure" << endl;
        }
    }
    return 0;
}
