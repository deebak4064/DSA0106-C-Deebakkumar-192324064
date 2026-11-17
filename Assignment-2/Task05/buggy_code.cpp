#include <iostream>

// Line 4: Incomplete forward declarations
class Engine;

class Engine {
private:
    int temperature;
    int rpm;

public:
    Engine(int t, int r) : temperature(t), rpm(r) {}

    // Declaring friend function
    friend void inspectDiagnostics(Engine e, TelemetryAuditor a);
};

class TelemetryAuditor {
private:
    int alertThreshold;

public:
    TelemetryAuditor(int threshold) : alertThreshold(threshold) {}

    friend void inspectDiagnostics(Engine e, TelemetryAuditor a);
};

// Line 27: Friend function implementation
void inspectDiagnostics(Engine e, TelemetryAuditor a) {
    // Line 29: Unqualified member access error
    if (e.temperature > alertThreshold) {
        std::cout << "Warning: Engine overheat!" << std::endl;
    } else {
        std::cout << "Engine operating nominally at " << e.rpm << " RPM." << std::endl;
    }
}

int main() {
    Engine v8(105, 3200);
    TelemetryAuditor audit(100);

    // Line 41: Invoking friend function as a member function
    v8.inspectDiagnostics(v8, audit);
    return 0;
}
