#include <iostream>

// Forward declaration: the name is known before Engine uses it
class TelemetryAuditor;

class Engine {
private:
    int temperature;
    int rpm;

public:
    Engine(int t, int r) : temperature(t), rpm(r) {}

    friend void inspectDiagnostics(const Engine &e, const TelemetryAuditor &a);
};

class TelemetryAuditor {
private:
    int alertThreshold;

public:
    TelemetryAuditor(int threshold) : alertThreshold(threshold) {}

    friend void inspectDiagnostics(const Engine &e, const TelemetryAuditor &a);
};

// Non-member friend: no this pointer, so every member is object-qualified
void inspectDiagnostics(const Engine &e, const TelemetryAuditor &a) {
    if (e.temperature > a.alertThreshold) {
        std::cout << "Warning: Engine overheat! (" << e.temperature
                  << " > " << a.alertThreshold << ")" << std::endl;
    } else {
        std::cout << "Engine operating nominally at " << e.rpm << " RPM." << std::endl;
    }
}

int main() {
    Engine v8(105, 3200);
    Engine cruise(90, 2400);
    TelemetryAuditor audit(100);

    // Called like an ordinary function, not through an object
    inspectDiagnostics(v8, audit);
    inspectDiagnostics(cruise, audit);
    return 0;
}
