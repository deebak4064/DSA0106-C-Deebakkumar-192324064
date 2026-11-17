#include <iostream>

int main() {
    unsigned char num = 15;

    // Line 7: Intended to check if num is odd AND greater than 10
    if (num & 1 == 1 && num > 10) {
        std::cout << "Valid Odd Number: " << (int)num << std::endl;
    } else {
        std::cout << "Condition Failed for: " << (int)num << std::endl;
    }

    // Line 14: Intended to decrement from 3 down to 0 inclusive
    for (unsigned char i = 3; i >= 0; --i) {
        std::cout << (int)i << " ";
        if (i == 0) break; // Added as a temporary patch
    }
    std::cout << std::endl;

    return 0;
}
