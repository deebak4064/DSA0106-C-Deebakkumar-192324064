#include <iostream>
#include <iomanip>
using namespace std;

const unsigned GYRO_LOCKED = 0x01, ACCEL_CALIBRATED = 0x02, BARO_ONLINE = 0x04, GPS_FIX = 0x08;
const unsigned LOW_BATTERY = 0x10, OVER_TEMP = 0x20, RADIO_LINK = 0x40, FATAL_ACTUATOR = 0x80;
const unsigned BYTE_MASK = 0xFF;
const unsigned MANDATORY_MASK = GYRO_LOCKED | ACCEL_CALIBRATED | BARO_ONLINE | GPS_FIX;   // 0x0F
const unsigned INHIBITOR_MASK = LOW_BATTERY | OVER_TEMP | FATAL_ACTUATOR;                 // 0xB0

void printHex(unsigned v) {
    cout << "0x" << hex << uppercase << setw(2) << setfill('0') << v << dec << setfill(' ');
}

bool CheckFlightReadiness(unsigned statusRegister) {
    bool ready = true;
    statusRegister &= BYTE_MASK;
    unsigned presentSensors   = statusRegister & MANDATORY_MASK;
    unsigned missingSensors   = presentSensors ^ MANDATORY_MASK;
    unsigned crossCheck       = (~statusRegister) & MANDATORY_MASK;
    unsigned activeInhibitors = statusRegister & INHIBITOR_MASK;

    if (crossCheck != missingSensors) cout << "Internal error: mask computation mismatch." << endl;

    if (activeInhibitors != 0) {
        ready = false;
        if (activeInhibitors & LOW_BATTERY)    cout << "FAULT Bit 4: Low Battery Warning" << endl;
        if (activeInhibitors & OVER_TEMP)      cout << "FAULT Bit 5: Over-Temperature Warning" << endl;
        if (activeInhibitors & FATAL_ACTUATOR) cout << "FAULT Bit 7: Fatal Actuator Hardware Failure" << endl;
    }
    if (missingSensors != 0) {
        ready = false;
        cout << "Missing-sensor XOR mask = "; printHex(missingSensors); cout << endl;
        if (missingSensors & GYRO_LOCKED)      cout << "MISSING Bit 0: Gyroscope not locked" << endl;
        if (missingSensors & ACCEL_CALIBRATED) cout << "MISSING Bit 1: Accelerometer not calibrated" << endl;
        if (missingSensors & BARO_ONLINE)      cout << "MISSING Bit 2: Barometric altimeter offline" << endl;
        if (missingSensors & GPS_FIX)          cout << "MISSING Bit 3: No GPS satellite fix" << endl;
    }
    if (statusRegister & RADIO_LINK) cout << "INFO Bit 6: Radio telemetry link active" << endl;
    else                             cout << "INFO Bit 6: Radio link inactive (non-blocking)" << endl;

    cout << (ready ? "STATUS: CLEARED FOR FLIGHT" : "STATUS: FLIGHT INHIBITED") << endl;
    return ready;
}

int main() {
    const unsigned testBytes[2] = {0x4F, 0x3B};
    for (unsigned b : testBytes) {
        cout << "--- statusRegister = "; printHex(b); cout << " ---" << endl;
        CheckFlightReadiness(b);
        cout << endl;
    }
    return 0;
}
