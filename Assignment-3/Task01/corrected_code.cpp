#include <iostream>
#include <cstring>

class DynamicString {
private:
    char *buffer;
    int length;

public:
    // Parameterized Constructor
    DynamicString(const char *str) {
        length = std::strlen(str);
        buffer = new char[length + 1];
        std::strcpy(buffer, str);
    }

    // Copy Constructor: parameter passed by const reference
    DynamicString(const DynamicString &source) {
        length = source.length;
        buffer = new char[length + 1];          // fresh buffer (deep copy)
        std::strcpy(buffer, source.buffer);
    }

    ~DynamicString() {
        delete[] buffer;
    }

    void print() const {
        std::cout << buffer << std::endl;
    }
};

int main() {
    DynamicString s1("Antigravity C++");
    DynamicString s2 = s1; // calls DynamicString(const DynamicString&)
    std::cout << "s1: "; s1.print();
    std::cout << "s2: "; s2.print();
    return 0;
}
