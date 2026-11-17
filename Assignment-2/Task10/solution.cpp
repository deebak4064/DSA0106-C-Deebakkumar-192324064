#include <iostream>
#include <iomanip>
using namespace std;

class RegisterBank {
private:
    int registers[8];
    int errorSink;
public:
    RegisterBank() : errorSink(-1) {
        for (int i = 0; i < 8; ++i) registers[i] = 0;
    }
    int& GetRegister(int index) {
        if (index >= 0 && index < 8) return registers[index];
        cout << "ALERT: index " << index << " out of bounds; write redirected to errorSink" << endl;
        errorSink = -1;
        return errorSink;
    }
    void DisplayState() const {
        for (int i = 0; i < 8; ++i)
            cout << "R" << i << "=0x" << hex << uppercase << setw(2) << setfill('0')
                 << registers[i] << dec << setfill(' ') << (i == 3 ? "\n" : "  ");
        cout << endl << "errorSink = " << errorSink << endl;
    }
};

int main() {
    RegisterBank bank;
    bank.GetRegister(0) = 170;
    bank.GetRegister(1) = 255;
    int readVal = bank.GetRegister(0);
    cout << "readVal = " << readVal << endl;
    bank.GetRegister(10) = 999;
    bank.DisplayState();
    return 0;
}
