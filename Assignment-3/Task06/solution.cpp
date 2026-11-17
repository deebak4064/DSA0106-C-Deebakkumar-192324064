#include <iostream>
using namespace std;

class DynStr {
private:
    char *dataPtr;
    int charCount;
public:
    DynStr(const char *sourceString) {
        charCount = 0;
        while (sourceString[charCount] != '\0') charCount++;
        dataPtr = new char[charCount + 1];
        for (int i = 0; i <= charCount; ++i) dataPtr[i] = sourceString[i];
        cout << "[alloc] " << charCount + 1 << " bytes for \"" << dataPtr << "\"" << endl;
    }
    DynStr(const DynStr &other) {
        charCount = other.charCount;
        dataPtr = new char[charCount + 1];
        for (int i = 0; i <= charCount; ++i) dataPtr[i] = other.dataPtr[i];
        cout << "[deep copy] " << charCount + 1 << " bytes for \"" << dataPtr << "\"" << endl;
    }
    ~DynStr() {
        cout << "[free] \"" << dataPtr << "\"" << endl;
        delete[] dataPtr;
        dataPtr = nullptr;
    }
    DynStr operator+(const DynStr &rhs) const {
        int total = charCount + rhs.charCount;
        char *temp = new char[total + 1];
        cout << "[temp] " << total + 1 << " bytes for concatenation" << endl;
        for (int i = 0; i < charCount; ++i) temp[i] = dataPtr[i];
        for (int j = 0; j < rhs.charCount; ++j) temp[charCount + j] = rhs.dataPtr[j];
        temp[total] = '\0';
        DynStr result(temp);
        delete[] temp;
        cout << "[temp freed]" << endl;
        return result;
    }
    void Display() const { cout << "\"" << dataPtr << "\" (" << charCount << " chars)" << endl; }
};

int main() {
    DynStr strA("Hello ");
    DynStr strB("World!");
    DynStr strC = strA + strB;
    cout << "strC = "; strC.Display();
    DynStr strD = strC;
    cout << "strD = "; strD.Display();
    cout << "--- end of main: destructors run in reverse order ---" << endl;
    return 0;
}
