#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class WaterConsumer {
private:
    string consumerID;
    double previousReading, currentReading, unitsConsumed, totalBill;
    double tier1Cost, tier2Cost, tier3Cost, surcharge;
    bool isValid;
public:
    WaterConsumer() : previousReading(0), currentReading(0), unitsConsumed(0), totalBill(0),
                      tier1Cost(0), tier2Cost(0), tier3Cost(0), surcharge(0), isValid(false) {}

    bool Initialize(const string &id, double prev, double curr) {
        if (prev < 0.0 || curr < 0.0) {
            cout << "Error: meter readings cannot be negative." << endl;
            isValid = false;
        } else if (curr < prev) {
            cout << "Error: current reading is below previous reading." << endl;
            isValid = false;
        } else {
            consumerID = id; previousReading = prev; currentReading = curr; isValid = true;
        }
        return isValid;
    }
    void CalculateConsumption() { if (isValid) unitsConsumed = currentReading - previousReading; }
    void ComputeBill() {
        const double TIER1_LIMIT = 100.0, TIER2_LIMIT = 300.0;
        const double RATE1 = 1.50, RATE2 = 2.50, RATE3 = 4.00, SURCHARGE_RATE = 0.10;
        double t1, t2, t3;
        if (unitsConsumed <= TIER1_LIMIT)      { t1 = unitsConsumed; t2 = 0; t3 = 0; }
        else if (unitsConsumed <= TIER2_LIMIT) { t1 = TIER1_LIMIT; t2 = unitsConsumed - TIER1_LIMIT; t3 = 0; }
        else { t1 = TIER1_LIMIT; t2 = TIER2_LIMIT - TIER1_LIMIT; t3 = unitsConsumed - TIER2_LIMIT; }
        tier1Cost = t1 * RATE1; tier2Cost = t2 * RATE2; tier3Cost = t3 * RATE3;
        double baseAmount = tier1Cost + tier2Cost + tier3Cost;
        surcharge = (unitsConsumed > TIER2_LIMIT) ? baseAmount * SURCHARGE_RATE : 0.0;
        totalBill = baseAmount + surcharge;
    }
    void DisplayBill() const {
        cout << fixed;
        cout << "========== WATER BILL INVOICE ==========" << endl;
        cout << "Consumer ID      : " << consumerID << endl;
        cout << setprecision(1);
        cout << "Previous Reading : " << previousReading << " m3" << endl;
        cout << "Current Reading  : " << currentReading << " m3" << endl;
        cout << "Units Consumed   : " << unitsConsumed << " m3" << endl;
        cout << setprecision(2);
        cout << "Tier 1 (1-100)   : $" << tier1Cost << endl;
        cout << "Tier 2 (101-300) : $" << tier2Cost << endl;
        cout << "Tier 3 (> 300)   : $" << tier3Cost << endl;
        cout << "Env. Surcharge   : $" << surcharge << endl;
        cout << "TOTAL PAYABLE    : $" << totalBill << endl;
        cout << "========================================" << endl;
    }
};

int main() {
    WaterConsumer consumer;
    string id; double prev, curr;
    cout << "Enter consumer ID      : "; cin >> id;
    cout << "Enter previous reading : "; cin >> prev;
    cout << "Enter current reading  : "; cin >> curr;
    if (consumer.Initialize(id, prev, curr)) {
        consumer.CalculateConsumption();
        consumer.ComputeBill();
        consumer.DisplayBill();
    } else {
        cout << "Billing aborted: invalid meter readings." << endl;
    }
    return 0;
}
