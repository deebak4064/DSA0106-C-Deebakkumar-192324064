#include <iostream>

int main() {
    unsigned char num = 15;

    // Parentheses force (num & 1) to be evaluated before ==
    if (((num & 1) == 1) && (num > 10)) {
        std::cout << "Valid Odd Number: " << static_cast<int>(num)
                  << std::endl;
    } else {
        std::cout << "Condition Failed for: " << static_cast<int>(num)
                  << std::endl;
    }

    // Signed counter: i becomes -1 after 0, so i >= 0 turns false
    for (int i = 3; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
