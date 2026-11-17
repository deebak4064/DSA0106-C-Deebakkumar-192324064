#include <iostream>
#include <sstream>
#include <string>
using namespace std;

inline string FormatPrefix(const string &prefixTag) {
    return "[" + prefixTag + "] ";
}

// Overload 1: general information message
void LogEvent(const string &message) {
    cout << FormatPrefix("INFO") << message << endl;
}

// Overload 2: severity is required; timestamp keeps its default argument
void LogEvent(const string &message, int severityLevel, const string &timestamp = "00:00:00") {
    string severityText;
    switch (severityLevel) {
        case 1: severityText = "LOW"; break;
        case 2: severityText = "MEDIUM"; break;
        case 3: severityText = "CRITICAL"; break;
        default: severityText = "UNKNOWN";
    }
    cout << FormatPrefix(severityText) << "@ " << timestamp << " : " << message << endl;
}

// Overload 3: hardware fault diagnostic
void LogEvent(int errorCode, const string &systemModule) {
    ostringstream hexCode;
    hexCode << hex << uppercase << errorCode;
    cout << FormatPrefix("HARDWARE_FAULT") << "Module: " << systemModule
         << " -> Error Code: 0x" << hexCode.str() << endl;
}

int main() {
    LogEvent("System boot complete");
    LogEvent("Coolant pressure dropping", 2);
    LogEvent("Spindle motor stalled", 3, "14:32:07");
    LogEvent(4660, "ACTUATOR_CTRL");
    return 0;
}
